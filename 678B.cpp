#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int leapYear(ll x){
    if(x%400==0) return 1;
    if(x%4==0 && x%100!=0) return 1;
    return 0;
}

int main(){

    ll y;
    cin>>y;

    ll days=0;

    for(ll x=y;;x++){
        if(leapYear(x)) days=(days+366)%7;
        else days=(days+365)%7;

        if(x!=y && days==0 && leapYear(x+1)==leapYear(y)) {
            cout<<x+1<<endl;
            break;
        }
    }

    return 0;
}
