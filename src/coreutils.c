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
    printf("%s\n", table->metadbname);

    if (!table->db || table->fd == -1 || !table->metadb)
    {
        fprintf(stderr, "Could not make connection\n");
        free(table->dbname);
        free(table->metadbname);
        free(table);
        exit(EXIT_FAILURE);
    }

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
