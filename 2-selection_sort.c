#include "sort.h"
/**
 * selection_sort - sorts array of integers in ascending order
 * @array: sorted array
 * @size: array size
 * Return: no return
*/
void selection_sort(int *array, size_t size)
{
	int *pass, *min;
	size_t n = 0, d = n + 1;

	if (!array || size < 2)
	{
		return;
	}
	for (; n < size - 1; n++)
	{
		min = array + n;
		for (; d < size; d++)
		{
			if (array[d] < *min)
			{
				min = array + d;
			}
		}
		if ((array + n) != min)
		{
			pass = array + n;
			array[n] = *min;
			*min = *pass;
			print_array(array, size);
		}
	}
}
