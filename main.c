// Copyright 2021

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "spinner.h"

int
main(int argc, char** argv)
{
    spinner_t* s = spinner_new(9);
    s->delay = 100000;
    s->prefix = "Doing all the things... ";
    s->final_msg = "\nComplete!\n";
    spinner_start(s);
    sleep(60);
    spinner_stop(s);
    spinner_free(s);
    return 0;
}
