// using Binary Search
// O(LogN)
#include<iostream>
#include<vector>
using namespace std;

void findLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> lis;
    for (int i=0; i<n; i++) {
        if (lis.empty()) {
            lis.push_back(arr[i]);
        }
        else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        }
        else {
            auto itr = lower_bound(lis.begin(), lis.end(), arr[i]);
            *itr = arr[i];
        }
    }
    cout << lis.size() << endl;
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