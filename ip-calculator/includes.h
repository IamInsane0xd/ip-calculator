#pragma once

// std stuff
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

// string
#include <string.h>

// consts
#define MAX_NETWORK_NAME_LENGTH 12
#define IP_STRING_LENGTH 16
#define INT_MASK_STRING_LENGTH 16
#define BIN_MASK_STRING_LENGTH 36
#define MAX_INDIVIDUAL_HOST_COUNT 126
#define MAX_HOST_COUNT 256
#define MAX_NETWORK_COUNT 64
#define INT_OCTET_LENGTH 3
#define BIN_OCTET_LENGTH 8

// macros
#define I(x) int_to_binary(x)
#define B(x) binary_to_int(#x)
#define TABLE_ROW_SEPARATOR "+--------------+-------------+---------+---------------+-----------+-------+-------+\n"
#define TABLE_ROW(x1, x2, x3, x4, x5, x6, x7) "| %-12s | %-11s | %-7s | %-13s | %-9s | %-5s | %-5s |\n", x1, x2, x3, x4, x5, x6, x7
#define TABLE_HEADER_ROW TABLE_ROW("network name", "addr. count", "network", "first assign.", "broadcast", ".mask", "/mask")

// math
#include <math.h>

// network
#include "ip.h"
#include "mask.h"
#include "network.h"

// utils
#include "array.h"
#include "utils.h"
#include "table.h"
