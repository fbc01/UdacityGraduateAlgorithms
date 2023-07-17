#include<iostream>
#include<vector>
using namespace std;

void findLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main() {
    cout << "input : " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    findLIS(arr);
    return 0;
}