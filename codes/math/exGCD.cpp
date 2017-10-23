//Find one solution `$(x,y)$` of `$ax+by=gcd(a,b)$`
long long ex_gcd(long long a,long long b,long long &x,long long &y) {
  if (b) {
    long long ret = ex_gcd(b,a%b,x,y),tmp = x;
    x = y;
    y = tmp-(a/b)*y;
    return ret;
  } else {
    x = 1;
    y = 0;
    return a;
  }
}
