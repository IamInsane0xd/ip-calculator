#pragma once
#include "includes.h"

typedef struct
{
	unsigned int octet_1;
	unsigned int octet_2;
	unsigned int octet_3;
	unsigned int octet_4;
} ip_t;

void create_ip(ip_t* ip, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4);

void parse_ip_string(char *ip_string, ip_t *out);

void ip_to_string(ip_t ip, char *out);

void ip_get_octet(ip_t ip, int index, char *out);
