# Custom Priority Scheduler in XV6

This project extends the XV6 operating system by implementing a priority-based scheduler, along with two new system calls: `setpriority()` and `getpinfo()`. It allows processes to be prioritized and schedules them accordingly, enhancing process control and observability.

## Overview

### New System Calls

- `int setpriority(int num)`:  
  Sets the priority of the current process. Implemented in `proc.c` and `sysproc.c`.

- `int getpinfo(struct pstat *)`:  
  Retrieves scheduling and priority information for all processes. Uses a custom `struct pstat` defined in `types.h`.

### Kernel Modifications

- Added `int priority` field in `struct proc`, initialized to 10 in `allocproc()`.
- Modified the scheduler in `proc.c` to:
  - Locate the last `RUNNABLE` process with the highest priority (smallest value).
  - Run all `RUNNABLE` processes matching that priority level in reverse order.

### Additional Tools

- `ps.c`: Mimics Unix `ps` by displaying process state and priority.
  - Uses `print_enum2string()` to format `enum procstate`.
  - Relies on updated `types.h` that includes `pstat` and `procstate`.

## Testing

The project passes all test cases in:
- `usertests` (with default and single CPU)
- `priotest` (with default and single CPU)

## Compilation and Running

```bash
make qemu / make CPUS=1 qemu
ps
priotest
usertests
Exit qemu: Ctrl-A and X.
```

## Author

Δημήτριος Χρυσός

---

This project was created as part of an operating systems assignment, focusing on kernel development and scheduler customization.

# For xv6
xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern RISC-V multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)).  See also https://pdos.csail.mit.edu/6.1810/, which provides
pointers to on-line resources for v6.

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by
Takahiro Aoyagi, Silas Boyd-Wickizer, Anton Burtsev, carlclone, Ian
Chen, Dan Cross, Cody Cutler, Mike CAT, Tej Chajed, Asami Doi,
eyalz800, Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel
Filardo, flespark, Peter Froehlich, Yakir Goaron, Shivam Handa, Matt
Harvey, Bryan Henry, jaichenhengjie, Jim Huang, Matúš Jókay, John
Jolly, Alexander Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller,
Jungwoo Kim, Jonathan Kimmitt, Eddie Kohler, Vadim Kolontsov, Austin
Liew, l0stman, Pavan Maddamsetti, Imbar Marinescu, Yandong Mao, Matan
Shabtay, Hitoshi Mitake, Carmi Merimovich, Mark Morrissey, mtasm, Joel
Nider, Hayato Ohhashi, OptimisticSide, Harry Porter, Greg Price, Jude
Rich, segfault, Ayan Shafqat, Eldar Sehayek, Yongming Shen, Fumiya
Shigemitsu, Cam Tenny, tyfkda, Warren Toomey, Stephen Tu, Rafael Ubal,
Amane Uehara, Pablo Ventura, Xi Wang, WaheedHafez, Keiichi Watanabe,
Nicolas Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng,
ZhUyU1997, and Zou Chang Wei.


The code in the files that constitute xv6 is
Copyright 2006-2022 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

Please send errors and suggestions to Frans Kaashoek and Robert Morris
(kaashoek,rtm@mit.edu).  The main purpose of xv6 is as a teaching
operating system for MIT's 6.1810, so we are more interested in
simplifications and clarifications than new features.

BUILDING AND RUNNING XV6

You will need a RISC-V "newlib" tool chain from
https://github.com/riscv/riscv-gnu-toolchain, and qemu compiled for
riscv64-softmmu.  Once they are installed, and in your shell
search path, you can run "make qemu".
