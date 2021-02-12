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
 
    int tc, n, piles[200001], prev;
    vector<vector<uset<int>>> memo;
    cin >> tc;
    while (tc--) {
        cin >> n;
        memo.assign(n + 1, vector<uset<int>>(2, uset<int>()));
        memo[0][0].insert(0);
        rep(i, 0, n) cin >> piles[i];
 
        rep(i, 0, n) {
            rep(j, 0, 2) {
                trav(pile, memo[i][j]) {
                    if (pile <= piles[i]) memo[i + 1][j].insert(piles[i] - pile);
 
                    if (i+1<n&&!j&&pile<=piles[i+1]) {
                        int h = piles[i + 1] - pile;
                        if (h <= piles[i]) memo[i + 2][1].insert(piles[i] - h);
                    }
                }
            }
        }
        if (memo[n][0].count(0) || memo[n][1].count(0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}