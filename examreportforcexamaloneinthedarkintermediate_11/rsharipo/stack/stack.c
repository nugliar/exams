/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:54:50 by exam              #+#    #+#             */
/*   Updated: 2019/01/22 10:06:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack;

	stack = malloc(sizeof(struct s_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	void *ret;
	struct s_node *tmp;

	if (!stack || !stack->top)
		return (NULL);
	tmp = stack->top;
	ret = tmp->content;
	stack->top = stack->top->next;
	free(tmp);
	return (ret);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	if (!stack)
		return ;
	new = malloc(sizeof(struct s_node));
	if (!new)
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}
