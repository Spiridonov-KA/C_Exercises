#include <stdio.h>
#include <stdlib.h>

struct point_t {
    unsigned size;
    unsigned char *sieve;
};

void print_address_pointer(struct point_t *p) {
    printf("%p\n", p->sieve);
    p->sieve[0] = 10;
}

void print_address_copy(struct point_t p) {
    printf("%p\n", p.sieve);
    free(p.sieve);
    p.sieve = NULL;
}

int main() {
	int arr[4];
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
}
