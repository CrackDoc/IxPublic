#pragma once
#ifndef IxPublicExport_h__
#define IxPublicExport_h__

#if defined(WIN32)

#ifdef IxPublic_EXPORTS
#define IxPublic_EXPORT __declspec(dllexport)
#else
#define  IxPublic_EXPORT __declspec(dllimport)
#endif

#elif __linux__
#define IxPublic_EXPORT

#else
#define IxPublic_EXPORT 
#endif
#endif // IxPublicExport_h__