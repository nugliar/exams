/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:08:55 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 12:03:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	print_left(struct s_node *root)
{
	// TODO: if-else to avoid leaf printing

	if (!root)
		return ;
	if (root->left)
	{
		if (root->left->left || root->left->right)
			printf(" %d", root->left->value);
		print_left(root->left);
	}
}

void	print_leafs(struct s_node *root)
{
	// TODO: remake function to be called on left anf right separately

	if (!root)
		return ;
	if (root->left)
		print_leafs(root->left);
	if (root->right)
		print_leafs(root->right);
	if (!root->left && !root->right)
		printf(" %d", root->value);
}

void	print_right(struct s_node *root)
{
	// TODO: if-else to avoid leaf printing

	if (!root)
		return ;
	if (root->right)
	{
		print_right(root->right);
		if (root->right->right || root->right->left)
			printf(" %d", root->right->value);
	}
}

void	perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		print_left(root);
		print_leafs(root);
		print_right(root);
	}
	printf("\n");
}
