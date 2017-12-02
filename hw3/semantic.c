
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nodedef.h"
#include "semantic.h"


void symbol_table_new_scope(){
    symbol_table.level ++;
    if( symbol_table.level == symbol_table.max_level){
        symbol_table.max_level *= 2;
        Block *temp = (Block*)malloc(sizeof(Block) * symbol_table.max_level);
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
    symbol_table.max_level = INITIAL_LEVEL_SIZE;
    symbol_table.levels = (Block*)malloc(sizeof(Block) * INITIAL_LEVEL_SIZE);
    for(i = 0 ;i < INITIAL_LEVEL_SIZE; i ++){
        symbol_table.levels[i].size = 0;
        symbol_table.levels[i].max_size = INITIAL_SYMBOL_COUNT;
        symbol_table.levels[i].symbols = (Symbol*)malloc(sizeof(Symbol) * INITIAL_SYMBOL_COUNT);
    }
}
void symbol_table_insert(Symbol *symbol){
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

// not yet compeleted
bool check_redeclar(IDNode *id){
    return false;
}

Symbol* symbol(const char* name, NodeType kind, TypeNode *type, AttrNode* attr){
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    //*s = (Symbol){ .name = strdup(name), .node_type = kind, .type = *type, .attr = *attr };
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

TypeNode* array_type_node(TypeNode* inherit, int low, int hight){
    TypeNode *node = (TypeNode*)malloc(sizeof(TypeNode));
    *node = (TypeNode){ 
        .type = inherit->type, 
        .dims = inherit->dims + 1, 
        .__max_dims = inherit->__max_dims, 
        .dim_nodes = (inherit->dims 
                     ? inherit->dim_nodes 
                     : (ArrayDimNode*)malloc(sizeof(ArrayDimNode) * inherit->__max_dims))
    };
    if(node->dims == node->__max_dims){
        node->__max_dims *= 2;
        ArrayDimNode *temp = (ArrayDimNode*)malloc(sizeof(ArrayDimNode) * node->__max_dims);
        memcpy(temp, node->dim_nodes, sizeof(ArrayDimNode) * node->dims);
        free(node->dim_nodes);
        node->dim_nodes = temp;
    }
    free(inherit);
}
