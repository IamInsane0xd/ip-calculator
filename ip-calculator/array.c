#include "includes.h"

void init_array(array_t *array)
{
	array->length = 0;
}

void init_array_multiple(int array_count, ...)
{
	va_list args;
	int i;

	va_start(args, array_count);
	
	for (i = 0; i < array_count; i++)
	{
		array_t *array = va_arg(args, array_t *);
		init_array(array);
	}
	
	va_end(args);
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
