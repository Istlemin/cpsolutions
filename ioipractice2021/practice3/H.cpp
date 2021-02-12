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
 
    vector<pair<short, short>> nums;
    short n, k, sum_fives = 0, sum_twos = 0, sum;
    cin >> n >> k;
    ll num;
    rep(i, 0, n) {
        cin >> num;
        short fives = 0, twos = 0;
        while (!(num % 5)) {
            ++fives;
            num /= 5;
        }
 
        while (!(num % 2)) {
            ++twos;
            num /= 2;
        }
        sum_twos += twos;
        sum_fives += fives;
        if (fives || twos) nums.emplace_back(twos, fives);
    }
 
    sum = sum_twos + sum_fives + 1;
    short ans = 0;
 
    n = sz(nums);
    k = min(k, n);
    if (!n) {
        cout << 0 << endl;
        return 0;
    }
 
    vector<vector<short>> dp, dp2, dummy(k, vector<short>(sum, -1));
    dp = dp2 = dummy;
    dp[0][sum_twos] = 0;
 
    rep(i, 0, n) {
        short stop = min(k, short(i + 1));
        rep(j, 0, stop) {
            rep(l, 0, sum) {
                if (dp[j][l] == -1) continue;
                dp2[j][l] = max(dp2[j][l], dp[j][l]);
 
                short actual_fives, actual_twos, twos = 0;
                if (l < sum_twos) {
                    actual_twos = sum_twos - l;
                    actual_fives = 0;
                } else {
                    actual_fives = l - sum_twos;
                    actual_twos = 0;
                }
 
                actual_twos += nums[i].first;
                actual_fives += nums[i].second;
                int next_fives = actual_fives - actual_twos + sum_twos;
 
                if (j + 1 == k)
                    ans = max(ans, short(dp[j][l] + min(actual_twos, actual_fives)));
                else dp2[j + 1][next_fives] = max(dp2[j + 1][next_fives], short(dp[j][l] + min(actual_twos, actual_fives)));
                
            }
        }
        dp.swap(dp2);
        dp2 = dummy;
    }
 
    cout << ans << endl;
    return 0;
}
