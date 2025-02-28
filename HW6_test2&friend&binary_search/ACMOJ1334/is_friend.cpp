#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// 简单的模板参数解析
vector<string> parse_params(const string& s) {
    vector<string> params;
    stringstream ss(s);
    string param;
    while (ss >> param) {
        params.push_back(param);
    }
    return params;
}

// 判断模板A是否是模板B的友元
bool is_friend(const vector<string>& A_params, const vector<pair<string, vector<string>>>& A_friends, const string& B_name, const vector<string>& B_params) {
    for (const auto& friend_info : A_friends) {
        const string& friend_name = friend_info.first;
        const vector<string>& friend_params = friend_info.second;

        if (friend_name == B_name) {
            // 非约束友元
            if (friend_params.empty()) return true;

            // 完全匹配友元
            if (friend_params == B_params) return true;

            // 半约束友元
            if (friend_params.size() == B_params.size()) {
                bool match = true;
                for (size_t i = 0; i < friend_params.size(); ++i) {
                    if (friend_params[i] != B_params[i] && friend_params[i] != "") {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    map<string, pair<vector<string>, vector<pair<string, vector<string>>>>> templates;

    // 解析类模板声明
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        // 解析模板参数
        string params_str;
        ss >> params_str; // 读取模板参数部分，格式类似于 "< T1 T2 >"
        params_str = params_str.substr(1, params_str.length() - 2);  // 去掉尖括号 <>
        vector<string> params = parse_params(params_str);

        // 读取类名
        string template_name;
        ss >> template_name;

        int k;
        cin >> k;
        cin.ignore();

        vector<pair<string, vector<string>>> friends;

        for (int j = 0; j < k; ++j) {
            getline(cin, line);
            line = line.substr(1, line.size() - 2);  // 去掉尖括号<>
            stringstream fs(line);
            string friend_params_str, friend_name;
            fs >> friend_params_str >> friend_name;
            getline(fs, friend_params_str);

            vector<string> friend_params = parse_params(friend_params_str);
            friends.push_back({friend_name, friend_params});
        }

        templates[template_name] = {params, friends};
    }

    // 处理查询
    for (int i = 0; i < m; ++i) {
        string line;
        string A_name, B_name;
        vector<string> A_params, B_params;

        // 读取 A 的实例化信息
        getline(cin, line);
        stringstream ss_A(line);
        ss_A >> A_name;
        string A_params_str;
        getline(ss_A, A_params_str);
        A_params = parse_params(A_params_str);

        // 读取 B 的实例化信息
        getline(cin, line);
        stringstream ss_B(line);
        ss_B >> B_name;
        string B_params_str;
        getline(ss_B, B_params_str);
        B_params = parse_params(B_params_str);

        // 检查 A 是否为 B 的友元
        if (templates.find(A_name) != templates.end() && templates.find(B_name) != templates.end()) {
            auto& A_info = templates[A_name];
            auto& B_info = templates[B_name];
            if (is_friend(A_info.first, A_info.second, B_name, B_params)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
