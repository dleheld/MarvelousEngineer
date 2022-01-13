#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 9999322
#define MAX_N 6
int N, Graph[MAX_N][MAX_N]; //N�� �������� ���� 
int solve(int pos, int visited)//pos�� ���� ���� ��ġ, visted�� �̹� �� ��. bit
{
	if (visited == (1 << N) - 1) {
		return 0; // base case
	}
	int ret = INF; //�ʱ�ȭ
	for (int next = 0; next < N; ++next) { //�־��� pos�� ���� ���, ���� Ž��
		if (!((1 << next) & visited) && Graph[pos][next]) {//��Ʈ AND �� �� AND
			int tmp = Graph[pos][next] + solve(next, ((1 << next) | visited)); //�ݺ��� ��ɹ� ����
			if (tmp < ret)
				ret = tmp;
		}
	}
}
int main() {
	int tcCnt;
	freopen("tsp_input.txt", "r", stdin);
	cin >> tcCnt; //test case�� ���� �Է�
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> Graph[i][j];

		int ans = INF; //�ʱ�ȭ

		for (int i = 0; i < N; i++) {
			int tmp = solve(i, 1 << i);
			if (ans > tmp) ans = tmp;
		}
		cout << "#" << t << ' ' << ans << endl;
	}
}