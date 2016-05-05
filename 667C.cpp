#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

string s;
int n;
set<string> x;
int dp[1000006][5];

void solve(int n,string pre){
    //cout<<n<<" "<<pre<<endl;

    //cerr<<n << " "<<pre<< " "<<dp[n-2][3] <<" "<<dp[n-1][2] <<endl;

    if(n-2>4 && !dp[n-2][3]){
        string t="";
        t.push_back(s[n-2]);
        t.push_back(s[n-1]);
        t.push_back(s[n]);

        if(pre!=t) {
            x.insert(t);
            solve(n-3,t);
            dp[n-2][3]=1;
        }
    }

    if(n-1>4 && !dp[n-1][2]){
        string t="";
        t.push_back(s[n-1]);
        t.push_back(s[n]);

        if(pre!=t) {
            x.insert(t);
            solve(n-2,t);
            dp[n-1][2]=1;
        }
    }

}

int main(){

    cin>>s;
    n=s.length();

    solve(n-1,"");

    cout<<x.size()<<endl;

    for(set<string>::iterator it=x.begin();it!=x.end();it++){
        cout<<(*it)<<endl;
    }

    return 0;
}
