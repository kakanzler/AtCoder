#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ll a, b; cin >> a  >> b;

    // 今はこっちが標準らしい。
    ll ans = gcd(a, b);
    cout << ans << endl;

    ans = __gcd(a+20, b+20);
    cout << ans << endl;

    return 0;
}