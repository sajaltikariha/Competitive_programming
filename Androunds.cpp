#include<bits/stdc++.h>
#define ll long long
#define mx 22000

using namespace std;

ll int a[mx],tree[4*mx+2];

void build(ll int root , ll int s, ll int e)
{
    if(s==e)
    {
        tree[root]=a[s];
        return ;
    }
    ll int mid =(s+e)/2;
    build(2*root,s,mid);
    build(2*root+1,mid+1,e);
    tree[root]=tree[2*root]&tree[2*root+1];
    return ;
}
ll int query(ll int root, ll int s, ll int e, ll int l, ll int r)
{
    if(s>r || e<l || s>e)
        return INT_MAX;
    if(l<=s && e<=r)
    {
        return tree[root];
    }
    ll int mid=(s+e)/2;
    ll int s1=query(2*root,s,mid,l,r);
    ll int s2=query(2*root+1,mid+1,e,l,r);
    return s1&s2;
}


int main()
{
    ll int t,n,k,i,j;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a[0]=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=0;i<=4*n+2;i++)
            tree[i]=0;

        build(1,1,n);
        k=min(k,n);
        for(i=1;i<=n;i++)
        {

           if(i-k<1)
           {
             ll int ans=-1;
             ans&=query(1,1,n,1,i+k);
             ans&=query(1,1,n,n+(i-k),n);
             cout<<ans<<" ";
           }
           else if(i+k>n)
           {
             ll int ans=-1;
             ans&=query(1,1,n,i-k,n);
             ans&=query(1,1,n,1,(i+k)-(n));
             cout<<ans<<" ";
           }
           else cout<<query(1,1,n,i-k,i+k)<<" ";

        }
        cout<<endl;
    }
    return 0;
}
