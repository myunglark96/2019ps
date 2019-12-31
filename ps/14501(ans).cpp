#include<iostream>
#include<algorithm>
using namespace std;

int day[16];
int price[16];
int maxVal;
int N;

void problemIn() {
    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>day[i]>>price[i];
    }
}



void dfs(int curD, int sum) {

    maxVal=max(maxVal, sum);

    if (curD==N+1) {
        return;
    }

    if (curD+day[curD]<=N+1) { // ���� ��
        dfs(curD+day[curD], sum+price[curD]);
    }

    if (curD+1<=N+1) { // ���� ���ϰ�, ���� ���� ��
        dfs(curD+1, sum);
    }
}


void solve() {

    dfs(1, 0);

}

int main() {
    problemIn();
    solve();
    cout<<maxVal<<endl;
    return 0;
}