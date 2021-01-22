#pragma once
#ifndef Guid_h__
#define Guid_h__
#include "PublicExport.h"

#include <string>
#include <stdio.h>

#ifdef WIN32
#include <objbase.h>
#else
#include <uuid/uuid.h>

typedef struct _GUID
{
	unsigned long Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
} GUID, UUID;
#endif

//����ʱ��WIN32������ole32, Linux������libuuid
class PUBLIC_EXPORT CGuid
{
public:
	~CGuid(void);
public:

	/**
	 * @fn       GenerateGuid()   
	 * @brief    ����Guid   
	 * @param    NULL
	 * @return   NULL
	*/
	static CGuid GenerateGuid();
	/**
	 * @fn       toString()   
	 * @brief    ת��Ϊ�ַ���  
	 * @param    NULL
	 * @return   std::string
	*/
	std::string toString();
private:
	CGuid(void);
	GUID m_nGuid;
};
#endif // Guid_h__
