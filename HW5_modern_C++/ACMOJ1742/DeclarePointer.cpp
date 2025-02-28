#include <iostream>
#include <string>
using std::cin, std::string, std::cout, std::endl;
string name = "";
bool match(char a, char b) {
    if (a == '(' && b == ')')  return true;
    if (a == '[' && b == ']')  return true;
    return false;
}
string parseType(const string& d) {
    string result = "";
    int n = d.size();
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if ((97 <= d[i] && d[i] <= 122 || 65 <= d[i] && d[i] <= 90) && (97 <= d[j] && d[j] <= 122 || 65 <= d[j] && d[j] <= 90)) {
            name = d.substr(i, j - i + 1);
            break;
        }
        if (match(d[i], d[j])) {
            ++i;  --j;
            if (d[i] == '*') {
                ++i;
                result = "pointer to " + result;
            }
        } else {
            if (d[j] == ']' && d[i] != '*') {
                j -= 2;
                result = "array of " + result;
                continue;
            }
            if (d[i] == '*') {
                ++i;
                result = "pointer to " + result;
            }
        }
    }
    return result;
}

int main() {
    string type;
    cin >> type;
    cin.ignore();

    string decl;
    getline(cin, decl);
    
    cout << name + " is " + parseType(decl) + type << endl;
    return 0;
}
//int (*(**a)[])[][]
//a is pointer to pointer to array of pointer to array of array of int