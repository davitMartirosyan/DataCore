#include "includes.h"

int     Create(table_t *table, student_t *student)
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

int     Retrieve(table_t *table, student_t *student)
{
    return (0);
}

void    Delete(table_t *table, student_t* student)
{

}

void    List(table_t *table)
{

}

void    Sort(table_t *table, void (*sortF)(table_t*))
{

}