#include "includes.h"

void create_ip(ip_t *ip, int octet_1, int octet_2, int octet_3, int octet_4)
{
	ip->octet_1 = octet_1;
	ip->octet_2 = octet_2;
	ip->octet_3 = octet_3;
	ip->octet_4 = octet_4;
}

char *ip_to_string(ip_t ip)
{
	char *ip_string = malloc(sizeof(char) * 16);
	sprintf_s(ip_string, sizeof(char) * 16, "%i.%i.%i.%i", ip.octet_1, ip.octet_2, ip.octet_3, ip.octet_4);
	return ip_string;
}
