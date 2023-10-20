#include "../include/push_swap.h"

t_stack *init_stack()
{
  return (NULL);
}

bool is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void free_split(char **tab) 
{
    char **temp = tab;  

    if (!tab)
        return ;
    while (*tab)
    {
        free(*tab);  
        tab++;
    }
    free(temp);  
}

void handle_error(char **tab, const char *message) 
{
    free_split(tab);
    printf("%s\n", message);
    exit(1);
}