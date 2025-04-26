#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < m; j++) {
			grid[i][j] = str[j] - '0';
		}
	}
	// Calculate row_contrib
	vector<int> row_contrib(n, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m - 1; j++) {
			if(grid[i][j] == grid[i][j + 1]) row_contrib[i] += 2;
		}
	}
	if(n == 1) {
		cout << row_contrib[0] << endl;
		return 0;
	}
	// DP
	long long prev0 = row_contrib[0];
	long long prev1 = row_contrib[0];
	for(int i = 1; i < n; i++) {
		// Calculate col_contrib
		long long col00 = 0; // t=0, s=0
		for(int j = 0; j < m; j++) {
			if(grid[i - 1][j] == grid[i][j]) col00 += 2;
		}
		long long col01 = 0; // t=0, s=1
		for(int j = 0; j < m; j++) {
			if(grid[i - 1][j] == (1 - grid[i][j])) col01 += 2;
		}
		long long col10 = 0; // t=1, s=0
		for(int j = 0; j < m; j++) {
			if((1 - grid[i - 1][j]) == grid[i][j]) col10 += 2;
		}
		long long col11 = 0; // t=1, s=1
		for(int j = 0; j < m; j++) {
			if((1 - grid[i - 1][j]) == (1 - grid[i][j])) col11 += 2;
		}
		// Calculate dp[i][0]
		long long dp_i_0 = max(prev0 + col00, prev1 + col10) + row_contrib[i];
		// Calculate dp[i][1]
		long long dp_i_1 = max(prev0 + col01, prev1 + col11) + row_contrib[i];
		// Update prev
		prev0 = dp_i_0;
		prev1 = dp_i_1;
	}
	cout << max(prev0, prev1) << endl;
	return 0;
}