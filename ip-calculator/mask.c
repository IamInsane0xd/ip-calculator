#include "includes.h"

void create_mask(mask_t *mask, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4)
{
	mask->int_octet_1 = octet_1;
	mask->int_octet_2 = octet_2;
	mask->int_octet_3 = octet_3;
	mask->int_octet_4 = octet_4;
	mask->bin_octet_1 = I(octet_1);
	mask->bin_octet_2 = I(octet_2);
	mask->bin_octet_3 = I(octet_3);
	mask->bin_octet_4 = I(octet_4);
}

void parse_mask_string(mask_t *mask, char *mask_string)
{
	unsigned int octet_1, octet_2, octet_3, octet_4;
	sscanf_s(mask_string, "%u.%u.%u.%u", &octet_1, &octet_2, &octet_3, &octet_4);
	create_mask(mask, octet_1, octet_2, octet_3, octet_4);
}

char *int_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * INT_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * INT_MASK_STRING_LENGTH, "%u.%u.%u.%u", mask.int_octet_1, mask.int_octet_2, mask.int_octet_3, mask.int_octet_4);
	return str;
}

char *bin_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * BIN_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * BIN_MASK_STRING_LENGTH, "%s.%s.%s.%s", mask.bin_octet_1, mask.bin_octet_2, mask.bin_octet_3, mask.bin_octet_4);
	return str;
}
