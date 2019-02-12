/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:14:47 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 10:29:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_H
# define FLOOD_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif
