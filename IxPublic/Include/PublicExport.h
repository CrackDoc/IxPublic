#pragma once
#ifndef PublicExport_h__
#define PublicExport_h__

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
#endif // PublicExport_h__