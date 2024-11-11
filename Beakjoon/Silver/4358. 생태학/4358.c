#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    int count;
} Tree;

int compare(const void *a, const void *b) {
    return strcmp(((Tree*)a)->name, ((Tree*)b)->name);
}


int main() {
    Tree trees[10000];
    int total_count = 0;
    int tree_types = 0;
    char name[31];

    while (fgets(name, 31, stdin) != NULL) {
        name[strcspn(name, "\n")] = 0;

        int found = 0;
        for (int i = 0; i < tree_types; i++) {
            if (strcmp(trees[i].name, name) == 0) {
                trees[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(trees[tree_types].name, name);
            trees[tree_types].count = 1;
            tree_types++;
        }

        total_count++;
    }

    qsort(trees, tree_types, sizeof(Tree), compare);

    for (int i = 0; i < tree_types; i++) {
        printf("%s %.4f\n", trees[i].name, (trees[i].count * 100.0) / total_count);
    }

    return 0;
}
