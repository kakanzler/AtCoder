
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;

using ll = long long;

using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define out(n) cout << n << endl;

void solve() {
    ll n, m;
    cin >> n >> m;
    string vote;

    vl res(n);

    vvl vv(n, vector<ll>(m));

    rep(i, n){
        cin >> vote;
        if (vote.size() > 0){
            rep (j,m) vv[i][j] = vote[j] - '0';
        }
    }
    rep(i, m){
        ll count=0;
        rep(j,n) count += vv[j][i];

        ll winner = 0;
        if (count <= n/2) winner = 1;
        if (count == 0){
             winner = 0;
        } else if (count == n){
            winner = 1;
        }

        rep(j,n){
            if(vv[j][i] == winner) res[j] += 1;
        }
    }
    ll mx = 0;
    rep(i,n) mx = max(mx, res[i]);
    string ans = "";
    rep(i,n) if (res[i] == mx) ans += to_string(i+1) + " ";
    ans.pop_back();
    cout << ans << endl;
    return;
}

int main() {
    solve();
}