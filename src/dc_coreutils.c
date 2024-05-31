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

void dc_cleanup(table_t **table)
{
    if (!*table)
        return ;
    // fclose(table->db);
    // close(table->fd);
    free((*table)->dbase_name);
    free((*table)->meta_dbase_name);
    free((*table)->metainfo); 
    __destruct(table);
}


void     __construct(table_t **table)
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
