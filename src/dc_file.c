#include "includes.h"

file_t dc_create_file(table_t *table, char *relative, char *filename, char *ext, mode_t mod)
{
    struct stat st;
    char *file = NULL;
    int f = 0;

    if (stat(relative, &st) == 0)
    {
        //exists
        if (S_ISDIR(st.st_mode))
            printf("is directory\n");
        file = relative_path(relative, filename, ext);
        mkdir_p(relative);
        free(file);
    }
    else
    {

    }
    return (0);
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

int mkdir_p(const char *path)
{
    char tmp[256];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", path);
    return (0);
}