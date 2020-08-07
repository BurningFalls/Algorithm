#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int N, K;
	int minimum = 0, maximum = 0;
	int arr[10];
	int letters = 1;
	int LEFT;
	int temp;
	int Check = 0;
	int len;
	pair<int, int> left, right, mid;
	int sub_left, sub_right;
	/*
	�� �ڸ������� ��� ���ڰ� �ִ���
	arr[1] = 9, arr[2] = 90*2, arr[3] = 900*3...
	*/
	for (int i = 1; i <= 8; i++) {
		arr[i] = 9 * int(pow(10, i - 1)) * i;
	}
	// N, K �Է¹ް�
	cin >> N >> K;
	// ���� ���̰� k���� ������ Ȯ��
	len = to_string(N).size();
	for (int i = 1; i < len; i++) {
		Check += arr[i];
	}
	Check += (N - int(pow(10, len - 1)) + 1) * len;
	if (Check < K)
		cout << -1;
	// else
	else {
		// K��° �ڸ� ������ �ڸ����� �˾Ƴ���
		for (int i = 1; i <= 9; i++) {
			/*
			i=1 -> min=1, max=9
			i=2 -> min=10, max=189
			i=3 -> min=190, max=2889
			*/
			if (i == 1)
				minimum = 1;
			else
				minimum += arr[i - 1];
			if (i == 9)
				maximum = minimum + 8;
			else
				maximum = minimum + arr[i] - 1;
			/*
			K�� min�� max ������ ���
			letters�� �ڸ����� ����
			left�� right -> first:���� ����, second:���ݱ��� ������ ����
			(if letters�� 2���)
			left = (10, 10), right = (99, 189)
			*/
			if (minimum <= K && K <= maximum) {
				letters = i;
				left = make_pair(int(pow(10, i - 1)), minimum);
				right = make_pair(int(pow(10, i)) - 1, maximum);
				break;
			}
		}
		LEFT = left.second;
		while (true) {
			// mid ��� ���
			mid = make_pair((left.first + right.first) / 2, (left.second + right.second) / 2);
			// temp ����� ���� �� ���ڿ����� ��ġ �ľ� (1032���� 0�� ��ġ�� 1)
			temp = (mid.second - LEFT) % letters;
			// �װ� �������� 1032���� 1�� ��ġ�� 2�� ��ġ�� ���
			sub_left = mid.second - temp;
			sub_right = mid.second + (letters - 1) - temp;
			// K���� �� ���̿� �ִٸ� �ش� mid.first�� ����� ���ڰ� ��
			if (sub_left <= K && K <= sub_right) {
				// �� ���ڿ��� ��ġ�� �ٽ� ����ؼ� �ϳ��� ���ڸ� ã�Ƴ�
				cout << to_string(mid.first)[K - sub_left];
				break;
			}
			// K�� sub_left���� ������ right ����
			if (sub_left > K) {
				right = make_pair(mid.first - 1, sub_left - 1);
			}
			// K�� sub_right���� Ŭ�� left ����
			else if (K > sub_right) {
				left = make_pair(mid.first + 1, sub_right + 1);
			}
		}
	}

	return 0;
}