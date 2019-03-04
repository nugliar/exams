/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:40:08 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 12:58:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define MAX(A, B)	((A>=B)?(A):(B))
#define MIN(A, B)	((A<=B)?(A):(B))
#define ASC(X)		(X - 48)
#define BASE		10

int slen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;
	return (len);
}

char *skip_zeros(char *s, int len)
{
	while (len-- > 1 && *s == '0')
		s++;
	return (s);
}

int compare(char *a, char *b, int alen, int blen)
{
	if (alen != blen)
		return (alen - blen);
	while (alen-- > 0)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

char *_do_sub(char *a, char *b, int alen, int blen)
{
	int len = MAX(alen, blen);
	char *res = malloc(len + 1);
	char *aptr = a + alen-1;
	char *bptr = b + blen-1;
	char *rptr = res + len-1;
	int borrow = 0;
	int value;

	if (!res)
		return (res);
	for (int i = 0; i < len; i++)
		res[i] = '0';
	res[len] = 0;

	while (aptr >= a && bptr >= b)
	{
		value = ASC(*aptr) - ASC(*bptr) - borrow;
		if (value < 0)
		{
			value += BASE;
			borrow = 1;
		}
		else
			borrow = 0;
		*rptr-- = value + 48;
		aptr--;
		bptr--;
	}
	while (aptr >= a)
	{
		value = ASC(*aptr) - borrow;
		if (value < 0)
		{
			value += BASE;
			borrow = 1;
		}
		else
			borrow = 0;
		*rptr-- = value + 48;
		aptr--;
	}
	res = skip_zeros(res, len);
	return (res);
}

char *sub(char *a, char *b)
{
	int aneg = 0;
	int bneg = 0;
	char *res;

	if (*a == '-') {aneg = 1; a++;}
	if (*b == '-') {bneg = 1; b++;}

	int alen = slen(a);
	int blen = slen(b);

	if (compare(a, b, alen, blen) > 0)
	{
		if (aneg) write(1, "-", 1);
		res = _do_sub(a, b, alen, blen);
	}
	else if (compare(a, b, alen, blen) < 0)
	{
		if (bneg) write(1, "-", 1);
		res = _do_sub(b, a, blen, alen);
	}
	else
		return ("0");
	return (res);
}

char *add(char *a, char *b)
{
	int alen = slen(a);
	int blen = slen(b);
	int len = MAX(alen, blen) + 1;
	char *res = malloc(len + 1);
	char *aptr = a + alen-1;
	char *bptr = b + blen-1;
	char *rptr = res + len-1;
	int carry = 0;
	int value;

	if (!res)
		return (res);
	for (int i = 0; i < len; i++)
		res[i] = '0';
	res[len] = 0;

	while (aptr >= a && bptr >= b)
	{
		value = ASC(*aptr) + ASC(*bptr) + carry;
		if (value > BASE-1)
		{
			value -= BASE;
			carry = 1;
		}
		else
			carry = 0;
		*rptr-- = value + 48;
		aptr--;
		bptr--;
	}

	if (aptr < a)
	{
		a = b;
		aptr = bptr;
		alen = blen;
	}
	
	while (aptr >= a)
	{
		value = ASC(*aptr) + carry;
		if (value > BASE-1)
		{
			value -= BASE;
			carry = 1;
		}
		else
			carry = 0;
		*rptr-- = value + 48;
		aptr--;
	}
	*rptr = carry + 48;
	res = skip_zeros(res, len);
	return (res);
}

int main(int ac, char **av)
{
	char *a;
	char *b;
	char *res;
	int	neg = 0;

	if (ac == 3)
	{
		a = av[1];
		b = av[2];

		if (*a == '-' && *b == '-')
		{
			write(1, "-", 1);
			res = add(++a, ++b);
		}
		else if ((*a == '-') || (*b == '-'))
			res = sub(a, b);
		else
			res = add(a, b);

		write(1, res, slen(res));
	}
	write(1, "\n", 1);
}
