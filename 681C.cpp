#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

string f(ll x){
    if(x==0) return "0";
    string s="";
    if(x<0) {
        x=-x;
        s="-";
    }
    string a="";
    while(x) {
        a=char('0'+x%10)+a;
        x=x/10;
    }
    return s+a;
}

int main(){
    //fin;
    fastio;
    priority_queue<ll,vector<ll>,greater<ll> > q;

    ll t;
    cin>>t;

    vector< pair<string,int> > ans;

    while(t--){
        string x;
        cin>>x;

        if(x=="insert"){
            ll y;
            cin>>y;

            q.push(y);
            ans.push_back(make_pair(x,y));
        }
        else if(x=="getMin") {
            ll y;
            cin>>y;

            while(!q.empty() && q.top()<y) {
                ans.push_back(make_pair("removeMin",-1));
                q.pop();
            }

            if(q.empty() || q.top()>y){
                q.push(y);
                ans.push_back(make_pair("insert",y));
            }

            ans.push_back(make_pair(x,y));
        }
        else if(x=="removeMin"){
            if(q.empty()){
                q.push(1);
                ans.push_back(make_pair("insert",1));
            }
            q.pop();
            ans.push_back(make_pair("removeMin",-1));
        }
    }

    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++){
        if(ans[i].first=="removeMin")
            cout<<ans[i].first<<endl;
        else
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}
