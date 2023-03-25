/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:04:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 15:29:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	merge(int arr[], int left, int mid, int right)
{
	int	*l_r;
	int	ind_part[3];

	l_r = (int *)malloc((right - left + 1) * sizeof(int));
	if (!l_r)
		return (ERROR);
	ind_part[0] = 0;
	ind_part[1] = left;
	ind_part[2] = mid + 1;
	while ((ind_part[1] <= mid) && (ind_part[2] <= right))
	{
		if (arr[ind_part[1]] <= arr[ind_part[2]])
			l_r[ind_part[0]++] = arr[ind_part[1]++];
		else
			l_r[ind_part[0]++] = arr[ind_part[2]++];
	}
	while (ind_part[1] <= mid)
		l_r[ind_part[0]++] = arr[ind_part[1]++];
	while (ind_part[2] <= right)
		l_r[ind_part[0]++] = arr[ind_part[2]++];
	ind_part[0] = -1;
	while (++(ind_part[0]) < (right - left + 1))
		arr[left + ind_part[0]] = l_r[ind_part[0]];
	free(l_r);
	return (0);
}

int	merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		if (merge_sort(arr, left, mid) == ERROR)
			return (ERROR);
		if (merge_sort(arr, mid + 1, right) == ERROR)
			return (ERROR);
		if (merge(arr, left, mid, right) == ERROR)
			return (ERROR);
	}
	return (0);
}
