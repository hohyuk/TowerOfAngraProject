#pragma once
#include"pch.h"
// 멀티바이트 집합 사용시 define
#define _WINSOCK_DEPRECATED_NO_WARNINGS

// DB정보
// DBconnector 클래스랑 연결
#define DB_ADDRESS		"localhost"
#define DB_PORT			 3306
#define DB_ID			"root"
#define DB_PASSWORD		"rhrnak"
#define DB_TITLE		"graduation"

// IOCP 소켓 구조체
struct SOCKETINFO
{
	WSAOVERLAPPED	overlapped;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[SOCKET_BUF_SIZE +1];
	int				recvBytes;
	int				sendBytes;
};

class Server : public singletonBase<Server>
{
private:
	SOCKETINFO *	SocketInfo;		// 소켓 정보
	SOCKET			Sock;	// 서버 리슨 소켓
	HANDLE			Handle;			// IOCP 객체 핸들
	bool			Accept;		// 요청 동작 플래그
	bool			WorkerThread;	// 작업 스레드 동작 플래그
	HANDLE *		WorkerHandle;	// 작업 스레드 핸들		
	int				ThreadCount;

public:
	void err_display(const char* msg);
	void err_quit(const char* msg);
	int recvn(SOCKET s, char* buf, int len, int flags);
	bool initialize();
	void startServer();
	Server();
	~Server();
};

