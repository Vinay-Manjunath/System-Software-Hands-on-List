/*
============================================================================
Name        : 2.c
Author      : M Vinay
Description : C program that executes in an infinite loop in the background.
              After running, its process details can be inspected from
              the /proc/<pid>/ directory, which exposes kernel and runtime
              information such as memory usage, open files, scheduling info,
              and process status.

Date        : 14th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 2.c
    $ ./a.out &
    [1] 677

    $ ls /proc/677
    arch_status      gid_map            ns             smaps
    attr             io                 numa_maps      smaps_rollup
    auxv             ksm_merging_pages  oom_adj        stack
    cgroup           ksm_stat           oom_score      stat
    clear_refs       latency            oom_score_adj  statm
    cmdline          limits             pagemap        status
    comm             loginuid           patch_state    syscall
    coredump_filter  map_files          personality    task
    cpuset           maps               projid_map     timens_offsets
    cwd              mem                root           timers
    environ          mountinfo          sched          timerslack_ns
    exe              mounts             schedstat      uid_map
    fd               mountstats         sessionid      wchan
    fdinfo           net                setgroups

    $ cat /proc/677/status
    Name:   a.out
    Umask:  0022
    State:  R (running)
    Tgid:   677
    Ngid:   0
    Pid:    677
    PPid:   356
    TracerPid:      0
    Uid:    0       0       0       0
    Gid:    0       0       0       0
    FDSize: 256
    Groups: 0
    NStgid: 677
    NSpid:  677
    NSpgid: 677
    NSsid:  356
    Kthread:        0
    VmPeak:     2672 kB
    VmSize:     2648 kB
    VmLck:         0 kB
    VmPin:         0 kB
    VmHWM:      1024 kB
    VmRSS:      1024 kB
    RssAnon:               0 kB
    RssFile:            1024 kB
    RssShmem:              0 kB
    VmData:       92 kB
    VmStk:       136 kB
    VmExe:         4 kB
    VmLib:      1796 kB
    VmPTE:        40 kB
    VmSwap:        0 kB
    Threads:        1
    SigQ:   0/15097
    nonvoluntary_ctxt_switches: 75
    ...
============================================================================
*/

#include <stdio.h>

int main() {
    for (;;);   
    return 0;
}

