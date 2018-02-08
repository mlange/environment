#include <moca.h>

#include <stdio.h>
#include <stdlib.h>
#include <process.h>


void main(int argc, char *argv[])
{
    int status;
    char *val1, *val2;

    val1 = getenv("VAR");
    printf("Value 1: %s\n", val1 ? val1 : "NULL");

    status = _spawnlp("main.bat", "main.bat", NULL);
    if (status == -1)
    {
        fprintf(stderr, "_spawnvp: %s", osError( ));
        fprintf(stderr, "Could not call main.bat\n");
        exit(EXIT_FAILURE);
    }

    val2 = getenv("VAR");
    printf("Value 2: %s\n", val2 ? val2 : "NULL");

    exit(0);
}
