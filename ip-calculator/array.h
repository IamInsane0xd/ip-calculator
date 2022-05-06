#pragma once
#include "includes.h"

typedef struct
{
	int length;
	void **items;
} array_t;

void init_array(array_t *array);

void init_array_multiple(int array_count, ...);

void array_append(array_t* array, void *element);

void array_append_multiple(array_t *array, int element_count, ...);
