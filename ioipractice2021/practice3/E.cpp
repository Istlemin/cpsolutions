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
 
int n;
ll memo[100001][2], energy[100001];
string words[100001];
 
ll dp(int i, bool rev){
    if (i>n) return 0;
 
    string prev=words[i-1], curr =words[i];
    if (rev) reverse(all(prev));
 
    ll &ans=memo[i][rev];
    if(ans!=-1)return ans;
 
    ans=1e16;
    if (curr>=prev)ans=dp(i+1,0);
    reverse(all(curr));
    if(curr>=prev)ans=min(ans,dp(i+1,1)+energy[i]);
 
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    words[0]="A";
    memset(memo,-1,sizeof(memo));
    cin>>n;
    rep(i,0,n)cin>>energy[i+1];
    rep(i,0,n)cin>>words[i+1];
 
    ll ans=dp(1,0);
    if (ans>1e15)ans=-1;
    cout<<ans<<endl;
    return 0;
}