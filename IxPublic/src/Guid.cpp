#include "Guid.h"
#include <string>

CGuid::CGuid(void)
{
	szGuid[64] = { 0 };

}
CGuid::~CGuid(void)
{

}
CGuid CGuid::GenerateGuid()
{
	CGuid nGuid;

#ifdef WIN32
	CoCreateGuid(&nGuid.m_nGuid);
#else
	uuid_generate(reinterpret_cast<unsigned char *>(&guid));
#endif
	return nGuid;
}


CGuid& CGuid::operator=(CGuid other)
{
	m_nGuid.Data1 = other.GetGUID().Data1;

	m_nGuid.Data2 = other.GetGUID().Data2;

	m_nGuid.Data3 = other.GetGUID().Data3;

	m_nGuid.Data4[0] = other.GetGUID().Data4[0];

	m_nGuid.Data4[1] = other.GetGUID().Data4[1];

	m_nGuid.Data4[2] = other.GetGUID().Data4[2];

	m_nGuid.Data4[3] = other.GetGUID().Data4[3];

	m_nGuid.Data4[4] = other.GetGUID().Data4[4];

	m_nGuid.Data4[5] = other.GetGUID().Data4[5];

	m_nGuid.Data4[6] = other.GetGUID().Data4[6];

	m_nGuid.Data4[7] = other.GetGUID().Data4[7];

	return *this;
}

GUID CGuid::GetGUID()
{
	return m_nGuid;
}

const char* CGuid::toString()
{
char buf[64] = { 0 };
#ifdef __GNUC__
	snprintf(
#else // MSVC
	_snprintf_s(
#endif
		buf,
		sizeof(buf),
		"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		m_nGuid.Data1, m_nGuid.Data2, m_nGuid.Data3, 
		m_nGuid.Data4[0], m_nGuid.Data4[1],
		m_nGuid.Data4[2], m_nGuid.Data4[3],
		m_nGuid.Data4[4], m_nGuid.Data4[5],
		m_nGuid.Data4[6], m_nGuid.Data4[7]);

	memset(szGuid, '\0', sizeof(char) * 64);

	strcat(szGuid, buf);
	return szGuid;
}
