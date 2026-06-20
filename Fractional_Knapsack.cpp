#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define endl '\n'
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
// #define ft first
// #define sd second
#define pb push_back
#define bug(a) cout << #a << " : " << a << endl;
#define bug2(a, b) cout << #a << " : " << a << "   " << #b << " : " << b << endl;
#define p_arr(a) cout << a << " ";

struct items {
    int ft;
    int sd;
};

bool cmp(items a,items b) {
    return (ll)a.ft*b.sd>(ll)b.ft*a.sd;
}

double f(int w,vector<items> &v) {
    sort(v.begin(),v.end(),cmp);
    double tot=0;
    for(auto i : v) {
        if(w>=i.sd) {
            w-=i.sd;
            tot+=i.ft;
        } else {
            tot+=i.ft*((double)w/i.sd);
            break;
        }
    }
    return tot;
}

void solve() {
    int n,w; cin >> n >> w;
    vector<items> v;
    for(int i=0; i<n; i++) {
        int a,b; cin >> a >> b;
        v.pb({a,b});
    }
    double max_val=f(w,v);
    cout << max_val;
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
