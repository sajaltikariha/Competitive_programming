#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll int a[100009],tree[400050],lazy[400050];
void update(ll int root, ll int s, ll int e, ll int l, ll int r, ll int val)
{
    if(lazy[root]!=0)
    {
        tree[root]+=(e-s+1)*lazy[root];
        if(s!=e)
        {
            lazy[2*root]+=lazy[root];
            lazy[2*root+1]+=lazy[root];
        }
        lazy[root]=0;
    }
    if(s>r || e<l)
        return ;
    if(l<=s && e<=r)
    {
        tree[root]+=(e-s+1)*val;
        if(s!=e)
        {
            lazy[2*root]+=val;
            lazy[2*root+1]+=val;
        }
        return ;
    }
    ll int mid=(s+e)/2;
    update(2*root,s,mid,l,r,val);
    update(2*root+1,mid+1,e,l,r,val);
    tree[root]=tree[2*root]+tree[2*root+1];
    return ;
}

ll int query(ll int root, ll int s,ll int e, ll int l,ll int r)
{
    if(lazy[root]!=0)
    {
        tree[root]+=(e-s+1)*lazy[root];
        if(s!=e)
        {
            lazy[2*root]+=lazy[root];
            lazy[2*root+1]+=lazy[root];
        }
        lazy[root]=0;
    }
    if(s>r || l>e)
        return 0;
    if(s>=l && e<=r)
    {
        return tree[root];
    }
    ll int mid=(s+e)/2;
    ll int s1=query(2*root,s,mid,l,r);
    ll int s2=query(2*root+1,mid+1,e,l,r);
    return s1+s2;
}
int main()
{
    ll int i,n,sz,x,p,q,v,c;
    cin>>sz;
    while(sz--)
    {
        cin>>n>>c;
        for(i=0;i<=n;i++)
            a[i]=0;
        for(i=0;i<=4*n+5;i++)
            tree[i]=0,lazy[i]=0;
        while(c--)
        {
            cin>>x>>p>>q;
            if(x==0)
            {
                cin>>v;
                update(1,1,n,p,q,v);
            }
            else if(x==1)
            {
                cout<<query(1,1,n,p,q)<<endl;

            }
        }
    }

    return 0;
}

