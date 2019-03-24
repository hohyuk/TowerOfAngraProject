#include "pch.h"
#include "Server.h"


Server::Server()
{
	Accept = true;
	WorkerThread = true;
}


Server::~Server()
{
}
//소켓 함수 오류 출력
void Server::err_quit(const char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

// 소켓 함수 오류 출력
void Server::err_display(const char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int Server::recvn(SOCKET s, char *buf, int len, int flags)
{
	int retval;
	char *ptr = buf;
	int  left = len;

	while (left > 0)
	{
		retval = recv(s, ptr, left, flags);

		if (retval == SOCKET_ERROR)
		{
			return SOCKET_ERROR;
		}

		else if (retval == 0)
		{
			break;
		}

		left -= retval;
		ptr += retval;
	}
	return (len - left);
}

bool Server::initialize()
{
	WSADATA wsaData;
	int retval;
	// winsock 2.2 버전으로 초기화
	retval = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (retval != 0)
	{
		printf_s(" 초기화 실패\n");
		return false;
	}
	// 소켓 생성
	Sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	if (Sock == INVALID_SOCKET)
	{
		printf_s("[ERROR] 소켓 생성 실패\n");
		return false;
	}
	// 서버 정보 설정
	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_port = htons(SERVERPROT);
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	// 소켓 설정
	retval = ::bind(Sock, (struct sockaddr*)&serverAddr, sizeof(SOCKADDR_IN));

	if (retval == SOCKET_ERROR)
	{
		err_quit("ERROR()");
	}
	// 수신 대기열 생성
	retval = listen(Sock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		err_quit("LISTEN()");
	}
	return true;
}

void Server::startServer()
{
	int retval;
	// 클라이언트 정보
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(SOCKADDR_IN);
	SOCKET clientSocket;
	DWORD recvBytes;
	DWORD flags;

	// Completion Port 객체 생성
	Handle = CreateIoCompletionPort
	(
		INVALID_HANDLE_VALUE,
		NULL,
		0,
		0
	);


	printf_s("[INFO] 서버 시작...\n");

	// 클라이언트 접속을 받음
	while (Accept)
	{
		printf("while() 문 들어옴\n");

		clientSocket = WSAAccept
		(
			Sock,
			(struct sockaddr *)&clientAddr,
			&addrLen,
			NULL,
			NULL
		);
		printf("Accept() 문 들어옴\n");
		if (clientSocket == INVALID_SOCKET)
		{
			printf_s("[ERROR] Accept 실패\n");
			return;
		}
		// 접속한 클라이언트 정보 출력
		printf("\n[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d\n",
			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

		SocketInfo = new SOCKETINFO();
		SocketInfo->socket = clientSocket;
		SocketInfo->recvBytes = 0;
		SocketInfo->sendBytes = 0;
		SocketInfo->dataBuf.len = SOCKET_BUF_SIZE;
		SocketInfo->dataBuf.buf = SocketInfo->messageBuffer;
		flags = 0;

		Handle = CreateIoCompletionPort
		(
			(HANDLE)clientSocket,
			Handle,
			(DWORD)SocketInfo,
			0
		);

		retval = WSARecv
		(
			SocketInfo->socket,
			&SocketInfo->dataBuf,
			1,
			&recvBytes,
			&flags,
			&(SocketInfo->overlapped),
			NULL
		);

		if (retval == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING)
		{
			printf_s("[ERROR] IO Pending 실패 : %d", WSAGetLastError());
			return;
		}
	}
}
