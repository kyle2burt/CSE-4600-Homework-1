// pipe1.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    FILE *fpi;
    // for reading a pipe
    char buffer[BUFSIZ + 1];
    // BUFSIZ defined in <stdio.h>
    int chars_read;
    memset(buffer, 0, sizeof(buffer)); // clear buffer

    // length of command piped through program
    if (!argv[1]) {
        cout << "Enter a command after the executable like this: `./pipe1a.exe "
                "ls -l` "
             << endl;
        return 1;
    }

    int user_cmd_size = strlen(argv[1]);
    char user_cmd[user_cmd_size];
    // copy command to `user_cmd`
    strcpy(user_cmd, argv[1]);
    fpi = popen(user_cmd, "r");

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

// Johnny Thavisay 005330373
