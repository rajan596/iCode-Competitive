#include<bits/stdc++.h>

using namespace std;

int findPP(int a[],int b[],int n){
    int temp=0,s=0,e=0;

    do{
        temp+=a[e]-b[e];
        if(temp<0) {
            temp=0;
            s=(e+1)%n;
        }
        e=(e+1)%n;
    }while(s!=e && s!=0);

    return s;
}

int main()
{

    int a[]={4,6,7,4};
    //int b[]={6,5,3,5};
    int b[]={2,5,3,5};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<findPP(a,b,n)<<endl;

    return 0;
}
