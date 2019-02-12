/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:52:12 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 11:30:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

int	get_width(struct s_node *n, unsigned int *longest)
{
	unsigned int	left;
	unsigned int	right;

	if (!n)
		return (0);
	left = 1 + get_width(n->left, longest);
	right = 1 + get_width(n->right, longest);
	if (left + right - 1 > *longest)
		*longest = left + right - 1;
	if (left >= right)
		return (left);
	else
		return (right);
}

int	width_tree(struct s_node *n)
{
	unsigned int	longest;

	if (!n)
		return (0);
	longest = 0;
	get_width(n, &longest);
	return (longest);
}
