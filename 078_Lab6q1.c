//64050078
//Q2.5 มี 2 แบบ 1.แม่เสร็จก่อนลูก 2.ลูกเสร็จก่อนแม่
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Global var
int msum = 0;
int csum = 0;
int diff = 0;
void *runner(void *param);

int main(int argc, char *argv[]) {

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);

    pthread_join(tid, NULL);
    int upper = atoi(argv[1]);
    int i;
    if (upper > 0) {
        for (i = 0; i <= upper; i++) {
            msum += i;
        }
    }
    diff = csum - msum;
    printf("|csum - msum| = %d\n",diff);
    return 0;
}
void *runner(void *param) {
    int upper = (atoi(param) * 2);
    int i;
    if (upper > 0) {
        for (i = 0; i <= upper; i++) {
            csum += i;
        }
        pthread_exit(0);
    }
}
