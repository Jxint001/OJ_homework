#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using std::cin, std::swap;
const int RANDOM_SEED = std::chrono::system_clock::now().time_since_epoch().count();
const int N = 4e7 + 1;
std::mt19937 rng(RANDOM_SEED); // random number generator
int randint(int l, int r) { // rand in [l, r]
    return int (rng() % (r - l + 1) + l);
}

int n, k;
int a[N];

void read_input_data_array() {  //a的1到n是数组
    int m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    unsigned int z = a[m];
    for (int i = m + 1; i <= n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

int index_p(int* a, int l, int r) {
    int rand = randint(l, r);
    //int rand = r;
    int tmp = a[rand], i = l, j = l;
    int k = r;
    while (i <= k) {
        if (a[i] < tmp) {
            swap(a[i], a[j]);
            i++;  j++;
        }
        else if (tmp < a[i]) {
            swap(a[i], a[k]);
            k--;
        } else  i++;
    }
    return i - 1;
}
int quick_select(int* a, int k, int l, int r) {
    if (l <= r) {
        int pindex = index_p(a, l, r);
        if (pindex == k)  return a[pindex];
        if (pindex > k)  return  quick_select(a, k, l, pindex - 1);
        if (pindex < k)  return  quick_select(a, k, pindex + 1, r);
    }
    return -1;
}
int main() {
    read_input_data_array();
    std::cout << quick_select(a, k, 1, n) << std::endl;
    return 0;
}