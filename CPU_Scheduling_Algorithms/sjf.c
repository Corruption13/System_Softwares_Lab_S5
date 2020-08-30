// S Sandeep Pillai
// CS 5 A
// 59

/* 
    Program to Implement Shortest Job First Process Scheduling 
    Lab Work 1 (b)
    20 August 2020
*/
#include <stdio.h>
void main(){
    int n;
    printf("Enter number of processes to schedule: ");
    scanf("%d", &n);
    int process_ID[n];
    int burst_time[n];
    
    for(int i = 0; i < n ; i++){
        process_ID[i] = i+1 ;
        printf("Enter burst time of process %d : ", process_ID[i] );
        scanf("%d", &burst_time[i] );
    }

    for(int i=0; i<n; i++ ){        
            int temp;
            int pos=i;
            for(int j = i+1; j < n; j++ )
            {
                if(burst_time[j] < burst_time[pos])
                    pos = j;
            }
    
            temp = burst_time[i];
            burst_time[i] = burst_time[pos];
            burst_time[pos] = temp;
    
            temp = process_ID[i];
            process_ID[i] = process_ID[pos];
            process_ID[pos] = temp;
    }

    int wait_time[n] ;
    int turn_around_time[n];
    int total_wait_time = 0;
    int total_turn_around_time = 0;


    wait_time[0] = 0;
    turn_around_time[0] = burst_time[0];

    for(int i = 1; i < n; i++){
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        turn_around_time[i] = burst_time[i] + wait_time[i] ;
    }


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