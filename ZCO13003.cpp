#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);

    int j=0;
    long long ans=0;

    for(int i=0;i<n;i++){
        int j=lower_bound(a+i+1,a+n,k-a[i])-a;
        ans+=j-i;
    }

    cout<<ans-n<<endl;

    return 0;
}
