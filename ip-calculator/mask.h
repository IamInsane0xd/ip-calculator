#pragma once
#include "includes.h"

typedef struct
{
	int int_octet_1;
	int int_octet_2;
	int int_octet_3;
	int int_octet_4;
	char *bin_octet_1;
	char *bin_octet_2;
	char *bin_octet_3;
	char *bin_octet_4;
} mask_t;

void create_mask(mask_t *mask, int octet_1, int octet_2, int octet_3, int octet_4);

// int mask to string converter
char *int_mask_to_string(mask_t mask);

// binary mask to string converter
char *bin_mask_to_string(mask_t mask);
