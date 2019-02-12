/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:31:16 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 12:25:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	factorial(int n)
{
	int result;

	if (n == 1)
		return (1);
	result = n * factorial(n - 1);
	return (result);
}

void	get_seq(int **p, int *seq, int n, int cur, int val)
{
	if (cur == n)
	{
		memcpy(*p, seq, sizeof(int) * n);
		p++;
	}
	seq[cur] = val;
	
}

void	scan(int **p, int size, int n)
{
	int	arr[n];
	int seq[n];
	int *cur;

	if (n <= 0)
		return ;
	for (int i = 0; i < n; i++)
		arr[i] = i;
	for (int j = 0; j < n; i++)
		get_seq(seq, arr, n, 0, j);
	p[size] = NULL;
}

int	**get_permuts(int n)
{
	int permut_count = 0;
	int	**permuts = NULL;

	permut_count = factorial(n);
	permuts = malloc(sizeof(int *) * (permut_count + 1));
	scan(permuts, permut_count, n);
	return (permuts);
}

int	**range_comb(int n)
{
	int	arr[n];
	int	**permuts;

	if (n <= 0)
		return (NULL);
	permuts = get_permuts(n);
	return (permuts);
}

int	main(int ac, char **av)
{
	int	**arr;
	int	n;

	if (ac != 2)
		return (0);
	n = atoi(av[1]);
	if (!n)
		return (0);
	arr = range_comb(n);
	if (!arr)
		return (0);
	for (int i = 0; arr[i] != NULL; i++)
	{
		printf("{ ");
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("} ");
	}
	printf("\n");
	return (0);
}
