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

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------



//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる

#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

template<class T> bool chmin (T &a, T b){
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<class T> bool chmax (T &a, T b){
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back

#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

#define pop_cnt(s) ll(popcount(uint64_t(s)))

#define next_p(v) next_permutation(v.begin(),v.end())

//if (regex_match(s, regex("")))YN;//文字列sの判定を行う。コメントアウトを外して「""」の中に判定する内容を入れる

//-------------------------------



struct Edge{
    ll v;
    ll w;
    ll num;
    Edge (ll v, ll w, ll num) : v(v), w(w), num(num) {};
};

void solve() {
    ll n, m; cin >> n >> m;

    vector<vector<Edge>> g(n);
    rep(i, m){
        ll u, v, c; cin >> u >> v >> c; u--; v--;
        g[u].pb(Edge(v, c, i+1));
        g[v].pb(Edge(u, c, i+1));
    }

    pq_g<pair<ll, ll>> q;
    q.emplace(0, 0);
    vc<pair<ll, ll>> seen(n, {-1, -1});
    seen[0] = {0, 0};
    vl total_cost(n, INF);
    total_cost[0] = 0;

    while(q.size()){
        auto [cost, v] = q.top(); q.pop();

        if (total_cost[v] != cost) continue;

        for(Edge e: g[v]){
            if (!chmin(total_cost[e.v], e.w + cost)) continue;
            // if (seen[e.v].first == v && seen[e.v].second == e.num ) continue;

            seen[e.v] = {v, e.num};
            q.emplace(e.w + cost, e.v);

        }
    }
    // rep(i, n) cout << "v: " << seen[i].first << " road : " << seen[i].second << endl;

    rep(i, n-1) cout << seen[i+1].second << ' ';
    cout << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}