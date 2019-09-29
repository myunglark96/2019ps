#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, t, f = 0, plug = 0, pri_n[100] = {0,}, max = 0, pri=0, pop;
	vector<int> s, cur_p;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> t;
		s.push_back(t);
	}

	for (int i = 0; i < k; i++)
	{
		auto it = find(cur_p.begin(), cur_p.end(), s[i]);
		if (it == cur_p.end())
		{
			cur_p.push_back(s[i]);
			f++;
		}

		if (f >= n) break;
	}

	for (int j = f; j < k; j++)
	{
		auto it = find(cur_p.begin(), cur_p.end(), s[j]);
		if (it == cur_p.end()) {
			for (int i = 0; i < n; i++)
			{
				for (int z = j; z < k; z++)
				{
					pri++;
					if (s[z] == cur_p[i])
					{
						pri_n[i] = pri;
						pri = 0;
						break;
					}
					else if (z == k - 1)
					{
						pri_n[i] = pri+1;
						pri = 0;
					}
				}
				//auto it = find(s.begin() + j + f, s.end(), cur_p[i]);
				//if(it == s.end()) pri_n[i] = k;
				//else pri_n[i] = *it;
			}
			for (int i = 0; i < n; i++)
			{
				if (max < pri_n[i]) {
					max = pri_n[i];
					pop = i;
				}
				pri_n[i] = 0;
			}
			cur_p[pop] = s[j];
			max = 0;
			plug++;
		}
		
	}
	cout << plug;

	return 0;
}