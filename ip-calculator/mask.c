#include "includes.h"

void create_mask(mask_t *mask, int octet_1, int octet_2, int octet_3, int octet_4)
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

char *int_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * 16);
	sprintf_s(str, sizeof(char) * 16, "%i.%i.%i.%i", mask.int_octet_1, mask.int_octet_2, mask.int_octet_3, mask.int_octet_4);
	return str;
}

char *bin_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * 36);
	sprintf_s(str, sizeof(char) * 36, "%s.%s.%s.%s", mask.bin_octet_1, mask.bin_octet_2, mask.bin_octet_3, mask.bin_octet_4);
	return str;
}
