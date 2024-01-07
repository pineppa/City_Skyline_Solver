/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:10:00 by simarcha          #+#    #+#             */
/*   Updated: 2024/01/07 22:38:22 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size + 2)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	**ft_init_board(int size)
{
	int		col;
	int		row;
	int		**board;

	board = malloc(sizeof(int *) * (size + 2));
	if (!board)
		return (NULL);
	col = -1;
	while (++col < size + 2)
	{
		row = -1;
		board[col] = malloc(sizeof(int) * (size + 2));
		if (!board[col])
			return (NULL);
		while (++row < size + 2)
			board[col][row] = 0;
	}
	return (board);
}

int	**ft_init_input(char *str, int size, int **board)
{
	int	n;

	n = -1;
	while (*str && ++n < 4 * size)
	{
		if (n < size)
			board[0][n % size + 1] = *str - '0';
		else if (n < 2 * size)
			board[size + 1][n % size + 1] = *str - '0';
		else if (n < 3 * size)
			board[n % size + 1][0] = *str - '0';
		else if (n < 4 * size)
			board[n % size + 1][size + 1] = *str - '0';
		str += 2;
	}
	return (board);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	size;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	size = ft_check_input(argv[1]);
	if (!size)
		return (1);
	board = ft_init_board(size);
	if (!board)
		return (1);
	board = ft_init_input(argv[1], size, board);
	ft_solve_puzzle(size, board);
	free_matrix(board, size);
	return (0);
}
