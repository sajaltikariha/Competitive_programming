#include<bits/stdc++.h>
#define ll long long
#define mx 4000000
using namespace std;
struct node{
ll int l,r;
};
//())(()
//()(())
node tree[mx];
char str[30050];
void build(ll int root, ll int s, ll int e)
{
    if(s==e)
    {
        if(str[s]==')')
        {
            tree[root].l=1;
        }
        else {
                tree[root].r=1;
        }
	    return ;
    }
    ll int mid=(s+e)/2;
    build(2*root,s,mid);
    build(2*root+1,mid+1,e);
    if(tree[2*root].r<=tree[2*root+1].l)
    {
        tree[root].l=tree[2*root].l+tree[2*root+1].l-tree[2*root].r;
        tree[root].r=tree[2*root+1].r;
    }
    else {
            tree[root].l=tree[2*root].l;
            tree[root].r=tree[2*root+1].r +tree[root*2].r-tree[2*root+1].l;
    }
    return ;
}
void update(ll int root, ll int s, ll int e, ll int idx)
{
	if(s==e)
	{
		if(str[s]==')')
			{str[s]='(';(tree[root].r)=1;(tree[root].l)=0;}
		else {str[s]=')';(tree[root].l)=1;(tree[root].r)=0;}
		return ;
	}
	ll int mid =(s+e)/2;
	if(idx<=mid && idx>=s)
	update(2*root,s,mid,idx);
	else if(idx>mid && idx<=e)
	update(2*root+1,mid+1,e,idx);
	if(tree[2*root].r<=tree[2*root+1].l)
    {
        tree[root].l=tree[2*root].l+tree[2*root+1].l-tree[2*root].r;
        tree[root].r=tree[2*root+1].r;
    }
    else {
            tree[root].l=tree[2*root].l;
            tree[root].r=tree[2*root+1].r +tree[root*2].r-tree[2*root+1].l;
    }
 return ;
}

int main()
{

ll int i,n,m,sz=10,k;
for(ll int j=1;j<=sz;j++)
{
	for(i=0;i<mx;i++)
    tree[i].l=0,tree[i].r=0;
    scanf("%lld",&n);
    scanf("%s",&str);
    build(1,0,n-1);
    scanf("%lld",&m);
    printf("Test %lld:",j);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&k);
        if(k==0)
        {
            if(tree[1].l==0 && tree[1].r==0)
            printf("YES\n");
            else printf("NO\n");
        }
        else if(k!=0)
           {
             update(1,0,n-1,k-1);
           }
    }
}
return 0;
}
