#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

// Function to prin "procstate" enum values as strings
void print_enum2string(int num) {
    printf("STATE = ");
    switch (num) {
    case 0:
        printf("UNUSED");
        break;
    case 1:
        printf("USED");
        break;
    case 2:
        printf("SLEEPING");
        break;
    case 3:
        printf("RUNNABLE");
        break;
    case 4:
        printf("RUNNING");
        break;
    case 5:
        printf("ZOMBIE");
        break;
    }
    printf("  ||  ");
}

int main()
{
    // Print info about every active process
    struct pstat pinfo;
    getpinfo(&pinfo);
    for (int i = 0 ; i < NPROC ; i++) {
        if (pinfo.state[i] >= 1 && pinfo.state[i] <= 5) {
            printf("PID = %d  ||  ", pinfo.pid[i]);
            printf("PPID = %d  ||  ", pinfo.ppid[i]);
            printf("NAME = %s  ||  ", pinfo.name[i]);
            printf("PRIORITY = %d  ||  ", pinfo.priority[i]);
            print_enum2string(pinfo.state[i]);
            printf("SIZE = %lu\n", pinfo.sz[i]);
        }
    }
    exit(0);
}