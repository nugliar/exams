/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:51:36 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 10:38:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *concatList(struct s_node *a, struct s_node *b)
{
	struct s_node *aLast;
	struct s_node *bLast;

	if (!a)
		return (b);
	if (!b)
		return (a);
	
	aLast = a->left;
	bLast = b->left;

	aLast->right = b;
	b->left = aLast;

	bLast->right = a;
	a->left = bLast;

	return (a);
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *listLeft;
	struct s_node *listRight;

	if (!bst)
		return (bst);

	listLeft = convert_bst(bst->left);
	listRight = convert_bst(bst->right);

	bst->left = bst->right = bst;

	return (concatList(concatList(listLeft, bst), listRight));
}
