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
    table->dbname = ft_strdup(db);
    table->metadbname = ft_strjoin(__METADATA__, ft_strrchr(db, '/')+1);
    table->db = fopen(db, "a+");
    table->fd = fileno(table->db);
    table->metadb = fopen(table->metadbname, "a+");
    if (!table->db || table->fd == -1 || !table->metadb)
    {
        fprintf(stderr, "Could not make connection\n");
        free(table->dbname);
        free(table->metadbname);
        free(table);
        exit(EXIT_FAILURE);
    }

    table->cmap[0] = "create";
    table->cmap[1] = "add";
    table->cmap[2] = "retrieve";
    table->cmap[3] = "update";
    table->cmap[4] = "delete";
    table->cmap[5] = "list";
    table->cmap[6] = "sort";
    
    table->fmap[0] = &dc_create;
    table->fmap[1] = &dc_add;
    table->fmap[2] = &dc_retrieve;
    table->fmap[3] = &dc_update;
    table->fmap[4] = &dc_delete;
    table->fmap[5] = &dc_list;
    table->fmap[6] = &dc_sort;

    return (table);
}

void dc_cleanup(table_t *table)
{
    if (!table)
        return ;
    fclose(table->db);
    close(table->fd);
    free(table->dbname);
    free(table);
}
