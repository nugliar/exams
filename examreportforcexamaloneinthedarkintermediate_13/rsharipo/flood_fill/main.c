/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:50:14 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 10:16:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill(char **tab, int y, int x, int max_y, int max_x, char c)
{
	tab[y][x] = 'F';
	if (x - 1 >= 0 && tab[y][x - 1] == c)
		fill(tab, y, x - 1, max_y, max_x, c);
	if (x + 1 < max_x && tab[y][x + 1] == c)
		fill(tab, y, x + 1, max_y, max_x, c);
	if (y - 1 >= 0 && tab[y - 1][x] == c)
		fill(tab, y - 1, x, max_y, max_x, c);
	if (y + 1 < max_y && tab[y + 1][x] == c)
		fill(tab, y + 1, x, max_y, max_x, c);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];

	fill(tab, begin.y, begin.x, size.y, size.x, c);
}
