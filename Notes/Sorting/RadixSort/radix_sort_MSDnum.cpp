#include <cstdint>
#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <tuple>

typedef uint32_t u32;
using u32ptr = u32*;
const u32 maxn = 2e7 + 2;
using std::tuple, std::stack, std::tie, std::make_tuple;

inline u32 nextInteger(u32 x);
bool outputArr(void *a, u32 size);
void RadixSort(u32ptr begin, u32ptr end);
//u32 Key(u32 num, u32 shift);

u32 n, a[maxn], seed;

signed main() {
    scanf("%d%d", &n, &seed);
    for (u32 i = 0; i < n; ++i) {
        seed = nextInteger(seed);
        a[i] = seed;
    }
    RadixSort(a, a+n);
    outputArr(a, n * sizeof(u32));
}

void RadixSort(u32ptr first, u32ptr last) {
    static constexpr u32 highestW = 32;
    static constexpr u32 lowestW = 8;
    static constexpr u32 W = 1 << lowestW;
    static constexpr u32 mask = W - 1;

    //u32ptr temp = (u32ptr)calloc(last - first, sizeof(u32));    //用来存储整个数组（不同位置）排好的结果
    u32ptr temp = new u32[last-first];

    using node = tuple<u32ptr, u32ptr, u32>;
    stack<node> book;  //改变了node的底层存储方式，需要连续的内存来存储计数排序的结果（存在temp[]里）,诶好像不改变也行？
    book.push(make_tuple(first, last, highestW-lowestW));

    while (!book.empty()) {
        u32ptr begin, end;
        u32 shift, length;
        tie(begin, end, shift) = book.top();
        length = end - begin;
        book.pop();

        if (length <= 1)  continue;    //当前key值已经没有重复的元素，不需要继续往下（迭代）排序了

        //计数排序
        u32 cnt[W] = {};
        auto Key = [](const u32 x, const u32 shift) { return (x >> shift) & mask; };
        for (u32ptr it = begin; it != end; ++it)  ++cnt[Key(*it, shift)];
        for (u32 i = 1; i < W; ++i)  cnt[i] += cnt[i - 1];  

        if (shift >= lowestW) {
            book.push(make_tuple(begin, begin + cnt[0], shift - lowestW));
            for (u32 i = 1; i < W; ++i)  book.push(make_tuple(begin + cnt[i - 1], begin + cnt[i], shift - lowestW));
        }

        for (u32ptr it = end - 1 ; it != begin-1; --it) {
            --cnt[Key(*it, shift)];
            temp[cnt[Key(*it, shift)]] = *it;
        }

        //for (u32 i = 0; i < length; i++) *begin++ = temp[i];
        std::copy(temp, temp + length, begin);
    }
    delete[] temp;
}

// u32 Key(u32 num, u32 shift) {
//     static constexpr u32 mask = 0B11111111;
//     u32 key = (num >> shift) & mask;   //只会保留二进制0到7位的数字
//     return key;
// }
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
// /*
// 思路：把数字分成不同位数/基数的整数倍（不一定是10k），相同“位数”装入一个“桶”，按照一定次序对桶进行内部排序，如果第一个桶相同，则比较第二位，以此类推
// 每次都提取最上方的一个排序状态进行排序，否则无法保证MSD
//时间复杂度：kn+w1+w2+...
// */
