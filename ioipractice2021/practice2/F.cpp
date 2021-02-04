#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
 
vi a;
vi d;
vector<vector<pii>> e;
vi add;
 
void getDist(ll v,ll dist){
	d[v] = dist;
	rep(i,0,e[v].size()) getDist(e[v][i].first,dist+e[v][i].second);
}
 
vi ans;
 
ll getAns(ll v){
	ans[v] = add[v];
	rep(i,0,e[v].size())
		ans[v] += getAns(e[v][i].first);
	return ans[v];
}
 
int main(){
	cin.sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	a.resize(n);
	d.resize(n);
	add.resize(n);
	vi p(n);
	vector<vi> jump(30,vi(n));
	e.resize(n);
	rep(i,0,n) cin>>a[i];
	rep(i,1,n){
		ll w;
		cin>>p[i]>>w;
		p[i]--;
		e[p[i]].emplace_back(i,w);
	}
	getDist(0,0);
	//rep(i,0,n) cout<<d[i]<<" ";
	//cout<<endl;
	jump[0] = p;
	rep(i,1,30)
		rep(j,0,n)
			jump[i][j] = jump[i-1][jump[i-1][j]];
 
	rep(i,1,n){
		add[p[i]]++;
		ll to = i;
		for(ll j = 29;j>=0;j--){
			ll newTo = jump[j][to];
			if(d[i]-d[newTo]<=a[i]) to = newTo;
		}
		if(to!=0)
			add[p[to]]--;
	}
 
	ans.resize(n);
	getAns(0);
	rep(i,0,n) cout<<ans[i]<<" ";
	cout<<endl;
}
