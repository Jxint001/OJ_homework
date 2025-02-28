#include <iostream>
#include <vector>
int N, M;
std::vector<int> a(100005);
void add() {
    ++N;
    int x, y;
    std::cin >> x >> y;
    a.insert(a.begin() + x, y);
}
void erase() {
    --N;
    int x;
    std::cin >> x;
    a.erase(a.begin() + x - 1);
}
void (*func[3])() = { NULL, add, erase};
int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)  std::cin >> a[i];
    int opt;
    for (int i = 0; i < M; ++i) {
        std::cin >> opt;
        func[opt]();
    }
    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std:: endl;
    return 0;
}