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
 
class UnionFind {
   public:
    vi p, rank;
    int numSets;
 
    UnionFind(int n) {
        p.assign(n, 0);
        rep(i, 0, n) p[i] = i;
        rank.assign(n, 0);
        numSets = n;
    }
 
    int findSet(int i) { return p[i] == i ? i : p[i] = findSet(p[i]); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int num() { return numSets; }
 
    void unionSet(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if (i == j) return;
        --numSets;
        if (rank[i] > rank[j]) swap(i, j);
        p[i] = j;
        if (rank[i] == rank[j]) ++rank[j];
    }
    void reset(int n) {
        p.assign(n, 0);
        rep(i, 0, n) p[i] = i;
        rank.assign(n, 0);
        numSets = n;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    vi graph[100002];
    int k, n, left, right, m, q, dis_sets[10002], curr = 10, lose[10002];
    lose[0] = 0;
    cin >> n >> k >> m;
 
    UnionFind birds(n), groups(n), ufds(n);
 
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[min(--u, --v)].pb(max(u, v));
    }
 
    rep(i, 0, n) {
        trav(fri, graph[i]) {
            if (i / 10 == fri / 10 && !groups.isSameSet(i, fri)) {
                groups.unionSet(i, fri);
                ufds.unionSet(i, fri);
                --curr;
            }
        }
 
        if (i + 1 == n || i % 10 == 9) {
            dis_sets[i / 10] = curr;
            if (i / 10) dis_sets[i / 10] += dis_sets[i / 10 - 1];
 
            if (i != 9) {
                int overlap = 0;
                rep(j, i - k - 9, i - 9) {
                    trav(fri, graph[j]) {
                        if (!ufds.isSameSet(j, fri) && j / 10 != fri / 10) {
                            ufds.unionSet(j, fri);
                            ++overlap;
                        }
                    }
                }
                lose[i / 10] = overlap + lose[i / 10 - 1];
            }
            curr = 10;
        }
    }
 
    ufds.reset(n);
    cin >> q;
    while (q--) {
        cin >> left >> right;
        --left;
        --right;
        int ans = 0, group_left = left / 10, group_right = right / 10;
 
        if (group_right - group_left <= 1) {
            ans = right - left + 1;
            rep(i, left, right + 1) {
                trav(fri, graph[i]) if (fri <= right && !birds.isSameSet(i, fri)) {
                    birds.unionSet(i, fri);
                    --ans;
                }
            }
 
        } else {
            if (left % 10) ++group_left;
            if (right % 10 != 9) --group_right;
 
            ans = dis_sets[group_right] - (group_left > 0 ? dis_sets[group_left - 1] : 0) - lose[group_right] + lose[group_left];
            ans += group_left * 10 - left;
            rep(i, group_left * 10, (group_left + 1) * 10) {
                trav(fri, graph[i]) {
                    if (fri < (group_left + 1) * 10 && !birds.isSameSet(i, fri)) birds.unionSet(i, fri);
                }
            }
 
            rep(i, left, group_left * 10) {
                trav(fri, graph[i]) {
                    if (!birds.isSameSet(i, fri)) {
                        birds.unionSet(i, fri);
                        --ans;
                    }
                }
            }
 
            if (right % 10 != 9) {
                rep(i, group_right * 10, (group_right + 1) * 10) {
                    trav(fri, graph[i]) {
                        if (fri < (group_right + 1) * 10 && !birds.isSameSet(i, fri)) birds.unionSet(i, fri);
                    }
                }
                ++group_right;
                ans += right - group_right * 10 + 1;
                rep(i, group_right * 10 - k, right + 1) {
                    trav(fri, graph[i]) if (fri >= group_right * 10 && fri <= right && !birds.isSameSet(i, fri)) {
                        birds.unionSet(i, fri);
                        --ans;
                    }
                }
            }
        }
        cout << ans << endl;
        birds = ufds;
    }
    return 0;
}