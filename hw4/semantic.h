
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <vector>
#include <string>
using namespace std;

enum ScopeType: int{
    DEFAULT_SCOPE,  GLOBAL_SCOPE,   FUNCTION_SCOPE, LOOP_SCOPE
};

enum NodeType : int{ 
    T_VOID,     T_PROGRAM,  T_STRING,   T_REAL,     T_INTEGER,  
    T_BOOLEAN,  T_FUNCTION, T_PARAMS,   T_PARAM,    T_VAR,
    T_CONST_VAR,T_ARRAY,    T_LOOP_VAR, T_OPERATOR
} ;

enum OperatorType: int{
    T_OP_ADD,       T_OP_SUB,     T_OP_MUL,     T_OP_DIV,     T_OP_MOD,
    T_OP_LT,        T_OP_LE,      T_OP_EQ,      T_OP_GT,      T_OP_GE,
    T_OP_NE,        T_OP_AND,     T_OP_OR,      T_OP_NOT,     T_OP_ASSIGN 
};

struct ConstValue{
    ConstValue();
    ConstValue(NodeType type, void *value);
    const ConstValue operator *= (int factor);
    const ConstValue operator && (ConstValue& operand);
    const ConstValue operator || (ConstValue& operand);
    const ConstValue operator ! ();
    const ConstValue operator + (ConstValue& operand);
    const ConstValue operator - (ConstValue& operand);
    const ConstValue operator * (ConstValue& operand);
    const ConstValue operator / (ConstValue& operand);
    const ConstValue operator % (ConstValue& operand);
    const ConstValue operator > (ConstValue& operand);
    const ConstValue operator >= (ConstValue& operand);
    const ConstValue operator == (ConstValue& operand);
    const ConstValue operator <= (ConstValue& operand);
    const ConstValue operator < (ConstValue& operand);
    const ConstValue operator != (ConstValue& operand);

    NodeType type;
    union {
        float real_value;
        int int_value;
        char *str_value;
        bool bool_value;
    } value;
private:
    const ConstValue __arithmetic(ConstValue& operand, float (*op)(float, float));
    const ConstValue __compare(ConstValue& operand, bool (*op)(float, float));
};

typedef struct Dimension{ 
    Dimension();
    Dimension(int lb, int ub);
    int lower_bound, upper_bound, size; 
}Dimension;

typedef struct TypeNode{
    TypeNode();
    TypeNode(NodeType type);
    // array constructor
    TypeNode(TypeNode *type, int lower_bound, int upper_bound); 
    NodeType type;
    vector<Dimension> dimensions;
} TypeNode;

typedef struct IDList{
    IDList();
    IDList(const char *id);
    void insert(const char *id);
    vector<string> ids;
} IDList;

typedef struct Param{
    Param();
    Param(const char *name, NodeType node_type, TypeNode *type);
    char *name;
    NodeType node_type;
    TypeNode *type;
} Param; 

struct ParamList{
    ParamList();
    ParamList(IDList *id_list, TypeNode *type);
    void extend(ParamList *param_list);
    void insert(Param *param);
    NodeType type;
    vector<Param> params;
};

union AttrNode{
    AttrNode();
    AttrNode(ConstValue *const_value);
    AttrNode(ParamList *param_list);
    ParamList *param_list;
    ConstValue *const_value;
};

struct Symbol{
    Symbol();
    Symbol(const char *name, NodeType node_type, TypeNode *type, AttrNode *attr = NULL);
    char *name;
    NodeType node_type;
    TypeNode *type;
    AttrNode *attr;
};

struct ExprList{ vector<ConstValue> exprs; };

struct VarRef{
    VarRef();
    VarRef(Symbol* symbol);
    ConstValue* get_value();
    NodeType get_type();
    Symbol* symbol;
    vector<int> addr;
};

typedef vector<Symbol> Scope;

class SymbolTable{
public:
    SymbolTable();
    void dump_symbols();
    void new_scope(int sope_type = DEFAULT_SCOPE);
    void delete_scope(bool dump = false);
    void insert(Symbol symbol, bool global = false);
    Symbol* find(const char* name);
    bool has_been_declared(char* name);
private:
    vector<Scope> scopes;
    // used to store previous scope type
    int __scope; 
};

/*******************************
*       Helper functions       *
*******************************/


bool verify_function_call(Symbol* func, ExprList* args);
bool verify_assignable(VarRef* var_ref, ConstValue* value);
NodeType coercion(NodeType a, NodeType b);
const char* stringify(NodeType node_type);
const char* stringify(TypeNode type);
const char* stringify(vector<Param>& params);
const char* stringify(ConstValue& const_value);

#endif
