#include "sort.h"
/**
 * implement_lomuto_partition - implement Lomuto partition scheme on array
 * @array: array sorted
 * @init: initial partition
 * @fin: final partition
 * @size: array size
 * Return: pivot index
*/
int implement_lomuto_partition(int *array, int init, int fin, size_t size)
{
	int pivot = array[fin];
	int n = init - 1, d, tmp;

	for (d = init; d <= fin - 1; d++)
	{
		if (array[d] <= pivot)
		{
			n++;
			if (n != d)
			{
				tmp = array[n];
				array[n] = array[d];
				array[d] = tmp;
				print_array(array, size);
			}
		}
	}
	if ((n + 1) != fin)
	{
		tmp = array[n + 1];
		array[n + 1] = array[fin];
		array[fin] = tmp;
		print_array(array, size);
	}
	return (n + 1);
}
/**
 * recursive_quick_sort - recursive quick sort
 * @array: array sorted
 * @init: initial partition
 * @fin: final partition
 * @size: array size
 * Return: no return
*/
void recursive_quick_sort(int *array, int init, int fin, size_t size)
{
	int pivot;

	if (init < fin)
	{
		pivot = implement_lomuto_partition(array, init, fin, size);
		recursive_quick_sort(array, init, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, fin, size);
	}
}
/**
 * quick_sort - sort array of integers in ascending order
 * @array: array sorted
 * @size: array size
 * Return: no return
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	recursive_quick_sort(array, 0, size - 1, size);
}
