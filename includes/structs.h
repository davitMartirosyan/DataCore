#ifndef STRUCTS_H
#define STRUCTS_H
#include "includes.h"

typedef struct	student_t           student_t;
typedef struct	table_t             table_t;
typedef int                         studid_t;
typedef int                         f_ret;
typedef struct  query_t             query_t;
typedef struct  querytok_t          querytok_t;
typedef struct  Orion               Orion;
typedef struct  string_t            string_t;
typedef struct  int_t               int_t;
typedef struct  meta_t              meta_t;
typedef struct  stack               stack;
typedef int                         file_t;
typedef struct garbage_collector_t  garbage_collector_t;

typedef f_ret    (*fmap_t)(table_t *, query_t**);


typedef enum type_t
{
    COMMAND,
    WORD,
    EXPANSION_FIELD,
    IDENTIFIER,
    SP,
    COMMA,
    COLON,
} type_t;

typedef struct student_t
{
    int id;
    char age;
    short grade;
    char *fname;
    char *lname;
    char *faculty;
} student_t;

typedef struct table_t
{
    FILE*   meta_dbase;
    FILE*   dbase;
    char*   dbase_name;
    char*   meta_dbase_name;
    meta_t  **metainfo;
    fmap_t  fmap[7];
    char    *cmap[7];
    char    *uname;
    char    *pass;
    int     fd;
} table_t;

typedef struct query_t
{
    int size;
    int cap;
    int maxexp;
    int ident_count; //-> <identify>
    int expression_count; //-> WORD EXPANSION ... etc
    int expansion_count; // -> {}
    int expansion_key_count; // {keys} {}
    int expansion_value_count; // {} {values}
    bool is_inside;
    char *cmd;
    char *cols;
    querytok_t *tokens;
}query_t;

typedef struct querytok_t
{
    type_t type;
    char *lexeme;
    querytok_t *prev;
    querytok_t *next;
}querytok_t;

typedef struct meta_t
{
    char    *col;
    char    *type;
}meta_t;

typedef struct Orion
{
    char        *type;
    int         int_type; // ?
    string_t    *s_type;
    int_t       *i_type;
    void        *next;
    void        *prev;
} Orion;

typedef struct string_t
{
    char        *column;
    char        *val;
    string_t    *next;
} string_t;

typedef struct int_t
{
    char        *column;
    int         val;
    int_t       *next;
}int_t;

typedef struct garbage_collector_t
{
    char **list;
    query_t **query_list;
} garbage_collector_t;


typedef struct stack
{
    int top;
    
} stack;

#endif
