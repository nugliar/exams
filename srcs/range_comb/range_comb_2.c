/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:26:44 by exam              #+#    #+#             */
/*   Updated: 2019/02/14 12:51:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int		compare(int *a, int *b)
{
	while (*a != INT_MIN && *b != INT_MIN)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

void	merge(int **arr, int **a, int **b)
{
	while (*a || *b)
	{
		if (!(*a))
			*arr++ = *b++;
		else if (!(*b))
			*arr++ = *a++;
		else if (compare(*a, *b) <= 0)
			*arr++ = *a++;
		else
			*arr++ = *b++;
	}
}

void	merge_sort(int **arr, int low, int high)
{
	int 	mid = low + (high - low) / 2;
	int 	**a = malloc((mid - low + 1) * sizeof(int *));
	int		**b = malloc((high - mid + 1) * sizeof(int *));

	if (low + 1 >= high)
		return ;

	merge_sort(arr, low, mid);
	merge_sort(arr, mid, high);

	for (int i = 0; i < mid - low; i++)
		a[i] = arr[low + i];
	a[mid - low] = NULL;

	for (int i = 0; i < high - mid; i++)
		b[i] = arr[mid + i];
	b[high - mid] = NULL;

	merge(arr + low, a, b);

	free(a);
	free(b);
}

int	factorial(int n)
{
	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	return (n * factorial(n - 1));
}

void	swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

void	perms(int **res, int *arr, int low, int high, int *idx)
{
	if (low > high)
	{
		res[*idx] = malloc((high + 1) * sizeof(int));
		memcpy(res[*idx], arr, (high + 1) * sizeof(int));
		*idx += 1;
		return ;
	}
	for (int i = low; i <= high; i++)
	{
		swap(arr + low, arr + i);
		perms(res, arr, low + 1, high, idx);
		swap(arr + low, arr + i);
	}
}

int    **range_comb(int n)
{
	int arr[n];
	int **res;
	int idx = 0;
	int size = factorial(n);

	if (n <= 0)
		return (0);
	for (int i = 0; i < n; i++)
		arr[i] = i;
	res = malloc((size + 1) * sizeof(int *));
	for (int i = 0; i <= size; i++)
		res[i] = 0;
	perms(res, arr, 0, n - 1, &idx);
	merge_sort(res, 0, size);
	return (res);
}

int main(int ac, char **av)
{
	int **arr;
	int	size;

	if (ac != 2)
		return (0);

	size = atoi(av[1]);
	arr = range_comb(size);
	// for (int i = 0; arr[i]; i++)
	// {
	// 	for (int j = 0; j < size; j++)
	// 		printf("%d ", arr[i][j]);
	// 	printf("\n");
	// }
	return (0);
}
