# include <bits/stdc++.h>
# include <vector>
# define rep(i, N) for(int i =0; i < N; ++i)
using namespace std;

vector<int> v;

int binary_search(int quiz){
    int s = 0, e = v.size();
    while (e-s > 1){
        int c = s + (e-s)/2;
        if (v[c] >= quiz){
            e = c;
        } else {
            s = c;
        }
    }
    return e;
}


int main(){
    int N, Q;
    cin >> N >> Q;
    int quiz;
    v.resize(N);

    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());

    rep(i, Q) {
        cin >> quiz;
        if (v[N-1] < quiz) {
            cout << 0 << endl;
            continue;
        }
        if (v[0] >= quiz){
            cout << N << endl;
            continue;
        }
        cout << N - binary_search(quiz) << endl;
    }

    return 0;
}