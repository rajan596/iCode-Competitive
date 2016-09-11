#include<bits/stdc++.h>

using namespace std;

const int N=100055;

int LPD[1000006];
int a[N];
int segTree[4*N];

void f(){
    for(int i=0;i<=1e6;i++) LPD[i]=0;

    LPD[1]=1;
    LPD[0]=1;

    for(int i=2;i<=1e6;i++){
        if(LPD[i]==0) {
            for(int j=i;j<=1e6;j+=i){
                if(LPD[j]==0)
                    LPD[j]=i;
            }
        }
    }
}

void initialize(int l,int r,int node){
    if(l>r) return;
    if(l==r) {
        segTree[node]=LPD[a[l]];
        return;
    }
    int mid=(r+l)/2;
    initialize(l,mid,2*node);
    initialize(mid+1,r,2*node+1);
    segTree[node]=max(segTree[2*node],segTree[2*node+1]);
}

void update(int ul,int ur,int l,int r,int node){
    if(l>r) return;
    if(ur<l || ul>r) return;
    if(l==r) {
        a[l]=a[l]/LPD[a[l]];
        segTree[node]=LPD[a[l]];
        return;
    }
    if(segTree[node]==1) return;
    int mid=l+(r-l)/2;
    update(ul,ur,l,mid,2*node);
    update(ul,ur,mid+1,r,2*node+1);
    segTree[node]=max(segTree[2*node],segTree[2*node+1]);
}

int query(int ql,int qr,int l,int r,int node){
    if(l>r) return 1;

    if(l>qr || r<ql) return 1;
    if(ql<=l && qr>=r) return segTree[node];

    if(segTree[node]==1) return 1;

    int mid=(r+l)/2;
    int L=query(ql,qr,l,mid,2*node);
    int R=query(ql,qr,mid+1,r,2*node+1);
    return max(L,R);
}

int main(){

    f();

    int t;
    scanf("%d",&t);

    while(t--) {

        int n,m;
        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        initialize(1,n,1);

        while(m--) {
            int type;
            scanf("%d",&type);

            int l,r;
            scanf("%d %d",&l,&r);

            if(type==0) {
                update(l,r,1,n,1);
            }
            else {
                int y=query(l,r,1,n,1);
                printf("%d ",y);
            }
        }
        printf("\n");
    }

    return 0;
}
