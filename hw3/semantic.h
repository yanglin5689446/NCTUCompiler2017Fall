
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "nodedef.h"

#define INITIAL_LEVEL_SIZE      25
#define INITIAL_SYMBOL_COUNT    50
#define INITIAL_ID_LIST_SIZE    5
#define INITIAL_ARRAY_SIZE      5
#define INITIAL_PARAMS_SIZE     4

typedef struct Block{
    int size;
    int max_size;
    Symbol* symbols;
} Block;

// a symbol table is a list containing several blocks,
// each blocks has some of the entry
struct SymbolTable{
    int max_level;
    int level;
    Block* levels;
} symbol_table;

void symbol_table_init() ;
void symbol_table_new_scope() ;
void symbol_table_delete_scope() ;
void symbol_table_insert(Symbol*) ;

void id_list_insert(IDList*, const char*);
IDList* id_list_create();


bool check_redeclar(IDNode*);
Symbol* symbol(const char*, NodeType, TypeNode*, AttrNode*);
RValueNode* rvalue_node(NodeType type, void* value);
TypeNode* type_node(NodeType);
TypeNode* array_type_node(TypeNode*, int, int);
#endif
