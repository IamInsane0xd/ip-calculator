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

void parse_mask_string(char *mask_string, mask_t *out)
{
	unsigned int octet_1, octet_2, octet_3, octet_4;
	sscanf_s(mask_string, "%u.%u.%u.%u", &octet_1, &octet_2, &octet_3, &octet_4);
	create_mask(out, octet_1, octet_2, octet_3, octet_4);
}

void int_mask_to_string(mask_t mask, char *out)
{
	char *str = malloc(sizeof(char) * INT_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * INT_MASK_STRING_LENGTH, "%u.%u.%u.%u", mask.int_octet_1, mask.int_octet_2, mask.int_octet_3, mask.int_octet_4);
	out = str;
}

void bin_mask_to_string(mask_t mask, char *out)
{
	char *str = malloc(sizeof(char) * BIN_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * BIN_MASK_STRING_LENGTH, "%s.%s.%s.%s", mask.bin_octet_1, mask.bin_octet_2, mask.bin_octet_3, mask.bin_octet_4);
	out = str;
}

void mask_get_int_octet(mask_t mask, int index, char *out)
{
	char *octet_string = malloc(sizeof(char) * INT_OCTET_LENGTH);

	switch (index)
	{
	case 1:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", mask.int_octet_1);
		break;

	case 2:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", mask.int_octet_2);
		break;

	case 3:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", mask.int_octet_3);
		break;

	case 4:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", mask.int_octet_4);
		break;

	default:
		octet_string = "###";
	}

	out = octet_string;
}

void mask_get_bin_octet(mask_t mask, int index, char *out)
{
	char *octet_string = malloc(sizeof(char) * BIN_OCTET_LENGTH);

	switch (index)
	{
	case 1:
		octet_string = mask.bin_octet_1;
		break;

	case 2:
		octet_string = mask.bin_octet_2;
		break;

	case 3:
		octet_string = mask.bin_octet_3;
		break;

	case 4:
		octet_string = mask.bin_octet_4;
		break;

	default:
		octet_string = "########";
	}

	out = octet_string;
}
