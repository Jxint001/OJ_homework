#include <iostream>
#include <vector>
using std::cin,std::cout,std::endl,std::vector,std::string;
struct noname {
    string votes;
    int num;
};
int main() {
    int n, max = 0;
    cin >> n;
    vector<noname> book;
    for (int i = 0; i < n; ++i) {
        string votes;
        cin >> votes;
        book.push_back({votes,i});
        if (votes.length() > max)  max = votes.length();
    }
    string M = "";
    int cnt = book.size(),num;
    for (int i = 0; i < cnt; ++i) {
        if (book[i].votes > M && book[i].votes.length() == max) {
            M = book[i].votes;
            num = i;
        }
    }
    cout << num + 1 << endl << M << endl;
}