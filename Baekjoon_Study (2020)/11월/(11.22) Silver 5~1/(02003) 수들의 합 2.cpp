#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[10002];

int main() {
	FASTIO;
	int N, M;
	int left = 1, right = 1;
	int sum;
	int cnt = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	sum = arr[1];
	arr[N + 1] = 0;
	while (right <= N) {
		if (sum == M) {
			cnt++;
			right++;
			sum += arr[right];
		}
		else if (sum > M) {
			sum -= arr[left];
			left++;
			if (left > right) {
				right = left;
				sum = arr[left];
			}
		}
		else if (sum < M) {
			right++;
			sum += arr[right];
		}
	}
	cout << cnt;

	return 0;
}