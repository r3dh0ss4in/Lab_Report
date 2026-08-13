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

int const MOD=1000000007;

void f(int n, int amount, vi coins) {
    vector<vi> dp(n+1, vi (amount+1,0));
    for(int i=0; i<n; i++) {
        dp[i][0]=1;
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=amount; j++) {
            int skip=dp[i+1][j];
            int take=0;
            if(coins[i]<=j) take=dp[i][j-coins[i]];
            dp[i][j]=(skip+take)%MOD;
        }
    }
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=amount; j++) {
    //         p_arr(dp[i][j])
    //     }
    //     cout << endl;
    // }
    cout << dp[0][amount];
}

void solve() {
    int n,x; cin >> n >> x;
    vi coins(n);
    for(int &i : coins) {
        cin >> i;
    }
    f(n,x,coins);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
