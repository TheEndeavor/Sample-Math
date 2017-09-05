// StdAfx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once



#ifndef WINDOWS
	#ifndef LINUX
		#ifndef MACINTOSH
			#ifdef WIN32
				#define NOMINMAX
				#define WINDOWS
			#elif LIN32
				#define LINUX
			#elif MAC32
				#define MACINTOSH
			#else
				#error System type undefined. Please compile for a supported architecture and operating system.
			#endif
		#endif
	#endif
#endif


#ifdef WINDOWS

	#ifdef _GLOBAL_USING
		#if _GLOBAL_USING
			#undef _GLOBAL_USING
			#define _GLOBAL_USING 0
		#endif // if _GLOBAL_USING
	#endif // ifdef _GLOBAL_USING
	

	//	Windows debugging information.
	#ifdef _DEBUG
		#include <vld.h>
	#endif
	
	//#define _CRT_SECURE_NO_WARNINGS
	
	#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
	#include <windows.h>
	#undef near
	#undef far
	
	

#elif LINUX
	#define __cdecl __attribute__((cdecl))
	#define __stdcall __attribute__((stdcall))
#endif

#include <stddef.h>
