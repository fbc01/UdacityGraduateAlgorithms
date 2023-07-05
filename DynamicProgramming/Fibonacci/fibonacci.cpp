// using dynamic programming
#include<iostream>
#include<vector>
using namespace std;

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<long long> f(n+1);
    f[1] = 1ll;
    for (int i=2; i<=n; i++) f[i] = f[i-1] + f[i-2];
    return f[n];
}

int main() {
    cout << "input : " << endl;
    int n;
    cin >> n;
    cout << "result : " << fib(n) << endl;
    return 0;
}