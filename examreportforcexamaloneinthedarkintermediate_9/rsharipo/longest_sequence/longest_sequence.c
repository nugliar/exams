/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:44:11 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 10:21:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct				s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

void	find_seq(struct s_node *node, int prev, int seq, int *longest)
{
	if (!node)
		return ;
	if (node->value == prev + 1)
		seq += 1;
	else
		seq = 1;
	if (seq > *longest)
		*longest = seq;
	find_seq(node->left, node->value, seq, longest);
	find_seq(node->right, node->value, seq, longest);
}

int	longest_sequence(struct s_node *node)
{
	int	longest;

	longest = 1;
	if (!node)
		return (0);
	find_seq(node, node->value, 1, &longest);
	return (longest); 
}
