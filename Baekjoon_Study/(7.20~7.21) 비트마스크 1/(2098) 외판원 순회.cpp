#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321

int N;
int W[16][16];
int DP[16][1 << 16];

int DFS(int node, int bit) {
	// ��� ���ø� �� �湮�� ��� = ��� ��Ʈ�� 1�� ���(0~15)
	if (bit == (1 << N) - 1) {
		// ���ư��� ���� �Ұ����� ��� return INF
		if (W[node][0] == 0)
			return INF;
		// ���ǿ� ��ȸ�� �����ϸ� ���� ��ġ���� 0(���� ��ġ)�� ���ư��� �� return
		else
			return W[node][0];
	}

	// ���� �� �湮�� ���
	// DP���� �̹� �ִٸ�
	if (DP[node][bit] != -1)
		// �״�� DP�� return
		return DP[node][bit];
	// DP���� ���� ���ٸ� INF�� �ʱ�ȭ
	DP[node][bit] = INF;

	// ���� node���� �� �� �ִ� �� Ž��
	for (int i = 0; i < N; i++) {
		// ���� ���� �Ұ����� ���̸� pass
		if (W[node][i] == 0) continue;
		// bit�� �˻��Ͽ� �̹� �湮�� ���̸� pass
		if ((bit & (1 << i))) continue;
		// �湮 ������ ���� ���
		// ���� DP�� �� VS ���ݱ��� ���Ŀ� �� + ���� ��ġ���� �߰��� ��带 ������ DFS��
		// �޸������̼�
		DP[node][bit] = min(DP[node][bit], W[node][i] + DFS(i, bit | (1 << i)));
	}
	// �޸������̼� �� ���� return
	return DP[node][bit];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	// DP���� �����ϴ��� ���ϴ����� �����ϱ� ���� -1�� �ʱ�ȭ
	memset(DP, -1, sizeof(DP));
	// 0���� �����ؼ� 0���� �ٽ� ���ƿ��� ����
	// 0���� �湮������ 0�� ��Ʈ�� 1�� �ٲ� -> bit = 1
	cout << DFS(0, 1);

	return 0;
}