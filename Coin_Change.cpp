// https://cses.fi/problemset/task/1634/
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

void f(int n, int amount, vi coins) {
    int dp[n+1][amount+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=amount; j++) {
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=0; i<=amount; i++) {
        dp[0][i]=INT_MAX;
    }
    for(int i=0; i<=n; i++) {
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            if(j>=coins[i-1]&&dp[i][j-coins[i-1]]!=INT_MAX) {
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            } else dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][amount]!=INT_MAX) cout << dp[n][amount];
    else cout << -1;
    cout << endl;
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
