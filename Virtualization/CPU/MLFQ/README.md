# 1

**Run a few randomly-generated problems with just two jobs and
two queues; compute the MLFQ execution trace for each. Make
your life easier by limiting the length of each job and turning off
I/Os.**

```
python mlfq.py -j 2 -m 100 -i 0 -n 2 -M 0 -c
```

```
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 0
OPTIONS ioTime 0
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime  84 - ioFreq   0
  Job  1: startTime   0 - runTime  42 - ioFreq   0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 126
  Job  1: startTime   0 - response  10 - turnaround  92

  Avg  1: startTime n/a - response 5.00 - turnaround 109.00
```

# 2

**How would you run the scheduler to reproduce each of the exam-
ples in the chapter?**

I ignore this exercise cause I'm way too lazy. :(

# 3

**How would you configure the scheduler parameters to behave just
like a round-robin scheduler?**

Easiest solution: Set quantum time = 1

```
python mlfq.py -j 2 -m 100 -i 0 -n 2 -M 0 -q 1 -c
```

```
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is   1
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is   1
OPTIONS boost 0
OPTIONS ioTime 0
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime  84 - ioFreq   0
  Job  1: startTime   0 - runTime  42 - ioFreq   0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 126
  Job  1: startTime   0 - response   1 - turnaround  84

  Avg  1: startTime n/a - response 0.50 - turnaround 105.00
```

# 4

**Craft a workload with two jobs and scheduler parameters so that
one job takes advantage of the older Rules 4a and 4b (turned on
with the -S flag) to game the scheduler and obtain 99% of the CPU
over a particular time interval.**

```
python mlfq.py -S -l 10,30,9:0,30,0 -i 1 -q 10 -S -I -c
```

```
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 3
OPTIONS allotments for queue  2 is   1
OPTIONS quantum length for queue  2 is  10
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 0
OPTIONS ioTime 1
OPTIONS stayAfterIO True
OPTIONS iobump True


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime  10 - runTime  30 - ioFreq   9
  Job  1: startTime   0 - runTime  30 - ioFreq   0

  Final statistics:
  Job  0: startTime  10 - response   0 - turnaround  33
  Job  1: startTime   0 - response   0 - turnaround  60

  Avg  1: startTime n/a - response 0.00 - turnaround 46.50
```

# 5

**Given a system with a quantum length of 10 ms in its highest queue,
how often would you have to boost jobs back to the highest priority
level (with the -B flag) in order to guarantee that a single long-
running (and potentially-starving) job gets at least 5% of the CPU**

I set the boost time is 5, with the 


```
python mlfq.py -j 2 -m 100 -i 0 -n 2 -M 0 -q 10 -B 5 -c -l 0,100,0:0,50,0:0,20,0
```

```
Here is the list of inputs:
OPTIONS jobs 3
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 5
OPTIONS ioTime 0
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime 100 - ioFreq   0
  Job  1: startTime   0 - runTime  50 - ioFreq   0
  Job  2: startTime   0 - runTime  20 - ioFreq   0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 149
  Job  1: startTime   0 - response   6 - turnaround 170
  Job  2: startTime   0 - response   7 - turnaround 103

  Avg  2: startTime n/a - response 4.33 - turnaround 140.67
```