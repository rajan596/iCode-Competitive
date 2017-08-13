/*
SPOJ : http://www.spoj.com/problems/AGGRCOW/
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,c;
int A[100005];

bool f(int x){
    int total=1;

    int last=0;
    for(int i=1;i<n;i++){
        if(A[i]-A[last]>=x) {
            total++;
            last=i;
        }
    }

    return total>=c;
}

int solve(){

    cin>>n>>c;

    for(int i=0;i<n;i++)
        cin>>A[i];

    sort(A,A+n);

    int low=1,high=A[n-1]-A[0];

    int mid;
    int ans=0;

    while(low<=high) {
        mid=low+(high-low)/2;

        if(f(mid)) {
            ans=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }

    return ans;
}

int main() {
	// your code goes here

	int T;
	cin>>T;

	while(T--) {
	    cout<<solve()<<endl;
	}

	return 0;
}
