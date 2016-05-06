#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    int n;
    cin>>n;

    int x=2*(n/7);
    int y=n%7;

    int mn=x,mx=x;

    if(y==1) mx++;
    else if(y>1)mx+=2;

    if(y==6) mn++;

    cout<<mn<<" "<<mx<<endl;

    return 0;
}
