/*Design a scheduler that can schedule the processes arriving system at periodical intervals.
Every process is assigned with a fixed time slice t milliseconds.
If it is not able to complete its execution within the assigned time quantum, then automated timer generates an interrupt.
The scheduler will select the next process in the queue and dispatcher dispatches the process to processor for execution.
Compute the total time for which processes were in the queue waiting for the processor.
Take the input for CPU burst, arrival time and time quantum from the user.
*/

#include<stdio.h>
int main()
{
  //initialization of variables
  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n; //no. of processes
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
    scanf("%d",&at[count]); //input for arrival time
    scanf("%d",&bt[count]);  //input for burst time
    rt[count]=bt[count];  //remaining time
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);  //time slicing for each process
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
