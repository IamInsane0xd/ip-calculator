#pragma once
#include "includes.h"

void reverse_string(char *str);

// int to binary converter
char *int_to_binary(int num);

// binary to int converter
unsigned __int64 binary_to_int(const char *s);

void read_line(const char *prompt, const bool prompt_size_prefix, const bool start_with_newline, char *out, const size_t size);
