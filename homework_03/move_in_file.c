#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int cur_pos, n;
    char word[256];
    FILE *f = fopen("example.txt", "w");
    if (!f) {
        perror("Error opening file");
        return 1;
    }
    cur_pos = ftell(f);
    printf("Current position in file: %d\n", cur_pos);
    // fscanf(f, "%d", &n);
    // printf("Read word: %d\n", n);
    fscanf(f, "%s", word);
    printf("Read word: %s\n", word);
    cur_pos = ftell(f);
    printf("Current position in file: %d\n", cur_pos);
    fprintf(f, "This is an apple\n");
    fseek(f, 9, SEEK_SET);
    fprintf(f, "%s", " sam");
    printf("SEEK_SET = %d\n", SEEK_SET);
    printf("SEEK_SET = %d\n", SEEK_CUR);
    printf("SEEK_SET = %d\n", SEEK_END);
    fclose(f);
}