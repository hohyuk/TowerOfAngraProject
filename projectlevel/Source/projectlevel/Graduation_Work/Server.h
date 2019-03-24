#pragma once
#include"pch.h"
// ��Ƽ����Ʈ ���� ���� define
#define _WINSOCK_DEPRECATED_NO_WARNINGS

// DB����
// DBconnector Ŭ������ ����
#define DB_ADDRESS		"localhost"
#define DB_PORT			 3306
#define DB_ID			"root"
#define DB_PASSWORD		"rhrnak"
#define DB_TITLE		"graduation"

// IOCP ���� ����ü
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
	SOCKETINFO *	SocketInfo;		// ���� ����
	SOCKET			Sock;	// ���� ���� ����
	HANDLE			Handle;			// IOCP ��ü �ڵ�
	bool			Accept;		// ��û ���� �÷���
	bool			WorkerThread;	// �۾� ������ ���� �÷���
	HANDLE *		WorkerHandle;	// �۾� ������ �ڵ�		
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

