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


//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
//----------------------------------------------

void solve() {
    ll m; cin >> m;
    vvl g(9);
    rep(i, m){
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vl state(9, -1);
    rep(i, 8) {
        ll p; cin >> p; p--;
        state[p] = i;
    }

    auto get_strstate = [&] (const vl& lis){
        string pos = "";
        rep(i, 9) {
            if (lis[i] == -1) pos += 'e';
            else {
                pos += char(lis[i] + '0');
            }
        }
        return pos;
    };

    auto swap_state = [&] (string ss, ll i, ll j){
        swap(ss[i], ss[j]);
        return ss;
    };

    string pos = get_strstate(state);

    queue<string> q;
    q.emplace(pos);

    map<string, ll> dist;
    dist.insert({pos, 0});

    while(q.size()){
        string pos = q.front(); q.pop();
        ll v = pos.find('e');

        if (pos == "01234567e") {
            cout << dist[pos] << endl;
            return;
        }
        for (ll nv : g[v]){
            string npos = swap_state(pos, v, nv);
            if(dist.contains(npos)) continue;

            // cout << pos << " -> " << npos << endl;
            q.emplace(npos);
            dist.insert({npos, dist[pos] + 1});

        }
        // cout << "---" << endl;
    }

    cout << -1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}