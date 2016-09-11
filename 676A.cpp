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
    int i,j;
    for(int ii=1;ii<=n;ii++) {
        int x;
        cin>>x;
        if(x==1){
            i=ii;
        }
        if(x==n){
            j=ii;
        }
    }

    int a[4];
    a[0]=abs(i-1);
    a[1]=abs(i-n);
    a[2]=abs(j-1);
    a[3]=abs(j-n);

    sort(a,a+4);

    cout<<a[3]<<endl;

    return 0;
}
