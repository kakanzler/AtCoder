# include <bits/stdc++.h>
# include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n ; i++)

int main(){
    int N, x=0;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i<N ; i++){
        cin >> a[i];
        if (a[i] > x) x = a[i];
    }
    vector<int> gcd(x+1);
    fill(gcd.begin(), gcd.end(), 0);

    for (int i = 2; i<=x ; i++){
        for (int j = 0; j<N ; j++){
            if (a[j]%i == 0) gcd[i] +=1;
        }
    }

    vector<int>::iterator itr = max_element(begin(gcd), end(gcd));
    cout << distance(gcd.begin(), itr) << endl;

    return 0;
}