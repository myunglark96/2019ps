#include <iostream>
#include <vector>
using namespace std;
int a[2000];
int b[2000];

int main()
{
	vector<int> v;
	int n, m, comp, putf, r = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < m; i++)
	{
		putf = a[i];
		comp = b[i];
		v.push_back(putf);
		for (int j = 0; j < m; j++)
		{
			auto it = find(v.begin(), v.end(), b[i]);
			if (b[i] == a[j] && it == v.end())
			{
				putf = b[i];
				comp = b[j];
				v.push_back(putf);
				r++;
				j = 0;
				if (r >= 4)
				{
					break;
				}
			}
			else if(b[i] == b[j] && it == v.end())
			{
				putf = b[i];
				comp = a[j];
				v.push_back(putf);
				r++;
				j = 0;
				if (r >= 4)
				{
					break;
				}
			}
		}

		if (r >= 4)
		{
			break;
		}
		else
		{
			r = 0;
		}
		
	}

	if (r >= 4)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}