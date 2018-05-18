#include<iostream>
#define ll long long
#define s(a) scanf("%Ld",&a)
#define p(a) printf("%lld",a)

using namespace std;

ll int tree[10000]={0},a[10000]={0};

void build(ll int root,ll int s,ll int e)
{
    if(s==e)
    {
        tree[root]=a[s];
        return ;
    }
    ll int mid=(s+e)/2;
    build(2*root,s,mid);
    build(2*root+1,mid+1,e);
    tree[root]=tree[2*root]+tree[2*root+1];
    return ;
}
void update(ll int root, ll int s,ll int e,ll int val,ll int idx)
{
    if(s==e)
    {
        tree[root]=val;
        return ;
    }
    ll int mid=(s+e)/2;
    if( idx<=mid && idx>=s)
    update(2*root,s,mid,val,idx);
    if( idx>mid && idx<=e)
    update(2*root+1,mid+1,e,val,idx);
    tree[root]=tree[2*root]+tree[2*root+1];
    return ;
}
ll int query(ll int root, ll int s,ll int e, ll int l, ll int r)
{
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
    {
        return tree[root];
    }
    ll int mid =(s+e)/2;
    ll int s1=query(2*root,s,mid,l,r);
    ll int s2=query(2*root+1,mid+1,e,l,r);
    return s1+s2;

}
int main()
{
    ll int i,j,n,m;
    cin>>m;
    tree[0]=0,a[0]=0;
    for(i=1;i<=4*m;i++)
    {
        tree[i]=0;
        a[i]=0;
    }
    for(i=1;i<=m;i++)
    cin>>a[i];
    build(1,1,m);
    for(i=1;i<=4*m;i++)
    {
        cout<<tree[i]<<" ";
    }
    update(1,1,m,8,5);
    for(i=1;i<=4*m;i++)
    {
        cout<<tree[i]<<" ";
    }

    return 0;
}
