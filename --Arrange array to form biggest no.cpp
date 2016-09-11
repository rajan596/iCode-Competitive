#include<bits/stdc++.h>

using namespace std;

bool compare(int a,int b){
    char *A,*B;
    itoa(a,A,10);
    itoa(b,B,10);
}

int main()
{

    int a[]={54,546,548,60};
    int n=sizeof(a)/sizeof(a[0]);

    sort(a,a+n,compare);

    for(int i=0;i<n;i++) cout<<a[i] <<"";

    return 0;
}
