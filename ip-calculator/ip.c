#include "includes.h"

void create_ip(ip_t *ip, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4)
{
	ip->octet_1 = octet_1;
	ip->octet_2 = octet_2;
	ip->octet_3 = octet_3;
	ip->octet_4 = octet_4;
}

void parse_ip_string(ip_t *ip, char *ip_string)
{
	unsigned int octet_1, octet_2, octet_3, octet_4;
	sscanf_s(ip_string, "%u.%u.%u.%u", &octet_1, &octet_2, &octet_3, &octet_4);
	create_ip(ip, octet_1, octet_2, octet_3, octet_4);
}

char *ip_to_string(ip_t ip)
{
	char *ip_string = malloc(sizeof(char) * IP_STRING_LENGTH);
	sprintf_s(ip_string, sizeof(char) * IP_STRING_LENGTH, "%i.%i.%i.%i", ip.octet_1, ip.octet_2, ip.octet_3, ip.octet_4);
	return ip_string;
}
