/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:41:27 by exam              #+#    #+#             */
/*   Updated: 2018/11/06 12:57:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int		str_in(char *coin, char *src)
{
	int i = 0;

	if (ft_strlen(coin) == 0)
		return (0);
	while (coin[i] && src[i])
	{
		if (coin[i] != src[i])
			return (0);
		i++;
	}
	if (coin[i])
		return (0);
	return (1);
}

char	*ft_strstr(char *src, char *coin)
{
	int	i = 0;

	if (!coin)
		return (NULL);
	while (src[i])
	{
		if (str_in(coin, src + i))
			return (coin);
		i++;
	}
	return (NULL);
}

char	*check_str(char **av, char *s, int len, int ac)
{
	char	*to_check;
	int		i = 0;

	to_check = malloc(len + 1);
	while (i < len)
	{
		to_check[i] = s[i];
		i++;
	}
	to_check[i] = 0;
	i = 2;
	while (i < ac)
		if (!ft_strstr(av[i++], to_check))
			return (NULL);
	return (to_check);
}

void	do_something(char **av, char *s, int ac, int min)
{
	int		i;
	int		j;
	char	*ku;
	int		len = ft_strlen(s);
	int		done = 0;

	j = len;
	while (j >= 0)
	{
		if (done)
			break ;
		i = 0;
		while (i + j <= len)
		{
			if ((ku = check_str(av, s + i, j, ac)) != NULL)
			{
				done = 1;
				write(1, ku, ft_strlen(ku));
				write(1, "\n", 1);
				if (ft_strlen(ku) <= min)
					break ;
			}
			i++;
		}
		j--;
	}
	if (!done)
		write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	i = 1;
	int	len = 0;
	int	min = INT_MAX;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ac == 2)
	{
		write(1, av[1], ft_strlen(av[1]));
		write(1, "\n", 1);
		return (0);
	}
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (len <= min)
			min = len;
		i++;
	}
	do_something(av, av[1], ac, min);
	return (0);
}
