#include <iostream>
#include <stack>
using namespace std;
char grid[100][100];
bool check[100][100] = { false, };


void dfs(int x, int y)
{
	stack<pair<int, int>> s;
	s.push(make_pair(x, y));
	check[x][y] = true;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,-1,0,1 };
	int nx, ny;

	while (!s.empty())
	{
		pair<int, int> t;
		t = s.top();
		s.pop();
		nx = t.first;
		ny = t.second;
		for (int i = 0; i < 4; i++)
		{
			nx = t.first + dx[i];
			ny = t.second + dy[i];
			if (check[nx][ny] == false && nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && grid[nx][ny] == grid[t.first][t.second])
			{
				s.push(make_pair(nx, ny));
				check[nx][ny] = true;
			}
		}
	}
}

int main()
{
	int n, count = 0, count2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> grid[i];
	}

	//평범한 사람
	dfs(0, 0);
	count++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false)
			{
				dfs(i, j);
				count++;
			}
		}
	}

	cout << count << ' ';

	//적록색약 구역 만들기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 'G')
			{
				grid[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			check[i][j] = false;
		}
	}
	//적록색약 사람
	dfs(0, 0);
	count2++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false)
			{
				dfs(i, j);
				count2++;
			}
		}
	}

	cout << count2;
	
	return 0;
}