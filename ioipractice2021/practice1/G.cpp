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
	ll n,m,w;
	cin>>n>>m>>w;
	vi a(n);
	rep(i,0,n) cin>>a[i];
 
	ll l = 0;
	ll r = 1e11;
	while(l+1<r){
		ll mid = (l+r)/2;
		//cout<<"Trying "<<mid<<endl;
		ll days = 0;
		ll added = 0;
		vi sub(n+w);
		rep(i,0,n){
			if(a[i]+added<mid){
				ll newAdd = mid - (a[i]+added);
				//cout<<i<<": "<<added<<" "<<newAdd<<endl;
				days += newAdd;
				added += newAdd;
				sub[i+w-1] += newAdd;
			}
			added -= sub[i];
		}
		if(days<=m) l = mid;
		else r = mid;
	}
	cout<<l<<endl;
}