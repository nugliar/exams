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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

int findCeil(char str[], char first, int l, int h)
{
	int ceilIndex = l;

	for (int i = l + 1; i <= h; i++)
		if (str[i] > first && str[i] < str[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}

void perms(char str[])
{
	int size = strlen(str);

	int isFinished = 0;
	while (!isFinished)
	{
		printf ("%s\n", str);

		int i;
		for (i = size - 2; i >= 0; --i)
			if (str[i] < str[i + 1])
				break;

		if (i == -1)
			isFinished = 1;
		else
		{
			int ceilIndex = findCeil(str, str[i], i + 1, size - 1);
			swap(&str[i], &str[ceilIndex]);
			reverse();
		}
	}
}

int main()
{
	char str[] = "0123456789";
	char **res;
	int idx = 0;

	perms(str);
	return 0;
}
