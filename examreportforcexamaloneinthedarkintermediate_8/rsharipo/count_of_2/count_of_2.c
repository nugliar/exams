/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:03:35 by exam              #+#    #+#             */
/*   Updated: 2018/10/02 09:12:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_2_count(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		if (n % 10 == 2)
			count++;
		n = n / 10;
	}
	return (count);
}

int	count_of_2(int n)
{
	int	i;
	int	count;

	if (n <= 1)
		return (0);
	i = 0;
	count = 0;
	while (i <= n)
		count += get_2_count(i++);
	return (count);
}
