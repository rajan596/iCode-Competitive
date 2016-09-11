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
        int n;
        string origin;
        cin>>n>>origin;
        int score=0;
        while(n--) {
            string type;
            cin>>type;

            if(type=="CONTEST_WON") {
                int r;
                cin>>r;
                score+=300+max(0,20-r);
            }
            else if(type=="TOP_CONTRIBUTOR"){
                score+=300;
            }
            else if(type=="BUG_FOUND"){
                int s;
                cin>>s;
                score+=s;
            }
            else if(type=="CONTEST_HOSTED"){
                score+=50;
            }
        }
        if(origin=="INDIAN") cout<<score/200<<endl;
        else cout<<score/400<<endl;
    }

    return 0;
}
