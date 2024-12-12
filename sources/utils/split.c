#include "utils.h"

void   free_split(char **split)
{
    int i = 0;

    while (split[i])
        free(split[i++]);
    free(split);
}

static char *result_malloc(char *str, char c, char **result, int idx)
{
    int len = 0;

    while (str[len] && str[len] != c)
        len++;
    
    result[idx] = (char *)malloc(sizeof(char) * (len + 1));
    if (result[idx] == NULL)
    {
        while (--idx >= 0)
            free(result[idx]);
        free(result);
        return (NULL);
    }

    strncpy(result[idx], str, len);
    result[idx][len] = '\0';
    return (result[idx]);
}

static char **result_double_malloc(char *str, char c)
{
    size_t cnt = 0;
    char **result;

    while (*str)
    {
        if (*str != c)
        {
            cnt++;
            while (*str && *str != c)
                str++;
        }
        else
            str++;
    }

    result = (char **)malloc(sizeof(char *) * (cnt + 1));
    if (result == NULL)
        return (NULL);
    
    return (result);
}

char **split(char *s, char c)
{
    char *str;
    char **result;
    int i = 0;

    if (s == NULL)
        return (NULL);

    str = s;
    result = result_double_malloc(str, c);
    if (result == NULL)
        return (NULL);

    while (*str)
    {
        if (*str != c)
        {
            if (result_malloc(str, c, result, i++) == NULL)
                return (NULL);
            
            while (*str && *str != c)
                str++;
        }
        else
            str++;
    }
    result[i] = NULL;

    return (result);
}
