struct Deque {
  int val, idx;
  Deque(int v = 0, int x = 0) : val(v), idx(x) {}
} Q[maxn];
int head, tail;
vector<int> Max, Min;
int n, k;
void solve_min() {
  Min.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Min.push_back(Q[head].val);
  }
}
void solve_max() {
  Max.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Max.push_back(Q[head].val);
  }
}
