#include <cstdio>
#include <set>
struct Interval {
    int l, r;
    Interval(int l, int r) : l(l), r(r) {}
    bool operator<(const Interval& other) const {
        return l < other.l; // 按左端点升序排序
    }
};

std::set<Interval> intervals;

int add_interval(int l, int r) {
    auto it = intervals.upper_bound(Interval(r, r)); // 第一个左端点>r的区间
    int deleted = 0;

    while (it != intervals.begin()) {
        --it;
        if (it->r < l) {
            ++it;
            break;
        }
        deleted++;
        it = intervals.erase(it);
    }
    intervals.insert(Interval(l, r));
    return deleted;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'A') {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", add_interval(l, r));
        } else {
            printf("%zu\n", intervals.size());
        }
    }
    return 0;
}