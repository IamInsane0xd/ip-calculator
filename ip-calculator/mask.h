#pragma once
#include "includes.h"

typedef struct
{
	unsigned int int_octet_1;
	unsigned int int_octet_2;
	unsigned int int_octet_3;
	unsigned int int_octet_4;
	char *bin_octet_1;
	char *bin_octet_2;
	char *bin_octet_3;
	char *bin_octet_4;
} mask_t;

void create_mask(mask_t *mask, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4);

void parse_mask_string(mask_t *mask, char *mask_string);

// int mask to string converter
char *int_mask_to_string(mask_t mask);

// binary mask to string converter
char *bin_mask_to_string(mask_t mask);
