#include<bits/stdc++.h>

using namespace std;

int findMin(int a[],int l,int r){
    int mid;
    while(l<r) {
        mid=(l+r)>>1;
        //cout<<a[l]<<" "<<a[mid]<<" "<<a[r]<<endl;
        if(a[l]<=a[r]) return a[l];
        else if(mid-1>=l && mid+1<=r && a[mid]<=a[mid+1] && a[mid]<a[mid-1]){
            return a[mid];
        }
        else if(a[l]<=a[mid]) {
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return a[l];
}

int main()
{
    int a[]={5,5,5,5,5,5,5,6,7,8,9,10,10,11,1,1,1,1,1,2,2,2,3,4};
    //int a[]={5,5,5,50,1,4};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<findMin(a,0,n-1)<<endl;

    return 0;
}
