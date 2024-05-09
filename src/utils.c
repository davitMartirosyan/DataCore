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
    if (!table->db)
    {
        perror("Fopen");
        exit(EXIT_FAILURE);
    }
}