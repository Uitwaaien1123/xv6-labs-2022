#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char* argv[])
{
    if (argc != 2)  //to judge whether there's only one number input
    {
        printf("usage: sleep [time...]\n"); // reminding the usage of sleep()
        exit(1);
    }
    int time = atoi(argv[1]); //atoi turns char* into int
    sleep(time);//use sleep function
    printf("(nothing happens for a little while)\n");
    exit(0);
}