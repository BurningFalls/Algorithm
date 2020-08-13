#include <iostream>
#include <deque>
using namespace std;

int N;		// ������ ũ�� (2~100)
int map[102][102] = { 0, };		// ���� (N*N)
			// �� = 1, ��� = 2
int K;		// ����� ���� (0~100)
int L;		// ���� ���� ��ȯ Ƚ�� (1~100)
int dir_inf[10002];		// �̵� ���� ����
			// 0=������, 1=��, 2=����, 3=�Ʒ�
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
deque<pair<int, int>> snake_dq;	// ���� ��ġ ����

int Move_Snake(int X) {
	int y, x, ny, nx;
	int time = X + 2;
	for (int i = 1; i <= X + 1; i++) {
		y = snake_dq.front().first;
		x = snake_dq.front().second;
		ny = y + dy[dir_inf[i]];
		nx = x + dx[dir_inf[i]];
		if (ny < 1 || nx < 1 || ny > N || nx > N)
			return i;
		if (map[ny][nx] == 1)
			return i;

		if (map[ny][nx] == 0) {
			y = snake_dq.back().first;
			x = snake_dq.back().second;
			map[y][x] = 0;
			snake_dq.pop_back();
		}
		map[ny][nx] = 1;
		snake_dq.push_front(make_pair(ny, nx));
	}
	while (true) {
		y = snake_dq.front().first;
		x = snake_dq.front().second;
		ny = y + dy[dir_inf[X + 1]];
		nx = x + dx[dir_inf[X + 1]];
		if (ny < 1 || nx < 1 || ny > N || nx > N)
			return time;
		if (map[ny][nx] == 1)
			return time;
		if (map[ny][nx] == 0) {
			y = snake_dq.back().first;
			x = snake_dq.back().second;
			map[y][x] = 0;
			snake_dq.pop_back();
		}
		map[ny][nx] = 1;
		snake_dq.push_front(make_pair(ny, nx));
		time++;
	}
	return -1;
}

int main() {
	int apple_pos_y, apple_pos_x;
	int X;
	char C;
	int node = 1;

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> apple_pos_y >> apple_pos_x;
		map[apple_pos_y][apple_pos_x] = 2;
	}
	cin >> L;

	// 0=������, 1=��, 2=����, 3=�Ʒ�
	dir_inf[1] = 0;	// ó���� ������
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		for (int j = node; j <= X; j++) {
			dir_inf[j] = dir_inf[node];
		}
		if (C == 'L') {	// ���� 90�� ȸ��
			dir_inf[X + 1] = (dir_inf[node] + 1) % 4;
		}
		else if (C == 'D') {	// ������ 90�� ȸ��
			dir_inf[X + 1] = (dir_inf[node] + 3) % 4;
		}
		node = X + 1;
	}
	/*for (int i = 1; i <= X + 1; i++) {
		cout << dir_inf[i];
	}*/

	map[1][1] = 1;	// �ʱ� ��
	snake_dq.push_front(make_pair(1, 1));
	cout << Move_Snake(X);

	return 0;
}