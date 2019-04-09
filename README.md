# K17SM_B56
Round Robin with and without priority

Ques. 5. CPU schedules N processes which arrive at different time intervals and each process is allocated the CPU for a specific user input time unit, processes are scheduled using a preemptive round robin scheduling algorithm. Each process must be assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes one task has priority 0. The length of a time quantum is T units, where T is the custom time considered as time quantum for processing. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue. Design a scheduler so that the task with priority 0 does not starve for resources and gets the CPU at some time unit to execute. Also compute waiting time, turn around.


Solution:-
In Priority_round_robin.cpp the code implements priority based Round robin algorithm in which the after a particular Time Quantum the process preemption occurs and the process with the highest priority in the queue will get the chance to use the CPU. 



Ques. 16. Design a scheduler that can schedule the processes arriving system at periodical intervals. Every process is assigned with a fixed time slice t milliseconds. If it is not able to complete its execution within the assigned time quantum, then automated timer generates an interrupt. The scheduler will select the next process in the queue and dispatcher dispatches the process to processor for execution. Compute the total time for which processes were in the queue waiting for the processor. Take the input for CPU burst, arrival time and time quantum from the user.


Solution:-
Round_Robin.c contains the code for implementing the round robin algorithm in which after a particular time Quantum the process preemption
occurs and the next process gets the chance to use the CPU.This kind of algorithm reduces starvation(if the Time Quantum is not too large)

