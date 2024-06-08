#include "includes.h"
extern int dc_errno;
file_t dc_create_file(table_t *table, char *relative, char *filename, char *ext, mode_t mod)
{
    struct stat st;
    file_t fio = 0;
    file_t fret = 0;
    char *file = NULL;

    if (stat(relative, &st) != 0)
    {
        fret = mkdir_p(relative, 0755);
        file = relative_path(relative, filename, ext);
        if ((fio = open(file, O_CREAT|O_RDWR|O_APPEND, mod)) < 0)
            dc_errno |= PERM;
    }
    else
    {
        file = relative_path(relative, filename, ext);
        if((fio = open(file, O_CREAT|O_RDWR|O_APPEND|O_EXCL, mod)) < 0)
            dc_errno |= EXIST;
    }
    free(file);
    close(fio);
    return (fret);
}

char	*relative_path(char * s1, char * s2, char * s3)
{
	char	*arguments = NULL;
    int     l1 = ft_strlen(s1), l2 = ft_strlen(s2), l3 = ft_strlen(s3);
	int		i = -1;
    int     j = -1;
    int     c = -1;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
    
	arguments = malloc(sizeof(char) *  (l1 + l2 + l3 + 1));
	if (!arguments)
		return (NULL);
    while (s1[++i])
        arguments[i] = s1[i];
    while (s2[++j])
        arguments[i++] = s2[j];
    while (s3[++c])
        arguments[i++] = s3[c];
    arguments[i] = '\0';
	return (arguments);
}

int mkdir_p(const char *path, mode_t mod)
{
    int sz = 0;
    char **recursive = ft_split(path, '/', &sz);
    int i = -1;
    char *r_path = NULL;
    int fret = 0;
    while (recursive[++i] && fret >= 0)
    {
        r_path = conlcat(r_path, '/', recursive[i]);
        if (mkdir(r_path, mod) < 0 && errno != EEXIST)
            fret = -1;
    }
    free(r_path);
    free_fields(recursive);
    return (fret);
}