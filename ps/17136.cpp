#include <iostream>
#include <stdio.h>
using namespace std;
int map[10][10];
int t_map[10][10];
bool check[10][10] = { false, };
int pap[5] = { 5,5,5,5,5 };

int c_box(int x, int y) {
	int flag = -1, count = 0;
	for (int k = 5; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (map[y + i][x + j] == 1) {
					count++;
				}
			}
		}
		if (count == k * k) {
			flag = k;
			count = 0;
			return flag;
		}
		else {
			count = 0;
		}
	}
	return flag;
}

int put_p(int x, int y, int la) {
	int pcoun = 0;
	for (int k = 0; k < la; k++) {
		for (int l = 0; l < la; l++) {
			check[y + k][x + l] = true;
			t_map[y + k][x + l] = 0;
		}
	}
	if (pap[la - 1] - 1 < 0) {
		return -1;
	}
	else {
		pap[la - 1]--;
		pcoun++;
	}
	return pcoun;
}


int main() {
	int d = 0, lang, pcount = 0, max = 0, mx, my, no_ele = 0, loo = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			t_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				no_ele++;
			}
		}
	}

	if (!no_ele) {
		cout << 0;
		exit(0);
	}

	while (!loo) {
		loo++;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (t_map[i][j] == 1 && !check[i][j]) {
					lang = c_box(j, i);
					if (lang > max) {
						max = lang;
						mx = j;
						my = i;
					}
				}
			}
		}
		if (put_p(mx, my, max) == -1)
		{
			if (max - 1 == 0) {
				cout << -1;
				exit(0);
			}
			else {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						t_map[i][j] = map[i][j];
						check[i][j] = false;
					}
				}
				pcount = 0;
				put_p(mx, my, max - 1);
			}
		}
		else {
			pcount = pcount + put_p(mx, my, max);
		}
		for (int k = 0; k < 10; k++) {
			for (int l = 0; l < 10; l++) {
				if (t_map[k][l] == 1) {
					no_ele = 0;
					loo = no_ele;
				}
			}
		}
		max = 0;
	}
	
	cout << pcount;
	return 0;
}