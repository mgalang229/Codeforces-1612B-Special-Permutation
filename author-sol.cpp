#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, a, b;
		cin >> n >> a >> b;
		// put a in the first position (since it should be the minimum in the 1st half)
		vector<int> vec = {a};
		// afterward, place numbers n, n - 1, n - 2, ..., 1 (not including a and b)
		for (int i = n; i > 0; i--) {
			if (i != a && i != b) {
				vec.push_back(i);
			}
		}
		// lastly, place b in the last position (since it should be the maximum in the 2nd half)
		vec.push_back(b);
		int m = vec.size();
		int mn = 101;
		for (int i = 0; i < m / 2; i++) {
			mn = min(mn, vec[i]);
		}
		int mx = 0;
		for (int i = n / 2; i < n; i++) {
			mx = max(mx, vec[i]);
		}
		// check if the sequence created is of length n, the minimum element of the 1st
		// half is equal to a and the maximum element of the 2nd half is equal to b
		if ((int) vec.size() == n && mn == a && mx == b) {
			for (int i = 0; i < n; i++) {
				cout << vec[i] << " ";
			}
		} else {
			cout << -1;
		}
		cout << '\n';
	}
	return 0;
}
