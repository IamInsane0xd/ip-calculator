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

void parse_mask_string(char *mask_string, mask_t *out)
{
	int octet_1, octet_2, octet_3, octet_4;
	sscanf_s(mask_string, "%i.%i.%i.%i", &octet_1, &octet_2, &octet_3, &octet_4);
	create_mask(out, octet_1, octet_2, octet_3, octet_4);
}

char *int_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * INT_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * INT_MASK_STRING_LENGTH, "%i.%i.%i.%i", mask.int_octet_1, mask.int_octet_2, mask.int_octet_3, mask.int_octet_4);
	return str;
}

char *bin_mask_to_string(mask_t mask)
{
	char *str = malloc(sizeof(char) * BIN_MASK_STRING_LENGTH);
	sprintf_s(str, sizeof(char) * BIN_MASK_STRING_LENGTH, "%s.%s.%s.%s", mask.bin_octet_1, mask.bin_octet_2, mask.bin_octet_3, mask.bin_octet_4);
	return str;
}

char *mask_get_int_octet(mask_t mask, int index)
{
	char *octet_string = malloc(sizeof(char) * (INT_OCTET_LENGTH + 1));

	switch (index)
	{
	case 0:
		sprintf_s(octet_string, sizeof(char) * (INT_OCTET_LENGTH + 1), "%u", mask.int_octet_1);
		break;

	case 1:
		sprintf_s(octet_string, sizeof(char) * (INT_OCTET_LENGTH + 1), "%u", mask.int_octet_2);
		break;

	case 2:
		sprintf_s(octet_string, sizeof(char) * (INT_OCTET_LENGTH + 1), "%u", mask.int_octet_3);
		break;

	case 3:
		sprintf_s(octet_string, sizeof(char) * (INT_OCTET_LENGTH + 1), "%u", mask.int_octet_4);
		break;

	default:
		octet_string = "###";
	}

	return octet_string;
}

char *mask_get_bin_octet(mask_t mask, int index)
{
	char *octet_string = malloc(sizeof(char) * (BIN_OCTET_LENGTH + 1));

	switch (index)
	{
	case 0:
		octet_string = mask.bin_octet_1;
		break;

	case 1:
		octet_string = mask.bin_octet_2;
		break;

	case 2:
		octet_string = mask.bin_octet_3;
		break;

	case 3:
		octet_string = mask.bin_octet_4;
		break;

	default:
		octet_string = "########";
	}

	return octet_string;
}
