/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:28:55 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 09:38:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int cur;
	int max = 0;

	if (!root)
		return (-1);
	if (!root->nodes)
		return (0);
	for (int i = 0; root->nodes[i]; i++)
	{
		cur = 1 + height_tree(root->nodes[i]);
		if (cur > max)
			max = cur;
	}
	return (max);
}
