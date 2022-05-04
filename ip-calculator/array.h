#pragma once
#include "includes.h"

typedef struct
{
	int length;
	void **items;
} array_t;

typedef struct
{
	int length;
	network_t **items;
} narray_t;

void init_array(array_t *array);

void array_append(array_t* array, void *element);

void array_append_multiple(array_t *array, int element_count, ...);

void init_narray(narray_t *array);

void narray_append(narray_t *array, network_t *network);
