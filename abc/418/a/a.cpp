#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define ll long long
#define rep(i, n) for (int i=0; i<n; ++i)
#define out(n) cout << n << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;

void solve(){
    ll N;
    string S;
    cin >> N;
    cin >> S;
    if (N < 3 or S.substr(N-3, N) != "tea") {
        No()
    } else {
        Yes()
    };
    return;
}

int main(){
    solve();
}