/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:42:06 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 11:12:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void	get_longest(struct s_node *n, int cur, int *longest)
{
	int left = 0;
	int right = 0;

	if (!n)
		return ;
	if (n->left && n->left->value == n->value + 1)
		left++;
	if (n->right && n->right->value == n->value + 1)
		right++;
	if (!left && !right)
		if (cur > *longest)
			*longest = cur;
	get_longest(n->left, (left ? cur + 1: 1), longest);
	get_longest(n->right, (right ? cur + 1: 1), longest);
}

int	longest_sequence(struct s_node *node)
{
	int	longest = 0;

	if (!node)
		return (0);
	get_longest(node, 1, &longest);
	return (longest);
}
