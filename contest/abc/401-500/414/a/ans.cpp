# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;

    int x, y;
    int count = 0;
    for (int i = 0; i < n ; i++){
        cin >> x >> y;
        if (x <= l && y >= r) {
            count++;
        }
    }

    cout << count << endl;
}