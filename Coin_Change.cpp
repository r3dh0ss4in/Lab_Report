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

void f(int n,int amount,vi coins) {
    int dp[n+1][amount+1];
    dp[0][0]=0;
    for(int i=1; i<=n; i++) {
        dp[i][0]=0;
    }
    for(int i=1; i<=amount; i++) {
        dp[0][i]=INT_MAX;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            if(j>=coins[i-1]) dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout << "Min Coins" << endl;
    cout << dp[n][amount];
    cout << "Items : " << endl;
    int i=n;
    int j=amount;
    while(j>0&&i>0) {
        if(dp[i][j]==dp[i-1][j]) i--;
        else {
            cout << coins[i-1] << " ";
            j-=coins[i-1];
        }
    }
}

void solve() {
    int n, amount; cin >> n >> amount;
    vi c(n);
    for(int &i : c) {
        cin >> i;
    }
    f(n,amount,c);
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
