/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:21:30 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:25:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define MAX(A,B)	((A>=B)?(A):(B))
#define MIN(A,B)	((A<=B)?(A):(B))
#define ASC(X)		(X-48)
#define BASE		10

int slen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;

	return len;
}

int is_negative(char **a, char **b)
{
	int neg = 0;

	if (**a == '-')
	{
		*a += 1;
		neg = ~neg;
	}
	if (**b == '-')
	{
		*b += 1;
		neg = ~neg;
	}

	return neg;
}

char *mul_nums(char *a, char *b, int alen, int blen)
{
	int len = alen+blen;
	char *res = malloc(len+1);
	char *aptr, *bptr, *aend, *bend, *rptr;
	int sum = 0;
	int idx = 0;

	if (!res)
		return NULL;

	for (int i = 0; i < len; i++)
		res[i] = '0';
	res[len] = 0;
	rptr = res + len-1;

	while (idx < len)
	{
		aptr = a+alen-1 - MIN(idx, alen-1);
		aend = a+alen-1 - MAX(0, idx-blen+1);
		bptr = b+blen-1 - MIN(idx, blen-1);
		bend = b+blen-1 - MAX(0, idx-alen+1);

		while (bend >= bptr && aptr <= aend)
		{
			sum += ASC(*bend) * ASC(*aptr);
			bend--;
			aptr++;
		}

		*rptr-- = (sum % BASE) + 48;
		sum = sum / BASE;

		idx++;
	}
	while (*res == '0' && len-- > 1)
		res++;

	return res;
}

int main(int ac, char **av)
{
	char *res, *a, *b;
	int neg = 0;

	if (ac == 3)
	{
		a = av[1];
		b = av[2];
		neg = is_negative(&a, &b);
		if ((slen(a) == 1 && *a == '0') || (slen(b) == 1 && *b == '0'))
			write(1, "0", 1);
		else
		{
			res = mul_nums(a, b, slen(a), slen(b));
			if (neg)
				write(1, "-", 1);
			write(1, res, slen(res));
		}
	}
	write(1, "\n", 1);

	return 0;
}
