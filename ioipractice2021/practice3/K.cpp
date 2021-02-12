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
 
vector<vector<int>> memo(101, vector<int>((1 << 17), -1));
vi primes;
vii nums;
int n, arr[101];
 
void sieve() {
    bitset<61> p;
    rep(i, 2, 60) {
        if (p[i]) continue;
        primes.pb(i);
        for (int j = i * i; j < 60; j += i) p[j] = 1;
    }
}
 
int dp(int i, int mask) {
    if (i == n) return memo[i][mask] = 0;
 
    int &ans = memo[i][mask];
    if (ans != -1) return ans;
 
    ans = 10000;
    trav(num, nums) {
        if (num.second == (num.second & mask)) ans = min(ans, int(dp(i + 1, mask ^ num.second) + abs(num.first - arr[i])));
    }
    return ans;
}
 
void print_dp(int i, int mask) {
    if (i == n) return;
 
    int val = memo[i][mask];
    trav(num, nums) {
        if (val == memo[i + 1][mask ^ num.second] + abs(num.first - arr[i]) && num.second == (num.second&mask)) {
            cout << num.first << ' ';
            print_dp(i + 1, mask ^ num.second);
            break;
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    sieve();
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
 
    rep(i, 1, 60) {
        int factors = 0, j = i;
 
        rep(l, 0, 17) {
            if (j % primes[l]) continue;
            factors |= 1 << l;
            j /= primes[l];
        }
        nums.emplace_back(i, factors);
    }
 
    dp(0, (1 << 17) - 1);
    print_dp(0, (1 << 17) - 1);
    return 0;
}