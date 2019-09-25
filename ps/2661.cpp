#include <iostream>
#include <stack>
#include <string>
using namespace std;
string ans;

bool comp(string s, int n)
{
	int j;
	string tmp, comp1, comp2;
	
	if (s.size() % 2 == 0)
	{
		for (j = 0; j <= ((s.size() + 1) / 2) - 1; j++)
		{
			tmp = s;
			comp1 = tmp.substr(s.size() - j - 1, j + 1);
			comp2 = tmp.substr(s.size() - 2 * j - 2, j + 1);
			if (comp1 == comp2)
			{
				tmp.clear();
				break;
			}
		}
		if (j == ((s.size() + 1) / 2))
		{
			if (tmp == "")
			{
				tmp.clear();
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		for (j = 0; j < ((s.size() + 1) / 2)-1; j++)
		{
			tmp = s;
			comp1 = tmp.substr(s.size() - j - 1, j + 1);
			comp2 = tmp.substr(s.size() - 2 * j - 2, j + 1);
			if (comp1 == comp2)
			{
				tmp.clear();
				break;
			}
		}
		if (j == ((ans.size() + 1) / 2))
		{
			if (tmp == "")
			{
				tmp.clear();
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	
}

int main()
{
	int n, a, count = 0, j, k;
	char p;
	cin >> n;
	ans = ans + "12";
	for (int i = 2; i < n; i++)
	{
		for (a = 1; a <= 3; a++)
		{
			if (comp((ans + to_string(a)), a))
			{
				ans = ans + to_string(a);
				break;
			}
		}
		if (a == 4)
		{
			i--;
			p = ans[ans.size() - 1];
			ans = ans.substr(0, ans.size()-1);
			for (j = 1; j <= 3; j++)
			{
				if (p != (j+'0') && comp(ans+to_string(j), j))
				{
					ans = ans + to_string(j);
					break;
				}
				
			}
			if (j == 4)
			{
				i--;
				p = ans[ans.size() - 1];
				ans = ans.substr(0, ans.size() - 1);
				for (k = 1; k <= 3; k++)
				{
					if (p != (k + '0') && comp(ans + to_string(k), j))
					{
						ans = ans + to_string(k);
						break;
					}

				}
			}
			
		}
	}
	
	if (n == 1)
	{
		cout << 1;
	}
	else if (n == 2)
	{
		cout << 12;
	}
	else
	{
		cout << ans;
	}
	
	return 0;
}