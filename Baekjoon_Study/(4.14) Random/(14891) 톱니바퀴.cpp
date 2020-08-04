#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string str[5];

void rot(int n, int dir) {
	int temp;
	if (dir == 1) {
		temp = str[n][7];
		for (int i = 7; i >= 1; i--) {
			str[n][i] = str[n][i - 1];
		}
		str[n][0] = temp;
	}
	else if (dir == -1) {
		temp = str[n][0];
		for (int i = 0; i <= 6; i++) {
			str[n][i] = str[n][i + 1];
		}
		str[n][7] = temp;
	}
}

void left_Check(int node, int dir) {
	if (node == 1)
		return;
	if (str[node - 1][2] != str[node][6]) {
		left_Check(node - 1, dir * (-1));
		rot(node - 1, dir * (-1));
	}
	else {
		return;
	}
}

void right_Check(int node, int dir) {
	if (node == 4)
		return;
	if (str[node][2] != str[node + 1][6]) {
		right_Check(node + 1, dir * (-1));
		rot(node + 1, dir * (-1));
	}
	else {
		return;
	}
}

int main() {
	int K; // ȸ�� Ƚ��
	vector<pair<int, int>> v; // ȸ����Ų ��Ϲ����� ��ȣ, ����
							  // 1:�ð�, -1:�ݽð�
	int a, b;
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		cin >> str[i];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for (int i = 0; i < K; i++) {
		left_Check(v[i].first, v[i].second);
		right_Check(v[i].first, v[i].second);
		rot(v[i].first, v[i].second);
	}
	for (int i = 1; i <= 4; i++) {
		if (str[i][0] == '1')
			sum += pow(2, i - 1);
	}
	cout << sum;

	return 0;
}