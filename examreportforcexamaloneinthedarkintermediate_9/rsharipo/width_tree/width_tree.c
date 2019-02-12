/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:23:38 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 11:06:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct 				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

int	find_width(struct s_node *node, int *max)
{
	int	left;
	int	right;

	if (!node)
		return (0);
	left = 1 + find_width(node->left, max);
	right = 1 + find_width(node->right, max);
	if (left + right - 1 > *max)
		*max = left + right - 1;
	if (left >= right)
		return (left);
	else
		return (right);
}

int	width_tree(struct s_node *n)
{
	int	max;

	max = 0;
	if (!n)
		return (0);
	find_width(n, &max);
	return (max);
}
