#pragma once
#include"pch.h"


// 소켓 통신 구조체
struct SOCKETIONFO
{
	WSAOVERLAPPED	overlapped;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[SOCKET_BUF_SIZE];
	int				recvBytes;
	int				sendBytes;
};



class ClientNetwork : public singletonBase <ClientNetwork>
{
private:
	SOCKET	Sock;				// 서버와 연결할 소켓	

public:
	ClientNetwork();
	~ClientNetwork();

public:
	int nTotalSockets = 0;
	SOCKETIONFO* SocketInfoArray[WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT EventArray[WSA_MAXIMUM_WAIT_EVENTS];
	CRITICAL_SECTION cs;

	//비동기 입출력 처리 함수
	DWORD WINAPI WorkerThread(LPVOID arg);
	//소켓 관리 함수
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(int nIndex);


	bool InitSock();
	bool Connect(const char*, int);
	//오류 출력 함수
	void err_quit(const char* msg);
	void err_display(const char* msg);
	int recvn(SOCKET s, char* buf, int len, int flags);

private:
	static ClientNetwork* Instance;
public:
	static ClientNetwork* GetInstance()
	{
		if (NULL == Instance)
			Instance = new ClientNetwork();
		return Instance;
	}
};

