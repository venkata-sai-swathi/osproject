#include<stdio.h>
void main()
{
 int c[10],d[10],s[10];
 int wt[10],tat[10],cp[10];
 int q,p,small,count=0,t,n;
 double averag=0,tAt=0,end;
 
 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);
 for(q=0;q<n;q++)
 {
   printf("\nEnter arrival time of process %d : ",q+1);
   scanf("%d",&c[q]);
 }
 for(q=0;q<n;q++)
 {
   printf("\nEnter burst time of process %d : ",q+1);
   scanf("%d",&d[q]);
 }
 for(q=0;q<n;q++)
 s[q]=d[q];

  d[9]=9999;
 //printf("time => process number");
 for(t=0;count!=n;t++)
 {
   small=9;
  for(q=0;q<n;q++)
  {
   if(c[q]<=t && d[q]<d[small] && d[q]>0 )
   small=q;
  }
  d[small]--;
  //printf("\n%d => p%d",time+1,small);
  if(d[small]==0)
  {
   count++;
   end=t+1;
   cp[small] = end;
   wt[small] = end - c[small] - s[small];
   tat[small] = end - c[small];
   // printf("\n %d  %d   %d",small,wt[small],tatp[small]);
  }
 }
 printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 for(q=0;q<n;q++)
 {
   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",q+1,s[q],c[q],wt[q],tat[q],cp[q]);
   averag = averag + wt[q];
   tAt = tAt + tat[q];
 }
 printf("\n  %If   %If",averag,tAt);
 printf("\n\nAverage waiting time = %lf\n",averag/n);
 printf("Average Turnaround time = %lf",tAt/n);
 
}
