#include "includes.h"

// reverse string
void reverse_string(char *str)
{
	int i, j, n = strlen(str);
	char temp;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

// int to binary converter
char *int_to_binary(int num)
{
	int i, n = 0, rem, len = 0;
	char *bin = (char *) malloc(sizeof(char) * 32);

	while (num != 0)
	{
		rem = num % 2;
		num /= 2;
		bin[n++] = rem + '0';
	}

	for (i = 0; i < n; i++)
		len++;
	
	bin[n] = '\0';
	reverse_string(bin);

	return bin;
}

unsigned __int64 binary_to_int(const char *s)
{
	unsigned __int64 i = 0;

	while (*s)
	{
		i <<= 1;
		i += *s++ - '0';
	}

	return i;
}

// read line from stdin
void read_line(const char *prompt, const bool prompt_size_prefix, const bool start_with_newline, char *out, const size_t size)
{
	int ch, i = 0;
	bool has_typed = false;

	if (prompt_size_prefix)
		printf(start_with_newline ? "\n(%llu) %s" : "(%llu) %s", size, prompt);
	
	else
		printf(start_with_newline ? "\n%s" : "%s", prompt);

	while (!has_typed)
	{
		ch = getchar();
		
		if (ch != '\n')
		{
			has_typed = true;
			
			if (i < size)
				out[i++] = ch;
		}
	}
	
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if (i < size)
			out[i++] = ch;
	} 

	out[i] = '\0';
}
