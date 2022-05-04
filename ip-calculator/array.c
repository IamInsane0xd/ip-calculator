#include "includes.h"

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

	int size = 0, i;

	for (i = 0; i < array->length; i++)
		size += sizeof(array->items[i]);

	array->items = realloc(array->items, size + sizeof(element));
	array->items[array->length++] = element;
}

void array_append_multiple(array_t *array, int element_count, ...)
{
	va_list args;
	int i;

	va_start(args, element_count);

	for (i = 0; i < element_count; i++)
		array_append(array, va_arg(args, void *));
	
	va_end(args);
}

void init_narray(narray_t *array)
{
	array->length = 0;
}

void narray_append(narray_t *array, network_t *network)
{
	if (array->length == 0)
	{
		array->items = malloc(sizeof(network));
		array->items[array->length++] = network;
		return;
	}

	int size = sizeof(network) * array->length;

	array->items = realloc(array->items, size + sizeof(network));
	array->items[array->length++] = network;
}
