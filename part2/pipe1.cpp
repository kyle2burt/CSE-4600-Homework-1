// pipe1.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main() {
    FILE *fpi;
    // for reading a pipe
    char buffer[BUFSIZ + 1];
    // BUFSIZ defined in <stdio.h>
    int chars_read;
    memset(buffer, 0, sizeof(buffer)); // clear buffer
    fpi = popen("ps -auxw", "r");
    // pipe to command "ps -auxw"
    if (fpi != NULL) {
        // read data from pipe into buffer
        chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);
        if (chars_read > 0)
            cout << "Output from pipe: " << buffer << endl;
        pclose(fpi);
        // close the pipe
        return 0;
    }
    return 1;
}
// the contents of `ps -auxw` is streamed and saved onto *fpi and then that
// stream is read and saved into buffer `chars_read`. Loop over `chars_read`
// while we have data and cout until < 0.
