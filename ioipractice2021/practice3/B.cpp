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
 
int n, lens[3], memo[3][4001];
 
 
int solve(int curr, int left) {
    if (!left) return 0;
    else if (left < 0 || curr >= 3) return -INF;
 
    if (memo[curr][left] != -1) return memo[curr][left];
    return memo[curr][left] = max(solve(curr + 1, left), solve(curr, left - lens[curr]) + 1);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    memset(memo,-1,sizeof(memo));
    cin>>n;
    rep(i,0,3)cin>>lens[i];
    cout<<solve(0,n)<<endl;
    return 0;
}