/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:04:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 11:04:49 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	merge(int arr[], int left, int mid, int right)
// {
// 	int	L[mid - left + 1];
// 	int	R[right - mid];
// 	int	i;
// 	int	j;
// 	int	k;
	
// 	i = -1;
// 	j = -1;
// 	while ((++i) < (mid - left + 1))
// 		L[i] = arr[left + i];
// 	while ((++j) < (right - mid))
// 		R[j] = arr[mid + 1 + j];
// 	i = 0;
// 	j = 0; 
// 	k = left; 
// 	while ((i < (mid - left + 1)) && (j < (right - mid))) 
// 	{
// 		if (L[i] <= R[j])
// 			arr[k++] = L[i++];
// 		else
// 			arr[k++] = R[j++];
// 	}
// 	while (i < (mid - left + 1))
// 		arr[k++] = L[i++];
// 	while (j < (right - mid))
// 		arr[k++] = R[j++];
// }

static void	merge(int arr[], int left, int mid, int right)
{
	int	L_R[right - left + 1];
	int	i;
	int	j;
	int	k;
	
	i = -1;
	while ((++i) < (right - left + 1))
		L_R[i] = arr[left + i];
	i = 0;
	j = 0;
	k = left;
	while ((i < (mid - left + 1)) && (j < (right - mid))) 
	{
		if (L_R[i] <= L_R[mid + 1 + j])
			arr[k++] = L_R[i++];
		else
			arr[k++] = L_R[mid + 1 + (j++)];
	}
	while (i < (mid - left + 1))
		arr[k++] = L_R[i++];
	while (j < (right - mid))
		arr[k++] = L_R[mid + 1 + (j++)];
}

void	merge_sort(int *arr, int left, int right)
{
	int mid;

	if (left < right) {
		mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
