// Server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <WinSock2.h>  
#include <stdio.h>  
#include <iostream>   
using namespace std;

#pragma comment(lib, "ws2_32.lib")   

#define GET_HOST_COMMAND "GetIPAddr"
const int MAX_BUF_LEN = 255;
#define SERVER_PORT 12811   

//ֻ����һ��ip��ַ
bool GetLocalIP(char* ip)
{
	//1.��ʼ��wsa  
	WSADATA wsaData;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (ret != 0)
	{
		return false;
	}
	//2.��ȡ������  
	char hostname[256];
	ret = gethostname(hostname, sizeof(hostname));
	if (ret == SOCKET_ERROR)
	{
		return false;
	}
	//3.��ȡ����ip  
	HOSTENT* host = gethostbyname(hostname);
	if (host == NULL)
	{
		return false;
	}
	//4.ת��Ϊchar*����������  
	strcpy(ip, inet_ntoa(*(in_addr*)*host->h_addr_list));
	return true;
}

bool doServer() {
	int m_nPort = SERVER_PORT;

	SOCKET sClient;
	sockaddr_in clientAddr, bindAddr;
	WSADATA wsdata;

	//����SOCKET�⣬�汾Ϊ2.0
	WORD    wVer = MAKEWORD(2, 0);
	if (0 != WSAStartup(wVer, &wsdata))
	{
		//AfxMessageBox(L"Not Support Socket2.0");
		return false;
	}

	//��UDP��ʼ���׽���
	sClient = socket(AF_INET, SOCK_DGRAM, 0);
	//���ø��׽���Ϊ�㲥���ͣ�
	BOOL optval = TRUE;
	bindAddr.sin_family = AF_INET;
	bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bindAddr.sin_port = htons(m_nPort);
	setsockopt(sClient, SOL_SOCKET, SO_BROADCAST, (char FAR *)&optval, sizeof(optval));
	bind(sClient, (sockaddr *)&bindAddr, sizeof(sockaddr_in));

	int nAddrLen = sizeof(SOCKADDR);
	char buf[256] = { 0 };
	int fromlength = sizeof(SOCKADDR);
	printf("the server is start.\n");

	char ipaddr[30] = { 0 };

	char buff[MAX_BUF_LEN] = "";
	if (GetLocalIP(ipaddr))
	{
		sprintf(buff, "my ip is:%s", ipaddr);
	}
	else
	{
		sprintf(buff, "%s", "my ip is:******");
	}

	//�ж��ip��ַ��ʱ����������
	//IPInfo ips[10];
	//int len1 = 0;
	//GetLocalIPs(ips, 10,&len1);

	while (true)
	{
		int nRet = recvfrom(sClient, buf, 256, 0, (struct sockaddr FAR *)&clientAddr, (int FAR *)&fromlength);
		if (SOCKET_ERROR != nRet)
		{
			char    *pIPAddr = inet_ntoa(clientAddr.sin_addr);
			if (NULL != pIPAddr)
			{
				WCHAR    wzIPBuffer[32] = { 0 };
				printf("clientAddr: %s\n", pIPAddr);
				printf("receive command: %s\n", buf);
			}
			if (strcmp(buf, GET_HOST_COMMAND) != 0)
			{
				printf("the command not valid and was ignored %s.\n", buf);
				continue;
			}
			// ��������   
			int nSendSize = sendto(sClient, buff, strlen(buff), 0, (SOCKADDR*)&clientAddr, nAddrLen);
			if (SOCKET_ERROR == nSendSize)
			{
				int err = WSAGetLastError();
				printf("\"sendto\" error!, error code is %d\n", err);
				return false;
			}

		}
		else
		{
			//AfxMessageBox(L"Recv UDP Failed");
		}

		Sleep(1000);
	}

	closesocket(sClient);
	return true;
}

int main()
{
	if (!doServer())
	{
		printf("sever returned an error");
		return -1;
	}
	return 0;
}