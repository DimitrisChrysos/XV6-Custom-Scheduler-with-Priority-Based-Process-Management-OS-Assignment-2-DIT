#include "kernel/param.h"

typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int  uint32;
typedef unsigned long uint64;

typedef uint64 pde_t;

// Moved from "proc.h"
enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// Info for every active process
struct pstat {
  int pid[NPROC];                     // Process ID
  int ppid[NPROC];                    // Parent process ID
  char name[NPROC][16];               // Process name (debugging)
  int priority[NPROC];                // Priority number
  enum procstate state[NPROC];        // Process state
  uint64 sz[NPROC];                   // Size of process memory (bytes)
};