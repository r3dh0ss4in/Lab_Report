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

struct activity {
    char name[10];
    int st;
    int nd;
};

void solve() {
    int n;
    cout << "Enter the number of activity: " << endl;
    cin >> n;
    struct activity actv[n];
    for(int i=0; i<n; i++) {
        cout << "Enter the name of activity " << i+1 << ": " << endl;
        cin >> actv[i].name;
        cout << "Enter the start time of the activity " << i+1 << ": " << endl;
        cin >> actv[i].st;
        cout << "Enter the finish time of the activity " << i+1 << ": " << endl;
        cin >> actv[i].nd;
    }
    for(int i=0; i+1<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(actv[i].nd>actv[j].nd) {
                swap(actv[i],actv[j]);
            }
        }
    }
    vector<string> sel_activity;
    int c=1;
    int last_nd=actv[0].nd;
    for(int i=0; i<n; i++) {
        if(actv[i].st>=last_nd) {
            sel_activity.pb(actv[i].name);
            c++;
            last_nd=actv[i].nd;
        }
    }
    cout << "Total number of selected activity : " << c << endl;
    cout << "selected activity are :" << endl;
    for(string s : sel_activity) {
        cout << s << endl;
    }
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