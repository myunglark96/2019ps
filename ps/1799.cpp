#include <iostream>
#include <stack>
using namespace std;
int map[10][10];
bool check[10][10] = {false,};
int dfs(int sx, int sy);

int main() {
	int n;
	cin >> n;
	stack<pair<int, int>> track;
	int dn[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) check[i][j] = true;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true) {
				track.push(make_pair(i, j));
				while (!track.empty()) {					

				}
			}
		}
	}
	
	return 0;
}

int dfs(int sx, int sy) {

}