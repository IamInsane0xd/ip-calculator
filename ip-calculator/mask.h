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

void parse_mask_string(char *mask_string, mask_t *out);

void int_mask_to_string(mask_t mask, char *out);

void bin_mask_to_string(mask_t mask, char *out);

char *mask_get_int_octet(mask_t mask, int index);

char *mask_get_bin_octet(mask_t mask, int index);
