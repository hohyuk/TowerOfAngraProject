#pragma once
#include"pch.h"


// ���� ��� ����ü
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
	SOCKET	Sock;				// ������ ������ ����	

public:
	ClientNetwork();
	~ClientNetwork();

public:
	int nTotalSockets = 0;
	SOCKETIONFO* SocketInfoArray[WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT EventArray[WSA_MAXIMUM_WAIT_EVENTS];
	CRITICAL_SECTION cs;

	//�񵿱� ����� ó�� �Լ�
	DWORD WINAPI WorkerThread(LPVOID arg);
	//���� ���� �Լ�
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(int nIndex);


	bool InitSock();
	bool Connect(const char*, int);
	//���� ��� �Լ�
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

