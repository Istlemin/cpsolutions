#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a - 1; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
 
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
 
#define umap unordered_map
#define uset unordered_set
#define INF 1000000007
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    string str;
    int m, prefix[200001], l, r;
    prefix[0] = prefix[1] = 0;
    cin>>str>>m;
    rep(i,2,sz(str)+1) prefix[i] = prefix[i - 1] + (str[i - 1] == str[i - 2]);
 
    while(m--){
        cin>>l>>r;
        cout<<prefix[r]-prefix[l]<<endl;
    }
    return 0;
}