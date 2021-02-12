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
 
struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = 1e15, madd = 0, val = -1e15;
    Node(ll lo, ll hi) : lo(lo), hi(hi) {}
 
    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = min(l->val, r->val);
        } else
            val = v[lo];
    }
 
    ll query(ll L, ll R) {
        if (R <= lo || hi <= L) return 1e15;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != 1e15)
                mset += x;
            else
                madd += x;
            val += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != 1e15)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = 1e15;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m, l, r, v;
    cin >> n;
    vector<ll> nums(1LL << ll(ceil(log2(n))), 1e15);
    rep(i, 0, n) cin >> nums[i];
    Node segtree(nums,0,sz(nums));
 
    cin >> m;
    while (m--) {
        cin >> l >> r;
        if (cin.peek() == '\n') {
            if (l > r)
                cout << min(segtree.query(0, r+1), segtree.query(l, n)) << endl;
            else
                cout << segtree.query(l, r+1) << endl;
        } else {
            cin >> v;
            if (l > r) {
                segtree.add(0, r+1, v);
                segtree.add(l, n, v);
            } else
                segtree.add(l, r+1, v);
        }
    }
    return 0;
}