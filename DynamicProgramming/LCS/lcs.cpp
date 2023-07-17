// using Dynamic Programming
// O(N^2)
#include<iostream>
#include<vector>
using namespace std;

void findLCS(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (s1[i-1] != s2[j-1]) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    cout << dp[m][n] << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    findLCS(s1, s2);
    return 0;
}