#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2);
    a[0] = a[n + 1] = n + 1;
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == 0) {
            std::cout << "0 " << mid << std::endl;
            std::cin >> a[mid];
        }
        if (a[mid - 1] == 0) {
            std::cout << "0 " << mid - 1 << std::endl;
            std::cin >> a[mid - 1];
        }
        if (a[mid + 1] == 0) {
            std::cout << "0 " << mid + 1 << std::endl;
            std::cin >> a[mid + 1];
        }
        if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1]) {
            std::cout << "1 " << mid << std::endl;
            return 0;
        } else if (a[mid] > a[mid - 1]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
   return 0;
}