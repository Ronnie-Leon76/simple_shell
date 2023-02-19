#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ownCmdHandler(char** parsed)
{
    int NoOfOwnCmds = 2, i, switchOwnArg = 0;
    char *OwnCmds[NoOfOwnCmds];

    OwnCmds[0] = "exit";
    OwnCmds[1] = "cd";

    for (i = 0; i < NoOfOwnCmds; i++) {
        if (strcmp(parsed[0], OwnCmds[i]) == 0) {
            switchOwnArg = i + 1;
            break;
        }
    }

    switch (switchOwnArg) {
        case 1:
            printf("\nGoodbye\n");
            exit(0);
        case 2:
            chdir(parsed[1]);
            return 1;
        default:
            break;
    }

    return 0;
}