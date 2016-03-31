#include<bits/stdc++.h>

using namespace std;

#define ll int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n,m;
    cin>>n>>m;

    map< ll , vector< pair< ll , string > > > mp;

    for(ll i=0;i<n;i++) {
        ll regno,score;
        string name;
        cin>>name>>regno>>score;

        mp[regno].push_back({score,name});
    }

    for(ll i=1;i<=m;i++){
        if(mp[i].size()<2){
            cout<<"?"<<endl;
            continue;
        }
        sort(mp[i].begin(),mp[i].end());
        ll len=mp[i].size();
        if(mp[i].size()>2 && mp[i][len-3].first==mp[i][len-2].first){
            cout<<"?"<<endl;
        }else{
            cout<<mp[i][len-1].second<<" "<<mp[i][len-2].second<<endl;
        }
    }

    return 0;
}
