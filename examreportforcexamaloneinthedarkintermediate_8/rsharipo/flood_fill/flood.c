/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:17:02 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 10:34:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood.h"

void	fill(char **tab, char spot, t_point s, t_point b)
{
	int	x;
	int	y;

	x = b.x;
	y = b.y;
	tab[y][x] = 'F';
	if (x + 1 < s.x && tab[y][x + 1] == spot)
	{
		b.x = x + 1;
		b.y = y;
		fill(tab, spot, s, b);
	}
	if (x - 1 >= 0 && tab[y][x - 1] == spot)
	{
		b.x = x - 1;
		b.y = y;
		fill(tab, spot, s, b);
	}
	if (y - 1 >= 0 && tab[y - 1][x] == spot)
	{
		b.y = y - 1;
		b.x = x;
		fill(tab, spot, s, b);
	}
	if (y + 1 < s.y && tab[y + 1][x] == spot)
	{
		b.y = y + 1;
		b.x = x;
		fill(tab, spot, s, b);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	spot;

	if (!tab)
		return ;
	if (begin.y < 0 || begin.x < 0)
		return ;
	if (size.y < 0 || size.x < 0)
		return ;
	spot = tab[begin.y][begin.x];
	fill(tab, spot, size, begin);
}
