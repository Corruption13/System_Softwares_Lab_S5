// S Sandeep Pillai
// CS 5 A
// 59

/* 
    Program to Implement Round Robin Process Scheduling 
    Lab Work 1 (c)
    20 August 2020
*/


#include <stdio.h>

void main()
{
    int i, n, quantum;

    printf("Number of Processes: ");
    scanf("%d", &n);
    int burst_time[20], turn_around_time[20], wait_time[20];
    int process_ID[n];
    for(int i = 0; i < n ; i++){
        process_ID[i] = i+1 ;
        printf("Enter burst time of process %d : ", process_ID[i] );
        scanf("%d", &burst_time[i] );
    }

    printf("Enter time quantum:");
    scanf("%d", &quantum);
    
    int b_rem[20];
    for (i = 0; i < n; ++i) {
        b_rem[i] = burst_time[i];                        
    }
    int time = 0;                             

    while (1)
    {

        int flag = 0;

        for (i = 0; i < n; ++i) {

            if (b_rem[i] > 0) {                 
                flag = 1;                       
                if (b_rem[i] > quantum) {
                    time += quantum;            
                    b_rem[i] -= quantum;        
                }
                else {                        
                    time += b_rem[i];          
                    wait_time[i] = time - burst_time[i];        
                    b_rem[i] = 0;             
                }
            }
        }
        if (flag == 0) {                      
            break;
        }
    }


    for (i = 0; i < n; ++i) {
        turn_around_time[i] = burst_time[i] + wait_time[i];
    }
    int total_wait_time = 0;
    int total_turn_around_time = 0;


    for (int  i=0; i<n; i++)  
        {  
            total_wait_time = total_wait_time + wait_time[i];  
            total_turn_around_time = total_turn_around_time + turn_around_time[i];  
            printf("\nID: %d \n", process_ID[i] ); 
            printf("Burst Time: %d \n", burst_time[i] ); 
            printf("Wait Time: %d \n", wait_time[i] ); 
            printf("Turn Around Time: %d \n", turn_around_time[i] );  
        }  
    printf("\n\nAverage Wait Time: %f", (double)total_wait_time / n );
    printf("\nAverage Turn Around Time: %f \n", (double)total_turn_around_time / n );


}