/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:05:58 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 09:26:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int first = 1;

	if (!a || !b || !na || !nb)
		return ;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (first)
				first = 0;
			else
				printf(" ");
			printf("%d", a[i]);
			i++;
			j++;
		}
		else if (a[i] <= b[j])
			i++;
		else
			j++;
	}
	printf("\n");
}
