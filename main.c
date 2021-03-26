// Copyright 2021

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "spinner.h"

#ifdef GLIMPSE_ENABLED 
#define GLIMPSE_FN_DUR()                            \
    clock_t t;                                      \
    t = clock();                                    \
    sleep(5);                                       \
    t = clock() - t;                                \
    double time_taken = ((double)t)/(CLOCKS_PER_SEC/1000); \
    printf("%s took %f milliseconds to execute \n", __func__, time_taken);
#endif

void
run() 
{
    GLIMPSE_FN_DUR();
}

int
main(int argc, char** argv)
{
    spinner_t* s = spinner_new(9);
    s->delay = 100000;
    s->prefix = "Doing all the things... ";
    run();
    s->final_msg = "Complete!\n";
    spinner_start(s);
    sleep(60);
    spinner_stop(s);
    spinner_free(s);
    return 0;
}
