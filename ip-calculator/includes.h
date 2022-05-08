#pragma once

// std stuff
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

// string
#include <string.h>

// math
#include <math.h>

// assert
#include <assert.h>

// macros
#define I(x) int_to_binary(x)
#define B(x) binary_to_int(#x)
#define MAX_NETWORK_NAME_LENGTH 12
#define IP_STRING_LENGTH 16
#define INT_MASK_STRING_LENGTH 16
#define BIN_MASK_STRING_LENGTH 36
#define MAX_INDIVIDUAL_HOST_COUNT 126
#define MAX_HOST_COUNT 256
#define MAX_NETWORK_COUNT 64
#define INT_OCTET_LENGTH 3
#define BIN_OCTET_LENGTH 8
#define TABLE_ROW_SEPARATOR_NORMAL "+--------------+-------------+---------+---------------+-----------+-------+-------+\n"
#define TABLE_ROW_SEPARATOR_IP "+--------------+-------------+-----------------+-----------------+-----------------+-------+-------+\n"
#define TABLE_ROW_SEPARATOR_MASK "+--------------+-------------+---------+---------------+-----------+-----------------+-------+\n"
#define TABLE_ROW_SEPARATOR_IP_MASK "+--------------+-------------+-----------------+-----------------+-----------------+-----------------+-------+\n"
#define TABLE_HEADER_ROW_NORMAL "| network name | addr. count | network | first assign. | broadcast | .mask | /mask |\n"
#define TABLE_HEADER_ROW_IP "| network name | addr. count | network         | first assign.   | broadcast       | .mask | /mask |\n"
#define TABLE_HEADER_ROW_MASK "| network name | addr. count | network | first assign. | broadcast | .mask           | /mask |\n"
#define TABLE_HEADER_ROW_IP_MASK "| network name | addr. count | network         | first assign.   | broadcast       | .mask           | /mask |\n"
#define TABLE_ROW(x1, x2, x3, x4, x5, x6, x7, x1l, x2l, x3l, x4l, x5l, x6l, x7l, p1, p2)\
				"| %-*s | %-*s | %s%-*s | %s%-*s | %s%-*s | %s%-*s | /%-*s |\n", x1l, x1, x2l, x2, p1, x3l, x3, p1, x4l, x4, p1, x5l, x5, p2, x6l, x6, x7l, x7
#define TABLE_ROW_NORMAL(x1, x2, x3, x4, x5, x6, x7) TABLE_ROW(x1, x2, x3, x4, x5, x6, x7, 12, 11, 6, 12, 8, 4, 4, ".", ".")
#define TABLE_ROW_IP(x1, x2, x3, x4, x5, x6, x7) TABLE_ROW(x1, x2, x3, x4, x5, x6, x7, 12, 11, 15, 15, 15, 4, 4, "", ".")
#define TABLE_ROW_MASK(x1, x2, x3, x4, x5, x6, x7) TABLE_ROW(x1, x2, x3, x4, x5, x6, x7, 12, 11, 6, 12, 8, 15, 4, ".", "")
#define TABLE_ROW_IP_MASK(x1, x2, x3, x4, x5, x6, x7) TABLE_ROW(x1, x2, x3, x4, x5, x6, x7, 12, 11, 15, 15, 15, 15, 4, "", "")
#define MAX_MENU_OPTIONS_COUNT 8
#define MAX_MENU_OPTION_LENGTH 20
#define MAX_MENU_TITLE_LENGTH 17
#define MAX_OPTIONS_OPTION_COUNT 8

// network
#include "ip.h"
#include "mask.h"
#include "network.h"

// utils
#include "array.h"
#include "utils.h"
#include "table.h"

// menu
#include "options.h"
#include "menu.h"

// main
#include "main.h"

// globals
options_t OPTIONS;
