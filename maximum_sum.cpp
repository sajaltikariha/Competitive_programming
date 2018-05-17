#include<bits/stdc++.h>
#define ll long long
#define mx 1000009
#define scanf(a) scanf("%lld",&a)
using namespace std;

struct node{

ll int max1,max2;
};
node  tree[4*mx];
ll int a[mx];

void build(ll int root, ll int s, ll int e)
{
    if(s==e)
    {
        tree[root].max1=a[s];
        tree[root].max2=INT_MIN;
        return ;
    }
    ll int mid=(s+e)/2;
    build(2*root,s,mid);
    build(2*root+1,mid+1,e);
    tree[root].max1=max(tree[2*root].max1,tree[2*root+1].max1);
    tree[root].max2=min(max(tree[2*root].max2,tree[2*root+1].max1),max(tree[2*root].max1,tree[2*root+1].max2));
    return ;
}
void update (ll int root, ll int s, ll int e, ll int idx, ll int val)
{
    if(s==e)
    {
        a[s]=val;
        tree[root].max1=val;
        tree[root].max2=INT_MIN;
        return ;
    }
    ll int mid=(s+e)/2;
    if(idx<=mid && idx>=s)
    update(2*root,s,mid,idx,val);
    if(idx>mid && idx<=e)
    update(2*root+1,mid+1,e,idx,val);
    tree[root].max1=max(tree[2*root].max1,tree[2*root+1].max1);
    tree[root].max2=min(max(tree[2*root].max2,tree[2*root+1].max1),max(tree[2*root].max1,tree[2*root+1].max2));
    return ;
}

node query(ll int root, ll int s, ll int e, ll int l, ll int r)
{
    node temp;
    temp.max1=INT_MIN,temp.max2=INT_MIN;
    if(s>r || e<l)
        return temp;
    if(s>=l && e<=r)
        return tree[root];
    ll int mid=(s+e)/2;
    if(r<=mid)
    return query(2*root,s,mid,l,r);
    if(l>mid)
    return query(2*root+1,mid+1,e,l,r);
    node s1=query(2*root,s,mid,l,r);
    node s2=query(2*root+1,mid+1,e,l,r);
    temp.max1=max(s1.max1,s2.max1);
    temp.max2=min(max(s1.max2,s2.max1),max(s1.max1,s2.max2));

    return temp;
}
int main()
{
    ll int i,j,n,m,x,y;
    node ans;
    char ch;
    scanf(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<4*mx;i++)
        tree[i].max1=INT_MIN,tree[i].max2=INT_MIN;
    build(1,0,n-1);
    scanf(m);
    for(i=0;i<m;i++)
    {
        cin>>ch;
        scanf(x);
        scanf(y);
        if(ch=='U')
            update(1,0,n-1,x-1,y);
        else if(ch=='Q')
        {
            ans=query(1,0,n-1,x-1,y-1);
            printf("%lld\n",ans.max1+ans.max2);
        }
    }
    return 0;
}
