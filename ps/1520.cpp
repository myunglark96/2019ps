#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
bool npath[500][500] = { false, };
int map[500][500];
int dfs(int sx, int sy, int lx, int ly);

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &map[i][j]);
		}
	}

	printf("%d", dfs(0, 0, n - 1, m - 1));
	
	return 0;
}

/*
int dfs(int sx, int sy, int lx, int ly){
	int cx = sx, cy = sy, count = 0;
	queue<pair<int,int>> way;
	way.push(make_pair(sx, sy));
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	
	while (!way.empty())
	{
		cx = way.front().first;
		cy = way.front().second;
		way.pop();
		for (int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx <= lx && ny >= 0 && ny <= ly && map[cx][cy] > map[nx][ny]) {
				way.push(make_pair(nx, ny));
			}
			if (nx == ly && ny == lx && map[cx][cy] > map[nx][ny]) {
				count++;
			}
		}
	}

	return count;
}
*/

int dfs(int sx, int sy, int lx, int ly) {
	int cx = sx, cy = sy, count = 0, cp = 0;
	stack<pair<int, int>> way;
	way.push(make_pair(sx, sy));
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	while (!way.empty())
	{
		cx = way.top().first;
		cy = way.top().second;
		way.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx <= lx && ny >= 0 && ny <= ly && map[cx][cy] > map[nx][ny] && !npath[nx][ny]) {
				way.push(make_pair(nx, ny));
				cp++;
			}

			if (nx == ly && ny == lx && map[cx][cy] > map[nx][ny]) {
				count++;
			}
		}
		if (cp == 0 && cx != ly && cy != lx) {
			npath[cx][cy] = true;
		}
		else {
			cp = 0;
		}
	}

	return count;
}
