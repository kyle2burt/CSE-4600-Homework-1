#include <pthread.h>
#include <stdio.h>

void *func1(void *data) {
    char *tname = (char *)data;
    printf("I'm the %s\n", tname);
    pthread_exit(0);
}

void *func2(void *data) {
    char *tname = (char *)data;
    printf("%s to last\n", tname);
    pthread_exit(0);
}

void *func3(void *data) {
    char *tname = (char *)data;
    printf("%s and late to the party\n", tname);
    pthread_exit(0);
}

int main() {
    pthread_t id1, id2, id3;
    pthread_attr_t attr1, attr2, attr3;
    char const *tnames[3] = {"Thread 1", "Thread 2", "Thread 3"};
    // get the default attributes
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    // create the threads
    pthread_create(&id1, &attr1, func1, (void *)tnames[0]);
    pthread_create(&id2, &attr2, func2, (void *)tnames[1]);
    pthread_create(&id3, &attr3, func3, (void *)tnames[2]);
    // wait for the threads to exit
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);
    return 0;
}
