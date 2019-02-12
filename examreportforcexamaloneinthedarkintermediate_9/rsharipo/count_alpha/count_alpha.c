/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:19:10 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 09:40:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	to_lower(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
		i++;
	}
}

void	count_alpha(char *s)
{
	static int	arr[128];
	int			not_first;
	int			i;

	not_first = 0;
	if (!s)
		return ;
	to_lower(s);
	i = 0;
	while (s[i])
		arr[(int)s[i++]] += 1;
	i = 0;
	while (s[i])
	{
		if (arr[(int)s[i]] && s[i] >= 97 && s[i] <= 122)
		{
			if (not_first)
				printf(", ");
			printf("%d%c", arr[(int)s[i]], s[i]);
			arr[(int)s[i]] = 0;
			not_first = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
