#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>
#include <queue>
#include <climits>

const int MAXN = 5000005;

const int inf = INT_MAX;

std::string processInput(const std::string &filename) {
    std::ifstream fin(filename);
    std::string line, T;
    while (getline(fin, line)) {
        for (const auto &c: line) {
            if (islower(c)) {
                T += c;
            } else if (!T.empty() && T.back() != ' ')
                T += ' ';
        }
        if (!T.empty() && T.back() != ' ')
            T += ' ';
    }
    fin.close();
    return T;
}

struct AC {
    int fail[MAXN], ch[MAXN][27], sum[MAXN], cnt = 0, rt, key[MAXN], pos[MAXN], max[MAXN], wei[MAXN];
    std::queue<int> que;
    std::vector<int> vec[MAXN];

    AC() {
        rt = ++cnt;
        fail[rt] = sum[rt] = key[rt] = 0;
        max[rt] = inf;
        for (int i = 0; i < 27; i++) ch[rt][i] = 0;
    }

    void newNode(int &x) {
        x = ++cnt;
        max[x] = inf;
        fail[x] = sum[x] = key[x] = 0;
        for (int i = 0; i < 27; i++) ch[x][i] = 0;
    }

    void insert(std::string s, size_t id) {
        auto len = s.size();
        int temp = rt;
        for (int i = 0; i < len; i++) {
            int t;
            if (s[i] == ' ')t = 26;
            else t = s[i] - 'a';
            if (!ch[temp][t])newNode(ch[temp][t]);
            temp = ch[temp][t];
        }
        key[temp] = id;
        pos[id] = temp;
    }

    void getFail() {
        que.push(rt);
        while (!que.empty()) {
            int t = que.front();
            que.pop();
            for (int i = 0; i <= 26; i++) {
                if (!ch[t][i])continue;
                if (!fail[t]) {
                    fail[ch[t][i]] = rt;
                    que.push(ch[t][i]);
                    continue;
                }
                int temp = fail[t];
                for (; temp && !ch[temp][i]; temp = fail[temp]);
                if (!temp)fail[ch[t][i]] = rt;
                else fail[ch[t][i]] = ch[temp][i];
                que.push(ch[t][i]);
            }
        }
    }

    void query(std::string s) {
        auto len = s.size();
        int temp = rt;
        int num = 1;
        int t;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') t = 26;
            else t = s[i] - 'a';
            if (ch[temp][t])temp = ch[temp][t];
            else {
                int p = temp;
                for (; p && !ch[p][t]; p = fail[p]);
                if (!p)temp = rt; else temp = ch[p][t];
            }
            sum[temp]++;
            max[temp] = std::min(max[temp], i);
            wei[i] = num;
            if (s[i] == ' ')num++;
        }
    }

    void init() {
        for (int i = 1; i <= cnt; i++)vec[fail[i]].push_back(i);
    }

    void dfs(int x, int fa) {
        for (int i = 0; i < vec[x].size(); i++) {
            sum[x] += sum[vec[x][i]];
            max[x] = std::min(max[x], max[vec[x][i]]);
            dfs(vec[x][i], x);
        }
    }
};

AC ac;
std::vector<std::string> qry;

void processQuery(const std::string &filename) {
    std::ifstream fin(filename);
    std::string s, line;
    while (getline(fin, line)) {
        qry.push_back(line);
        ac.insert(line, qry.size());
    }
    fin.close();
    ac.getFail();
}

int main() {
    std::string txt = processInput("corpus.txt");
    processQuery("query.txt");
    ac.query(txt);
    ac.init();
    ac.dfs(ac.rt, 0);
    for (int i = 0; i < qry.size(); i++) {
        if (ac.sum[ac.pos[i + 1]] == 0)
            std::cout << "-- " << qry[i] << std::endl;
        else
            std::cout << ac.wei[ac.max[ac.pos[i + 1]] - qry[i].size() + 1] << " " << qry[i] << " "
                      << ac.sum[ac.pos[i + 1]] << std::endl;
    }
    return 0;
}