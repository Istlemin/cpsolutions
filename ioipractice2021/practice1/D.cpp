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
	vi d(n);
	vi c(n);
	rep(i,0,n) cin>>c[i]>>d[i];
 
	ll nowMax = 1e18;
	ll nowMin = -1e18;
	ll add = 0;
 
	for(ll i = n-1;i>=0;i--){
		add-=c[i];
		if(d[i]==1){
			nowMin = max(nowMin,1900-add);
		} else {
			nowMax = min(nowMax,1900-add);
		}
	}
 
	if(nowMax == 1e18) cout<<"Infinity"<<endl;
	else if(nowMax>nowMin) cout<<nowMax-1<<endl;
	else cout<<"Impossible"<<endl;
}