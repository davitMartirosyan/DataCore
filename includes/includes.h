#ifndef INCLUDES_H
#define INCLUDES_H

#define __DATABASE__ "./db/"
#define __METADATA__ "./meta/"

#define __DATABASE_FORMAT__ "%d:%d:%s:%s:%s\n"
#define __SET__ " \t\r\b\a\n"
#define __REGEXP__ "{}[]\\\n\t\r\a\b"

#define FAILURE -1
#define EBADSYNTAX "Syntax Error\n"
#define FUNCTIONALITY 7

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
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <readline/readline.h>
#include "./structs.h"
#include "../libft/libft.h"
#include "dc_errno.h"

//CARUDLS -> Create - Add - Retrieve - Update - Delete - List - Sort

//Orion
Orion       *dc_query(table_t *table, char *query);

//void
f_ret        dc_create(table_t *table, query_t **query_list);
f_ret        dc_add(table_t *table, query_t **query_list);
f_ret        dc_retrieve(table_t *table, query_t **query_list);
f_ret        dc_update(table_t *table, query_t **query_list);
f_ret        dc_delete(table_t *table, query_t **query_list);
f_ret        dc_list(table_t *table, query_t **query_list);
f_ret        dc_sort(table_t *table, query_t **query_list);


//table : utils
table_t     *dc_init(char *db);
void        dc_cleanup(table_t **table);
void        __construct(table_t **table);
void        __destruct(table_t **table);


//files : core utils
file_t      dc_create_file(table_t *table, char *relative, char *filename, char *ext, mode_t mod);
char        *relative_path(char * s1, char * s2, char * s3);
int         mkdir_p(const char *path, mode_t mod);


//tokenization
query_t     *lexer(char *query);
int         split_expansion(query_t *tok, char *query, int *i, char *pattern, type_t type);
void        add_word(query_t *tok, char *query, int *i);


// int         expansion(query_t *tok, char *query, int*i);
// int         identify(query_t *tok, char *query, int *i);
// void        expansionopen(query_t *tok, char *query, int *i);
// void        expansionclose(query_t *tok, char *query, int *i);
// void        addexpfield(query_t *tok, char *query, int *i);

//dlist
querytok_t  *create_node(char *word, type_t type);
void        append_node(querytok_t **tokens, char *word, type_t type);
void        print_tokens(querytok_t *toks);


//parser
querytok_t	*find(querytok_t *qlist, type_t type);
fmap_t      find_command(table_t *table, query_t **query_list);
int         pexec(table_t *table, query_t **query_list);

int         dc_columns(query_t **query_list, char **fields, int size);
int         dc_column_type(char **col, int size);

//string manipulation
char        *concat(char * s1, char * s2);
char	    *convcat(char *s1, char ident, char *s2, char delim);
char	    *conlcat(char *s1, char ident, char *s2);


//Garbage collector
void		free_fields(char **field);
void        free_tokens(query_t **qtok);
void        clean_space(query_t **tok);
void        _init_query(void **initializer_list);
void        _dealloc(garbage_collector_t *space);

#endif
