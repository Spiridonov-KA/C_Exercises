#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int x) { return (x < 0) ? -x : x; }

int eu_mod(int x, int y) {
  int r;
  assert(y != 0);
  r = x % y;
  if (r < 0)
    r += iabs(y);
  return r;
}

#if 0
long long gcd(long long x, long long y) {
  long long q;
  q = eu_mod(x, y);
  if (q == 0)
    return y;
  return gcd(y, q);
}
#endif

long long gcd(long long x, long long y) {
	long long r, tmp;
	while (y) {
		r = eu_mod(x, y);
		x = y;
		y = r;
	}

	return x;
}

int main() {
  long long x = 0, y = 0, g;
  long long res;
  
  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%lld\n", g);
  return 0;
}
