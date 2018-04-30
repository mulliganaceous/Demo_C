#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cord {
    /* float or double */
    float x;
    float y;
};

int main() {
    float r = 3.0;
    int amount = 1000000;
    struct cord cords[amount];

    srand(time(NULL));
    for (int i = 0; i < amount; i++) {
        cords[i] = (struct cord) {
            /* Segfault occurs when (float) is replaced with (double) */
            ((float) rand()/(float) (RAND_MAX)) * (r*2),
            ((float) rand()/(float) (RAND_MAX)) * (r*2)
        };
	printf("%d: %p\n", i, &cords[i]);
    }
}