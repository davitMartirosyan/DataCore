#include "includes.h"

int     datacore_Create(table_t *table, student_t *student)
{
    // Create student from student struct
    //Format -> id:age:fname:lname:faculty\n
    FILE* f = fopen(__DATABASE__, "a+");
    if (f == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fprintf(f, __DATABASE_FORMAT__,\
        student->id,        \
        (int)student->age,  \
        student->fname,     \
        student->lname,     \
        student->faculty    \
    );
    return (1);
}

int     datacore_Retrieve(table_t *table, student_t *student)
{
    return (0);
}

void    datacore_Delete(table_t *table, student_t* student)
{

}

void    datacore_List(table_t *table)
{

}

void    datacore_Sort(table_t *table, void (*sortF)(table_t*))
{

}