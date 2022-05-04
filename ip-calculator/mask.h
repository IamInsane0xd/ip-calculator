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

void parse_mask_string(char *mask_string, mask_t *out);

void int_mask_to_string(mask_t mask, char *out);

void bin_mask_to_string(mask_t mask, char *out);

void mask_get_int_octet(mask_t mask, int index, char *out);

void mask_get_bin_octet(mask_t mask, int index, char *out);
