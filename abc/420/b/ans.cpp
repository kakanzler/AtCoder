
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;


void solve() {
    ll x, y;
    cin >> x >> y;
    int ans = (x + y) %12;
    if (ans == 0) ans = 12;
    cout << ans << endl;
    return;
}

int main() {
    solve();
}