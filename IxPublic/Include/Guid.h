#pragma once
#ifndef Guid_h__
#define Guid_h__
#include "PublicExport.h"
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
class IxPublic_EXPORT CGuid
{
public:
	CGuid(void);
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
	const char* toString();
	/**
	 * @fn       operator=
	 * @author   Crack
	 * @brief       
	 * @date     2021/5/8 14:03
	 * @param    
	 * @return   
	*/
	CGuid& operator=(const CGuid& other);

	/**
	 * @fn       brief
	 * @author   Crack
	 * @brief       
	 * @date     2021/5/8 14:05
	 * @param    
	 * @return   
	*/
	GUID GetGUID() const;
private:
	mutable GUID m_nGuid;
};
#endif // Guid_h__
