//dfs를 이용한 풀이
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

    if (curD+day[curD]<=N+1) { // 일을 함
        dfs(curD+day[curD], sum+price[curD]);
    }

    if (curD+1<=N+1) { // 일을 안하고, 다음 날로 감
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

//dp를 이용한 풀이
/*
#include <iostream>

using namespace std;

int t[1000] = { 0, };
int p[1000] = { 0, };
int dp[1000] = { 0, };

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int N;
    int next;

    cin >> N;

    for (int i = 1;i <= N;i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = N;i > 0;i--) {
        next = i + t[i];
        if (next > N + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);
        }

    }

    cout << dp[1] << endl;

    return 0;
}
*/