#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	getline(cin, S);
	int len = S.size();
	bool word_flag = false;
	int count = 0;

	for (int i = 0; i < len; i++) {
		// �����̰� ������ �ܾ �־��ٸ�
		// (�ܾ� �ϳ��� �� ������ ���鿡 �����ߴٸ�)
		// ���� ���¸� false�� �ٲ�
		if (S[i] == ' ' && word_flag == true) {
			word_flag = false;
		}
		// �����̰� ������ �ܾ �����ٸ�
		// (���⿴�ٰ� ���ο� �ܾ �����ߴٸ�)
		// ���� ���¸� true�� �ٲ�
		// ���ο� �ܾ ���������Ƿ� count�� +1
		else if (S[i] != ' ' && word_flag == false) {
			word_flag = true;
			count++;
		}
		// if (S[i] == ' ' && word_flag == false)
		// -> ������ ����ؼ� �о� �����Ƿ� ���ǹ�
		// (S[i] != ' ' && word_flag == true) 
		// -> ���ڸ� ����ؼ� �о� �����Ƿ� ���ǹ�
	}
	cout << count << endl;

	return 0;
}