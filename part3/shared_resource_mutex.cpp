/*
Compile: g++ -o shared_resource_mutex shared_resource_mutex.cpp -pthread
Execute: ./shared_resource_mutex
*/
#include <pthread.h>
#include <stdio.h>
#define iterations 300000000

long long shared_resource = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to modify shared resource
void *inc_dec_resource(void *arg) {
    // get the pointer from main thread and dereference it to put the value in
    // resource value
    int resource_value = *(int *)arg;
    for (int i = 0; i < iterations; i++) {
        pthread_mutex_lock(&mutex);
        shared_resource += resource_value;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(void) {
    // Thread 1 to increment shared resource
    pthread_t tid1, tid2;
    int value1 = 1;
    pthread_create(&tid1, NULL, inc_dec_resource, &value1);
    // Thread 2 to increment shared resource
    int value2 = -1;
    pthread_create(&tid2, NULL, inc_dec_resource, &value2);
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);
    printf("Shared resource value: %lld\n", shared_resource);
    return 0;
}
