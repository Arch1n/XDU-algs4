#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>
#include <queue>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
//#define pii pair<int,int>
const int MAXN=4e5+10;
int dis[MAXN],fa[MAXN],minn[MAXN],sz[MAXN],ch[MAXN][27];
const int inf=1e9+7;
int pos[MAXN];
#define link(x) for(edge *j=h[x];j;j=j->next)
using namespace std;


int Min(int aa,int bb){return aa>bb?bb:aa;}


std::string wang9897isMySon(const std::string& filename){
    std::ifstream fin(filename);
    std::string line, T;
    int cnt=1,cnt1=0;
    while(getline(fin, line)) {
        for (const auto &c: line) {
            if(islower(c)){
                T += c;
                pos[cnt1]=cnt;
                cnt1++;
            }
            else if(!T.empty() && T.back() != ' ')
                T += ' ',cnt++,cnt1++;
        }
        if(!T.empty() && T.back() != ' ')
            T += ' ';
    }
    fin.close();
    return T;
}

typedef struct AC{
    int fair[MAXN],ch[MAXN][27],sum[MAXN],cnt=0,rt,key[MAXN],pos[MAXN],maxx[MAXN],wei[MAXN];
    queue<int>que;
    vector<int>vec[MAXN];
    AC(){
        rt=++cnt;
        fair[rt]=sum[rt]=key[rt]=0;
        maxx[rt]=inf;
        inc(i,0,26)ch[rt][i]=0;
    }
    void newnode(int &x){
        x=++cnt;
        maxx[x]=inf;
        fair[x]=sum[x]=key[x]=0;
        inc(i,0,26)ch[x][i]=0;
    }
    void insert(std::string s,int id){
        int len=s.size();int temp=rt;
        for(int i=0;i<len;i++){
            int t;
            if(s[i]==' ')t=26;
            else t=s[i]-'a';
            if(!ch[temp][t])newnode(ch[temp][t]);
            temp=ch[temp][t];
        }
        key[temp]=id;pos[id]=temp;
    }
    void Fair(){
        que.push(rt);
        while(!que.empty()){
            int t=que.front();que.pop();
            for(int i=0;i<=26;i++){
                if(!ch[t][i])continue;
                if(!fair[t]){fair[ch[t][i]]=rt;que.push(ch[t][i]);continue;}
                int temp=fair[t];
                for(;temp&&!ch[temp][i];temp=fair[temp]);
                if(!temp)fair[ch[t][i]]=rt;
                else fair[ch[t][i]]=ch[temp][i];
                que.push(ch[t][i]);
            }
        }
    }
    void querty(string s){
        int len=s.size();int temp=rt;
        int num=1;int t;
        for(int i=0;i<len;i++){
            if(s[i]==' ')t=26;
            else t=s[i]-'a';
            if(ch[temp][t])temp=ch[temp][t];
            else{
                int p=temp;
                for(;p&&!ch[p][t];p=fair[p]);
                if(!p)temp=rt;else temp=ch[p][t];
            }
            sum[temp]++;maxx[temp]=min(maxx[temp],i);
            wei[i]=num;
            if(s[i]==' ')num++;
        }
    }
    void inte(){
        for(int i=1;i<=cnt;i++)vec[fair[i]].push_back(i);
    }
    void dfs(int x,int fa){
        for(int i=0;i<vec[x].size();i++){
            sum[x]+=sum[vec[x][i]];
            maxx[x]=min(maxx[x],maxx[vec[x][i]]);
            dfs(vec[x][i],x);
        }
    }
}AC;
AC *ac;
std::string qtr[MAXN];
int Arch0nisMySon(const std::string& filename){
    std::ifstream fin(filename);
    std::string s;
    int num=0;
    while(getline(fin, qtr[++num])){
        ac->insert(qtr[num],num);
    }
    fin.close();
    ac->Fair();
    return num-1;
}
int main() {
    ac=new AC;
    std::string s1=wang9897isMySon("corpus1.in");
    int q=Arch0nisMySon("corpus2.in");
    ac->querty(s1);
    ac->inte();
    ac->dfs(ac->rt,0);
    for(int i=1;i<=q;i++){
        if(ac->sum[ac->pos[i]]==0)printf("-1\n");
        else printf("%d %d\n",ac->wei[ac->maxx[ac->pos[i]]-qtr[i].size()+1],ac->sum[ac->pos[i]]);
    }
    return 0;
}