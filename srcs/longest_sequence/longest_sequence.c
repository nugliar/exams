/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:30:19 by exam              #+#    #+#             */
/*   Updated: 2019/02/05 09:46:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void find(struct s_node *node, int prev, int seq, int *max)
{
	if (!node)
		return ;

	if (node->value == prev + 1)
		seq += 1;
	else
		seq = 1;

	if (seq > *max)
		*max = seq;

	find(node->left, node->value, seq, max);
	find(node->right, node->value, seq, max);
}

int	longest_sequence(struct s_node *node)
{
	int longest = 0;

	if (node)
		find(node, node->value, 1, &longest);

	return (longest);
}
