#include <stdlib.h>

#include "array.h"

void init_array(array_t *array)
{
	array->length = 0;
}

void array_append(array_t *array, void *element)
{
	if (array->length == 0)
	{
		array->items = malloc(sizeof(element));
		array->items[array->length++] = element;
		return;
	}

	int size = 0;

	for (int i = 0; i < array->length; i++)
		size += sizeof(array->items[i]);

	array->items = realloc(array->items, size + sizeof(element));
	array->items[array->length++] = element;
}

void array_swap(array_t *array, void *element, int index)
{
	array->items[index] = element;
}
