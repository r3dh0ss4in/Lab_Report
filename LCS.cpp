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

void f(string s1,string s2) {
    int a=s1.length();
    int b=s2.length();
    vector<vi> dp(a+1, vi (b+1,0));
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << "LCS : ";
    cout << dp[a][b] << endl;
    string lcs="";
    int i=a,j=b;
    while(i>0&&j>0) {
        if(s1[i-1]==s2[j-1]) {
            lcs+=s1[i-1];
            i--;
            j--;
        } else if(dp[i-1][j]>dp[i][j-1]) {
            i--;
        } else j--;
    }
    reverse(lcs.begin(),lcs.end());
    cout << "LCS chars... : ";
    cout << lcs;
}

void solve() {
    string s1,s2; cin >> s1 >> s2;
    f(s1,s2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    // int t; cin >> t;
    // int tc=1;
    // while(t--) {
    //     // cout << "Case " << tc++ << ":";
    //     // cout << endl;
    //     solve();
    //     cout << endl;
    // }
}
