// S Sandeep Pillai
// CS 5 A
// 59

/* 
    Program to Implement Round Robin Process Scheduling 
    Lab Work 1 (b)
    20 August 2020
*/
#include <stdio.h>
void main(){
    int n;
    int time_delta ;
    printf("Enter number of processes to schedule: ");
    scanf("%d", &n);
    printf("Enter time period to give to each process per cycle: ");
    scanf("%d", &time_delta);

    int process_ID[n];
    int burst_time[n];
    int rem_time[n];
    int rem_process[n];
    int active_time[n];
    int wait_time[n] ;
    int total_execution_time=0;
    
    
    for(int i = 0; i < n ; i++){
        process_ID[i] = i+1 ;
        printf("Enter burst time of process %d : ", process_ID[i] );
        scanf("%d", &burst_time[i] );
        rem_time[i] = burst_time[i];
        rem_process[i] = 1   ;
        wait_time[i] = 0;
        total_execution_time = total_execution_time + burst_time[i] - 1 ;
    }


   
    

  
    int turn_around_time[n];
    int total_wait_time = 0;
    int total_turn_around_time = 0;


    int execution_t = 0;
    int incomplete_process_count = n;

    printf("%d", total_execution_time);
    while(execution_t < total_execution_time){

        for(int i = 0; i<n; i++){
            
            if(rem_process[i] == 0)
                continue ;

            else if(rem_time[i] >= 0){

                printf("\n%d) Executing %d, with %d %d %d", execution_t, process_ID[i], rem_time[0], rem_time[1], rem_time[2]);
                rem_time[i] = rem_time[i] - time_delta;

                if(rem_time[i] >= time_delta){
                    for(int j = 0; j < n; j++){
                        if(j!=i){
                            wait_time[j] += time_delta;
                        } 
                    }
                }
                else{
                    for(int j = 0; j < n; j++){
                        if(j!=i){
                            wait_time[j] += rem_time[i];
                        } 
                    }
                } 

                if(rem_time[i] == 0){
                   rem_process[i] = 0;
                   turn_around_time[i] = execution_t;
                   printf("\nExecution done for %d at %d", process_ID[i], turn_around_time[i]);
                }
     
            }

            execution_t = execution_t + 1;
        }

        

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