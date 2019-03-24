#include "pch.h"
#include "ClientNetwork.h"

#pragma warning(disable : 4996)
ClientNetwork::ClientNetwork()
{
}


ClientNetwork::~ClientNetwork()
{
}
int ClientNetwork::recvn(SOCKET s, char* buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}
	return (len - left);
}
bool ClientNetwork::InitSock()
{
	WSADATA wsaData;
	// 윈속 버전을 2.2로 초기화
	int retval = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (retval != 0) 
	{
		return false;
	}

	// TCP 소켓 생성	
	Sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (Sock == INVALID_SOCKET)
	{
		return false;
	}

	return true;
}
bool ClientNetwork::Connect(const char*, int)
{
	// 접속할 서버 정보를 저장할 구조체
	SOCKADDR_IN stServerAddr;

	stServerAddr.sin_family = AF_INET;
	// 접속할 서버 포트 및 IP
	stServerAddr.sin_port = htons(SERVERPROT);
	stServerAddr.sin_addr.s_addr = inet_addr(SERVERIP);

	int nRet = connect(Sock, (sockaddr*)&stServerAddr, sizeof(sockaddr));
	if (nRet == SOCKET_ERROR) 
	{
		return false;
	}

	return true;
}
void ClientNetwork::err_display(const char * msg)
{
	LPVOID lpMsgBuf;
	FormatMessage
	(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL
	);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

void ClientNetwork::err_quit(const char * msg)
{
	LPVOID lpMsgBuf;
	FormatMessage
	(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL
	);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}
