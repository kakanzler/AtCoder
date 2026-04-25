#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
template<typename T> using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;
ll INF = 2e18;

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define pb push_back

bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

void solve() {
    ll n, m; cin >> n >> m;

    queue<pair<ll, ll>> q;
    q.push({0,0});
    vvl dist(n, vector<ll>(n, -1));
    dist[0][0] = 0;

    set<pair<ll, ll>> d;
    rep(i, n){
        rep(j, n){
            if (i*i + j*j == m){
                d.insert({i, j});
                d.insert({-i, j});
                d.insert({i, -j});
                d.insert({-i, -j});
            }
        }
    }

    vector<pair<ll, ll>> move(d.begin(), d.end());
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        rep(i, (ll)move.size()){

            ll nx = x + move[i].first;
            ll ny = y + move[i].second;

            if (out_grid(nx, ny, n, n)) continue;
            if (dist[nx][ny] != -1) continue;

            q.emplace(nx, ny);
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

    // ans
    rep(i, n){
        rep(j, n){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}