
#ifndef NODEDEF_H
#define NODEDEF_H

#include <stdbool.h>

typedef enum { 
    T_PROGRAM,
    T_VOID,
    T_STRING, 
    T_REAL,
    T_INTEGER, 
    T_BOOLEAN, 
    T_ARRAY,
    T_FUNCTION,
    PARAMS,
    T_VAR,
    T_CONST_VAR,
} NodeType;

typedef struct RValueNode{
    NodeType type;
    union Value{
        float real_value;
        int int_value;
        char* str_value;
        bool bool_value;
    } value;
} RValueNode;

typedef struct ArrayDimNode{ int lower_bound, upper_bound, size; }ArrayDimNode;

typedef struct TypeNode{
    NodeType type;
    int dims;
    int __max_dims;
    ArrayDimNode* dim_nodes;
} TypeNode;

typedef struct IDNode{
    char *id;
} IDNode;

typedef struct IDList{
    NodeType type;
    int size;
    int __max_size;
    IDNode* id_nodes;
} IDList;

typedef struct Params{
    NodeType type;
} Params;

typedef struct ParamsList{
    NodeType type;
} ParamsList;

typedef struct ExprList{
    NodeType type;
} ExprList;

typedef struct ExprNode{
    NodeType type;
} ExprNode;

typedef struct AttrNode{
    ParamsList *params;
    RValueNode *rvalue;
} AttrNode;

typedef struct Symbol{
    char* name;
    NodeType node_type;
    TypeNode type;
    AttrNode attr;
} Symbol;


#endif
