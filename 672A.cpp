#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

string f(ll i){
    string ans="";
    while(i>0) {
        ans=string(1,'0'+i%10) + ans;
        i/=10;
    }
    return ans;
}

int main(){

    ll n;
    cin>>n;

    string s="";

    for(ll i=1;i<=n;i++){
        s+=f(i);
    }

    cout<<s[n-1]<<endl;

    return 0;
}
