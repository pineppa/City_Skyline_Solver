/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:11:22 by simarcha          #+#    #+#             */
/*   Updated: 2024/01/06 21:45:27 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_input(char *input)
{
//	int	i;
	int size;

//	i = 0;
	size = ft_getsize(input);
/*	if (size || !ft_th_one(input))
		return (0);
	if (!ft_check_sum(input))
		return (0);
*/	return (size);
}

int	ft_getsize(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (input[++i])
	{
		if ((input[i] < '0' || input[i] > '9') && is_space(input[i]))
		{
			ft_write_error();
			return (0);
		}
		if (input[i] == ' ' && (input[i + 1] == '/0' 
			|| is_space(input[i + 1])))
			count++;
	}
	if (count % 4 == 0)
		return (count / 4);
	else
		return (0);
}

int	ft_check_sum(int size, int **board)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < size + 2)
		sum += board[0][i];
	if (sum > (size * (size + 1) / 2))
	{
		ft_write_error();
		return (0);
	}
	i = -1;
	sum = 0;
	while (++i < size + 2)
		sum += board[size + 1][i];
	if (sum > (size * (size + 1) / 2))
	{
		ft_write_error();
		return (0);
	}
	i = -1;
	sum = 0;
	while (++i < size + 2)
		sum += board[i][0];
	if (sum > (size * (size + 1) / 2))
	{
		ft_write_error();
		return (0);
	}
	i = -1;
	sum = 0;
	while (++i < size + 2)
		sum += board[i][size + 1];
	if (sum > (size * (size + 1) / 2))
	{
		ft_write_error();
		return (0);
	}
	return (1);
}

int	ft_th_one(char *input)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (input[i + 1] != '\0')
	{
		if ((input[i] == ' ' && input[i + 1] == ' ')
			|| ((input[i] > '0' && input[i] < '5')
				&& (input[i + 1] > '0' && input[i + 1] < '5')))
				// Needs to be changed to allow random sizes
			check = 0;
		i++;
	}
	if (i != 30)
		check = 0;
	if (!check)
	{
		ft_write_error();
		return (check);
	}
	return (check);
}

void	ft_write_error(void)
{
	write(2, "Error\n", 6);
}
