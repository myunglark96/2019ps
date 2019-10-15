#include <iostream>
#include <set>
using namespace std;
int map[17][17];
int coun = 0;
int visited[17][17] = { 0, };
set<string> Arr;

struct pipe
{
	int x;
	int y;
	// 0 이면 가로 1 이면 세로 2이면 대각선
	int state;
};

void dfs(pipe node, int n) {
	if (node.x == n - 1 && node.y == n - 1 && map[n - 1][n - 1] == 0) {
		coun++;
		return;
	}


	if (node.state == 0) {
		if (map[node.y][node.x + 1] == 0 && node.x+1 < n && !visited[node.y][node.x + 1]) {
			visited[node.y][node.x + 1] = true;
			node.x++;
			dfs(node, n);
			node.x--;
			visited[node.y][node.x + 1] = false;
		}
		if (map[node.y + 1][node.x] == 0 && map[node.y][node.x + 1] == 0 && map[node.y + 1][node.x + 1] == 0 && node.x+1 < n && node.y+1 < n && !visited[node.y + 1][node.x + 1]) {
			visited[node.y + 1][node.x + 1] = true;
			node.x++;
			node.y++;
			node.state = 2;
			dfs(node, n);
			node.x--;
			node.y--;
			visited[node.y + 1][node.x + 1] = false;
			node.state = 0;
		}
	}
	else if (node.state == 1) {
		if (map[node.y+1][node.x] == 0 && node.y+1 < n && !visited[node.y + 1][node.x]) {
			visited[node.y + 1][node.x] = true;
			node.y++;
			dfs(node, n);
			node.y--;
			visited[node.y + 1][node.x] = false;
		}
		if (map[node.y + 1][node.x] == 0 && map[node.y][node.x + 1] == 0 && map[node.y + 1][node.x + 1] == 0 && node.x + 1 < n && node.y + 1 < n && !visited[node.y + 1][node.x + 1]) {
			visited[node.y + 1][node.x + 1] = true;
			node.x++;
			node.y++;
			node.state = 2;
			dfs(node, n);
			node.x--;
			node.y--;
			node.state = 1;
			visited[node.y + 1][node.x + 1] = false;
		}
	}
	else if(node.state == 2){
		if (map[node.y + 1][node.x] == 0 && node.y + 1 < n && !visited[node.y + 1][node.x]) {
			visited[node.y + 1][node.x] = true;
			node.y++;
			node.state = 1;
			dfs(node, n);
			node.y--;
			node.state = 2;
			visited[node.y + 1][node.x] = false;
		}
		if (map[node.y][node.x + 1] == 0 && node.x + 1 < n && !visited[node.y][node.x + 1]) {
			visited[node.y][node.x + 1] = true;
			node.x++;
			node.state = 0;
			dfs(node, n);
			node.x--;
			node.state = 2;
			visited[node.y][node.x + 1] = false;
		}
		if (map[node.y + 1][node.x] == 0 && map[node.y][node.x + 1] == 0 && map[node.y + 1][node.x + 1] == 0 && node.x + 1 < n && node.y + 1 < n && !visited[node.y + 1][node.x + 1]) {
			visited[node.y + 1][node.x + 1] = true;
			node.x++;
			node.y++;
			node.state = 2;
			dfs(node, n);
			node.x--;
			node.y--;
			visited[node.y + 1][node.x + 1] = false;
		}
	}
}

int main() {
	pipe s;
	s.x = 1;
	s.y = 0;
	s.state = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
		}
	}
	visited[0][1] = true;
	dfs(s, n);

	cout << coun;
	return 0;
}




