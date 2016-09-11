#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    //fin;

    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    ll na=0,nb=0;

    for(ll i=0;i<n;i++) {
        if(s[i]=='a') na++;
        else nb++;
    }

    if(k>=min(na,nb) || na==n || nb==n){
        cout<< n <<endl;
        return 0;
    }

    // case : 1 => b->a
    ll i=0,j=0;
    ll ans=0;
    queue<char> q;
    int kk=k;

    while(i<n) {
        if(s[i]=='a'){
            q.push(s[i]);
        }
        else {
            while(!q.empty() && kk<=0) {
                char c=q.front();
                q.pop();
                if(c=='b') kk++;
            }
            if(kk>0) {
                q.push(s[i]);
                kk--;
            }
        }
        //cout<<" # "<<q.size()<<endl;
        i++;
        ans=max(ans,(ll)q.size());
    }

    queue<char> q1;
    i=0,kk=k;

    while(i<n) {
        if(s[i]=='b'){
            q1.push(s[i]);
        }
        else {
            while(!q1.empty() && kk<=0) {
                char c=q1.front();
                q1.pop();
                if(c=='a') kk++;
            }
            if(kk>0) {
                q1.push(s[i]);
                kk--;
            }
        }
        i++;
        ans=max(ans,(ll)q1.size());
    }

    cout<<ans<<endl;
    return 0;
}
