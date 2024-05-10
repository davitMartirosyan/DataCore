#ifndef STRUCTS_H
#define STRUCTS_H
#include "includes.h"

typedef struct	student_t    student_t;
typedef struct	table_t      table_t;
typedef int	studid_t;

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
    int db_fd;
    FILE* db;
} table_t;

#endif
