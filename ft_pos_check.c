/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:34:30 by jsala             #+#    #+#             */
/*   Updated: 2024/01/07 22:12:12 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_chk_cu(int col, int size, int **board)
{
	int	n;
	int	t_col_max_h;
	int	t_col_vis;

	n = 0;
	t_col_max_h = 0;
	t_col_vis = 0;
	while (++n <= size && board[n][col] != 0)
	{
		if (t_col_max_h < board[n][col])
		{
			t_col_max_h = board[n][col];
			t_col_vis++;
		}
	}
	if (t_col_vis > board[0][col])
		return (0);
	else if (n == size + 1 && t_col_vis != board[0][col])
		return (0);
	return (1);
}

int	ft_chk_cl(int col, int size, int **board)
{
	int	n;
	int	t_col_max_h;
	int	t_col_vis;

	n = size + 1;
	t_col_max_h = 0;
	t_col_vis = 0;
	while (--n > 0)
	{
		if (t_col_max_h < board[n][col])
		{
			t_col_max_h = board[n][col];
			t_col_vis++;
		}
	}
	if (t_col_vis != board[size + 1][col])
		return (0);
	return (1);
}

int	ft_chk_rl(int row, int size, int **board)
{
	int	n;
	int	t_row_max_h;
	int	t_row_vis;

	n = 1;
	t_row_max_h = 0;
	t_row_vis = 0;
	while (n <= size && board[row][n] != 0)
	{
		if (t_row_max_h < board[row][n])
		{
			t_row_max_h = board[row][n];
			t_row_vis++;
		}
		n++;
	}
	if (t_row_vis > board[row][0])
		return (0);
	else if (n == size + 1 && t_row_vis != board[row][0])
		return (0);
	return (1);
}

int	ft_chk_rr(int row, int size, int **board)
{
	int	n;
	int	t_row_max_h;
	int	t_row_vis;

	n = size + 1;
	t_row_max_h = 0;
	t_row_vis = 0;
	while (--n > 0)
	{
		if (t_row_max_h < board[row][n])
		{
			t_row_max_h = board[row][n];
			t_row_vis++;
		}
	}
	if (t_row_vis != board[row][size + 1])
		return (0);
	return (1);
}
