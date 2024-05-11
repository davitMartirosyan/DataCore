#ifndef INCLUDES_H
#define INCLUDES_H

#define __DATABASE__ "./db/db.sql"
#define __DATABASE_FORMAT__ "%d:%d:%s:%s:%s\n"

#define __METADATA__ "./meta/"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "./structs.h"
#include "../libft/libft.h"

//CRUDLS - > Create - Retrieve - Update - Delete - List - Sort

int         dc_create(table_t *table, student_t *student);
int         dc_retrieve(table_t *table, studid_t id, student_t *student);
void        dc_delete(table_t *table, student_t* student);
void        dc_list(table_t *table);
void        dc_sort(table_t *table, void (*sortF)(table_t*));
void        dc_cleanup(table_t *table);


void *dc_query(table_t *table, char *query_text, ...);
table_t     *dc_init(char *db);
#endif
