#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
template<typename T> using vv = vc<vc<T>>;

using ll = long long;
ll INF = 2e18;

#define rep(i, n) for(int i = 0 ; i < (n) ; ++i)
#define out(n) cout << n << endl;


void solve(){
    ll N;
    cin >> N;

    vector<ll> s;

    ll type;
    ll num = 0;
    rep(i, N){
        cin >> type;
        if (type == 1){
            cin >> num;

            s.push_back(num);
        } else {
            sort(s.begin(), s.end());
            ll ans = s.front();
            s.erase(s.begin());
            cout << ans << endl;
        }
    }
    return;
}


int main(){
    solve();
}