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
 
class Fenwick {
   private:
    vector<ll> ft;
 
   public:
    Fenwick(int n) { ft.assign(n + 1, 0); }
 
    ll rsq(int i) {
        ll sum = 0;
        for (; i; i ^= i & -i) sum += ft[i];
        return sum;
    }
 
    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
 
    void update(int i, int v) {
        for (; i < sz(ft); i += i & -i) ft[i] += v;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, num, prev = 1;
    ll ans = 0;
    vi nums[100001];
    cin >> n;
    Fenwick tree(n);
    rep(i, 0, n) {
        cin >> num;
        nums[num].pb(i + 1);
    }
 
    rep(i, 1, 100001) {
        vi curr = nums[i];
        if (curr.empty()) continue;
 
        int indx = curr[sz(curr) - 1];
        rep(j, 0, sz(curr)) {
            if (curr[j] >= prev) {
                if (j) indx = curr[j - 1];
                break;
            }
        }
 
        if (indx < prev) {
            ans += n - prev - tree.rsq(prev, n)+1;
            prev=1;
        }
        ans += indx - prev - tree.rsq(prev, indx) + 1;
 
        prev = indx;
        trav(indx, curr) tree.update(indx, 1);
    }
    cout << ans << endl;
    return 0;
}