# include <bits/stdc++.h>
# include <atcoder/all>
#define rep(i, n) for(int i=0; i<n ; i++)
#define REP(i, n) for(int i=0; i<=n ; i++)
#define out(n) cout << n << endl;
using namespace std;
using ll = long long;


string get_a_num(int n, int a){
    string num = "";
    while(n){
        num.push_back('0' + n % a);
        n /= a;
    }
    reverse(num.begin(), num.end());
    return num;
}
bool judge_a_num(string an){
    while (an.size() > 1){
        if (an.front() != an.back()) return false;
        an.pop_back();
        an.erase(an.begin());
    }
    return true;
}

string get_palindrome(ll n, ll size){
    string strpal = to_string(n);
    if (size == 1){
        return strpal;
    } else if (size == 2) {
        return strpal + strpal;
    } else if (size % 2) {
        string re_strpal = to_string(n/10);
        reverse(re_strpal.begin(), re_strpal.end());
        return strpal + re_strpal;
    } else {
        string re_strpal = to_string(n);
        reverse(re_strpal.begin(), re_strpal.end());
        return strpal + re_strpal;
    }
}

ll solve(ll A, ll N){
    string palin = "";
    ll size = 1; ll ans = 0;
    ll counter = 1;
    ll lpl = 1;
    while(true){
        palin = get_palindrome(counter, size);
        if (!palin.empty()) {
            lpl = stoll(palin);
        }
        if(lpl > N){
            return ans;
        }
        counter++;
        if (log10(counter) == (size+1)/2){
            size += 1;
            if(size % 2 == 0) {
                counter /= 10;
                if (counter == 0) counter =1;
            }
        }
        // A-num
        string an = get_a_num(lpl, A);
        if (!judge_a_num(an)) continue;
        ans += lpl;
        cout << "pal: " << lpl << endl;
        cout << "A_num: " << an << endl;
    }
}


int main(){
    ll A, N;
    cin >> A >> N;

    // solve
    out(solve(A, N));
}