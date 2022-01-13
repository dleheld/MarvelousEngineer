#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 9999322
#define MAX_N 6
int N, Graph[MAX_N][MAX_N]; //N은 여행지의 개수 
int solve(int pos, int visited)//pos는 현재 나의 위치, visted는 이미 간 곳. bit
{
	if (visited == (1 << N) - 1) {
		return 0; // base case
	}
	int ret = INF; //초기화
	for (int next = 0; next < N; ++next) { //주어진 pos에 따라 재귀, 완전 탐색
		if (!((1 << next) & visited) && Graph[pos][next]) {//비트 AND 와 논리 AND
			int tmp = Graph[pos][next] + solve(next, ((1 << next) | visited)); //반복할 명령문 실행
			if (tmp < ret)
				ret = tmp;
		}
	}
}
int main() {
	int tcCnt;
	freopen("tsp_input.txt", "r", stdin);
	cin >> tcCnt; //test case의 수를 입력
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> Graph[i][j];

		int ans = INF; //초기화

		for (int i = 0; i < N; i++) {
			int tmp = solve(i, 1 << i);
			if (ans > tmp) ans = tmp;
		}
		cout << "#" << t << ' ' << ans << endl;
	}
}