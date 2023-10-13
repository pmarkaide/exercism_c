#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
	int h = 0;
	int lhs_len =	strlen(lhs);
	int rhs_len =	strlen(rhs);

	if (lhs_len != rhs_len)
		return -1;
	
	while (*lhs)
	{
		if(*lhs != *rhs)
			h++;
		lhs++;
		rhs++;
	}
	return h;
}