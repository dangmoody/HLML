#pragma once

#ifndef WIN64_ASSERT
#ifdef _DEBUG
#define WIN64_ASSERT( x ) \
	do { \
		if ( !(x) ) { \
			u32 error = GetLastError(); \
			LPSTR msgbuf = NULL; \
			FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, \
							NULL, error, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), (LPSTR) &msgbuf, 0, NULL ); \
			printf( "WIN64: %s failed at %s:%d: %s", #x, __FILE__, __LINE__, msgbuf ); \
\
			LocalFree( msgbuf ); \
\
			assert( false ); \
		} \
	} while ( 0 )
#else // _DEBUG
#define WIN64_ASSERT( x ) UNUSED( x )
#endif // _DEBUG
#endif // WIN64_ASSERT