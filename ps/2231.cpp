#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int n,r=0,a[7],tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		r = i;
		tmp = i;
		for (int j = 0; j < 7; j++)
		{
			a[j] = tmp / pow(10, 6-j);
			tmp = tmp % int(pow(10, 6-j));
			r = r + a[j];
		}
		if (r == n)
		{
			r = i;
			break;
		}
		else
		{
			r = 0;
		}
	}

	cout << r;
	return 0;
}