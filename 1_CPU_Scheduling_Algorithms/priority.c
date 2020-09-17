// S Sandeep Pillai
// CS 5 A
// 59

/* 
    Program to Implement Priority Process Scheduling 
    Lab Work 1 (c)
    20 August 2020
*/



#include <stdio.h>

int i, j, n;
float turn_around_time_average, wait_time_average;

struct Process {
    int pId;
    int burst_time;
    int priority;
};      // Probably should've done this for others too lol




int main()
{

    printf("Number of Processes: ");
    scanf("%d", &n);

    struct Process p[n];  
    int wait_time[n], turn_around_time[n];
    printf("\n");

    for (i = 0; i < n; ++i) {
        p[i].pId = i + 1;
        printf("Enter the burst time for process %d: ", p[i].pId);
        scanf("%d", &p[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &p[i].priority);
    }

    struct Process temp;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (p[j].priority > p[j + 1].priority) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    wait_time[0] = 0;
    int wtSum = 0;
    for (i = 1; i < n; ++i) {
        wait_time[i] = wait_time[i - 1] + p[i - 1].burst_time;
        wtSum += wait_time[i];
    }
    wait_time_average = (float)wtSum / n;

    
    int turn_around_time_total = 0;
    for (i = 0; i < n; ++i) {
        turn_around_time[i] = p[i].burst_time + wait_time[i];
        turn_around_time_total += turn_around_time[i];
    }
    turn_around_time_average = (float)turn_around_time_total / n;

    

    for (i = 0; i < n; i++ ) {

        printf("\nProcessID: %d", p[i].pId);
        printf("  BurstTime: %d", p[i].burst_time);
        printf("  Priority: %d", p[i].priority);
        printf("  Waiting time: %d", wait_time[i]);
        printf("  Turn Around Time: %d", turn_around_time[i]);

    }
    printf("\n\nAverage waiting time: %f", wait_time_average);
    printf("\nAverage turnaround time: %f", turn_around_time_average);
    printf("\n");


    return 0;
}

