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
    ll n,k,p;
    cin>>n>>k>>p;
    vi a(n); rep(i,0,n) cin>>a[i];
    vi b(k); rep(i,0,k) cin>>b[i];
    sort(all(a));
    sort(all(b));
    ll best = 1e18;
    rep(l,0,k-n+1){
        ll totTime = 0;
        rep(i,0,n){
            totTime = max(abs(a[i]-b[i+l]) + abs(p-b[i+l]),totTime);
        }
        best = min(best,totTime);
    }
    cout<<best<<endl;
}