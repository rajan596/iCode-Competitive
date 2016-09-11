#include<bits/stdc++.h>

using namespace std;

/*
n*(n-1)/2 = x => find n
*/
long long solve(long long x){
    long long i;
    for(i=0;((i)*(i-1))/2<=x;i++){
        if((i*(i-1))/2==x) return i;
    }

    return -1;
}

void fail(){
    cout<<"Impossible"<<endl;
}

void print(string s){
    cout<<s<<endl;
}

int main(){

    long long a11,a00,a10,a01;
    cin>>a00>>a01>>a10>>a11;

    long long n0=solve(a00);
    long long n1=solve(a11);

    if(n0<0 || n1<0) {
        fail();
        return 0;
    }

    if(n0==0 && (a01+a10>0)) {
        n0++;
    }

    if(n1==0 && (a01+a10>0)) {
        n1++;
    }

    if(a01+a10+a11+a00==0) {
        print("1");
        return 0;
    }

    if(a10+a01+a11+a00==1) {
        if(a00==1) print("00");
        if(a01==1) print("01");
        if(a10==1) print("10");
        if(a11==1) print("11");
        return 0;
    }

    if(a01+a10!=n0*n1) {
        fail();
        return 0;
    }

    if(n0==0) {
        while(n1--) cout<<1;
        return 0;
    }

    if(n1==0) {
        while(n0--) cout<<0;
        return 0;
    }

    int backzeroes=a10/n1;
    int left=a10%n1;

    for(int i=0;i<n0-backzeroes-(left>0);i++)
        cout<<0;

    for(int i=0;i<left;i++)
        cout<<1;

    if(left) cout<<0;

    for(int i=0;i<n1-left;i++)
        cout<<1;

    for(int i=0;i<backzeroes;i++)
        cout<<0;

    return 0;
}
