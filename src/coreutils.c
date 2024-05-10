#include "includes.h"

void datacore_init(table_t* table)
{
    table = malloc(sizeof(table_t));
    if (!table)
    {
        printf("Database can't be initialized\n");
        perror("Malloc");
        exit(EXIT_FAILURE);
    }
    table->db = fopen(__DATABASE__, "a+");
    table->db_fd = open(__DATABASE__, O_RDONLY);
    if (!table->db || table->db_fd == -1)
    {
        fprintf(stderr, "Could not make connection");
        exit(EXIT_FAILURE);
    }
}
