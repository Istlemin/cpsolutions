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
 
ll memo[4][1000][1000], work[1000][1000], n, m, er, ec, dr, dc;
 
bool valid(int row, int col) { return row >= 0 && row < n && col >= 0 && col < m; }
 
ll dp(ll dir, ll row, ll col) {
    if (row == er && col == ec) return memo[dir][row][col] = work[row][col];
    if (row < 0 || col < 0 || row >= n || col >= m) return -INF;
 
    ll &ans = memo[dir][row][col];
    if (ans != -1) return ans;
 
    ans = max(dp(dir, row + dr, col), dp(dir, row, col + dc)) + work[row][col];
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> work[i][j];
 
        rep(i, 0, 4) {
        if (i == 0) {
            er = n - 1;
            ec = m - 1;
            dr = 1;
            dc = 1;
            dp(i, 0, 0);
 
        } else if (i == 1) {
            er = ec = 0;
            dr = dc = -1;
            dp(i, n - 1, m - 1);
 
        } else if (i == 2) {
            er = 0;
            ec = m - 1;
            dr = -1;
            dc = 1;
            dp(i, n - 1, 0);
 
        } else {
            er = n - 1;
            ec = 0;
            dr = 1;
            dc = -1;
            dp(i, 0, m - 1);
        }
    }
 
    ll ans = 0;
    rep(row, 0, n) rep(col, 0, m) {
        if (row == 0 || row + 1== n || col == 0 || col + 1 == m) continue;
        
        ll guy = memo[1][row - 1][col] + memo[0][row + 1][col];
        ll girl = memo[3][row][col - 1] + memo[2][row][col + 1];
        ans = max(ans, guy + girl);
 
        guy = memo[1][row][col - 1] + memo[0][row][col + 1];
        girl = memo[3][row + 1][col] + memo[2][row - 1][col];
        ans = max(ans, guy + girl);
    }
    cout << ans << endl;
    return 0;
}