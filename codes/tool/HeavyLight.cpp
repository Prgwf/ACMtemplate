// with Segtree or splay...
void dfs(int u, int p, int d) {
  sz[u] = 1;
  fa[u] = p;
  deep[u] = d;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
  }
}

void link(int u, int first) {
  top[u] = first;
  tid[u] = ++tot;
  arc[tid[u]] = u;
  if (son[u] != -1) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
int solve(int u, int v) {
  int ret =  0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret += st.query(id[top[u]], id[u] + 1);
    u = fa[top[u]];
  }
  if (u == v) return ret; // 取决是否边权下放
  if (deep[u] > deep[v]) swap(u, v);
  ret += st.query(id[son[u]], id[v] + 1);
  return ret;
}

