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
#define MAX_HOST_COUNT 126
#define INT_OCTET_LENGTH 3
#define BIN_OCTET_LENGTH 8

// macros
#define I(x) int_to_binary(x)
#define B(x) binary_to_int(#x)

// math
#include <math.h>

// network
#include "ip.h"
#include "mask.h"
#include "network.h"

// utils
#include "array.h"
#include "utils.h"
