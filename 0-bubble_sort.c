#include "sort.h"

/**
  * bubble_sort - Implemments the optimized bubble sort algorithm
  *
  * @array: Array of integers to sort
  * @size: Size of array
  *
  * Return: nothing
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;

				print_array(array, size);
			}
		}

		if (flag == 0)
			break;
	}
}
