#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define trav(a, v) for (auto &a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
 
vi dfsNum;
vi dfsLow;
vector<bool> seen;
ll currNum = 0;
 
vector<vi> e;
vector<vi> sscs;
vi dfs_num, dfs_low, S, visited;
ll dfsNumberCounter = 0;
ll numSCC = 0;
void tarjanSCC(ll u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
 
	visited[u] = 1;
	for (ll j = 0; j < (ll)e[u].size(); j++) {
		ll v = e[u][j];
		if (dfs_num[v] == 1000000000)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		sscs.push_back(vi(0));
		while (1) {
			ll v = S.back();
			S.pop_back();
			visited[v] = 0;
			sscs[numSCC].push_back(v);
			if (u == v)
				break;
		}
		numSCC++;
	}
}
 
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n;
	vi c(n);
	e.resize(n);
	rep(i, 0, n) cin >> c[i];
	cin >> m;
	rep(i, 0, m) {
		ll a, b;
		cin >> a >> b;
		e[a - 1].push_back(b - 1);
	}
 
	dfs_num.assign(n, 1000000000); dfs_low.assign(n, 0); visited.assign(n, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < n; i++)
		if (dfs_num[i] == 1000000000)
			tarjanSCC(i);
 
	ll mod = 1e9 + 7;
	ll ans1 = 0;
	ll ans2 = 1;
 
	rep(i, 0, sscs.size()) {
		vi cs(sscs[i].size());
		rep(j,0,sscs[i].size()) cs[j] = c[sscs[i][j]];
		sort(all(cs));
		ll numMin = cs.size();
		rep(j, 0, cs.size()) if (cs[j] != cs[0]) {
			numMin = j;
			break;
		}
		//cout<<cs[0]<<" "<<numMin<<endl;
		ans1 += cs[0];
		ans2 = (ans2 * numMin) % mod;
	}
	cout << ans1 << " " << ans2 << endl;
}
