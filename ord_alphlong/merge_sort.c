/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:08:15 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 11:53:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int to_lower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int comp(char *a, char *b)
{
	int diff = 0;

	while (*a && *b)
	{
		if (!diff && to_lower(*a) != to_lower(*b))
			diff = to_lower(*a) - to_lower(*b);
		a++;
		b++;
	}
	if (!(*a) && !(*b))
		return (diff);
	else if (!(*a))
		return (-1);
	else
		return (1);
}

void merge(char **words, char **a, char **b)
{
	while (*a || *b)
	{
		if (!(*a) && *b)
			*words++ = *b++;
		else if (!(*b) && *a)
			*words++ = *a++;
		else if (comp(*a, *b) <= 0)
			*words++ = *a++;
		else
			*words++ = *b++;
	}
}

void merge_sort(char **words, int low, int high)
{
	int mid = low + (high - low) / 2;
	char* a[mid - low + 1];
	char* b[high - mid + 1];

	if (low + 1 >= high)
		return ;

	merge_sort(words, low, mid);
	merge_sort(words, mid, high);

	for (int i = 0; i < mid - low; i++)
		a[i] = words[i + low];
	a[mid - low] = 0;

	for (int i = 0; i < high - mid; i++)
		b[i] = words[i + mid];
	b[high - mid] = 0;

	merge(words + low, a, b);
}
