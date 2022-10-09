// Salvador Soto 007006630

#include <pthread.h>
#include <stdio.h>
using namespace std;

// for loop to iterate through each thread.
void *thread_func(void *data)
{
    char *tname = (char *)data;
    printf("My thread identifier is %s\n", tname);
    pthread_exit(0);
}
int main()
{
    pthread_t id1, id2, id3;
    pthread_attr_t attr1, attr2, attr3;

    // Displayed text for each thread
    char *tnames[3] = {"Thread 1", "Thread 2", "Thread 3"};
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    pthread_create(&id1, &attr1, thread_func, tnames[0]);
    pthread_create(&id2, &attr2, thread_func, tnames[1]);

    // Creating third thread
    pthread_create(&id3, &attr3, thread_func, tnames[2]);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);
    return 0;
}