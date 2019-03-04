/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:28:07 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 10:36:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node	*fast;
	struct s_node	*slow;

	if (!node)
		return (0);
	slow = node;
	fast = node;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
