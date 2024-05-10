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

int     datacore_Create(table_t *table, student_t *student);
int     datacore_Retrieve(table_t *table, studid_t id, student_t *student);
void    datacore_Delete(table_t *table, student_t* student);
void    datacore_List(table_t *table);
void    datacore_Sort(table_t *table, void (*sortF)(table_t*));
void    datacore_Cleanup(table_t *table);

void    datacore_init(table_t **table);
#endif
