# Multi-Level Feedback Queue

Multi-level feedback queue is a scheduling algorithm. Solaris 2.6 Time-Sharing (TS) scheduler implements this algorithm. The Mac OS X and Microsoft Windows schedulers can both be regarded as examples of the broader class of multilevel feedback queue schedulers. This scheduling algorithm is intended to meet the following design requirements for multimode systems:

    (a) Give preference to short jobs.
    (b) Give preference to I/O bound processes.
    (c) Separate processes into categories based on their need for the processor.
