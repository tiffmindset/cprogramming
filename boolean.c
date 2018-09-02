#include <stdio.h>
int firstchang = 888;
int main() {
        int i = 0;
        printf("i is %d\n", i);
        if(i) {
                printf("i is true\n");
        } else {
                printf("i is false\n");
        }

        i = 1;
        printf("i is %d\n", i);
        if(i) {
                printf("i is true\n");
        } else {
                printf("i is false\n");
        }

        i = -1;
        printf("i is %d\n", i);
        if(i) {
                printf("i is true\n");
        } else {
                printf("i is false\n");
        }

        i = (1 > 2);
        printf("1>2, i is %d\n", i);

        i = (1==1);
        printf("1==1, i is %d\n", i);
        return 0;
}
