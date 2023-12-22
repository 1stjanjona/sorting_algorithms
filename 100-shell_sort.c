#include "sort.h"
/**
 * shell_sort - sort array of integers in ascending order using
 * Shell sort algorithm
 * Knuth squenece
 * @array: array sorted
 * @size: array size
 * Return: no return
*/
void shell_sort(int *array, size_t size)
{
	size_t n, d, interval;
	int tmp;

	if (!array || size < 2)
	{
		return;
	}
	for (interval = 1; interval < (size / 3);)
	{
		interval = interval * 3 + 1;
	}
	for (; interval >= 1; interval /= 3)
	{
		for (n = interval; n < size; n++)
		{
			d = n;
			while (d >= interval && array[d - interval] > array[d])
			{
				tmp = array[d];
				array[d] = array[d - interval];
				array[d - interval] = tmp;
				d -= interval;
			}
		}
		print_array(array, size);
	}
}
