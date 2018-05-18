#include<bits/stdc++.h>
#define ll long long
#define mx 50009
using namespace std;
ll int a[mx];

struct node{

ll int  sum,maxsum,pre,suf;

}tree[4*mx];

void build( ll int root, ll int s, ll int e)
{
    if(s==e)
    {
        tree[root].pre=a[s];
        tree[root].suf=a[s];
        tree[root].maxsum=a[s];
        tree[root].sum=a[s];
        return ;
    }
    else {

        ll int mid=(s+e)/2;
        build(2*root,s,mid);
        build(2*root+1,mid+1,e);
        tree[root].sum=tree[2*root].sum+tree[2*root+1].sum;
        tree[root].pre=max(tree[2*root].pre,tree[2*root].sum+tree[root*2+1].pre);
        tree[root].suf=max(tree[2*root+1].suf,tree[2*root+1].sum+tree[root*2].suf);
        tree[root].maxsum=max(tree[root].pre,max(tree[root].suf,max(tree[2*root].maxsum,max(tree[root*2+1].maxsum,tree[2*root].suf + tree[2*root+1].pre))));
        return ;
    }
}
void update(ll int root, ll int s, ll int e, ll int idx, ll int val)
{
    if(s==e)
    {
        a[idx]=val;
        tree[root].sum=val;
        tree[root].maxsum=val;
        tree[root].pre=val;
        tree[root].suf=val;
        return ;
    }
    else {

        ll int mid=(s+e)/2;
        if(idx<=mid && idx>=s)
        update(2*root,s,mid,idx,val);
        if(idx>mid && idx<=e)
        update(2*root+1,mid+1,e,idx,val);

        tree[root].sum=tree[2*root].sum+tree[2*root+1].sum;
        tree[root].pre=max(tree[2*root].pre,tree[2*root].sum+tree[root*2+1].pre);
        tree[root].suf=max(tree[2*root+1].suf,tree[2*root+1].sum+tree[root*2].suf);
        tree[root].maxsum=max(tree[root].pre,max(tree[root].suf,max(tree[2*root].maxsum,max(tree[root*2+1].maxsum,tree[2*root].suf + tree[2*root+1].pre))));
        return ;
    }

}
node query(ll int root, ll int s, ll int e, ll int l,ll int r)
{
    node ans;
    ans.sum=ans.maxsum=ans.pre=ans.suf=INT_MIN;
    if(s>r || e<l )
    return ans;
    else if( s>=l && e<=r )
    return tree[root];

        ll int mid=(s+e)/2;
        if(l>mid )
        return query(2*root+1,mid+1,e,l,r);
        if(r<=mid)
        return query(2*root,s,mid,l,r);
        node s1=query(2*root,s,mid,l,r);
        node s2=query(2*root+1,mid+1,e,l,r);
        ans.sum=s1.sum+s2.sum;
        ans.pre=max(s1.pre,s1.sum+s2.pre);
        ans.suf=max(s2.suf,s2.sum+s1.suf);
        ans.maxsum=max(ans.pre,max(ans.suf,max(s1.maxsum,max(s2.maxsum,s1.suf + s2.pre))));
        return ans;
}

int main()
{
    ll int i,n,m,op,x,y;
    cin>>n;
    a[0]=0;
    for(i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    build(1,1,n);
    cin>>m;
    for(i=0;i<m;i++)
    {
       scanf("%lld%lld%lld",&op,&x,&y);
       if(op==1)
       printf("%lld\n",query(1,1,n,x,y).maxsum);
       else if(op==0)
       {
        update(1,1,n,x,y);
       }
    }

    return 0;
}
