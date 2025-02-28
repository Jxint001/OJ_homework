#include <cstdio>
#include <cstdint>
#include <algorithm>

typedef uint32_t u32;
const u32 maxn = 2e7 + 2;
using u32ptr = u32*;

u32 n, a[maxn], seed;

void RadixSort(u32ptr first, u32ptr last) {
    static constexpr u32 low = 8;
    static constexpr u32 W = 1 << low;
    static constexpr u32 mask = W - 1;

    u32 shift = 0;
    u32 book = 0;
    while (book <= 3) {
        size_t len = last - first;
        u32 cnt[W], tmp[len];

        //counting sort
        for (u32 i = 0; i < W; ++i)  cnt[i] = 0;
        //for (u32 i = 0; i < len; ++i)  tmp[i] = 0;
        for (u32ptr it = first; it != last; ++it) {
            size_t key = (*it >> shift) & mask;
            ++cnt[key];
        }
        for (u32 i = 1; i < W; ++i)  cnt[i] += cnt[i-1];
        u32ptr it = last;
        do {
            --it;
            size_t key = (*it >> shift) & mask;
            --cnt[key];
            tmp[cnt[key]] = *it;
        }while (it != first);

        std::copy(tmp, tmp + len, first);

        shift += low;
        ++book;
    }
}
inline u32 nextInteger(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

bool outputArr(void *a, u32 size) {
    if (size % 4) {
        return puts("-1"), 0;
    }

    u32 blocks = size / 4;
    u32 *A = (u32 *)a;
    u32 ret = size;
    u32 x = 23333333;
    for (u32 i = 0; i < blocks; i++) {
        ret = ret ^ (A[i] + x);
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
    }
    return printf("%u\n", ret), 1;
}

signed main() {
    scanf("%d%d", &n, &seed);
    for (u32 i = 0; i < n; ++i) {
        seed = nextInteger(seed);
        a[i] = seed;
    }

    RadixSort(a, a + n);

    outputArr(a, n * sizeof(u32));
}