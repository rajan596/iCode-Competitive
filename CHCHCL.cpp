#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    int t;
    cin>>t;

    while(t--) {
        int a,b;
        cin>>a>>b;

        if((a&1) && (b&1)) {
            cout<<"No"<<endl;
        }else {
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}
