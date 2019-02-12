/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:16:06 by exam              #+#    #+#             */
/*   Updated: 2019/01/22 09:51:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void	fill(char **tab, t_point s, int x, int y, char e)
{
	if (tab[y - 1][x - 1] != e || tab[y - 1][x - 1] == 'F')
		return ;
	tab[y - 1][x - 1] = 'F';
	if (x + 1 <= s.x)
		fill(tab, s, x + 1, y, e);
	if (x - 1 > 0)
		fill(tab, s, x - 1, y, e);
	if (y + 1 <= s.y)
		fill(tab, s, x, y + 1, e);
	if (y - 1 > 0)
		fill(tab, s, x, y - 1, e);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (!tab)
		return ;
	if (begin.x < 1 || begin.x > size.x)
		return ;
	if (begin.y < 1 || begin.y > size.y)
		return ;
	fill(tab, size, begin.x, begin.y, tab[begin.y - 1][begin.x - 1]);
}
