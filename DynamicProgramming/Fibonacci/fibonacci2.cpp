// using matrix exponentiation
#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return c;
}

vector<vector<long long>> power(vector<vector<long long>>& mat, int n) {
    if (n == 1) return mat;
    else {
        vector<vector<long long>> res = power(mat, n/2);
        vector<vector<long long>> res2 = multiply(res, res);
        if (n%2) res2 = multiply(res2, mat);
        return res2;
    }
}

long long fib(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    vector<vector<long long>> mat(2, vector<long long>(2));
    mat[0][0] = 1ll;
    mat[1][0] = 1ll;
    mat[0][1] = 1ll;
    mat[1][1] = 0ll;
    vector<vector<long long>> res = power(mat, n-1);
    return res[0][0];
}

int main() {
    cout << "input : " << endl;
    int n;
    cin >> n;
    cout << "result : " << fib(n) << endl;
    return 0;
}