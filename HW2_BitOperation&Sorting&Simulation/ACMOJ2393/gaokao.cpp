#include <iostream>
#include <vector>
#include <map>

using std::cin, std::cout, std::endl, std::vector, std::string, std::map;

struct f {
    string name;
    vector<int> grade;
};
vector<f> book;
vector<string> store;
map<string,int> col;
int sig, column, cnt;

void ReadChart(int);
void ReadCom(string);

int main() {
    int n, m;
    cin >> n;
    ReadChart(n);
    cin >> m;
    int input[2][m];
    for (int i = 0; i < m; ++i) {input[0][i] = 0;  input[1][i] = 0;}
    int u = 0;
    string com;
    while (u < m) {
        cin >> com;
        ReadCom(com);
        input[0][u] = sig;  input[1][u] = column;
        ++u;
    }
    u = m - 1;
    while (u >= 0) {
        if (input[0][u] == 1) {
            int k = input[1][u];
            bool flag = true;
            while (flag) {
                flag = false;
                for (int i = 0; i < n - 2; ++i) {
                    if (book[i].grade[k] > book[i + 1].grade[k]) {
                        for (int j = 1; j <= cnt; ++j)  std::swap(book[i].grade[j], book[i + 1].grade[j]);
                        string tp = book[i].name;
                        book[i].name = book[i + 1].name;
                        book[i + 1].name = tp;
                        flag = true;
                    }
                }
            }
        }
        if (input[0][u] == -1) {
            int k = input[1][u];
            bool flag = true;
            while (flag) {
                flag = false;
                for (int i = 0; i < n - 2; ++i) {
                    if (book[i].grade[k] < book[i + 1].grade[k]) {
                        for (int j = 1; j <= cnt; ++j)  std::swap(book[i].grade[j], book[i + 1].grade[j]);
                        string tp = book[i].name;
                        book[i].name = book[i + 1].name;
                        book[i + 1].name = tp;
                        flag = true;
                    }
                }
            }
        }
        --u;
    }
    //output
    for (auto &i : store)  cout << i << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << book[i].name << ',';
        for (int j = 1; j <= cnt; ++j) {
            if (j != cnt)  cout << book[i].grade[j] << ',';
            else cout << book[i].grade[j] << endl;
        }
    }
    return 0;
}

void ReadCom(string com) {
    int i = 0;
    string cp;
    while (i < com.length()) {
        if (com[i] != '-' && com[i] != '+') {
            cp += com[i];
        }else if (com[i] == '+'){
            sig = 1;
        }else {
            sig = -1;
        }
        column = col.find(cp)->second;
        ++i;
    }
}

void ReadChart(int n) {
    int u = 0;
    while (u < n) {
        if (u == 0) {
            string c, cp;
            cin >> c;
            store.push_back(c);
            cnt = 0;
            for (int i = 0; i < c.length(); ++i) {
                if (c[i] != ',') {
                    cp += c[i];
                }else {
                    col.insert(std::make_pair(cp, cnt));
                    ++cnt;
                    cp.clear();
                }
                if (i == c.length() - 1)  col.insert(std::make_pair(cp, cnt));
            }
        }
        else {
            string dis;
            cin >> dis;
            int j = 0, len = dis.length();   //u遍历第几个人，j遍历string位数
            f line;
            while (dis[j] != ',') {
                line.name += dis[j];
                ++j;
            }
            ++j;

            int p = 1;  //p记录当前为第几个成绩
            line.grade.insert(line.grade.begin(),20,-1);
            line.grade[0] = u;
            while (j < len) {
                if (line.grade[p] == -1)  line.grade[p] = 0;
                if (dis[j] != ',')  line.grade[p] = line.grade[p] * 10 + dis[j] - '0';
                if (dis[j] == ',')  ++p;
                ++j;
            }
            book.push_back({line.name, line.grade});
        }
        ++u;
    }
}