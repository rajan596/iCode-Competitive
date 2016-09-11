#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll a,b,c;
    cin>>a>>b>>c;

    int y=(b-a)/c + 1;

    if(c==0){
        if(a==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if((b-a)%c==0 && y>=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
