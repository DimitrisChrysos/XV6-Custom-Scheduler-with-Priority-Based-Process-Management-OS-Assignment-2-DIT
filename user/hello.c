#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main()
{
    printf("Hello world!\n");
    uint64 freebytes = freemem();
    printf("Amount of free bytes: %d\n", freebytes);
    exit(0);
}