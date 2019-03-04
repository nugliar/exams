/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:12:22 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 09:50:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue	*init(void)
{
	struct s_queue	*new;

	new = malloc(sizeof(struct s_queue));
	if (!new)
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*tmp;
	struct s_node	*new_node;

	if (!queue)
		return ;
	new_node = malloc(sizeof(struct s_node));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (!queue->last)
	{
		queue->last = new_node;
		queue->first = new_node;
	}
	else
	{
		tmp = queue->last;
		queue->last = new_node;
		tmp->next = new_node;
	}
}

void	*dequeue(struct s_queue *queue)
{
	void			*content;
	struct s_node	*tmp;

	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	content = queue->first->content;
	tmp = queue->first;
	if (queue->first == queue->last)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
		queue->first = queue->first->next;
	free(tmp);
	return (content);
}

void	*peek(struct s_queue *queue)
{
	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int		isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}
