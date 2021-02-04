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
 
int main(){
	cin.sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	map<string,ll> m;
	ll ans = 0;
	m["polycarp"] = 1;
	rep(i,0,n){
		string a,ign,b;
		cin>>a>>ign>>b;
		rep(i,0,a.size()) a[i] = tolower(a[i]);
		rep(i,0,b.size()) b[i] = tolower(b[i]);
 
		m[a] = m[b]+1;
		ans = max(ans,m[a]);
	}
	cout<<ans<<endl;
 
}
