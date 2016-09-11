#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,h;
    cin>>n>>h;

    int a[n+5];

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int k=1;
    bool p=1;
    bool hasbox=0;

    while(p) {
        int op;
        cin>>op;

        switch(op){
            case 1:
                if(k>1) k--;
                break;
            case 2:
                if(k<n) k++;
                break;
            case 3:
                if(a[k]>0 && !hasbox) a[k]--,hasbox=1;
                break;
            case 4:
                if(a[k]<h && hasbox) a[k]++,hasbox=0;
                break;
            default:
                p=0;
                break;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";

    return 0;
}
