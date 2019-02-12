/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:02:01 by exam              #+#    #+#             */
/*   Updated: 2019/01/22 09:13:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_2s(int n)
{
	int count = 0;

	while (n)
	{
		if (n % 10 == 2)
			count++;
		n /= 10;
	}
	return (count);
}

int    count_of_2(int n)
{
	int count = 0;

	if (n <= 1)
		return (0);
	while (n > 1)
	{
		count += get_2s(n);
		n--;
	}
	return (count);
}