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
 
ll n,s,m,k;
 
vi a;
vi l;
vi r;
 
bool test(ll mx){
	//cout<<mx<<": ";
	vi to(n,n+1);
	vector<vi> start(n);
	vector<vi> stop(n);
	rep(i,0,s){
		start[l[i]].push_back(i);
		stop[r[i]].push_back(i);
	}
 
	multiset<ll> left;
 
	rep(i,0,n){
		rep(j,0,start[i].size()) left.insert(i);
 
		if(left.size())
			to[i] = *left.begin();
		//cout<<i<<": ";
		//trav(v,left) cout<<v<<" ";
		//cout<<endl;
		rep(j,0,stop[i].size()) left.erase(left.find(l[stop[i][j]]));
	}
	//cout<<endl;
 
 
 
	vector<vi> dp(n+2,vi(m+1));
	rep(i,0,n){
		ll points = 0;
		rep(j,to[i],i+1) {
			points += (a[j]<=mx);
		}
		rep(w,1,m+1){
			dp[i+1][w] = max(dp[to[i]][w-1]+points,dp[i][w]);
		}
		//cout<<dp[i+1]<<" ";
	}
//	cout<<endl;
	return dp[n][m]>=k;
}
 
int main(){
	cin.sync_with_stdio(false); cin.tie(0);
	cin>>n>>s>>m>>k;
	a.resize(n);
	rep(i,0,n) cin>>a[i];
 
	l.resize(s);
	r.resize(s);
	rep(i,0,s) {
		cin>>l[i]>>r[i];
		--l[i]; --r[i];
	}
	ll dn = 0;
	ll up = 1e18;
 
	while(dn+1<up){
		ll mid = (dn+up)/2;
		if(test(mid)) up = mid;
		else dn = mid;
	}
	if(up==1e18) cout<<-1<<endl;
	else cout<<up<<endl;
}
