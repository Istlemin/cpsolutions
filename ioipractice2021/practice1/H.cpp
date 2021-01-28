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
	ll n;
	cin>>n;
	vi v(n);
	rep(i,0,n) cin>>v[i];
	map<ll,ll> f;
	vi sum(n);
	sum[0] = v[0];
	rep(i,1,n) sum[i] = sum[i-1]+v[i];
	rep(i,0,n) f[sum[i]]++;
	ll mx = 0;
	trav(x,f) {
		mx = max(mx,x.second);
		//cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<n-mx<<endl;
}