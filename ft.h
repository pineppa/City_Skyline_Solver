/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:24:58 by jsala             #+#    #+#             */
/*   Updated: 2024/01/07 18:24:58 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_check_input(char *input);
int		ft_valid(char *input);
int		ft_is_space(char c);
int		ft_check_sum(int size, int **board);
void	free_matrix(int **matrix, int size);
void	ft_putchar(char c);
void	ft_solve_puzzle(int size, int **board);
int		**ft_init_input(char *str, int size, int **board);
int		**ft_init_board(int size);
int		ft_pos_chk(int col, int row, int size, int **board);
int		ft_chk_rl(int row, int size, int **board);
int		ft_chk_rr(int row, int size, int **board);
int		ft_chk_cu(int col, int size, int **board);
int		ft_chk_cl(int col, int size, int **board);
int		ft_solve_pos(int col, int row, int size, int **board);
void	ft_write_error(void);
void	ft_print_sol(int **board, int size);
int		ft_getsize(char *input);

#endif