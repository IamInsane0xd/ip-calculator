#include "includes.h"

void create_ip(ip_t *ip, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4)
{
	ip->octet_1 = octet_1;
	ip->octet_2 = octet_2;
	ip->octet_3 = octet_3;
	ip->octet_4 = octet_4;
}

void parse_ip_string(char *ip_string, ip_t *out)

{
	unsigned int octet_1, octet_2, octet_3, octet_4;
	sscanf_s(ip_string, "%u.%u.%u.%u", &octet_1, &octet_2, &octet_3, &octet_4);
	create_ip(out, octet_1, octet_2, octet_3, octet_4);
}

void ip_to_string(ip_t ip, char *out)
{
	char *ip_string = malloc(sizeof(char) * IP_STRING_LENGTH);
	sprintf_s(ip_string, sizeof(char) * IP_STRING_LENGTH, "%i.%i.%i.%i", ip.octet_1, ip.octet_2, ip.octet_3, ip.octet_4);
	out = ip_string;
}

void ip_get_octet(ip_t ip, int index, char *out)
{
	char *octet_string = malloc(sizeof(char) * INT_OCTET_LENGTH);

	switch (index)
	{
	case 1:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", ip.octet_1);
		break;
		
	case 2:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", ip.octet_2);
		break;

	case 3:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", ip.octet_3);
		break;

	case 4:
		sprintf_s(octet_string, sizeof(char) * INT_OCTET_LENGTH, "%u", ip.octet_4);
		break;

	default:
		octet_string = "###";
	}

	out = octet_string;
}
