#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int iabs(int n) {
	return (n > 0)? n : -n;
}

#if 0
struct point_t {
  int x, y;
};

struct triangle_t {
  struct point_t pts[3];
};

void read_input(struct triangle_t *tr) {
	int nitems;
	nitems = scanf("%d%d%d%d%d%d", &(tr->pts[0]).x, &(tr->pts[0]).y, 
			&(tr->pts[1]).x, &(tr->pts[1]).y, 
			&(tr->pts[2]).x, &(tr->pts[2]).y);
	if (nitems != 6) {
		printf("Incorrect input\n");
		abort();
	}
}
#endif

int double_area(struct triangle_t tr) {
	return iabs((tr.pts[1].x - tr.pts[0].x) * (tr.pts[2].y - tr.pts[0].y) - 
			(tr.pts[1].y - tr.pts[0].y) * (tr.pts[2].x - tr.pts[0].x));
}

#if 0
int main() {

	int res;
	struct triangle_t tr;
	read_input(&tr);

	res = double_area(tr);

	printf("%d", res);
}
#endif
