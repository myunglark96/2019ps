#include <iostream>
#include <vector>

using namespace std;
vector<int> f[51];
char map[51][51];

int main()
{
	int n, max=0,check=0;
	cin >> n;
	int r[51] = {0,};
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'Y')
			{
				f[i].push_back(j);
			}
			else
			{
				if (i != j)
				{
					for (int k = 0; k < n; k++)
					{
						if (map[k][j] == 'Y' && map[i][k] == 'Y')
						{
							f[i].push_back(j);
							break;
						}
					}
				}
				
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		r[i] = f[i].size();
	}

	for (int i = 0; i < n; i++)
	{
		if (r[i] > max)
		{
			max = r[i];
		}
	}

	cout << max;
	return 0;
}