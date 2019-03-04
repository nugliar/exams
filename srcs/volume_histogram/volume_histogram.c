/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:46:19 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 11:29:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_max(int *histogram, int size)
{
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		if (histogram[i] > max)
			max = histogram[i];
	}
	return (max);
}

int volume_histogram(int *histogram, int size)
{
	int cur;
	int max;
	int total = 0;
	int i = 0;

	if (!histogram || size <= 0)
		return (0);
	while (i < size && histogram[i] == 0)
		i++;
	if (i == size)
		return (total);

	cur = histogram[i];
	max = get_max(histogram + i + 1, size - i - 1);
	for (; i < size; i++)
	{
		if (cur > max)
			cur = max;
		if (histogram[i] >= cur)
		{
			cur = histogram[i];
			max = get_max(histogram + i + 1, size - i - 1);
			continue ;
		}
		total += cur - histogram[i];
	}
	return (total);
}
