#include "./includes/includes.h"
int main( void )
{
    printf("Welcome to the DataCore\n");
    table_t *table;
    datacore_init(table);

    
    free(table);
}