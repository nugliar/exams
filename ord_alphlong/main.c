/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:44:23 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 11:51:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int count_words(char *s)
{
	int count = 0;
	int i = 0;

	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (s[i] && !is_space(s[i]))
			count++;
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (count);
}

void split_str(char **words, char *s)
{
	int i = 0;
	int j = 0;
	int start = 0;

	while (s[i])
	{
		j = 0;
		while (s[i] && is_space(s[i]))
			i++;
		if (s[i] && !is_space(s[i]))
			start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		*words = malloc(i - start + 1);
		while (start < i)
			(*words)[j++] = s[start++];
		(*words)[j] = 0;
		words++;
	}
	*words = 0;
}

int str_len(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;
	return (len);
}

void print_words(char **words)
{
	int first = 1;
	int len;
	int prev_len;

	if (!words)
		return ;

	prev_len = str_len(*words);
	for (int i = 0; words[i]; i++)
	{
		len = str_len(words[i]);
		if (len > prev_len)
		{
			write(1, "\n", 1);
			first = 1;
		}
		if (!first)
			write(1, " ", 1);
		else
			first = 0;
		write(1, words[i], len);
		prev_len = len;
	}
}

int main(int ac, char **av)
{
	char**	words;
	int		word_count = 0;

	if (ac == 2)
	{
		word_count = count_words(av[1]);
		words = malloc((word_count + 1) * sizeof(char *));
		split_str(words, av[1]);
		merge_sort(words, 0, word_count);
		print_words(words);
	}
	write(1, "\n", 1);
	return (0);
}
