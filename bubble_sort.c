/*
 ============================================================================
 Name        : bubble_sort.c
 Author      : Guillaume Bernard
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE_ARRAY 15

/*!
 *
 * \brief display the values to array [] of size
 *
 * \param[in] array : the array of values
 * \param[in] size  : the size of the array
 *
 */
void display(const uint32_t array[], uint32_t size)
{
	uint32_t index = 0;

	for(index = 0; index < size; index ++)
		printf(" %d ", array[index]);
}


/*!
 * \brief swap the values at indexa and indexb in the array
 *
 * \param[inout] array : the array of values
 * \param[in] indexa : the first value to swap
 * \param[in] indexb : the second value to swap
 */
void swap(uint32_t array[], const uint32_t indexa, const uint32_t indexb)
{
	uint32_t temp = array[indexa];
	array[indexa] = array[indexb];
	array[indexb] = temp;
}

/*!
 * \brief implementation of the selection sort algorithm
 *
 * \param[in] array : the array of values
 * \param[in] size : the size of the array
 */
void selection_sort(uint32_t array[], const uint32_t size)
{
	uint32_t index = 0;
	uint32_t sub_index = 0;

	/* we go through the whole array */
	for(index = 0 ; index < (size-1); index ++)
	{
		uint32_t minimum_value = array[index];
		uint32_t index_minimum_value = index;

		/* we research the smallest element from the index till the end of the array */
		for(sub_index = (index+1); sub_index < size; sub_index ++)
		{
			/* if the element is smaller, we save his data (value/position) */
			if(array[sub_index] < minimum_value)
			{
				minimum_value = array[sub_index];
				index_minimum_value = sub_index;
			}
		}

		/* we swap the index we the index of the minimum value found) */
		swap(array, index, index_minimum_value);
	}
}

/*!
 * \brief implementation of the bubble sort algorithm
 *
 * \param[in] array : the array of values
 * \param[in] size : the size of the array
 */
void bubble_sort(uint32_t array[], const uint32_t size)
{
	uint8_t issorted = 1;
	uint32_t index = 0;

	do
	{
		issorted = 1;
		for(index = 0; index < (size-1); index++)
		{
			if(array[index] > array[index+1])
			{
				swap(array, index, index+1);
				issorted = 0;
			}

		}
	}
	while(issorted == 0);
}

uint32_t partition(uint32_t array[], const int32_t start, int32_t end)
{
	/* we take the last element of the array as pivot */
	int32_t index_pivot = end;
	int32_t index_current = start;
	int32_t index_smallest = start-1;

	/* we go through the array till the pivot */
	for(index_current = start; index_current <= (end -1); index_current ++)
	{
		if(array[index_current] <= array[index_pivot])
		{
			index_smallest++;
			swap(array, index_current, index_smallest);
		}
	}

	swap(array, index_smallest +1, index_pivot);

	return (index_smallest+1);
}

void quick_sort(uint32_t array[], const int32_t start, const int32_t end)
{
	if(start < end)
	{
		int32_t partition_index = partition(array, start, end);


		quick_sort(array, partition_index +1, end);
		quick_sort(array, start, partition_index - 1);
	}
}

int main(void) {
	puts("values of the array (before sorting)"); /* prints !!!Hello World!!! */
	uint32_t array_values[SIZE_ARRAY] = {15,25,3,15,87,0,102,64,85,96,74,85,65,12,95};

	display(array_values, SIZE_ARRAY);

	//selection_sort(array_values, SIZE_ARRAY);

	quick_sort(array_values, 0, SIZE_ARRAY-1);

	puts("values of the array (after sorting)");

	display(array_values, SIZE_ARRAY);

	return EXIT_SUCCESS;
}
