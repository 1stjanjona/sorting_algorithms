#include "sort.h"
/**
 * selection_sort - sorts array of integers in ascending order
 * @array: sorted array
 * @size: array size
 * Return: no return
*/
void selection_sort(int *array, size_t size)
{
	int *min, temp;
	size_t n, d;

	if (!array || size < 2)
	{
		return;
	}
	for (n = 0; n < size - 1; n++)
	{
		min = array + n;
		for (d = n + 1; d < size; d++)
		{
			if (array[d] < *min)
			{
				min = array + d;
			}
		}
		if (min != array + n)
		{
			temp = array[n];
			array[n] = *min;
			*min = temp;
			print_array(array, size);
		}
	}
}
