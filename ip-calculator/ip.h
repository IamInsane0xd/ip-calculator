#pragma once
#include "includes.h"

typedef struct
{
	int octet_1;
	int octet_2;
	int octet_3;
	int octet_4;
} ip_t;

void create_ip(ip_t* ip, int octet_1, int octet_2, int octet_3, int octet_4);

void parse_ip_string(char *ip_string, ip_t *out);

void ip_to_string(ip_t ip, char *out);

char *ip_get_octet(ip_t ip, int index);
