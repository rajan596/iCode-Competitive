#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,d,b;
    cin>>n>>b>>d;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int ans=0,dd=0;
    for(int i=0;i<n;i++){
        if(a[i]>b) continue;

            dd+=a[i];
            if(dd>d) {
                dd=0;
                ans++;
            }

    }

    cout<<ans<<endl;

    return 0;
}
