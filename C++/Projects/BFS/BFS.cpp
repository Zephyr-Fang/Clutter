// BFS.cpp : �������̨Ӧ�ó������ڵ㡣
// ��Ҫ�Ľ����� �������ܵ��ĸ���һ�㶼��ѭ��д����Ҫ�ġ�

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void input(vector<vector<int>>& matrix);
int maxAreaOfIsland(vector<vector<int>>& grid);
void maxAresBFS(vector<vector<int>>& grid, vector<int>& pos, int& curCnt);

int main()
{
	vector<vector<int>> grid;
	int res = 0;
	input(grid);
	cout << "���ĵ������Ϊ��" << maxAreaOfIsland(grid) << endl;//������
	return 0;
}

void input(vector<vector<int>>& matrix) {
	cout << "�������������ո��������س����У���" ;
	int row, col;
	cin >> row >> col;
	cout << "��������󣨿ո�ָ����س����У���" << endl;;
	for (int i = 0;i < row;i++) {
		matrix.push_back(vector<int>());
		for (int j = 0;j < col;j++) {
			int tmp;
			cin >> tmp;
			matrix[i].push_back(tmp);
		}
	}
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int row = grid.size(), col = grid[0].size();
	int maxCnt = 0, curCnt = 0;
	for (int i = 0;i<row;i++) {
		for (int j = 0;j<col;j++) {
			if (grid[i][j] == 1) {
				vector<int> pos{ i,j };//��¼��ǰλ��
				maxAresBFS(grid, pos, curCnt);
				maxCnt = curCnt>maxCnt ? curCnt : maxCnt;
				curCnt = 0;
			}
		}
	}
	return maxCnt;
}

void maxAresBFS(vector<vector<int>>& grid, vector<int>& pos, int& curCnt) {
	queue<vector<int>> qIsland;
	qIsland.push(pos);//ѹ���һ��Ԫ��
	grid[pos[0]][pos[1]] = 0;//��λ����0����ֹ���α���
	while (!qIsland.empty()) {
		//ÿһ��ѭ���ȴӶ����ų�һ��Ԫ�أ�λ�ã�����+1�����ô�ֵ��0��������Χ4��λ�ã��ھ���߽��ڣ����Ϊ1������У�����Ϊ��ʱ�˳�
		pos = qIsland.front();
		qIsland.pop();
		++curCnt;//����
		//������Ϊ1�����ڲ��������
		if (pos[1]>0 && grid[pos[0]][pos[1] - 1] == 1) {
			qIsland.push({ pos[0] , pos[1] - 1 });
			grid[pos[0]][pos[1] - 1] = 0;//ѹ������0��������ܻ��ظ�������
		}
		//�ұ����Ϊ1�����ڲ��������
		if (pos[1]<grid[0].size() - 1 && grid[pos[0]][pos[1] + 1] == 1) {
			qIsland.push({ pos[0] , pos[1] + 1 });
			grid[pos[0]][pos[1] + 1] = 0;
		}
		//�ϱ����Ϊ1�����ڲ��������
		if (pos[0]>0 && grid[pos[0] - 1][pos[1]] == 1) {
			qIsland.push({ pos[0] - 1 , pos[1] });
			grid[pos[0] - 1][pos[1]] = 0;
		}
		//�±����Ϊ1�����ڲ��������
		if (pos[0]<grid.size() - 1 && grid[pos[0] + 1][pos[1]] == 1) {
			qIsland.push({ pos[0] + 1 , pos[1] });
			grid[pos[0] + 1][pos[1]] = 0;
		}
	}
}



