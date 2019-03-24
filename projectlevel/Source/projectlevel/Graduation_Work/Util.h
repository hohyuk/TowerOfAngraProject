#pragma once
#include"pch.h"
#include<atomic>


//Ŭ���� �̱��� define
#define CLOCK		       Clock::getSingleton()
#define SERVER		       Server::getSingleton()
//

//ũ�� ����
#define SIZE_8					8
#define SIZE_64					64
#define SIZE_128				128
#define SIZE_256				256

//

//Ÿ�� ����	

typedef std::time_t				tick_t;
typedef std::string				str_t;
typedef std::wstring			wstr_t;

//Socket
#define SOCKET_BUF_SIZE			1024 * 10
#define SERVERPROT				9000
#define SERVERIP				"127.0.0.1"

//
#define snprintf(dst, format, ...)				_snprintf_s(dst.data(), dst.size(), _TRUNCATE, format, __VA_ARGS__ )
#define snwprintf(dst, format, ...)				_snwprintf_s(dst.data(), dst.size(), _TRUNCATE, format, __VA_ARGS__ )


//for xml
//XML �ļ� ���
//DownLoad https://sourceforge.net/projects/tinyxml/
//���� : https://m.blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221014997196&proxyReferer=https%3A%2F%2Fwww.google.com%2F


typedef TiXmlDocument		xml_t;
typedef TiXmlElement		xmlNode_t;
typedef TiXmlHandle			xmlHandle_t;

//���ڿ� ��ȯ
//XMLŬ������
inline void StrConvA2T(CHAR* src, TCHAR* dest, size_t destLen)
{
#ifdef UNICODE
	if (destLen < 1)
	{
		return;
	}
	MultiByteToWideChar(CP_ACP, 0, src, -1, dest, (int)destLen - 1);
#endif
}

inline void StrConvT2A(TCHAR* src, CHAR* dest, size_t destLen)
{
#ifdef UNICODE
	if (destLen < 1)
	{
		return;
	}
	WideCharToMultiByte(CP_ACP, 0, src, -1, dest, (int)destLen, NULL, FALSE);
#endif
}

inline void StrConvA2W(CHAR* src, WCHAR* dest, size_t destLen)
{
	if (destLen < 1)
	{
		return;
	}
	MultiByteToWideChar(CP_ACP, 0, src, -1, dest, (int)destLen - 1);

}

inline void StrConvW2A(WCHAR* src, CHAR* dest, size_t destLen)
{
	if (destLen < 1)
	{
		return;
	}
	WideCharToMultiByte(CP_ACP, 0, src, -1, dest, (int)destLen, NULL, FALSE);

}


//delete object--------------------------
#undef  SAFE_DELETE

#define SAFE_DELETE(obj)			\
{									\
	if ((obj))						\
		delete(obj);				\
	(obj) = 0L;						\
}

#undef  SAFE_DELETE_ARRAY
#define  SAFE_DELETE_ARRAY(arr)		 \
{									 \
	if ((arr))						 \
		delete[](arr);				 \
	(arr) = 0L;						 \
}


#undef  SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(arr)	   \
{								   \
	if ((arr))					   \
		delete[](arr);			   \
	(arr) = 0L;					   \
}

#define SAFE_FREE(obj)			\
{							    \
	if ((obj))				    \
		obj->free();		    \
	(obj) = 0L;				    \
}

#define SAFE_RELEASE(obj)		\
{								\
	if (obj)					\
		obj.release();			\
}

