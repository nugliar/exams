/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:43:25 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 12:56:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *ref1 = lst1;
	struct s_node *ref2 = lst2;
	int len1 = 0;
	int len2 = 0;
	int len;

	if (!lst1 || !lst2)
		return (NULL);
	
	while (lst1)
	{
		lst1 = lst1->next;
		len1++;
	}
	while (lst2)
	{
		lst2 = lst2->next;
		len2++;
	}

	if (len1 > len2)
	{
		len = len1 - len2;
		lst1 = ref1;
		lst2 = ref2;
	}
	else
	{
		len = len2 - len1;
		lst1 = ref2;
		lst2 = ref1;
	}

	while (len--)
	{
		lst1 = lst1->next;
	}
	while (lst1)
	{
		if (lst1 == lst2)
			return (lst1);
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (NULL);
}
