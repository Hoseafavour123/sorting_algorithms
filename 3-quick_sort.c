#include "sort.h"

/**
  * swap_elements - Swaps two element
  * @e1: first element
  * @e2: second element
  *
  * Return: void
  */
void swap_elements(int *e1, int *e2)
{
	int tmp;

	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
  * partition - Partitions an array of integers using lomuto technique
  * @array: The array
  * @low: least index
  * @high: highest index
  * @size: size of array
  *
  * Return: Partition point(index)
  */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	if (array == NULL)
		return (-1);
	pivot = array[high];
	i = low - 1;
	j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_elements(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j++;
	}
	if (array[high] < array[i + 1])
	{
		swap_elements(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}


/**
  * recursive_sort - Recursively sorts an array of integers
  * @array: Array to be sorted
  * @low: Lowest index
  * @high: Highest index
  * @size: Size of array
  */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int partition_point;

	if (array == NULL)
		return;

	if (low < high)
	{
		partition_point = partition(array, low, high, size);
		recursive_sort(array, low, partition_point - 1, size);
		recursive_sort(array, partition_point + 1, high, size);
	}
}

/**
  * quick_sort - Quick sort algorithm implementation using lomuto technique
  * @array: Array to be sorted
  * @size: Size of array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	recursive_sort(array, 0, size - 1, size);
}
