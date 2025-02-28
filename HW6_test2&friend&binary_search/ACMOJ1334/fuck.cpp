#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cin, std::string, std::stringstream, std::unordered_map, std::unordered_multimap, std::pair, std::vector, std::make_pair, std::cout, std::endl;
int main() {
    //类名字--类模板参数
    unordered_map<string, vector<string> > CT;
    //类名字>友元名字--（友元模板参数， 友元实例参数）
    unordered_multimap<string, pair<vector<string>, vector<string>> > FT;
    vector<string> Args;  //存放模板参数
    vector<string> Fargs;  //存放友元实例参数
    int n, m;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string name;
        string tmp;
        //读类模板
        bool args = false;
        vector<string>().swap(Args);
        while (ss >> tmp) {
            if (tmp == "<") {
                args = true;
            }
            if (tmp == ">") {
                args = false;
            }
            if (args == true && tmp != "<") {
                //类参数
                Args.push_back(tmp);
            }
            if (args == false && tmp != ">") {
                //类名称
                name = tmp;
                CT.insert(make_pair(name, Args));
                break;
            }
        }
        //读友元声明
        int k;
        cin >> k;
        char ch = cin.get();
        if (ch == ' ')  cin.ignore();
        string tp;
        for (int j = 0; j < k; ++j) {
            vector<string>().swap(Args);
            vector<string>().swap(Fargs);
            getline(cin, line);
            stringstream fff(line);
            //读友元模板参数
            while (fff >> tmp) {
                if (tmp == "<") {
                    args = true;
                }
                if (tmp == ">") {
                    args = false;
                }
                if (args == true && tmp != "<") {
                    Args.push_back(tmp);
                }
                
                if (args == false && tmp != ">") {
                    //友元名称
                    tp = name + ">" + tmp;
                    break;
                }
            }
            //读友元实例参数
            while (fff >> tmp) {
                 if (tmp == "<") {
                    args = true;
                }
                if (tmp == ">") {
                    args = false;
                }
                if (args == true && tmp != "<") {
                    Fargs.push_back(tmp);
                }
                
                if (args == false) {
                    //读完了这条友元声明
                    FT.insert(make_pair(tp, make_pair(Args, Fargs)));
                    break;
                }
            }
        }
        cin.get();
    }
    for (int i = 0; i < m; ++i) {
        string line, A, B, tmp;
        vector<string> Aargs, Bargs;
        for (int j = 0; j < 2; ++j) {
            getline(cin, line);
            stringstream ss(line);
            if (j == 0)  ss >> A;
            if (j == 1)  ss >> B;
            //读类模板
            while (ss >> tmp) {
                if (tmp != "<" && tmp != ">") {
                    //类参数
                    if (j == 0)  Aargs.push_back(tmp);
                    if (j == 1)  Bargs.push_back(tmp);
                }
            }
        }
        if (i < m - 1) {
            cin.get();
        }
        
        //? A is a friend to B
        string key = B + ">" + A;
        bool next = false, yes = true;
        if (FT.find(key) != FT.end()) {
            auto range = CT.equal_range(B);
            for (auto it = range.first; it != range.second; ++it) {
                if (it->second.size() == Bargs.size()) {  //found corresponding class template
                    unordered_map<string, string> ins;   //typenames--realnames
                    for (int j = 0; j < it->second.size(); ++j) {
                        ins.insert(make_pair(it->second[j], Bargs[j]));
                    }
                    auto range2 = FT.equal_range(key);
                    for (auto is = range2.first; is != range2.second; ++is) {
                        yes = true;  next = false;
                        if (is->second.second.size() == Aargs.size()) {    //possible template
                           for (int h = 0; h < Aargs.size(); ++h) {
                                string findA = is->second.second[h];
                                if (ins.find(findA) != ins.end()) {
                                    if (ins.find(findA)->second != Aargs[h]) {
                                        next = true;  yes = false;
                                        break;
                                    }
                                } else {
                                    if (is->second.first.empty()) {    //require tmpl args but none
                                        next = true;  yes = false;
                                        break;
                                    } else {
                                        for (int p = 0; p < is->second.first.size(); ++p) {
                                            if (is->second.first[p] == findA) {
                                                ins.insert(make_pair(findA, Aargs[h]));
                                            }
                                        }
                                    }
                                }
                           }
                        }
                    }
                }
            }
        } else {
            cout << "No" << endl;
            continue;
        }
        if (yes)  cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}