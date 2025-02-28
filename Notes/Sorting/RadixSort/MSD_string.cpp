#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>

using std::copy;  // from <algorithm>
using std::make_tuple;
using std::stack;
using std::tie;
using std::tuple;
using std::vector;

using NTBS = char*;  // 空终止字节字符串
using NTBSptr = NTBS*;

void MSD_radix_sort(NTBSptr first, NTBSptr last) {
  static constexpr size_t W = 128;
  static constexpr size_t logW = 7;
  static constexpr size_t mask = W - 1;

  NTBSptr tmp = (NTBSptr)calloc(last - first, sizeof(NTBS));

  using node = tuple<NTBSptr, NTBSptr, size_t>;
  stack<node, vector<node>> s;
  s.push(make_tuple(first, last, 0));

  while (!s.empty()) {
    NTBSptr begin, end;
    size_t index, length;

    tie(begin, end, index) = s.top();
    length = end - begin;
    s.pop();

    if (begin + 1 >= end) continue;  // elements <= 1

    // 计数排序
    size_t cnt[W] = {};
    auto key = [](const NTBS str, const size_t index) { return str[index]; };

    for (NTBSptr it = begin; it != end; ++it) ++cnt[key(*it, index)];
    //for (char ch = 1; value < W; ++value) cnt[ch] += cnt[ch - 1];  不知道value是啥，先copy过来了

    // 求完前缀和后，计算相同关键字的元素范围
    // 对于 NTBS，如果此刻末尾的字符是 \0 则说明这两个字符串相等，不必继续迭代
    for (char ch = 1; ch < W; ++ch)
      s.push(make_tuple(begin + cnt[ch - 1], begin + cnt[ch], index + 1));

    NTBSptr it = end;
    do {
      --it;
      --cnt[key(*it, index)];
      tmp[cnt[key(*it, index)]] = *it;
    } while (it != begin);

    copy(tmp, tmp + length, begin);
  }

  free(tmp);
}