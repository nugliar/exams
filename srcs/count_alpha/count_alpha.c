/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:18:13 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 09:44:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	to_lower(char c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

int main(int ac, char **av)
{
	int 	arr[128] = { 0 };
	char	*s;
	int		c;
	int		first = 1;

	if (ac == 2)
	{
		s = av[1];
		for (int i = 0; s[i] != 0; i++)
			s[i] = to_lower(s[i]);
		for (int i = 0; s[i] != 0; i++)
		{
			c = (int)s[i];
			arr[c] += 1;
		}
		for (int i = 0; s[i] != 0; i++)
		{
			c = (int)s[i];
			if (arr[c] && s[i] >= 97 && s[i] <= 122)
			{
				if (first)
					printf("%d%c", arr[c], c);
				else
					printf(", %d%c", arr[c], c);
				arr[c] = 0;
			}
			first = 0;
		}
	}
	printf("\n");
	return (0);
}
