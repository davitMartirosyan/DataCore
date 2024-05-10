#include "includes.h"

int     datacore_Create(table_t *table, student_t *student)
{
    // Create student from student struct
    //Format -> id:age:fname:lname:faculty\n

    fprintf(table->db, __DATABASE_FORMAT__,\
        student->id,        \
        (int)student->age,  \
        student->fname,     \
        student->lname,     \
        student->faculty    \
    );
    return (1);
}

int    	datacore_Retrieve(table_t *table, studid_t id,  student_t *student)
{
	if (table->db_fd == -1)
	{
		fprintf(stderr, "Could not connect to database\n");
		return (-1);
	}
	char *ln = get_next_line(table->db_fd);
	while (ln)
	{
		printf("|%s|\n", ln);
		free(ln);
		ln = get_next_line(table->db_fd);
	}
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
