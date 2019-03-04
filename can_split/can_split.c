/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:34:03 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:45:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void get_total(struct s_node *n, int *total)
{
	if (!n)
		return ;

	*total += 1;

	get_total(n->left, total);
	get_total(n->right, total);
}

int try_split(struct s_node *n, const int total, int *yes)
{
	int left;
	int right;

	if (!n)
		return 0;
	
	left = 1 + try_split(n->left, total, yes);
	right = 1 + try_split(n->right, total, yes);

	if (left+right-1 == total - (left+right-1))
		*yes = 1;

	return left+right-1;
}

int	can_split(struct s_node *n)
{
	int total = 0;
	int yes = 0;

	get_total(n, &total);
	try_split(n, total, &yes);

	return yes;
}
