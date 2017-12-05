
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include "semantic.h"

extern int linenum;

const static std::string __type_names[] = { 
    "program", "void", "string", "real", "integer","boolean", "function", "", 
    "parameter", "variable", "constant", "variable", "loop_variable" 
};

ConstValue::ConstValue() = default;
ConstValue::ConstValue(NodeType type, void* value) : type(type){
    switch(type){
        case T_INTEGER:
            this->value.int_value = *(int*)value;
            delete (int*)value;
            break;
        case T_REAL:
            this->value.real_value = *(float*)value;
            delete (float*)value;
            break;
        case T_STRING:
            this->value.str_value = strdup((char*)value);
            break;
        case T_BOOLEAN:
            this->value.bool_value = *(bool*)value;
            delete (bool*)value;
            break;
    }
}

Dimension::Dimension() = default;
Dimension::Dimension(int lb, int ub) : lower_bound(lb), upper_bound(ub), size(ub - lb + 1) {}

TypeNode::TypeNode() = default;
TypeNode::TypeNode(NodeType type) : type(type) {}
TypeNode::TypeNode(TypeNode* inherit, int lb, int ub) : type(inherit->type), dimensions(std::move(inherit->dimensions)){
    dimensions.push_back(Dimension(lb, ub));
};

Symbol::Symbol() = default;
Symbol::Symbol(char const* name, NodeType node_type, TypeNode* type, AttrNode* attr) 
        : name(strdup(name)), node_type(node_type), type(type), attr(attr) {}

SymbolTable::SymbolTable(){ scopes.push_back(Scope()); };
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
        if(symbol.node_type == T_FUNCTION) printf("%-11s", stringify(symbol.attr->func_attr->params));
        else if(symbol.node_type == T_CONST_VAR) printf("%-11s", stringify(*symbol.attr->rvalue));
        printf("\n");
    }
    
    for(int i=0;i< 110;i++) printf("-");
    printf("\n");
}
void SymbolTable::insert(Symbol symbol, bool global){
    if( ! has_been_declared(symbol.name)){
        if(global)scopes[0].push_back(symbol);
        else scopes[scopes.size() - 1].push_back(symbol);
    }
    else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, symbol.name);
}
bool SymbolTable::has_been_declared(char* id){
    // first check current scope
    Scope &current_scope = scopes[scopes.size() - 1];
    for(auto &symbol: current_scope)
        if( !strcmp(id, symbol.name) )return true;
    // then check loop_vars in all scopes
    for(auto& scope: scopes)
        for(auto& symbol: scope)
            if(symbol.node_type == T_LOOP_VAR && !strcmp(id, symbol.name))return true;
    return false;
}


AttrNode::AttrNode() = default;
AttrNode::AttrNode(ConstValue* rvalue) : rvalue(rvalue) {}
AttrNode::AttrNode(FuncAttr* func_attr) : func_attr(func_attr) {}

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
Param::Param(const char* name, NodeType node_type, TypeNode* type) 
     : name(strdup(name)), node_type(node_type), type(type) {}

ParamList::ParamList() = default;
ParamList::ParamList(IDList* id_list, TypeNode* type){
    for(auto &id: id_list->ids)
        params.push_back(Param(id.c_str(), type->dimensions.size() ? T_ARRAY: T_VAR, type));
    delete id_list;
}
void ParamList::extend(ParamList* param_list){
    for(auto &param: param_list->params)params.push_back(param);
    delete param_list;
}

FuncAttr::FuncAttr() = default;
FuncAttr::FuncAttr(TypeNode* return_type, ParamList* param_list) {
    for(auto &param: param_list->params)params.push_back(param);
}

IDList::IDList() = default;
IDList::IDList(const char *id){ insert(id); }
void IDList::insert(const char* id){ ids.push_back(std::string(id)); }

const char* stringify(NodeType node_type){ return __type_names[node_type].c_str(); }
const char* stringify(TypeNode type){
    static std::string result;
    result = __type_names[type.type];
    if(type.dimensions.size()){
        result += ' ';
        for(auto dim = type.dimensions.rbegin(); dim != type.dimensions.rend() ; dim ++){
            result += '[';
            result += std::to_string(dim->size);
            result += ']';
        }
    }
    return result.c_str();
}
const char* stringify(std::vector<Param>& params){
    static std::string result;
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
    static std::string result;
    switch(const_value.type){
        case T_INTEGER: 
            result = std::to_string(const_value.value.int_value);
            break;
        case T_REAL: 
            result = std::to_string(const_value.value.real_value);
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
