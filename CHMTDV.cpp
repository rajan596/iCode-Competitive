/*
Approximation Codechef
*/

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,p;
    cin>>n>>p;

    int x;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>x;

    int y=n/p;
    for(int i=1;i<p;i++)
        cout<<(y*i)<<" ";

    cout<<"\n";
    for(int i=1;i<p;i++)
        cout<<(y*i)<<" ";

    return 0;
}
