
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include "cpp.h"
#include "semantic.h"
using namespace std;

extern int linenum;

const static string __type_names[] = { 
    "void", "program", "string", "real", "integer","boolean", "function", "", 
    "parameter", "variable", "constant", "variable", "loop_variable" 
};

ConstValue::ConstValue() = default;
ConstValue::ConstValue(NodeType type, void *value) : type(type){
    switch(type){
        case T_INTEGER:
            if(value){
                this->value.int_value = *(int*)value;
                delete (int*)value;
            }
            else this->value.int_value = 0;
            break;
        case T_REAL:
            if(value){
                this->value.real_value = *(float*)value;
                delete (float*)value;
            }
            else this->value.real_value = 0;
            break;
        case T_STRING:
            if(value)this->value.str_value = strdup((char*)value);
            else this->value.str_value = NULL;
            break;
        case T_BOOLEAN:
            if(value){
                this->value.bool_value = *(bool*)value;
                delete (bool*)value;
            }
            else this->value.bool_value = 0;
            break;
    }
}
const ConstValue ConstValue::__arithmetic(ConstValue& operand, float (*op)(float, float)){
    static ConstValue result;
    result = ConstValue(T_VOID, NULL);
    if (coercion(type, operand.type) == T_INTEGER) 
        result.type = T_INTEGER;
    else if (coercion(type, operand.type) == T_REAL || coercion(operand.type, type) == T_REAL)
        result.type = T_REAL;
    return result; 
}
const ConstValue ConstValue::__compare(ConstValue& operand, bool (*op)(float, float)){
    static ConstValue result;
    result = ConstValue(T_VOID, NULL);
    if (coercion(type, operand.type) == T_INTEGER || 
        coercion(type, operand.type) == T_REAL || 
        coercion(operand.type, type) == T_REAL)
        result.type = T_BOOLEAN;
    return result; 
}
const ConstValue ConstValue::operator *= (int factor){
    // currently do nothing
    switch(this->type){
        case T_INTEGER: 
            break;
        case T_REAL: 
            break;
    }
}

const ConstValue ConstValue::operator && (ConstValue& operand){
    // TODO: type check
    return ConstValue(T_BOOLEAN, new bool(this->value.bool_value && operand.value.bool_value));
}
const ConstValue ConstValue::operator || (ConstValue& operand){
    // TODO: type check
    return ConstValue(T_BOOLEAN, new bool(this->value.bool_value || operand.value.bool_value));
}
const ConstValue ConstValue::operator ! (){
    // TODO: type check
    return ConstValue(T_BOOLEAN, new bool(!this->value.bool_value));
}
const ConstValue ConstValue::operator + (ConstValue& operand){
    if((type == T_INTEGER || type == T_REAL) && (operand.type == T_INTEGER || operand.type == T_REAL))
        return __arithmetic(operand, [](float a, float b){ return a + b; });
    else if(type == T_STRING && operand.type == T_STRING){
        string s = string(value.str_value) + operand.value.str_value;
        return ConstValue(T_STRING, (void*)s.c_str());
    }
    return ConstValue(T_VOID, NULL);
}
const ConstValue ConstValue::operator - (ConstValue& operand){
    return __arithmetic(operand, [](float a, float b){ return a - b; });
}
const ConstValue ConstValue::operator * (ConstValue& operand){
    return __arithmetic(operand, [](float a, float b){ return a * b; });
}
const ConstValue ConstValue::operator / (ConstValue& operand){
    return __arithmetic(operand, [](float a, float b){ return a / b; });
}
const ConstValue ConstValue::operator % (ConstValue& operand){
    if (type == T_INTEGER && operand.type == T_INTEGER)
        return ConstValue(T_INTEGER, new int(0));
    return ConstValue(T_VOID, NULL);
}
const ConstValue ConstValue::operator > (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a > b; });;
}
const ConstValue ConstValue::operator >= (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a >= b; });;
}
const ConstValue ConstValue::operator == (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a == b; });;
}
const ConstValue ConstValue::operator <= (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a <= b; });;
}
const ConstValue ConstValue::operator < (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a < b; });;
}
const ConstValue ConstValue::operator != (ConstValue& operand){
    return __compare(operand, [](float a, float b){ return a != b; });;
}

Dimension::Dimension() = default;
Dimension::Dimension(int lb, int ub) : lower_bound(lb), upper_bound(ub), size(ub - lb + 1) {}

TypeNode::TypeNode() = default;
TypeNode::TypeNode(NodeType type) : type(type) {}
TypeNode::TypeNode(TypeNode *inherit, int lb, int ub) : type(inherit->type), dimensions(move(inherit->dimensions)){
    dimensions.push_back(Dimension(lb, ub));
    delete inherit;
}

AttrNode::AttrNode() = default;
AttrNode::AttrNode(ConstValue *const_value) : const_value(const_value) {}
AttrNode::AttrNode(ParamList *param_list) : param_list(param_list) {}

Symbol::Symbol() = default;
Symbol::Symbol(const char *name, NodeType node_type, TypeNode *type, AttrNode *attr) 
        : name(strdup(name)), node_type(node_type), type(type), attr(attr) {}

VarRef::VarRef() = default;
VarRef::VarRef(Symbol* symbol) : symbol(symbol) {}
ConstValue* VarRef::get_value(){ 
    if(symbol){
        switch(symbol->type->type){
            case T_INTEGER: return new ConstValue(T_INTEGER, new int(0));
            case T_REAL: return new ConstValue(T_REAL, new float(0));
            case T_BOOLEAN: return new ConstValue(T_BOOLEAN, new bool(0));
            case T_STRING: return new ConstValue(T_STRING, new char(0));
        }
    }
    return new ConstValue(T_VOID, NULL); 
}
NodeType VarRef::get_type(){ 
    if(symbol)return symbol->type->type;
    return T_VOID; 
}

SymbolTable::SymbolTable(){ scopes.push_back(Scope()); }
void SymbolTable::dump_symbols(){
    for(int i=0;i< 110;i++) printf("=");
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type", "Attribute");
    for(int i=0;i< 110;i++) printf("-");
    printf("\n");
    int level = scopes.size() - 1;
    for(auto &symbol: scopes[level]){
        if(symbol.node_type == T_LOOP_VAR)continue;
        printf("%-33s", symbol.name);
        printf("%-11s", stringify(symbol.node_type));
        printf("%d%-10s", level, level ? "(local)" : "(global)");
        printf("%-17s", symbol.type ? stringify(*symbol.type) : "");
        // attribute;
        if(symbol.node_type == T_FUNCTION) printf("%-11s", stringify(symbol.attr->param_list->params));
        else if(symbol.node_type == T_CONST_VAR) printf("%-11s", stringify(*symbol.attr->const_value));
        printf("\n");
    }
    
    for(int i=0;i< 110;i++) printf("-");
    printf("\n");
}
void SymbolTable::insert(Symbol symbol, bool global){
    if( !has_been_declared(symbol.name)){
        if(global)scopes[0].push_back(symbol);
        else scopes[scopes.size() - 1].push_back(symbol);
    }
    else {
        string message = string("symbol ") + symbol.name +  " is redeclared ";
        yyerror(message.c_str());
    }
}
Symbol* SymbolTable::find(const char* name){
    Scope &current_scope = scopes[scopes.size() - 1];
    // first seach current scope
    for(auto &symbol: current_scope)
        if( !strcmp(name, symbol.name) )return &symbol;
    // then search loop_vars in all scopes
    for(auto& scope: scopes)
        for(auto& symbol: scope)
            if( symbol.node_type == T_LOOP_VAR && !strcmp(name, symbol.name) )return &symbol;
    // then search global_vars in global scopes
    for(auto &symbol: scopes[0])
        if( !strcmp(name, symbol.name) )return &symbol;
    // not found;
    string message = string("symbol \'") + name + "\' used before declared.";
    yyerror(message.c_str());
    return NULL;
}
bool SymbolTable::has_been_declared(char *name){
    // first check current scope
    Scope &current_scope = scopes[scopes.size() - 1];
    for(auto &symbol: current_scope)
        if( !strcmp(name, symbol.name) )return true;
    // then check loop_vars in all scopes
    for(auto& scope: scopes)
        for(auto& symbol: scope)
            if(symbol.node_type == T_LOOP_VAR && !strcmp(name, symbol.name))return true;
    return false;
}

void SymbolTable::new_scope(int scope_type){ 
    if(!__scope)scopes.push_back(Scope()); 
    else __scope = 0;
    // function scope is a special case
    if(scope_type == FUNCTION_SCOPE)__scope = 1;
}
void SymbolTable::delete_scope(bool dump){
    if(dump)dump_symbols();
    scopes.pop_back();
}

Param::Param() = default;
Param::Param(const char *name, NodeType node_type, TypeNode *type) 
     : name(strdup(name)), node_type(node_type), type(type) {}

ParamList::ParamList() = default;
ParamList::ParamList(IDList *id_list, TypeNode *type){
    for(auto &id: id_list->ids)
        params.push_back(Param(id.c_str(), type->dimensions.size() ? T_ARRAY: T_VAR, type));
    delete id_list;
}
void ParamList::extend(ParamList *param_list){
    for(auto &param: param_list->params)params.push_back(param);
    delete param_list;
}

IDList::IDList() = default;
IDList::IDList(const char *id){ insert(id); }
void IDList::insert(const char *id){ ids.push_back(string(id)); }

/*******************************
*       Helper functions       *
*******************************/

bool verify_function_call(Symbol* func, ExprList* args){
    if(args){
        if(func->attr->param_list->params.size() > args->exprs.size()){
            string message = string("too few arguments to function \'") + func->name+ "\'"; 
            yyerror(message.c_str());
            return false;
        }
        else if(func->attr->param_list->params.size() < args->exprs.size()){
            string message = string("too many arguments to function \'") + func->name+ "\'"; 
            yyerror(message.c_str());
            return false;
        }
        else {
            bool ok = true;
            for(int i = 0 ;i < func->attr->param_list->params.size() ; i ++){
                if(func->attr->param_list->params[i].type->type != args->exprs[i].type){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                yyerror("parameter type mismatch");
                return false;
            }
        }
    }
    else if(func->attr->param_list->params.size()){
        string message = string("too many arguments to function \'") + func->name+ "\'"; 
        yyerror(message.c_str());
        return false;
    }
    return true;
}
bool verify_assignable(VarRef* var_ref, ConstValue* value){
    if(!var_ref || !value )return false;
    if(var_ref->get_type() != value->type){
        NodeType type = coercion(var_ref->get_type(), value->type);
        if(!type){
            string message = string("type mismatch, LHS= ") + __type_names[var_ref->get_type()];
            message += string(", RHS= ") + __type_names[value->type];
            yyerror(message.c_str());
            return false;
        }
    }
    return true;
}
NodeType coercion(NodeType a, NodeType b){
    if(a == b)return a;
    else if(a == T_INTEGER && b == T_REAL) return T_REAL;
    return T_VOID;
}

const char* stringify(NodeType node_type){ return __type_names[node_type].c_str(); }
const char* stringify(TypeNode type){
    static string result;
    result = __type_names[type.type];
    if(type.dimensions.size()){
        result += ' ';
        for(auto dim = type.dimensions.rbegin(); dim != type.dimensions.rend() ; dim ++){
            result += '[';
            result += to_string(dim->size);
            result += ']';
        }
    }
    return result.c_str();
}
const char* stringify(vector<Param>& params){
    static string result;
    result = "";
    bool first = true;
    for(auto &param: params){
        if(first)first = false;
        else result += ", ";
        result += stringify(*param.type);
    }
    return result.c_str();
}


const char* stringify(ConstValue& const_value){
    static string result;
    switch(const_value.type){
        case T_INTEGER: 
            result = to_string(const_value.value.int_value);
            break;
        case T_REAL: 
            result = to_string(const_value.value.real_value);
            break;
        case T_STRING: 
            result = const_value.value.str_value;
            break;
        case T_BOOLEAN: 
            result = const_value.value.bool_value ? "true" : "false";
            break;
   } 
   return result.c_str();
}

