#include <iostream>

constexpr int m = 1e9 + 7;

long long sum(const long long *d, int ind) {
  long long ans = 0;
  while (ind > 0) {
    ans = ans + d[ind];
    ind -= ind & -ind;
  }
  return ans;
}

void Update(long long *d, int ind, const int N, const int add) {
  while (ind <= N && ind > 0) {
    d[ind] = d[ind] + add;
    ind += ind & -ind;
  }
}

int main() {
  int N, Q;
  std::cin >> N >> Q;
  long long di[100005] = {0}, idi[100005] = {0};
  for (int i = 0; i <= N; ++i) {
    di[i] = 0, idi[i] = 0;
  }

  for (int i = 1; i <= N; ++i) {
    int data;
    std::cin >> data;
    Update(di, i, N, data);
    Update(di, i + 1, N, -data);
    Update(idi, i, N, i * data);
    Update(idi, i + 1, N, -data * (i + 1));
  }

  for (int i = 0; i < Q; ++i) {
    int command;
    std::cin >> command;
    switch (command) {
      case 1 : {
        int x, w;
        std::cin >> x >> w;
        long long ans = sum(di, x + w - 1) * (x + w) - sum(di, x - 1) * x - sum(idi, x + w - 1) + sum(idi, x - 1);
        std::cout << (ans % m + m) % m << '\n';
        break;
      }
      case 2 : {
        int x, w, value;
        std::cin >> x >> w >> value;
        Update(di, x, N, value);
        Update(di, x + w, N, -value);
        Update(idi, x, N, value * x);
        Update(idi, x + w, N, -value * (x + w));
        break;
      }
      default: ;
    }
  }
  return 0;
}
