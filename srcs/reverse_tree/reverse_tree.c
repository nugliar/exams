/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:41:08 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 09:45:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *temp;

	if (!root)
		return ;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
