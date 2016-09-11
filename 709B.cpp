#include<bits/stdc++.h>

using namespace std;

int main(){

    long long n,a;
    cin>>n>>a;

    long long x[n],sum=0;
    for(int i=0;i<n;i++)
        cin>>x[i];

    sort(x,x+n);

    if(n==1) {
        cout<<"0"<<endl;
        return 0;
    }

    vector<long long> ans;

    if(x[0]>=a){
        ans.push_back(x[n-2]-a);
    }
    else if(x[n-1]<=a) {
        ans.push_back(a-x[1]);
    }
    else if(x[1]>=a) {
        ans.push_back(x[n-1]-a);
        ans.push_back(a-x[0]+x[n-2]-x[0]);
        if(a<=x[n-2]) ans.push_back(x[n-2]-a+x[n-2]-x[0]);
    }
    else if(x[n-2]<=a){
        ans.push_back(a-x[0]);
        ans.push_back(x[n-1]-a+x[n-1]-x[1]);
        if(a>=x[1])ans.push_back(a-x[1]+x[n-1]-x[1]);
    }
    else {
        if(a>=x[0]) ans.push_back(a-x[0]+x[n-2]-x[0]);
        if(a>=x[1]) ans.push_back(a-x[1]+x[n-1]-x[1]);
        if(a<=x[n-1]) ans.push_back(x[n-1]-a+x[n-1]-x[1]);
        if(a<=x[n-2]) ans.push_back(x[n-2]-a+x[n-2]-x[0]);
    }

    sort(ans.begin(),ans.end());

    cout<<ans[0]<<endl;

    return 0;
}
