#include <stdlib.h>
#include <stdio.h>

void read_input(int *n, char **arr, int *nb) {
	int nitems;
	nitems = scanf("%d", n);
	if (nitems != 1) {
		printf("Incorrect input\n");
	}
	*arr = calloc(*n, sizeof(char));
	for (int i = 0; i < *n; ++i) {
		nitems = scanf("%hhd", &((*arr)[i]));
		if (nitems != 1) {
			printf("Incorrect input\n");
		}
	}
	nitems = scanf("%d", nb);
	if (nitems != 1) {
		printf("Incorrect input\n");
	}
}

int main() {
	int n, nb, lnb;
	char *arr;
	read_input(&n, &arr, &nb);
	if (nb / 8 < n) {
		lnb = nb % 8;	
		arr[nb / 8] = arr[nb / 8] ^ (1 << lnb);
	}

	for (int i = 0; i < n; ++i) {
		printf("%hhu ", arr[i]);
	}

	free(arr);
}
