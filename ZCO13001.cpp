#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n+5];

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    long long s[n+5];

    s[n-1]=a[n-1];

    for(int i=n-2;i>=0;i--){
        s[i]=s[i+1]+a[i];
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=s[i]-(n-i)*a[i];
    }

    cout<<ans<<endl;

    return 0;
}
