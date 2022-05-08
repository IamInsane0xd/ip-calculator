#pragma once
#include "includes.h"

typedef enum
{
	NORMAL,
	IP,
	MASK,
	BOTH,
} print_type_t;

void print_table(int row_count, char *rows[MAX_NETWORK_COUNT * 7], print_type_t print_type);
