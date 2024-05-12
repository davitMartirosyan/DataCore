#ifndef INCLUDES_H
#define INCLUDES_H

#define __DATABASE__ "./db/db.sql"
#define __METADATA__ "./meta/"

#define __DATABASE_FORMAT__ "%d:%d:%s:%s:%s\n"
#define __SET__ " \n\t\r\b"

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "./structs.h"
#include "../libft/libft.h"

//CRUDLS - > Create - Retrieve - Update - Delete - List - Sort

//Orion
Orion       *dc_query(table_t *table, char *query);

//void
void        dc_create(table_t *table, char *query);
void        dc_add(table_t *table, char *query);
void        dc_retrieve(table_t *table, char *query);
void        dc_update(table_t *table, char *query);
void        dc_delete(table_t *table, char *query);
void        dc_list(table_t *table, char *query);
void        dc_sort(table_t *table, char *query);
void        dc_cleanup(table_t *table);


//table : utils
table_t     *dc_init(char *db);


//tokenization
querytok_t  *lexer(char *query);
void        addword(query_t **tokens, int *i, char *query);
void        addexpansion(query_t **tokens, int *i, char *query);
void        space(query_t **tokens, int *i, char *query);
char        *word(char *query, int len, int s_pos);
int         wordlen(char *wordstart, int s_pos);
#endif
