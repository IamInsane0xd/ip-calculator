#include "includes.h"

/* 
*  table layout :
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  | network name | addr count | network | first assign. | broadcast | .mask | /mask |
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  | lan_1        | 128        | .0      | .1            | .127      | .128  | /25   |
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  ...
*/

void print_table(int row_count, char *rows[MAX_NETWORK_COUNT * 7])
{
	int i;
	
	printf(TABLE_ROW_SEPARATOR);
	printf(TABLE_HEADER_ROW);
	printf(TABLE_ROW_SEPARATOR);
	
	for (i = 0; i < row_count * 7; i += 7)
	{
		printf(TABLE_ROW(rows[i], rows[i + 1], rows[i + 2], rows[i + 3], rows[i + 4], rows[i + 5], rows[i + 6]));
		printf(TABLE_ROW_SEPARATOR);
	}
}
