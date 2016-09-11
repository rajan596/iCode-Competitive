#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll t;
    cin>>t;

    while(t--) {
        ll k;
        cin>>k;

        string ans="";
        k--;

        while(k>0) {
            ans=string(1,'0'+(k%5)*2) + ans;
            k=k/5;
        }

        if(ans=="") ans="0";

        cout<<ans<<endl;
    }

    return 0;
}
