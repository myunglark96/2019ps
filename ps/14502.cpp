#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[8][8], temp[8][8], exec_map[8][8], dx[4]={ 1,-1,0,0 }, dy[4]={ 0,0,1,-1 }, safemax=0;

void bfs(int N, int M) {
	int safecount=0;
	queue<pair<int, int>> q;

	for (int j=0; j<N; j++) {
		for (int i=0; i<M; i++) {
			temp[j][i]=map[j][i];
		}
	}

	for (int a=0; a<N*M; a++) {
		if (temp[a/M][a%M]==0) {
			temp[a/M][a%M]=1;
			for (int b=a; b<N*M; b++) {
				if(temp[b/M][b%M]==0) {
					temp[b/M][b%M]=1;
					for (int c=b; c<N*M; c++) {
						if (temp[c/M][c%M]==0) {
							temp[c/M][c%M]=1;
							//실행 map에 벽을 세운 경우의 수인 temp를 넣어줌
							for (int j=0; j<N; j++) {
								for (int i=0; i<M; i++) {
									exec_map[j][i]=temp[j][i];
								}
							}

							//바이러스 확산 
							for (int j=0; j<N; j++) {
								for (int i=0; i<M; i++) {
									if (exec_map[j][i]==2) {
										q.push(make_pair(i, j));
										while (!q.empty()) {
											pair<int, int> now, next;
											now=q.front();
											q.pop();
											for (int k=0; k<4; k++) {
												next.first=now.first+dx[k];
												next.second=now.second+dy[k];
												if (next.first>=0&&next.first<M&&next.second>=0&&next.second<N&&exec_map[next.second][next.first]==0) {
													exec_map[next.second][next.first]=2;
													q.push(make_pair(next.first, next.second));
												}
											}
										}
									}
								}
							}
							
							//안전지대 개수
							for (int j=0; j<N; j++) {
								for (int i=0; i<M; i++) {
									if (exec_map[j][i]==0) {
										safecount++;
									}
								}
							}

							//안전지대 개수 중 최대 개수 저장
							safemax=max(safemax, safecount);
							safecount=0;
							temp[c/M][c%M]=0;
						}
					}
					temp[b/M][b%M]=0;
				}
			}
			temp[a/M][a%M]=0;
		}
	}

	return;
}

int main() {
	int N, M;
	scanf_s("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	bfs(N,M);
	printf("%d", safemax);
	return 0;
}