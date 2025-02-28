#include <iostream>
#include <queue>
#include <unordered_map>
using std::cin, std::cout, std::endl;
int main() {
    int T;
    cin >> T;
    std::priority_queue<int> maxq;
    std::unordered_map<int, int> book;
    while (T > 0) {
        maxq = std::priority_queue<int>();
        book.clear();
        int n, a, cnt = 0, tp = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (!(a % 2) && book.find(a) == book.end()) {
                maxq.push(a);
                book.insert(std::make_pair(a, 1));
            }
        }
        if (maxq.empty()) {
            cout << 0 << endl;
            --T;  continue;
        }
        while (!maxq.empty()) {
            tp = maxq.top();
            maxq.pop();
            if (!(tp % 2)) {
                tp /= 2;
                if (!(tp % 2) && book.find(tp) == book.end()) {
                    maxq.push(tp);
                    book.insert(std::make_pair(tp, 1));
                }
            }
            ++cnt;
        }
        cout << cnt << endl;
        --T;
    }
    return 0;
}