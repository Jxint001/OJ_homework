#include <iostream>
void debugPrint() {
    std::cout << std::endl;
    return;
}
// template<typename T, typename... Tlist>
// void debugPrint(T s, Tlist... rest) {
//     std::cout << s << ' ';
//     debugPrint(rest ...);
// }

template<typename T, typename... Tlist>
void debugPrint(T s, Tlist&&... ts) {
    std::cout << s << ' ';
    debugPrint(std::forward<Tlist>(ts)...);
}

int main() {
    std::string str("test message");
    debugPrint("Hello, Happy World!", 19260817, false, str);
    debugPrint("debug");
    return 0;
}