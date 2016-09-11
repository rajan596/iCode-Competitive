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

    while(n--) {
        string name;
        int before,after;
        cin>>name>>before>>after;

        if(after>before && before>=2400) {
            ans="YES";
        }
    }

    cout<<ans<<endl;

    return 0;
}
