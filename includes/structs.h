#ifndef STRUCTS_H
#define STRUCTS_H
#include "includes.h"

typedef struct	student_t       student_t;
typedef struct	table_t         table_t;
typedef int                     studid_t;
typedef struct query_t          query_t;
typedef struct querytok_t       querytok_t;
typedef enum   type_t           type_t;


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

#endif
