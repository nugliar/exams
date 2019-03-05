/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:19:27 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 12:08:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct s_window
{
	int	odds;
	int	evens;
};

void	set_odd(char *arr, int len, int *odd)
{
	for (int i = 0; i < len; i++)
		odd[i] = arr[i] % 2;
}

char	*ssub(char *src, int len)
{
	char *res;

	res = malloc(len+1);

	if (!res)
		return NULL;

	for (int i = 0; i < len; i++)
		res[i] = src[i];
	res[len] = 0;

	return res;
}

void 	set_window(int *odd, struct s_window *window, int size)
{
	window->odds = 0;

	for (int i = 0; i < size; i++)
		window->odds += odd[i];
	window->evens = size - window->odds;
}

char	*longest_subarray(char *arr)
{
	int len = strlen(arr);
	struct s_window window;
	int odd[len];
	int idx;

	if (!arr)
		return NULL;

	set_odd(arr, len, odd);

	for (int curlen = len; curlen > 1; curlen--)
	{
		if (curlen % 2)
			continue ;

		set_window(odd, &window, curlen);
		idx = curlen;
		while (idx < len)
		{
			if (window.odds == window.evens)
				return ssub(arr + idx - curlen, curlen);
			window.odds -= odd[idx - curlen];
			window.odds += odd[idx];
			window.evens = curlen - window.odds;
			idx++;
		}
	}
	return NULL;
}
