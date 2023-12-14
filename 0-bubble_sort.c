#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: sorted array
 * @size: array size
 * Return: no return
*/
void bubble_sort(int *array, size_t size)
{
	size_t n, d, x;
	int swap_two, replace;

	if (!array || size < 2)
	{
		return;
	}
	for (n = 0; n < size - 1; n++)
	{
		swap_two = 0;
		for (d = 0; d < size - n - 1; d++)
		{
			if (array[d] > array[d + 1])
			{
				replace = array[d];
				array[d] = array[d + 1];
				array[d + 1] = replace;
				swap_two = 1;
				for (x = 0; x < size; x++)
				{
					printf("%d", array[x]);
					if (x < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
		if (swap_two == 0)
		{
			break;
		}
	}

}
