// BFS.cpp : 定义控制台应用程序的入口点。
// 需要改进的是 遍历四周的四个点一般都用循环写，需要改。

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
	cout << "最大的岛屿面积为：" << maxAreaOfIsland(grid) << endl;//输出结果
	return 0;
}

void input(vector<vector<int>>& matrix) {
	cout << "请输入行数（空格）列数（回车换行）：" ;
	int row, col;
	cin >> row >> col;
	cout << "请输入矩阵（空格分隔、回车换行）：" << endl;;
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
				vector<int> pos{ i,j };//记录当前位置
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
	qIsland.push(pos);//压入第一个元素
	grid[pos[0]][pos[1]] = 0;//将位置清0，防止二次遍历
	while (!qIsland.empty()) {
		//每一次循环先从队列排出一个元素（位置）计数+1，将该处值置0；遍历周围4个位置（在矩阵边界内）如果为1则入队列；队列为空时退出
		pos = qIsland.front();
		qIsland.pop();
		++curCnt;//计数
		//左边如果为1且在内部，入队列
		if (pos[1]>0 && grid[pos[0]][pos[1] - 1] == 1) {
			qIsland.push({ pos[0] , pos[1] - 1 });
			grid[pos[0]][pos[1] - 1] = 0;//压入后就请0，否则可能会重复遍历到
		}
		//右边如果为1且在内部，入队列
		if (pos[1]<grid[0].size() - 1 && grid[pos[0]][pos[1] + 1] == 1) {
			qIsland.push({ pos[0] , pos[1] + 1 });
			grid[pos[0]][pos[1] + 1] = 0;
		}
		//上边如果为1且在内部，入队列
		if (pos[0]>0 && grid[pos[0] - 1][pos[1]] == 1) {
			qIsland.push({ pos[0] - 1 , pos[1] });
			grid[pos[0] - 1][pos[1]] = 0;
		}
		//下边如果为1且在内部，入队列
		if (pos[0]<grid.size() - 1 && grid[pos[0] + 1][pos[1]] == 1) {
			qIsland.push({ pos[0] + 1 , pos[1] });
			grid[pos[0] + 1][pos[1]] = 0;
		}
	}
}



