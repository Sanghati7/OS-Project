#include<stdio.h>
#include<conio.h>
int queue1,queue2,queue3;
int roundrobin(int a, int b);
int fcfs(int a, int b);
int priority_scheduling(int a , int b);
int wt[20];
int main()
{
	//int queue1,queue2,queue3;
	printf("Enter number of processes in queue 1::");
	scanf("%d",&queue1);
	printf("Enter number of processes in queue 2::");
	scanf("%d",&queue2);
	printf("Enter number of processes in queue 3::");
	scanf("%d",&queue3);
	int p1,p2,p3;
	
	char name[3];
	printf("Enter priority_scheduling of queue 1::");
	scanf("%d",&p1);
	while(1)
	{
	printf("Enter priority_scheduling of queue 2::");
	scanf("%d",&p2);
	if(p1!=p2)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("Enter priority_scheduling of queue 3::");
	scanf("%d",&p3);
	if(p1!=p3&&p2!=p3)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)
	{
		roundrobin(queue1,1);
		if(p2<p3)
		{
			priority_scheduling(queue2,2);
			fcfs(queue3,3);
		}
		else
		{
			priority_scheduling(queue3,3);
			fcfs(queue2,2);
		}
	}
	else if(p2<p1&&p2<p3)
	{
		roundrobin(queue2,2);
		if(p1<p3)
		{
			priority_scheduling(queue1,1);
			fcfs(queue3,3);
		}
		else
		{
			priority_scheduling(queue3,3);
			
		}
	}
	else
	{
		roundrobin(queue3,3);
		if(p1<p2)
		{
			priority_scheduling(queue1,1);
			
		}
		else
		{
			priority_scheduling(queue2,2);
			
		}
	}
}


int priority_scheduling(int a,int b)
{
	int bt[20], process[20], tat[20], priority_scheduling[20];
      int i, j, limit, sum = 0, position, temp;
      float awt, atat;
      printf("applying priority_scheduling scheduling algorithm on queue no. %d",b);
      /*printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);*/
      limit=a;
      int ask=1;
      printf("\nEnter Burst Time and priority_scheduling For %d Processes\n", limit);
      if(ask=1)
      {
      	for(i = 0; i < limit; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Burst Time:\t");
            scanf("%d", &bt[i]);
            printf("Process priority_scheduling:\t");
            scanf("%d", &priority_scheduling[i]);
            process[i] = i + 1;
      }
      ask=0;
	  }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority_scheduling[j] < priority_scheduling[position])
                  {
                        position = j;
                  }
            }
            temp = priority_scheduling[i];
            priority_scheduling[i] = priority_scheduling[position];
            priority_scheduling[position] = temp; 
            temp = bt[i];
            bt[i] = bt[position];
            bt[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      wt[0] = 0;
      for(i = 1; i < limit; i++)
      {
            wt[i] = 0;
            for(j = 0; j < i; j++)
            {
                  wt[i] = wt[i] + bt[j];
            }
            sum = sum + wt[i];
      }
      awt = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            tat[i] = bt[i] + wt[i];
            sum = sum + tat[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], bt[i], wt[i], tat[i]);
      }
      atat = sum / limit;
      printf("\nAverage Waiting Time:\t%f", awt);
      printf("\nAverage Turnaround Time:\t%f\n", atat);
      return 0;
}

int fcfs(int c, int d)
{
	float bt[30], wt[30], tat[30];
        float awt = 0.0, atat = 0.0;
        int count, j, total_process;
        printf("applying fcfs on queue no . %d",d);
        /*printf("Enter The Number of Processes To Execute:\t");
        scanf("%d", &total_process);*/
        total_process=c;
        printf("\nEnter The Burst Time of Processes:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("Process [%d]:", count + 1);
                scanf("%f", &bt[count]);
        }
        wt[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                wt[count] = 0;
                for(j = 0; j < count; j++)
                {
                        wt[count] = wt[count] + bt[j];
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                tat[count] = bt[count] + wt[count];
                awt = awt + wt[count];
                atat = atat + tat[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, bt[count], wt[count], tat[count]);
        }
        printf("\n");
        awt = awt / count;
        atat = atat / count;
        printf("\nAverage Waiting Time = %f", awt);
        printf("\nAverage Turnaround Time = %f", atat);
        printf("\n");
        return 0;
}

int roundrobin(int e, int f)
{
	int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, tat = 0, arrival_time[10], bt[10], temp[10]; 
      float awt, atat;
      printf("applying roundrobin on queue no. %d ",f);
      /*printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit);*/
	  limit=e; 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      } 
    printf("\n Time Quantum:: \t"); 
   scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum &&temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum;
                  total = total +time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - arrival_time[i], total - arrival_time[i] - bt[i]);
                  wait_time = wait_time + total - arrival_time[i] - bt[i]; 
                  tat = tat + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      awt = wait_time * 1.0 / limit;
      atat = tat * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", awt); 
      printf("\nAvg Turnaround Time:\t%f\n", atat); 
      return 0; 
}
