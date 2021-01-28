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
	string str1,str2;
	cin>>str1>>str2;
	ll n = str1.size();
	vi p(n);
	rep(i,0,n) {
		ll x;
		cin>>x;
		p[x-1] = i;
	}
	ll l = 0;
	ll r = n+1;
	while(l+1<r){
		ll mid = (l+r)/2;
 
		ll ind2 = 0;
		rep(i,0,n){
			if(p[i]>=mid&&str2[ind2]==str1[i]) ind2++;
			if(ind2==sz(str2))break;
		}
		if(ind2==sz(str2)) l = mid;
		else r = mid;
	}
	cout<<l<<endl;
}