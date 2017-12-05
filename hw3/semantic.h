
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <vector>
#include <string>

enum ScopeType: int{
    DEFAULT_SCOPE,
    GLOBAL_SCOPE,
    FUNCTION_SCOPE,
    LOOP_SCOPE
};

enum NodeType : int{ 
    T_PROGRAM,
    T_VOID,
    T_STRING, 
    T_REAL,
    T_INTEGER, 
    T_BOOLEAN, 
    T_FUNCTION,
    T_PARAMS,
    T_PARAM,
    T_VAR,
    T_CONST_VAR,
    T_ARRAY,
    T_LOOP_VAR
} ;

typedef struct ConstValue{
    ConstValue();
    ConstValue(NodeType type, void* value);
    NodeType type;
    union {
        float real_value;
        int int_value;
        char* str_value;
        bool bool_value;
    } value;
} ConstValue;

typedef struct Dimension{ 
    Dimension();
    Dimension(int lb, int ub);
    int lower_bound, upper_bound, size; 
}Dimension;

typedef struct TypeNode{
    TypeNode();
    TypeNode(NodeType type);
    // array constructor
    TypeNode(TypeNode* type, int lower_bound, int upper_bound); 
    NodeType type;
    std::vector<Dimension> dimensions;
} TypeNode;

typedef struct IDList{
    IDList();
    IDList(const char* id);
    NodeType type;
    void insert(const char* id);
    std::vector<std::string> ids;
} IDList;

typedef struct Param{
    Param();
    Param(const char* name, NodeType node_type, TypeNode* type);
    char* name;
    NodeType node_type;
    TypeNode *type;
} Param; 

struct ParamList{
    ParamList();
    ParamList(IDList* id_list, TypeNode* type);
    void extend(ParamList* param_list);
    void insert(Param* param);
    NodeType type;
    std::vector<Param> params;
};
typedef struct FuncAttr{
    FuncAttr();
    FuncAttr(TypeNode* return_type, ParamList* param_list);
    TypeNode *return_type;
    std::vector<Param> params;
} FuncAttr;

union AttrNode{
    AttrNode();
    AttrNode(ConstValue* rvalue);
    AttrNode(FuncAttr* func_attr);
    FuncAttr *func_attr;
    ConstValue *rvalue;
};

struct Symbol{
    Symbol();
    Symbol(const char* name, NodeType node_type, TypeNode* type, AttrNode* attr);
    char* name;
    NodeType node_type;
    TypeNode *type;
    AttrNode *attr;
};

typedef std::vector<Symbol> Scope;

class SymbolTable{
public:
    SymbolTable();
    void dump_symbols();
    void new_scope(int sope_type = DEFAULT_SCOPE);
    void delete_scope(bool dump = false);
    void insert(Symbol symbol, bool global = false);
    bool has_been_declared(char*);
private:
    std::vector<Scope> scopes;
    // used to store previous scope type
    int __scope; 
};

const char* stringify(NodeType node_type);
const char* stringify(TypeNode type);
const char* stringify(std::vector<Param>& params);
const char* stringify(ConstValue& const_value);

#endif
