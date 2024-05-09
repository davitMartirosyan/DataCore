#ifndef INCLUDES_H
#define INCLUDES_H

#define __DATABASE__ "db.sql"
#define __DATABASE_FORMAT__ "%d:%d:%s:%s:%s\n"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "./structs.h"
#include "../libft/libft.h"

//CRUDLS - > Create - Retrieve - Update - Delete - List - Sort

int     Create(table_t *table, student_t *student);
int     Retrieve(table_t *table, student_t *student);
void    Delete(table_t *table, student_t* student);
void    List(table_t *table);
void    Sort(table_t *table, void (*sortF)(table_t*));


void    core_init(table_t *table);
#endif