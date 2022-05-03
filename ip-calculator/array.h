#pragma once

typedef struct
{
	int length;
	void** items;
} array_t;

void init_array(array_t *array);

void array_append(array_t* array, void* element);

void array_swap(array_t *array, void *element, int index);
