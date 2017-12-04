
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nodedef.h"
#include "semantic.h"

void symbol_table_new_scope(){
    symbol_table.level ++;
    if( symbol_table.level == symbol_table.__max_level){
        symbol_table.__max_level *= 2;
        Block *temp = (Block*)malloc(sizeof(Block) * symbol_table.__max_level);
        memcpy(temp, symbol_table.levels, sizeof(Block) * symbol_table.level);
        free(symbol_table.levels);
        symbol_table.levels = temp;
    }
    Block *level_ref = symbol_table.levels + symbol_table.level;
    level_ref = (Block*)malloc(sizeof(Block));
}

void symbol_table_delete_scope(){
    symbol_table.levels[symbol_table.level].size = 0;
    symbol_table.level --;
}

void symbol_table_init(){
    int i;
    symbol_table.level = 0;
    symbol_table.__max_level = INITIAL_LEVEL_SIZE;
    symbol_table.levels = (Block*)malloc(sizeof(Block) * INITIAL_LEVEL_SIZE);
    for(i = 0 ;i < INITIAL_LEVEL_SIZE; i ++){
        symbol_table.levels[i].size = 0;
        symbol_table.levels[i].__max_size = INITIAL_SYMBOL_COUNT;
        symbol_table.levels[i].symbols = (Symbol*)malloc(sizeof(Symbol) * INITIAL_SYMBOL_COUNT);
    }
}

void symbol_table_global(Symbol *symbol){
    int m = symbol_table.levels[0].size;
    symbol_table.levels[0].symbols[m] = *symbol;
    symbol_table.levels[0].size ++;
    if(symbol_table.levels[0].size == symbol_table.levels[0].__max_size){
        symbol_table.levels[0].__max_size *= 2;
        Symbol *temp = (Symbol*)malloc(sizeof(Symbol) * symbol_table.levels[0].__max_size);
        memcpy(temp, symbol_table.levels[0].symbols, sizeof(Symbol) * symbol_table.levels[0].size);
        free(symbol_table.levels[0].symbols);
        symbol_table.levels[0].symbols = temp;
    }
    free(symbol);
}

void symbol_table_insert(Symbol *symbol){
    int n = symbol_table.level;
    int m = symbol_table.levels[n].size;
    symbol_table.levels[n].symbols[m] = *symbol;
    symbol_table.levels[n].size ++;
    if(symbol_table.levels[n].size == symbol_table.levels[n].__max_size){
        symbol_table.levels[n].__max_size *= 2;
        Symbol *temp = (Symbol*)malloc(sizeof(Symbol) * symbol_table.levels[n].__max_size);
        memcpy(temp, symbol_table.levels[n].symbols, sizeof(Symbol) * symbol_table.levels[n].size);
        free(symbol_table.levels[n].symbols);
        symbol_table.levels[n].symbols = temp;
    }
    free(symbol);
}

void id_list_insert(IDList* id_list, const char* name){
    id_list->id_nodes[id_list->size].id = strdup(name);
    id_list->size ++;
    if(id_list->size == id_list->__max_size){
        id_list->__max_size *= 2;
        IDNode *temp = (IDNode*)malloc(sizeof(IDNode) * id_list->__max_size);
        memcpy(temp, id_list->id_nodes, sizeof(IDNode) * id_list->size);
        free(id_list->id_nodes);
        id_list->id_nodes = temp;
    }
}


IDList* id_list_create(){
    IDList *id_list = (IDList*)malloc(sizeof(IDList));
    id_list->__max_size = INITIAL_ID_LIST_SIZE;
    id_list->size = 0;
    id_list->id_nodes = (IDNode*)malloc(sizeof(IDNode) * INITIAL_ID_LIST_SIZE);
    return id_list;
}

void param_list_extend(ParamList* first_list, ParamList* second_list){
    if(first_list->size + second_list->size >= first_list->__max_size){
        first_list->__max_size = first_list->__max_size + second_list->__max_size;
        Param *temp = (Param*)malloc(sizeof(Param) * first_list->__max_size);
        memcpy(temp, first_list->params, sizeof(Param) * first_list->size);
        memcpy(temp + first_list->size, second_list->params, sizeof(Param) * second_list->size);
        free(first_list->params);
        first_list->params = temp;
    }
    else memcpy(first_list->params + first_list->size, second_list->params, sizeof(Param) * second_list->size);
    first_list->size += second_list->size;
    free(second_list->params);
    free(second_list);
}
void param_list_insert(ParamList* param_list, Param* param){
    param_list->params[param_list->size] = *param;
    param_list->size ++;
    free(param);
    if(param_list->size == param_list->__max_size){
        param_list->__max_size *= 2;
        Param *temp = (Param*)malloc(sizeof(Param) * param_list->__max_size);
        memcpy(temp, param_list->params, sizeof(Param) * param_list->size);
        free(param_list->params);
        param_list->params = temp;
    }

}
ParamList* param_list_create(){
    ParamList* param_list = (ParamList*)malloc(sizeof(ParamList));
    *param_list = (ParamList){ 
        .type = T_PARAMS, 
        .size = 0, 
        .__max_size = INITIAL_PARAMS_SIZE, 
        .params = (Param*)malloc(sizeof(Param) * INITIAL_PARAMS_SIZE)
    };
    return param_list;
}

bool check_redeclar(char* id){
    int n = symbol_table.level;
    int m = symbol_table.levels[n].size;
    for(int i = 0 ;i < m ; i ++)
        if(!strcmp(id, symbol_table.levels[n].symbols[i].name))return true;
    for(int i = 0 ;i < n ; i ++){
        for(int j = 0 ;j < symbol_table.levels[i].size ; j ++){
            Symbol *symbol = symbol_table.levels[i].symbols + j;
            if(symbol->node_type == T_LOOP_VAR && !strcmp(id, symbol->name))return true;
        }
    }
    return false;
}

Symbol* symbol(const char* name, NodeType kind, TypeNode *type, AttrNode* attr){
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    *s = (Symbol){ .name = strdup(name), .node_type = kind, .type = type, .attr = attr };
    return s;
}
Param* param(const char* name, NodeType kind, TypeNode* type){
    Param* s = (Param*)malloc(sizeof(Param));
    *s = (Param){ .name = strdup(name), .node_type = kind, .type = type };
    return s;
}

RValueNode* rvalue_node(NodeType type, void* value){
    RValueNode *node = (RValueNode*)malloc(sizeof(RValueNode));
    node->type = type;
    switch(type){
        case T_INTEGER:
            node->value.int_value = *(int*)value;
            break;
        case T_REAL:
            node->value.real_value = *(float*)value;
            break;
        case T_STRING:
            node->value.str_value = strdup((char*)value);
            break;
        case T_BOOLEAN:
            node->value.bool_value = *(bool*)value;
            break;
    }
    return node;
}

TypeNode* type_node(NodeType type){
    TypeNode *node = (TypeNode*)malloc(sizeof(TypeNode));
    *node = (TypeNode){ .type = type, .dims = 0, .__max_dims = INITIAL_ARRAY_SIZE, .dim_nodes = NULL };
    return node;
}

TypeNode* array_type_node(TypeNode* inherit, int low, int high){
    TypeNode *node = (TypeNode*)malloc(sizeof(TypeNode));
    *node = (TypeNode){ 
        .type = inherit->type, 
        .dims = inherit->dims, 
        .__max_dims = inherit->__max_dims, 
        .dim_nodes = (inherit->dims 
                     ? inherit->dim_nodes 
                     : (ArrayDimNode*)malloc(sizeof(ArrayDimNode) * inherit->__max_dims))
    };
    node->dim_nodes[node->dims] = (ArrayDimNode){ 
        .lower_bound = low, 
        .upper_bound = high,
        .size = high - low + 1
    };
    node->dims ++;
    if(node->dims == node->__max_dims){
        node->__max_dims *= 2;
        ArrayDimNode *temp = (ArrayDimNode*)malloc(sizeof(ArrayDimNode) * node->__max_dims);
        memcpy(temp, node->dim_nodes, sizeof(ArrayDimNode) * node->dims);
        free(node->dim_nodes);
        node->dim_nodes = temp;
    }
    free(inherit);
    return node;
}
