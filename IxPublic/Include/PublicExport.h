#pragma once
#ifndef PublicExport_h__
#define PublicExport_h__

#if defined(WIN32)

#ifdef IxPublic_EXPORTS
#define PUBLIC_EXPORT __declspec(dllexport)
#else
#define  PUBLIC_EXPORT __declspec(dllimport)
#endif

#elif __linux__
#define PUBLIC_EXPORT

#else
#define PUBLIC_EXPORT 
#endif
#endif // PublicExport_h__