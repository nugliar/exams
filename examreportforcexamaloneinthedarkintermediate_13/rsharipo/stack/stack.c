/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:22:20 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 10:39:21 by exam             ###   ########.fr       */
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

struct s_stack	*init(void)
{
	struct s_stack	*stack = NULL;

	stack = malloc(sizeof(struct s_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	void			*ret;
	struct s_node	*tmp;

	if (!stack || !stack->top)
		return (NULL);
	ret = stack->top->content;
	tmp = stack->top->next;
	free(stack->top);
	stack->top = tmp;
	return (ret);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node	*new = NULL;

	if (!stack)
		return ;
	new = malloc(sizeof(struct s_node));
	if (!new)
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void	*peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int	isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}
