#include "PublicMarco.h"

bool GLOBALUtility::isHostLittleEndian()
{
	unsigned int num,*p;
	num = 0;
	p = &num;
	*(unsigned char *)p = 0xff;
	if (num == 0xff)
	{
		return true;
	}
	return false;
}
