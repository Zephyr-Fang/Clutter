// broadcast.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <winsock2.h>  
#include <windows.h>

const bool issend = false;    // ����Ϊ����
const bool isrecieve = !issend;    // ����Ϊ����

// ����socket�е�һЩ���ţ�������ʾ����
#pragma comment(lib,"ws2_32.lib")

int main()
{
	SOCKET sendSock, revSock;    // ���������׽��ֺͽ����׽���
	sockaddr_in addrto, from, rev;    // ���Ͷ˷��͵�ַ�����ն��յ��ķ��͵�ַ�����ն˵�ַ
	// ����SOCKET�⣬�汾Ϊ2.0  
	WSADATA wsdata;
	WSAStartup(0x0202, &wsdata);
	
	char *smsg = "this is a test";    // �㲥�����ַ���
	// ��UDP��ʼ�����ն��׽���  
	revSock = socket(AF_INET, SOCK_DGRAM, 0);
	// ��UDP��ʼ�����Ͷ��׽���
	//sendSock = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)��
	sendSock = socket(AF_INET, SOCK_DGRAM, 0);
	// Ȼ��ֵ����ַ�������������ϵĹ㲥��ַ������Ϣ��  
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
	//���ø��׽���Ϊ�㲥����
	setsockopt(sendSock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));
	setsockopt(revSock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));
	int nlen = sizeof(addrto);    //���Ͷ�ip��ַ�ĳ���
	int fromlength = sizeof(SOCKADDR);    //���ն��յ��Ĺ㲥��ַ�ĳ���
	while (issend)
	{
		Sleep(1000);
		//�ӹ㲥��ַ������Ϣ  
		int ret = sendto(sendSock, smsg, 256, 0, (sockaddr*)&addrto, nlen);
		if (ret == SOCKET_ERROR)
			printf("%d\n", WSAGetLastError());
		else
			printf("It'sock OK, broadcast sending...\n");
	}
	// �ѽ����׽��ְ���һ�� rev ��ַ��  
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
		//�ӹ㲥��ַ (from) ������Ϣ��ע�������󶨵ĵ�ַ�ͽ�����Ϣ�ĵ�ַ�ǲ�һ����  
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