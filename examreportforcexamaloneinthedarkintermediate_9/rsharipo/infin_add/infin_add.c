/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:05:46 by exam              #+#    #+#             */
/*   Updated: 2018/10/16 12:52:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		s_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*reverse(char *s, int len)
{
	char	buf[len + 1];
	int		i;

	i = 0;
	while (i < len)
	{
		buf[len - i - 1] = s[i];
		i++;
	}
	buf[len] = 0;
	i = 0;
	while (i < len)
	{
		s[i] = buf[i];
		i++;
	}
	return (s);
}

char	*pad(char *s, int s_len, int len)
{
	char	*res;
	int		i;

	if (s_len == len)
		return (s);
	res = malloc(len + 1);
	i = 0;
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	while (i < len)
		res[i++] = '0';
	res[i] = 0;
	return (res);
}

char	*add_str(char *a, char *b, int len)
{
	int		i;
	int		res;
	int		carry;
	char	sum[len + 3];

	a = pad(a, s_len(a), len);
	b = pad(b, s_len(b), len);
		printf("%s\n", a);
		printf("%s\n", b);
	i = 0;
	carry = 0;
	while (i < len)
	{
		res = (a[i] + b[i] - 48 * 2) + carry;
		carry = res / 10;
		sum[i] = res % 10 + 48;
		printf("%c\n", sum[i]);
		i++;
	}
	if (carry)
		sum[i++] = 1;
	sum[i] = 0;
	return (reverse(sum, s_len(sum)));
}

int	main(int ac, char **av)
{
	char	*a;
	char	*b;
	int		a_len;
	int		b_len;
	int		neg;

	neg = 1;
	if (ac != 3)
		return (0);
	a_len = s_len(av[1]);
	b_len = s_len(av[2]);
	if (av[1][0] == '-')
		neg = neg * (-1);
	if (av[2][0] == '-')
		neg = neg * (-1);
	a = reverse(av[1], a_len);
	b = reverse(av[2], b_len);
	a_len = (a_len >= b_len) ? a_len : b_len;
	if (neg > 0)
		printf("%s\n", add_str(a, b, a_len));
	return (0);
}
