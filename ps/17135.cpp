#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int map[16][16];

struct archer
{
	int x;
	int y;
	int dif=0;
	pair<int, int> enemy;
};

int kill(int n, int m, int d, archer a1, archer a2, archer a3) {
	int k_count = 0;
	bool ex[3] = { false, };
	int t_map[16][16];
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			t_map[i][j] = map[i][j];
		}
	}
	for (int i = n; i > 0; i--) {
		a1.y = i;
		a2.y = i;
		a3.y = i;
		for (int j = i - 1; j >= 0; j--) {
			for (int k = 0; k < m; k++) {
				if (t_map[j][k] == 1) {
					if (a1.enemy.first == 17 && abs(k - a1.x) + abs(j - a1.y) <= d) {
						a1.enemy.first = k;
						a1.enemy.second = j;
						a1.dif = abs(k - a1.x) + abs(j - a1.y);
						ex[0] = true;
					} 
					else {
						if (abs(k - a1.x) + abs(j - a1.y) <= a1.dif) {
							if (abs(k - a1.x) + abs(j - a1.y) == a1.dif && k < a1.enemy.first)
							{
								a1.enemy.first = k;
								a1.enemy.second = j;
								a1.dif = abs(k - a1.x) + abs(j - a1.y);
								ex[0] = true;
							}
							else if(abs(k - a1.x) + abs(j - a1.y) < a1.dif) {
								a1.enemy.first = k;
								a1.enemy.second = j;
								a1.dif = abs(k - a1.x) + abs(j - a1.y);
								ex[0] = true;
							}
						}
					}
					if (a2.enemy.first == 17 && abs(k - a2.x) + abs(j - a2.y) <= d) {
						a2.enemy.first = k;
						a2.enemy.second = j;
						a2.dif = abs(k - a2.x) + abs(j - a2.y);
						ex[1] = true;
					}
					else {
						if (abs(k - a2.x) + abs(j - a2.y) <= a2.dif) {
							if (abs(k - a2.x) + abs(j - a2.y) == a2.dif && k < a2.enemy.first)
							{
								a2.enemy.first = k;
								a2.enemy.second = j;
								a2.dif = abs(k - a2.x) + abs(j - a2.y);
								ex[1] = true;
							}
							else if(abs(k - a2.x) + abs(j - a2.y) < a2.dif) {
								a2.enemy.first = k;
								a2.enemy.second = j;
								a2.dif = abs(k - a2.x) + abs(j - a2.y);
								ex[1] = true;
							}
						}
					}
					if (a3.enemy.first == 17 && abs(k - a3.x) + abs(j - a3.y) <= d) {
						a3.enemy.first = k;
						a3.enemy.second = j;
						a3.dif = abs(k - a3.x) + abs(j - a3.y);
						ex[2] = true;
					}
					else {
						if (abs(k - a3.x) + abs(j - a3.y) <= a3.dif) {
							if (abs(k - a3.x) + abs(j - a3.y) == a3.dif && k < a3.enemy.first)
							{
								a3.enemy.first = k;
								a3.enemy.second = j;
								a3.dif = abs(k - a3.x) + abs(j - a3.y);
								ex[2] = true;
							}
							else if(abs(k - a3.x) + abs(j - a3.y) < a3.dif) {
								a3.enemy.first = k;
								a3.enemy.second = j;
								a3.dif = abs(k - a3.x) + abs(j - a3.y);
								ex[2] = true;
							}
						}
					}
					
				}
			}
		}
		if (ex[0] && ex[1] && ex[2])
		{
			if (a1.enemy.first == a2.enemy.first && a1.enemy.first == a3.enemy.first && a2.enemy.first == a3.enemy.first && a1.enemy.second == a2.enemy.second && a1.enemy.second == a3.enemy.second && a2.enemy.second == a3.enemy.second) {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				k_count++;
			}
			else if (a1.enemy.first == a2.enemy.first && a1.enemy.second == a2.enemy.second) {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 2;
			}
			else if (a1.enemy.first == a3.enemy.first && a1.enemy.second == a3.enemy.second) {
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 2;
			}
			else if (a3.enemy.first == a2.enemy.first && a3.enemy.second == a2.enemy.second) {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 2;
			}
			else {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 3;
			}
		}
		else if (!ex[0] && ex[1] && ex[2])
		{
			if (a2.enemy.first == a3.enemy.first && a2.enemy.second == a3.enemy.second) {
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				k_count++;
			}
			else {
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 2;
			}
		}
		else if (ex[0] && !ex[1] && ex[2])
		{
			if (a1.enemy.first == a3.enemy.first && a1.enemy.second == a3.enemy.second) {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				k_count++;
			}
			else {
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				t_map[a3.enemy.second][a3.enemy.first] = 0;
				k_count = k_count + 2;
			}
		}
		else if (ex[0] && ex[1] && !ex[2])
		{
			if (a2.enemy.first == a1.enemy.first && a2.enemy.second == a1.enemy.second) {
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				k_count++;
			}
			else {
				t_map[a2.enemy.second][a2.enemy.first] = 0;
				t_map[a1.enemy.second][a1.enemy.first] = 0;
				k_count = k_count + 2;
			}
		}
		else if (ex[0] && !ex[1] && !ex[2])
		{
			t_map[a1.enemy.second][a1.enemy.first] = 0;
			k_count++;
		}
		else if (!ex[0] && ex[1] && !ex[2])
		{
			t_map[a2.enemy.second][a2.enemy.first] = 0;
			k_count++;
		}
		else if (!ex[0] && !ex[1] && ex[2])
		{
			t_map[a3.enemy.second][a3.enemy.first] = 0;
			k_count++;
		}
		for (int m = 0; m < 3; m++) {
			ex[m] = false;
		}
		a1.enemy.first = 17;
		a2.enemy.first = 17;
		a3.enemy.first = 17;
	}

	return k_count;
}

int main() {

	int n, m, d, max = 0;
	archer a, b, c;
	a.enemy = make_pair(17, 17);
	b.enemy = make_pair(17, 17);
	c.enemy = make_pair(17, 17);
	scanf_s("%d %d %d", &n, &m, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < m - 2; i++) {
		a.x = i;
		for (int j = i + 1; j < m - 1; j++) {
			b.x = j;
			for (int k = j + 1; k < m; k++) {
				c.x = k;
				int coun = kill(n, m, d, a, b, c);
				if (coun > max) max = coun;
			}
		}
	}
	cout << max;
	return 0;
}