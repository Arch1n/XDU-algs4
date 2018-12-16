#include <bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define mp make_pair
#define pb push_back
#define pii pair<double,int>
#define link(x) for(edge *j=h[x];j;j=j->next)
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
const int MAXN=3e5+10;
const double eps=1e-8;
#define ll long long
const ll inf=1e18+7;
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue < pii > heap;
struct edge{int t;double v;edge*next;}e[MAXN<<1],*h[MAXN],*o=e;
void add(int x,int y,double vul){o->t=y;o->v=vul;o->next=h[x];h[x]=o++;}
heap::point_iterator id[MAXN];
stringstream ss;
double d[MAXN];
int n,m,fa[MAXN];
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
typedef struct Node{
    double x,y;
}Node;
Node pos[MAXN];
typedef struct node{
    int v;double w;
    friend bool operator<(node aa,node bb){return aa.w>bb.w+eps;}
}node;

bool vis[MAXN];
double dis(Node aa,Node bb){
    return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));
}
int st[MAXN],tot;
void dij(int s,int tt){
    heap q;
    inc(i,1,n)vis[i]=0,d[i]=inf,id[i]=0;
    d[s]=0;fa[s]=0;vis[s]=1;
    id[s]=q.push(mp(0,s));
    while(!q.empty()){
	int t=q.top().second;q.pop();
	if(t==tt)break;
	link(t){
	    if(vis[j->t])continue;
	    if(d[j->t]>d[t]+j->v){
		vis[j->t]=1;fa[j->t]=t;
		d[j->t]=d[t]+j->v;
		if(id[j->t]!=0)q.modify(id[j->t],mp(d[j->t],j->t));
		else id[j->t]=q.push(mp(d[j->t],j->t));
	    }
	}
    }
}

int main(int argc, char *argv[]){
    int seed=time(NULL);
   // freopen("1.out","w",stdout);
    if(argc)
    {
	ss.clear();
	ss<<argv[1];
	ss>>seed;
    }
    srand(seed);
    n=read(),m=read();
    inc(i,1,n){
	read();
	pos[i].x=read();pos[i].y=read();
    }
    inc(i,1,m){
	int t1=read()+1;int t2=read()+1;
	add(t1,t2,dis(pos[t1],pos[t2]));
	add(t2,t1,dis(pos[t1],pos[t2]));
    }
    int q=1000;
    while(q--){
	int tt1=random(1,n);int tt2=random(1,n);
	dij(tt1,tt2);
    }
    return 0;
}
