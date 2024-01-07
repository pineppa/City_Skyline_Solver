/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_puzzle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:44:21 by simarcha          #+#    #+#             */
/*   Updated: 2024/01/07 18:26:59 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_space(char c)
{
	if ((c <= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	ft_solve_puzzle(int size, int **board)
{
	int	res;

	res = ft_solve_pos(1, 1, size, board);
	if (!res)
		ft_write_error();
}

int	ft_solve_pos(int col, int row, int size, int **board)
{
	int	val;
	int	res;

	val = 1;
	if (col + size * row > size * size)
	{
		ft_print_sol(board, size);
		return (1);
	}
	while (val <= size)
	{
		board[row][col] = val;
		if (ft_pos_chk(col, row, size, board))
		{
			if (col == size)
				res = ft_solve_pos(1, row + 1, size, board);
			else
				res = ft_solve_pos(col + 1, row, size, board);
			if (res == 1)
				return (1);
		}
		board[row][col] = 0;
		val++;
	}
	return (0);
}

int	ft_pos_chk(int col, int row, int size, int **board)
{
	int	n;

	n = 1;
	while (n <= size)
	{
		if (board[row][col] == board[row][n] && col != n)
			return (0);
		if (board[row][col] == board[n][col] && row != n)
			return (0);
		n++;
	}
	if (board[row][n] != 0)
		if (!ft_chk_rl(row, size, board))
			return (0);
	if (board[n][col] != 0)
		if (!ft_chk_cu(col, size, board))
			return (0);
	if (row == size)
		if (!ft_chk_cl(col, size, board))
			return (0);
	if (col == size)
		if (!ft_chk_rr(row, size, board))
			return (0);
	return (1);
}
