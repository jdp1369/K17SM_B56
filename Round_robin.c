#include<stdio.h>
struct process //A structure for storing the different data of the process.
{
 	char name;
 	int at; //Arival Time
	int bt; //Burst Time
	int wt; //Waiting Time
	int tt; //Turnaround Time
	int rt; //Run Time
 	int completed;
}p[10];
int n;
int q[100];  //queue
int front=-1,rear=-1;
int enqueue(int i) //a function to insert the process in the Queue
{
 	if(rear==100)
 	{
		printf("overflow");
		return 0;
	}rear++;
	q[rear]=i;
	if(front==-1)
		front=0;
}

int dequeue()//a funtion to delete the process from the Queue
{
 	if(front==-1)
 	{
		printf("underflow");
		return 0;
	}
	int temp=q[front];
 	if(front==rear)
 		front=rear=-1;
 	else
 		front++;
 	return temp;
}
int isInQueue(int i) //a function to check wheather the process is in the Queue or not. If it is in the Queue then return 1 else return 0
{
	int k;
	for(k=front;k<=rear;k++)
	{
		if(q[k]==i)
		return 1;
	}
	return 0;

}
void sortByArrival() //Since the process which didn't came to existance cannot be excuted so first that processes should be sorted acc. to the arival time.
{
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
		if(p[i].at>p[j].at)
 		{
  			temp=p[i];
  			p[i]=p[j];
  			p[j]=temp;
 		}
	}
}

void main()
{

	int i,j,time=0,sum_bt=0,tq;
	char c;
        float avgwt=0,avgtat=0;
	printf("Enter no of processes:");
	scanf("%d",&n);
 	for(i=0,c='A';i<n;i++,c++)
 	{
 		p[i].name=c;
		printf("\nEnter the details for process %c : ",p[i].name);
 		printf("\nEnter the arrival time : ");
 		scanf("%d",&p[i].at);
		printf("\nEnter the Burst time : ");
		scanf("%d",&p[i].bt);
 		p[i].rt=p[i].bt;
 		p[i].completed=0;
 		sum_bt+=p[i].bt;

	}
	printf("\nEnter the time quantum:");
	scanf("%d",&tq);
	int min_time = p[0].at;
	sortByArrival();      //sorting the process acc. to the arival time
	enqueue(0);          // enqueue the first process
	printf("Process execution order: ");
	for(time=p[0].at;time<sum_bt;)       // run until the total burst time reached
	{
		i=dequeue();
		if(p[i].rt<=tq)
 		{                          // for processes having remaining time with less than or equal time quantum
			time+=p[i].rt;
			p[i].rt=0;
			p[i].completed=1;
			printf("%c->",p[i].name);
		        p[i].wt=time-p[i].at-p[i].bt;
		        p[i].tt=time-p[i].at;
		      	for(j=0;j<n;j++)                // enqueue the processes which have come while scheduling
            		{
             			if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
             			{
              				enqueue(j);
              			}
           		}
        	}
     		else               // more than time quantum
     		{
      			time+=tq;
      			p[i].rt-=tq;
      			printf("%c->",p[i].name);
      			for(j=0;j<n;j++)             //enqueue the processes which have come scheduling first
      			{
        			if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
				{
				enqueue(j);
              			}
           		}
           		enqueue(i);   // then enqueue the uncompleted process
     		}

	}
	printf("NULL");

	printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
	for(i=0;i<n;i++)
	{
		avgwt+=p[i].wt;
		avgtat+=p[i].tt;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("\nAverage waiting time:%f\n",avgwt/n);
	printf("\nAverage TurnAround Time:%f\n",avgtat/n);
}

/*
ALL RIGHTS Reserved
	--dom_shadow
	--1369ltd
*/
