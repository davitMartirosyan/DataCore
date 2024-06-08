#include "includes.h"

table_t *dc_init(char *db)
{
    table_t *table = malloc(sizeof(table_t));
    if (!table)
    {
        printf("Database can't be initialized\n");
        perror("Malloc");
        free(table);
        exit(EXIT_FAILURE);
    }
    __construct(&table);
    return (table);
}



void __construct(table_t **table)
{
    (*table)->fd = -1;                      // file descriptor
    (*table)->dbase = NULL;                 // FILE
    (*table)->dbase_name = NULL;            // char * name of database 

    (*table)->meta_dbase = NULL;            // FILE
    (*table)->meta_dbase_name = NULL;       //char * name of meta file name
    (*table)->metainfo = NULL;

    (*table)->cmap[0] = "create";
    (*table)->cmap[1] = "add";
    (*table)->cmap[2] = "retrieve";
    (*table)->cmap[3] = "update";
    (*table)->cmap[4] = "delete";
    (*table)->cmap[5] = "list";
    (*table)->cmap[6] = "sort";
    (*table)->fmap[0] = &dc_create;
    (*table)->fmap[1] = &dc_add;
    (*table)->fmap[2] = &dc_retrieve;
    (*table)->fmap[3] = &dc_update;
    (*table)->fmap[4] = &dc_delete;
    (*table)->fmap[5] = &dc_list;
    (*table)->fmap[6] = &dc_sort;
}

void __destruct(table_t **table)
{
    (*table)->fd = -1;              // file descriptor
    (*table)->dbase = NULL;         // FILE
    (*table)->dbase_name = NULL;    // char * name of database 
    (*table)->meta_dbase = NULL;
    (*table)->meta_dbase_name = NULL;
    (*table)->metainfo = NULL;
    free(*table);
}

void _init_query(void **initializer_list)
{
	((query_t*)(*initializer_list))->is_inside = false;
	((query_t*)(*initializer_list))->size = 0;
	((query_t*)(*initializer_list))->cap = 0;
	((query_t*)(*initializer_list))->expression_count = 0;
	((query_t*)(*initializer_list))->expansion_count = 0;
	((query_t*)(*initializer_list))->ident_count = 0;
	((query_t*)(*initializer_list))->cmd = NULL;
	((query_t*)(*initializer_list))->tokens = NULL;
	((query_t*)(*initializer_list))->cols = NULL;
}