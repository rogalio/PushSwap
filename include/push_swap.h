/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:47:22 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 15:12:50 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk {
    int start;
    int end;
} t_chunk;

typedef struct s_process_chunk {
    t_chunk *chunks;
    int current_pair;
    int total_chunks;
} s_process_chunk;


// a_trier.c
int is_sorted2(t_stack *stack_a);
t_stack *get_element_at2(t_stack *stack, int index);
int *stack_to_array(t_stack *stack, int size);
bool	rotate_up(t_stack **stack);
bool	rotate_down(t_stack **stack);
bool    add_value_to_stack(t_stack **stack, int value);

// index.c
void index_stack(t_stack *stack);
int find_min_index(t_stack *stack);
int get_position(int *array, int size, int value);
int get_index_in_stack(t_stack *stack, int value);
int find_highest_index(t_stack *stack);

// large_sort.c
int determine_chunk_size(int size);
void sort_chunk_in_a(t_stack **stack_a);
void process_chunk_pair(t_stack **stack_a, t_stack **stack_b, s_process_chunk *process_chunk, int *size);
void distribute_elements_to_chunks(t_stack **stack_a, t_stack **stack_b, t_chunk *chunks, int total_chunks);
t_chunk *calculate_chunks(int size, int chunk_size);
int sort_large_elements(t_stack **stack_a, t_stack **stack_b);

// large_sort2.c
void insert_in_place(t_stack **stack_a, int inserted_index);
void move_chunks_to_a(t_stack **stack_a, t_stack **stack_b);
void rotate_to_top(t_stack **stack, int target_index, char stack_name);
void finalize_stack_a(t_stack **stack_a);
int get_position_in_sorted_stack(t_stack *stack, int target_index);

// parse.c
void    parse_input_arguments(int ac, char **av, t_stack **stack_a);
void    parse_one_arg(char *str, t_stack **stack_a);
int     parse_args(int ac, char **av, t_stack **stack_a);
t_stack *init_stack(void);
bool   is_valid_number(char *str);

// push_swap.c
void sort_stack(t_stack **stack_a, t_stack **stack_b);
int	main(int ac, char **av);

//sort_small.c
void sort_two_elements(t_stack **stack_a);
void sort_three_elements(t_stack **stack_a);
int remove_min(t_stack **stack_a, t_stack **stack_b);
int find_next_min(t_stack *stack, int min);
void sort_four_elements(t_stack **stack_a, t_stack **stack_b);

//sort_small2.c
int position_of(int value, t_stack *stack_a);
void remove_specific(t_stack **stack_a, t_stack **stack_b, int value);
void insert_in_order(t_stack **stack_a, t_stack **stack_b);
void sort_five_elements(t_stack **stack_a, t_stack **stack_b);

//stack_operations.c
bool    push(t_stack **stack, int value);
bool    pop(t_stack **stack);
bool    swap(t_stack **stack);
int     peek(t_stack *stack);
bool    is_empty(t_stack *stack);

//stack_operations2.c
void   sa(t_stack **stack_a);
void   sb(t_stack **stack_b);
void   ss(t_stack **stack_a, t_stack **stack_b);
void   pa(t_stack **stack_a, t_stack **stack_b);
void   pb(t_stack **stack_a, t_stack **stack_b);

//stack_rotation.c
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);

//stack_rotation2.c
void rrr(t_stack **stack_a, t_stack **stack_b);
int stack_size(t_stack *stack);
void is_sorted(t_stack *stack_a);
int find_min(t_stack *stack);

//utilities.c
int   free_stack(t_stack **stack);
void    handle_error(char **tab);
void   free_split(char **tab);
int    sort_array(int *array, int size);
int check_duplicates(t_stack *stack_a);


#endif
