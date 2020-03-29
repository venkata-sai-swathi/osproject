//LRTF.c project 

#include<stdio.h>
struct stu
{     
      int WT;//waiting time
     int StuId;//student id   
     int TAT;//turnaround time
int FoodTimetaken;  
};
int q;
void scheduling(struct stu list[],int k);
void show(struct stu list[],int k);
void agree(struct stu list[],int k);
void tAT(struct stu list[],int n);
void wT(struct stu list[],int n);


int main()
{
  
 
  int q;
 int n;
struct stu d[20];
   char e;
   do
    {
  printf("Can you please enter the Number of students that you wants to eat in mess?:");
  scanf("%d",&n);
scheduling(d,n);
 show(d,n);
  agree(d,n);
tAT(d,n);  
  wT(d,n);

 
  printf(" Would you like  to continue?\n\t\tpress 'y' :");
  scanf("%s" ,&e);
  }while(e=='y');
   return 0;
}

void agree(struct stu list[80],int k)
{
   int q ;
   for (q=0;q<k; q++)
   {
      printf("\n\nEnter data for Student #%d", q+1);
 
      printf("\nEnter Student id:");
      scanf("%d" , &list[q].StuId);
      printf("\nEnter Time Taken For Food:");
      scanf("%d" , &list[q].FoodTimetaken);
    }
}
 

void show(struct stu list[80], int k)
{
   int q,AWT=0,ATAT=0;
   int TWT=0,TTAT=0;
   printf("\n\n\n\t\t\tOtput according to LFRT\n");
   printf("\n\t\t\t\t|*******************************************|");
   printf("\n\n\n\t\t\t| Student id\tFoodTimeTime\tWaitingTime\tTurnAroundTime |");
   printf("\n\t\t\t**********************************************|");
   for (q = 0;q<k;q++)
   {
     printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t\t%d\t\t|",list[q].StuId,list[q].FoodTimetaken,list[q]. WT,list[q].TAT);
     printf("\a\n\t\t\t|------------------------------------------------|");
            TWT=TWT+list[q].WT;
            TTAT=TTAT+list[q].TAT;
   }

    printf("\n\n\t\t\tTotal Waiting Time is: = %d",TWT);
    printf("\n\n\t\t\tTotal TurnAround Time is: = %d\n\n",TTAT);
    printf("\n\n\t\t\tAverage Waiting Time is: = %d",TWT/k);
    printf("\n\n\t\t\tAverage TurnAround Time is: = %d\n\n",TTAT/k);
}

void scheduling(struct stu list[80],int k)
{
   int q,p;
   struct stu tmp;
   
   for(q = 0; q < k-1; q++)
   {
      for(p = 0; p < (k- 1-q);p++)
      {
        if (list[p].FoodTimetaken < list[p+1].FoodTimetaken)
        {
           tmp = list[p];
           list[p] = list[p + 1];
           list[p + 1] = tmp;
         }
         else if(list[p].FoodTimetaken == list[p + 1].FoodTimetaken)
         {
            if(list[p].StuId > list[p + 1].StuId)
            {
                tmp = list[p];
                list[p] = list[p+ 1];
                list[p + 1] = tmp;
             }
          }
        }
      }
 }

void wT(struct stu list[80],int n)
{
    int p,t,q;
    list[0].WT=0;
    for(p=1;p<n;p++)
    {
       list[p].WT=list[p -1].WT+list[p -1].FoodTimetaken;
    }
}
void tAT(struct stu list[80],int n)
{
   int p,t,q;
  
  for(p=0;p<n;p++)
  {
     list[p].TAT=list[p].WT+list[p].FoodTimetaken;
  }
}











  


