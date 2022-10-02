#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

int main(int argc, char **argv) {
  pid_t pid;

  std::stack<pid_t> ancestors;
  for (int i = 1; i < N; i++) {
    // checks if pid != 0 from the original process to keep calling fork
    // 0 indicates we are a child to add to ancestors stack until we're finished
    if ((pid = fork())) {
      break;
    }
    ancestors.push(getppid());
  }

  wait(NULL);
  printf("Process %d has child %d and ancestors: ", getpid(), pid);

  // starting from the main process, we list all ancestors and from the
  // beginning then delete it, so we go down the family tree (stack)
  while (!ancestors.empty()) {
    printf("%d, ", ancestors.top());
    ancestors.pop();
  }

  printf("\n");

  return 0;
}
