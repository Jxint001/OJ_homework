#include <iostream>
#include "jump_table.hpp"
#include <string>
//#include "from_gpt.hpp"
using namespace std;
int main() {
    SkipList<int> sk;
    sk.insert(9);
    sk.insert(2);
    sk.insert(4);
    sk.insert(1);
    sk.deleteItem(2);
    cout << sk.search(2) << " "<< sk.search(9) << endl;

    SkipList<std::string> str;
    std::string a = "hello", b = "world";
    str.insert(a);
    str.insert(b);
    //str.deleteItem(a);
    cout << str.search("noway") << endl;
    cout << str.search(a) << endl;
}