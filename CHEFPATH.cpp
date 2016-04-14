#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pb(x) push_back(x)

string funct(ll n,ll m){
        if(n==1 && m==2)
            return "Yes";
        if(m==1 && n==2)
            return "Yes";
        if(n!=1 && m!=1 && (n%2==0 || m%2==0))
            return "Yes";
        else
            return "No";
}

int main(){

    ll n,m;

    T {
        cin>>n>>m;
        cout<<funct(n,m)<<endl;
    }

    return 0;
}
