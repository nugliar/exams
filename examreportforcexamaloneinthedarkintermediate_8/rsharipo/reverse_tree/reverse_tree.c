/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:36:16 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 10:49:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	reverse_tree(struct s_node *root)
{
	struct s_node	*tmp;

	if (!root)
		return ;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
