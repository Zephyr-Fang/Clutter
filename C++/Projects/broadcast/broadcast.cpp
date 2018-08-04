// broadcast.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <winsock2.h>  
#include <windows.h>

const bool issend = false;    // 设置为发送
const bool isrecieve = !issend;    // 设置为接收

// 解析socket中的一些符号，否则提示错误
#pragma comment(lib,"ws2_32.lib")

int main()
{
	SOCKET sendSock, revSock;    // 建立发送套接字和接收套接字
	sockaddr_in addrto, from, rev;    // 发送端发送地址，接收端收到的发送地址，接收端地址
	// 启动SOCKET库，版本为2.0  
	WSADATA wsdata;
	WSAStartup(0x0202, &wsdata);
	
	char *smsg = "this is a test";    // 广播内容字符串
	// 用UDP初始化接收端套接字  
	revSock = socket(AF_INET, SOCK_DGRAM, 0);
	// 用UDP初始化发送端套接字
	//sendSock = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)；
	sendSock = socket(AF_INET, SOCK_DGRAM, 0);
	// 然后赋值给地址，用来从网络上的广播地址接收消息；  
	addrto.sin_family = AF_INET;
	addrto.sin_addr.s_addr = INADDR_BROADCAST;
	addrto.sin_port = htons(9000);
	rev.sin_family = AF_INET;
	rev.sin_addr.s_addr = 0;
	rev.sin_port = htons(12811);
	from.sin_family = AF_INET;
	from.sin_addr.s_addr = INADDR_BROADCAST;
	from.sin_port = htons(9000);
	bool opt = true;
	//设置该套接字为广播类型
	setsockopt(sendSock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));
	setsockopt(revSock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));
	int nlen = sizeof(addrto);    //发送端ip地址的长度
	int fromlength = sizeof(SOCKADDR);    //接收端收到的广播地址的长度
	while (issend)
	{
		Sleep(1000);
		//从广播地址发送消息  
		int ret = sendto(sendSock, smsg, 256, 0, (sockaddr*)&addrto, nlen);
		if (ret == SOCKET_ERROR)
			printf("%d\n", WSAGetLastError());
		else
			printf("It'sock OK, broadcast sending...\n");
	}
	// 把接收套接字绑定在一个 rev 地址上  
	int err = bind(revSock, (sockaddr *)&rev, sizeof(sockaddr_in));
	if (err = SOCKET_ERROR) {
		err = WSAGetLastError();
		printf("\"bind\" error! error code is %d\n", err);
		return -1;
	}
	char buf[256];
	while (isrecieve)
	{
		Sleep(2000);
		//从广播地址 (from) 接收消息，注意用来绑定的地址和接收消息的地址是不一样的  
		int nSendSize = recvfrom(revSock, buf, 256, 0, (sockaddr*)&from, &fromlength);
		if (nSendSize == SOCKET_ERROR)
			printf("Can't recieve broadcast: %d\n", WSAGetLastError());
		else {
			buf[nSendSize] = '\0';
			printf("Recieve broadcast: %s\n", buf);
		}
	}
	return 0;
}