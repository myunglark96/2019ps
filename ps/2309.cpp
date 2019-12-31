#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isHundred(vector<int> a);

int main() {
	int Nan[9], ind[9];
	vector<int> realNan;
	for (int i = 0; i < 9; i++) {
		scanf_s("%d", &Nan[i]);
	}

	sort(Nan, Nan+9);
	int k = 7;

	for (int i = 0; i < 9-k; i++) {
		ind[i] = 0;
	}
	for (int i = 9 - k; i < 9; i++) {
		ind[i] = 1;
	}

	//조합
	do {
		realNan.clear();
		for (int i = 0; i < 9; i++) {
			if (ind[i] == 1) {
				realNan.push_back(Nan[i]);
			}
		}
		if (isHundred(realNan)) {
			break;
		}
	} while (next_permutation(ind, ind +9));

	//출력
	for (int i = 0; i < 7; i++) {
		printf("%d\n", realNan[i]);
	}
	return 0;
}

bool isHundred(vector<int> a) {
	int sum=0, fron;
	for (int i = 0; i < 7; i++) {
		sum = sum + a[i];
	}

	if (sum == 100) return true;
	else return false;
}
