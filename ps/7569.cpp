#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[100][100][100] = { false, };
int tom[100][100][100];
int day[100][100][100] = { 0, };

struct bfs
{
	int x;
	int y;
	int z;
};

int main()
{
	bool nt = false;
	int m, n, h, count=0,d, max=0;
	cin >> m >> n >> h;
	bfs t, cn;
	queue<bfs> s;
	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> tom[k][j][i];
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (tom[k][j][i] == 1 && check[k][j][i] == false)
				{
					t.x = k;
					t.y = j;
					t.z = i;
					check[k][j][i] = true;
					s.push(t);
				}
			}
		}
	}
	
	while (!s.empty())
	{
		cn = s.front();
		s.pop();
		for (int l = 0; l < 6; l++)
		{
			d = day[cn.x][cn.y][cn.z];
			bfs next;
			next.x = cn.x + dx[l];
			next.y = cn.y + dy[l];
			next.z = cn.z + dz[l];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && next.z >= 0 && next.z < h && check[next.x][next.y][next.z] == false && tom[next.x][next.y][next.z] != -1)
			{
				tom[next.x][next.y][next.z] = 1;
				s.push(next);
				check[next.x][next.y][next.z] = true;
				day[next.x][next.y][next.z] = d + 1;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (max < day[k][j][i])
				{
					max = day[k][j][i];
				}
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (tom[k][j][i] == 0)
				{
					nt = true;
				}
			}
		}

	}
	

	if (nt)
	{
		cout << -1;
	}
	else
	{
		cout << max;
	}
	return 0;
}