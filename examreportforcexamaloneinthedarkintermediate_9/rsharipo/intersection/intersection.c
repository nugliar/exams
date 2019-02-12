/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:17:08 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 11:59:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct				s_node
{
	void			*content;
	struct s_node	*next;
};

void	*find_intersect(
		struct s_node *lst1, struct s_node *lst2, int len1, int len2)
{
	int diff;

	diff = len1 - len2;
	if (diff >= 0)
		while (diff-- && lst1)
			lst1 = lst1->next;
	else
		while (diff++ != 0 && lst2)
			lst2 = lst2->next;
	while (lst1 && lst2)
	{
		if (lst1 == lst2)
			break ;
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (lst1);
}

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node	*intersect;
	struct s_node	*ref1;
	struct s_node	*ref2;
	static int		len1;
	static int		len2;

	ref1 = lst1;
	ref2 = lst2;
	intersect = NULL;
	while (lst1 && lst1->next)
	{
		lst1 = lst1->next;
		len1++;
	}
	while (lst2 && lst2->next)
	{
		lst2 = lst2->next;
		len2++;
	}
	if (!lst1 || !lst2)
		return (NULL);
	if (lst1->next != lst2->next)
		return (NULL);
	return (find_intersect(ref1, ref2, ++len1, ++len2));
}
