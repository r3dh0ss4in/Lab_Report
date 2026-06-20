#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define endl '\n'
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
#define ft first
#define sd second
#define pb push_back
#define bug(a) cout << #a << " : " << a << endl;
#define bug2(a, b) cout << #a << " : " << a << "   " << #b << " : " << b << endl;
#define p_arr(a) cout << a << " ";

void f(int w,vi weight,vi values,int n) {
    vector<vi> dp(n+1,vi (w+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            if(weight[i-1]<=j) {
                dp[i][j]=max(values[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            } else dp[i][j]=dp[i-1][j];
        }
    }
    cout << "Maximum Value: " << dp[n][w] << endl;
    cout << "Items : ";
    int j=w;
    for(int i=n; i>0; i--) {
        if(dp[i][j]==dp[i-1][j]) continue;
        else {
            p_arr(i);
            j-=weight[i-1];
        }
    }
}

void solve() {
    int n,w; cin >> n >> w;
    vi values(n),weight(n);
    for(int &i : values) {
        cin >> i;
    }
    for(int &i : weight) {
        cin >> i;
    }
    f(w,weight,values,n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    // int t; cin >> t;
    // int tc=1;
    // while(t--) {
    //     // cout << "tc #" << tc++ << " ";
    //     // cout << endl;
    //     solve();
    //     cout << endl;
    // }
}