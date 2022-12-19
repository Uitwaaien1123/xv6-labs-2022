#include "kernel/types.h"
#include "user/user.h"
#define BUF 64

int main(int args, char* argv[])
{
    int des2c[2], des2p[2], child_pid; //
    char buf2c[BUF] = {0,}, buf2p[BUF] = {0,}; //seperate two buffer which accept data from each other
    pipe(des2c);
    pipe(des2p);
    child_pid = fork(); //make child process
    if (child_pid < 0) 
    {
        printf("Too much process or not enough memory...");
        exit(1);
    }
    else if (child_pid > 0) //parent process
    {
        close(des2c[0]); // not used
        close(des2p[1]); // not used
        write(des2c[1], "a", 1); 
        close(des2c[1]);
        read(des2p[0], buf2p, sizeof(buf2p));
        close(des2p[0]);
        //printf(1, buf2p);
        printf("<%d>: received ping\n", getpid());
    }
    else    //child process
    {
        close(des2c[1]); // not used
        close(des2p[0]); // not used
        read(des2c[0], buf2c, sizeof(buf2c));
        close(des2c[0]);
        //printf(1, buf2c);
        printf("<%d>: received ping\n", getpid());
        write(des2p[1], "b", 1);
        close(des2p[1]);
    }
    exit(0);
}