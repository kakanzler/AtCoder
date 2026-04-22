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

#include <boost/multiprecision/cpp_int.hpp>//インストール的なのをしてないとできないので注意
namespace multip = boost::multiprecision;
//using lll = multip::cpp_int;//無制限を使いたいときはこっちを使う
using lll = multip::int128_t;

using ld = long double;
using bl = bool;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------



//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using P = pair<ll, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;

//配列外参照対策のやつは一番上の行にあります

#define rep(i,n) for(ll i = 0; i < (n); ++i)//↓でrepを使うので書いてます
template<class T>istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

using ar2 = array<ll, 2>;

//----------------------------------



//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる

#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back


#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl


#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

#define pop_cnt(s) ll(popcount(uint64_t(s)))

#define next_p(v) next_permutation(v.begin(),v.end())

//if (regex_match(s, regex("")))YN;//文字列sの判定を行う。コメントアウトを外して「""」の中に判定する内容を入れる

//-------------------------------




//---------4.グリッド系----------
vl dx = { 1,0,-1,0 };//vl dx={1,1,0,-1,-1,-1,0,1};
vl dy = { 0,1,0,-1 };//vl dy={0,1,1,1,0,-1,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

#define vvl_kaiten(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//時計回りに90°回転
//#define vvl_kaiten(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//反時計周りに90°回転

#define vs_kaiten(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//文字列版 時計回りに90°回転
//#define vs_kaiten(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//文字列版　反時計周りに90°回転


#define vvl_tenti(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][i]=v[i][j];swap(nx,v);}
#define vs_tenti(v) {ll n = size(v); vs nx(n, string(n,'.')); rep(i, n)rep(j, n)nx[j][i] = v[i][j]; swap(nx, v);}

//--------------------------------




//-----------5.数学系--------------
#define yu_qurid(x,y) ((x)*(x)+(y)*(y))//ユークリッド距離 sqrtはしてないなので注意
#define mannhattan(x1,x2,y1,y2) (abs(x1-x2)+abs(y1-y2)) // マンハッタン距離 = |x1-x2|+|y1-y2|

template<class T>T tousa_sum1(T l, T d, T r) {//初項,公差,末項 で総和を求める
    T wide = (r - l) / d + 1;
    return (l + r) * wide / 2;
}
template<class T>T tousa_sum2(T a, T d, T n) {//初項,交差,項数 で総和を求める
    return (a * 2 + d * (n - 1)) * n / 2;
}
ll kousa_kousuu(ll l, ll r, ll d) {//初項,末項,交差 で等差数列の項数を求める
    return (r - l) / d + 1;
}
mint touhi_sum(mint a, mint r, ll n) {//初項,公比,項数で等比数列の総和を求める
    if (r == 1) {
        return a * n;
    }
    mint bunsi = a * (r.pow(n) - mint(1));
    mint bunbo = r - 1;
    return bunsi / bunbo;
}

ll nc2(ll x) { return x * (x - 1) / 2; }
ll nc3(ll x) { return x * (x - 1) * (x - 2) / 6; }

//----------------------------------------------




//-----------6.デバックや出力系------------------
void print(ld x) { printf("%.20Lf\n", x); }

void mukou_debug(vvl to, bool yukou) {//GRAPH × GRAPH用の無向グラフを出力する
    ll n = size(to); ll cnt = 0;//辺の本数
    vc<pair<ll, ll>>v; rep(i, n)for (ll t : to[i])  if (i < t || yukou)cnt++, v.eb(i + 1, t + 1);//有向グラフなら全部OK、違うなら無向なのでf<tのみ見る、using Pのやつを別のにしたいときのためにPを使わずにpair<ll,ll>にしてる
    cout << n << ' ' << cnt << endl; for (auto [f, t] : v)cout << f << ' ' << t << endl;
}

#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する

//----------------------------------------------

void solve(vvl& g, ll& n) {

    queue<ll> cq;
    queue<ll> dq;
    vl distc(n, -1);
    vl distd(n, -1);

    ll c, d; cin >> c >> d;
    c--; d--;

    cq.emplace(c);
    dq.emplace(d);
    distc[c] = 0;
    distd[d] = 0;

    auto bfs = [&](queue<ll> &q, vl &dist, ll &start){
        dist[start] = 0;
        q.push(start);

        while(q.size()){
            ll v = q.front(); q.pop();
            for (ll nv : g[v]){
                if (dist[nv] != -1) continue;

                q.push(nv);
                dist[nv] = dist[v]+1;
            }
        }
    };

    bfs(cq, distc, c);
    bfs(dq, distd, d);

    string ans = "Road";
    rep(i, n){
        // cout << distc[i] << " : " << distd[i] << endl;
        if (distc[i] == distd[i]) ans = "Town";
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q; cin >> n >> q;
    vvl g(n);
    rep(i, n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    rep(i, q){
        solve(g, n);
    }
}