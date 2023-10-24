# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// operations.c
bool push(t_stack **stack, int value);
bool pop(t_stack **stack);
bool swap(t_stack **stack);
int peek(t_stack *stack);
void display_stack(t_stack *stack);
bool rotate_up(t_stack **stack);
bool rotate_down(t_stack **stack);
bool is_sorted(t_stack *stack);

// utilities.c
t_stack *init_stack();
void free_split(char **tab);
void handle_error(char **tab, const char *message);
bool is_valid_number(char *str);

// parse.c
void parse_input_arguments(int ac, char **av, t_stack **stack_a);
bool add_value_to_stack(t_stack **stack, int value);
void parse_one_arg(char *str, t_stack **stack_a);
int parse_args(int ac, char **av, t_stack **stack_a);

// small_sort.c
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
void sort_small(t_stack **stack_a, t_stack **stack_b);

int find_median_of_three(t_stack **stack_a);
void move_median_to_top(t_stack **stack_a);
void sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot);
int partition_around_pivot(t_stack **stack_a, t_stack **stack_b, int pivot);
bool is_sorted(t_stack *stack);
void partition_sort(t_stack **stack_a, t_stack **stack_b);
void merge_partitions(t_stack **stack_a, t_stack **stack_b);