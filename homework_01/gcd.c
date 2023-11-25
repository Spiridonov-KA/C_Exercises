#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long llabs(long long x) { return (x < 0) ? -x : x; }

long long eu_mod(long long x, long long y) {
  long long r;
  assert(y != 0);
  r = x % y;
  if (r < 0)
    r += llabs(y);
  return r;
}

long long gcd(long long x, long long y) {
	long long q;
	long long t;
	assert(x != 0 || y != 0);
	if (x == 0)
		return llabs(y);
	if (y == 0)
		return llabs(x);
	q = eu_mod(x, y);
	while (q != 0) {
		t = q;
		q = eu_mod(y, q);
		y = t;
	}
	return llabs(y);	
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
