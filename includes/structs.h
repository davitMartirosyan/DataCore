#ifndef STRUCTS_H
#define STRUCTS_H
#include "includes.h"

typedef struct	student_t       student_t;
typedef struct	table_t         table_t;
typedef int                     studid_t;
typedef struct  query_t         query_t;
typedef struct  querytok_t      querytok_t;
typedef enum    type_t          type_t;
typedef struct  Orion           Orion;
typedef struct  string_t        string_t;
typedef struct  int_t           int_t;
typedef struct  meta_t          meta_t;

typedef enum type_t
{
    OPENBRACE   = '{',
    CLOSEBRACE  = '}',
    COLON       = ':'
}type_t;

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
    int     fd;
    char*   dbname;
    char*   metadbname;
    FILE*   db;
    FILE*   metadb;
    query_t *query;
    meta_t  **metainfo;
} table_t;

typedef struct query_t
{
    char *query_text;
    char **keys;
    char **values;
}query_t;

typedef struct querytok_t
{
    type_t type;
    char *token;
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
    int         int_tipe; // ?
    string_t    *s_type;
    int_t       *i_type;
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
    char        *val;
    int_t       *next;
}int_t;

#endif
