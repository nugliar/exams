/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:15:03 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 11:26:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int get_width(struct s_node *n, int *width)
{
	int left = 0;
	int right = 0;

	if (!n)
		return (0);
	left = 1 + get_width(n->left, width);
	right = 1 + get_width(n->right, width);
	if (left + right - 1 > *width)
		*width = left + right - 1;
	if (left >= right)
		return (left);
	else
		return (right);
}

int	width_tree(struct s_node *n)
{
	int width = 0;

	if (!n)
		return (0);
	get_width(n, &width);
	return (width);
}
