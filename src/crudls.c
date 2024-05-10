#include "includes.h"

int    dc_create(table_t *table, student_t *student)
{
    fprintf(table->db, __DATABASE_FORMAT__,\
        student->id,        \
        (int)student->age,  \
        student->fname,     \
        student->lname,     \
        student->faculty    \
    );
    return (1);
}

int    	dc_retrieve(table_t *table, studid_t id,  student_t *student)
{
	if (table->fd == -1)
	{
		fprintf(stderr, "Could not connect to database\n");
		return (-1);
	}
	char *ln = get_next_line(table->fd);
	while (ln)
	{
		
		free(ln);
		ln = get_next_line(table->fd);
	}
	return (0);
}

void    dc_delete(table_t *table, student_t* student)
{

}

void    dc_list(table_t *table)
{

}

void    dc_sort(table_t *table, void (*sortF)(table_t*))
{

}
