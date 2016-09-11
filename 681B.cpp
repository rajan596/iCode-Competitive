#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n;
    cin>>n;

    string ans="NO";

    for(ll i=0;i<=1e9;i+=1234567){
        for(ll j=0;j<=1e9;j+=123456){
            ll x=n-i-j;
            if(x==0 || (x>0 && x%1234==0)) {
                ans="YES";
                break;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
