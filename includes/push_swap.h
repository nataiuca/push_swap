/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:41:07 by natferna          #+#    #+#             */
/*   Updated: 2025/01/22 16:33:20 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Definición de estructuras
typedef struct s_list
{
	int		*sa;        // Pila A
	int		*sb;        // Pila B
	int		*sp;        // Array para ordenar
	int		sia;        // Tamaño de la pila A
	int		sib;        // Tamaño de la pila B
	int		sip;        // Tamaño del array para ordenar
	int		argc;       // Número de argumentos
	int		atoierror;  // Bandera de error en atoi
	int		error;      // Bandera de error general
	int		percentage; // Porcentaje para el ordenamiento
	int		cont;       // Número de particiones
	int		arguments;  // Argumentos procesados
	int		amax;       // Máximo de argumentos
	int		size_block; // Tamaño del bloque en ordenamiento
	int		lsp;        // Último elemento ordenado en pila B
	int		control;    // Control para ajustes durante el ordenamiento
}	t_list;

// Prototipos de funciones principales
int		arg_to_int(t_list *d, int arc, char **args);
int		ft_choose_size(int arc, t_list *d);
int init_stack_data(t_list *data, int arg_count);
int		check_args(char **args, int argc);
int		check_num(char *s);
int		check_order(t_list *d);
int		check_same_nums(t_list *d);
int process_arguments(t_list *data, int argc, char **argv);
int handle_sorting(t_list *data);
int get_index(t_list *data, int value);
int find_max(t_list *data);
int	find_min(int *stack, int size);
int	is_sorted(int *stack, int size);
void	sort_three(t_list *d);
void	move_max_to_a(t_list *d);
int execute_sorting_strategy(t_list *data, int argc);
void print_stacks(t_list *d);
void push_to_chunks(t_list *d, int *limit, int chunk_size);
int	find_max_index(t_list *d);
void	rotate_max_to_top(t_list *d, int index);

// Operaciones básicas de pilas
void	sa(t_list *d);
void	sb(t_list *d);
void	ss(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	ra(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rra(t_list *d);
void	rrb(t_list *d);
void	rrr(t_list *d);

// Algoritmos de ordenamiento
void	size3(t_list *d);
void	size5(t_list *d);
void	size100(t_list *d);
void	size500(t_list *d);

// Funciones auxiliares
int		ft_strlen(const char *s);
int		ft_atoi(const char *str, t_list *d);
void	ft_free(t_list *d);
void	ft_free2(t_list *d);
void	swap(int *a, int *b);
void	sortnum(t_list *d);
void	changenum(t_list *d);
int	ft_isdigit(int c);

// Otras funciones específicas del proyecto
void	ordernums(t_list *d);
void	ordernums_sb(t_list *d);
void	ordernums_sb_rotate(t_list *d);
void	ordernums_peq(t_list *d);
void	ordernums_peq2(t_list *d);
void	ordernums_peq3(t_list *d, int i);
void	ordernums_peq_sb(t_list *d);

#endif