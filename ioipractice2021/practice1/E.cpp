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
	vector<pii> v(n);
	rep(i,0,n) cin>>v[i].second>>v[i].first;
	sort(all(v));
	ll last = -1;
	ll ans = 0;
	rep(i,0,n){
		if(v[i].second>last){
			last = v[i].first;
			ans++;
		}
	}
	cout<<ans<<endl;
}