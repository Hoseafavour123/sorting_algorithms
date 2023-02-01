#include "sort.h"

/**
  * selection_sort - Implements the selection sort algorithm in sorting aan
  * array of integers
  *
  * @array: The array
  * @size: size of the array
  *
  * Return: void
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
