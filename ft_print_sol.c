/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:07:33 by jsala             #+#    #+#             */
/*   Updated: 2024/01/07 22:50:07 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_sol(int **board, int size)
{
	int		i;
	int		j;
	char	val;

	i = -1;
	while (++i <= size + 1)
	{
		j = -1;
		if (i == 1 || i == size + 1)
			ft_print_line(size);
		while (++j <= size + 1)
		{
			if (j == 1 || j == size + 1)
				write(1, "| ", 2);
			val = board[i][j] + '0';
			ft_putchar(val);
			if (j < size + 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	ft_print_line(int size)
{
	int	i;
	
	i = 0;
	write(1, "--|-", 4);
	while (i++ < size)
		write(1, "--", 2);
	write(1, "|--\n", 4);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
int	main(void)
{
	int	**board =
	{
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};
	ft_print_sol(board);
	return 0;
}*/
