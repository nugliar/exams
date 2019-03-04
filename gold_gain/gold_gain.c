/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:06:47 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 12:41:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int scan(int **mine, int **results, int n, int col, int row)
{
	int max = 0;
	int cur;

	if (row < 0 || row >= n || col >= n)
		return (0);
	if (results[row][col])
		return results[row][col];
	for (int i = -1; i <= 1; i++)
	{
		cur = mine[row][col] + scan(mine, results, n, col + 1, row + i);
		if (cur > max)
			max = cur;
	}
	results[row][col] = max;
	return (max);
}

int	gold_gain(int **mine, int n)
{
	int cur;
	int max = 0;
	int **results = malloc(n * sizeof(int *));

	for (int i = 0; i < n; i++)
	{
		results[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			results[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cur = scan(mine, results, n, 0, i);
		if (cur > max)
			max = cur;
	}
	return (max);
}
