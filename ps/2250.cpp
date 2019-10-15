#include <iostream>
#include <vector>
using namespace std;
int tree[10001][2];
vector<int> depth[10001];

int count_element(int d, int end) {
	vector<int> size = depth[d];
	int start = depth[d][0], fin = depth[d][depth[d].size() - 1];
	int count = 1, np;
	for (int i = 1; i <= d; i++) {
		count = depth[i].size() - 2 + count;
		if (tree[depth[i - 1][0]][0] == depth[i][0])
		{
			count++;
		}
		if (tree[depth[i - 1][depth[i - 1].size() - 1]][1] == depth[i][depth[i].size() - 1]) {
			count++;
		}

	}
	
	while (!size.empty())
	{
		np = size.front();
		size.erase(size.begin());
		if (np == start && tree[np][1] != -1)
		{
			size.push_back(tree[np][1]);
			count++;
		}
		else if (np == fin && tree[np][0] != -1)
		{
			size.push_back(tree[np][0]);
			count++;
		}
		else if(np != start && np != fin){
			if (tree[np][0] != -1) {
				size.push_back(tree[np][0]);
				count++;
			}
			if (tree[np][1] != -1) {
				size.push_back(tree[np][1]);
				count++;
			}
			
			
		}
	}

	return count;
}

int main() {
	int n, lef, rig, index, count=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> index >> lef >> rig;
		tree[index][0] = lef;
		tree[index][1] = rig;
	}

	depth[0].push_back(1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < depth[i].size(); j++)
		{
			if(tree[depth[i][j]][0] != -1) depth[i + 1].push_back(tree[depth[i][j]][0]);
			
			if(tree[depth[i][j]][1] != -1) depth[i + 1].push_back(tree[depth[i][j]][1]);
		}
	}

	cout << count_element(4, n);
	return 0;
}