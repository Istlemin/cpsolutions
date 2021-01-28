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
	ll n,m;
	cin>>n>>m;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(all(a));
	ll ans = 0;
	while(m>0){
		m-=a.back();
		a.pop_back();
		++ans;
	}
	cout<<ans<<endl;
}