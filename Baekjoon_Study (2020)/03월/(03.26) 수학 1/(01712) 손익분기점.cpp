#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C)
		cout << -1 << endl;
	else
		cout << A / (C - B) + 1 << endl;
	/*
	A + B * N < C * N    (N : �Ǹŷ�)
	(C - B) * N > A      (C - B > 0�� ����)
	N > A / (C - B)      (C - B > 0�� ����)

	A / (C - B)�� int���� ������ �� �Ҽ����� ������
	N�� ������ ���(�Ҽ�)���� Ŀ�� �ϹǷ� +1
	N�� ������ ���(����)�� ���ٸ� �װͺ��� 1�� ���ƾ�
	������ �߻��ϹǷ� +1
	*/
	return 0;
}