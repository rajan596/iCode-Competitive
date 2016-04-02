#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){

    ll n;
    cin>>n;

    ll a[n+2];

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    ll i=0,j=n-1;

    while(i<j){
        cout<<a[i++]<<" ";
        if(i<j)
            cout<<a[j--]<<" ";
    }

    if(i==j)
        cout<<a[i]<<endl;

    return 0;
}
