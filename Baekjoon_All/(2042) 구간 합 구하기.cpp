#include <iostream>
using namespace std;

typedef long long int ll;

int N; // ���� ���� (1~1,000,000)
int M; // ���� ������ �Ͼ�� Ƚ�� (1~10,000)
int K; // ������ ���� ���ϴ� Ƚ�� (1~10,000)
ll arr[1000001]; // ��
ll tree[4000001]; // Ʈ��

ll Make_Tree(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = Make_Tree(node * 2, start, mid) + Make_Tree(node * 2 + 1, mid + 1, end);
}

void Change_Number(int node, int start, int end, int target, ll dif) {
	if (start <= target && target <= end)
		tree[node] += dif;
	else
		return;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	Change_Number(node * 2, start, mid, target, dif);
	Change_Number(node * 2 + 1, mid + 1, end, target, dif);
}

ll Sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ll a, b, c;
	ll differ;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	Make_Tree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			// b��° ���� c�� �ٲ�
			differ = c - arr[b];
			arr[b] = c;
			Change_Number(1, 1, N, b, differ);
		}
		else if (a == 2) {
			// b��° ������ c��° �������� ���� ���Ͽ� ���
			cout << Sum(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}