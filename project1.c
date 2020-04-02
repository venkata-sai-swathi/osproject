/*LRTF.c
question number : 12
regrstration number :11805316
section :k18uw
*/


#include <stdio.h>
struct stu
{
    int StuId;
    int FTT;//food taken time
    int WT;//waiting time
    int TAT;//turnaroundtime
};

void agree(struct stu list[], int k);
void show(struct stu list[], int k);
void schedule(struct stu list[], int k);
void tAT(struct stu list[], int n);
void wT(struct stu list[], int n);

int main()
{
    struct stu d[20];
    int n;
      int s;
    char o;
    do
	{
    printf("Enter  Number of Students wants to take  mess? : ");
    scanf("%d", &n);
    agree(d, n);
    schedule(d, n);
    wT(d,n);
    tAT(d,n);
    show(d, n);
    printf("Want to continue? press 'y' : ");
    scanf("%s",&o);
    }while(o=='y');
    return 0;
} 

void agree(struct stu list[80], int k)
{
    int s;
    for (s = 0; s < k; s++)
    {
        printf("\n\nEnter data for Student #%d", s + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[s].StuId);

        printf("Enter time taken for food (minuts): ");
        scanf("%d", &list[s].FTT);
    } 
}

void show(struct stu list[80], int k)
{
    int s,AWT=0,ATAT=0;
	int TWT=0,TTAT=0;
    printf("\n\n\n\t\t\t\tOutput according to LRTF\n");
    printf("\n\n\t\t\t\t|****************************************|");
    printf("\n\n\t\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|*************************************************|");    
    for (s = 0; s < k; s++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[s].StuId, list[s].FTT,list[s].WT,list[s].TAT);
        printf("\a\n\t\t\t|---------------------------------------------------------------|");
		TWT= TWT+list[s].WT;
		TTAT= TTAT+list[s].TAT;
	} 
	printf("\n\n\t\n\t\t\tTotal Waiting Time is: = %d",TWT);
	printf("\n\n\t\t\t\tTotal Turn around Time is: = %d\n\n",TTAT);
	printf("\n\n\n\t\t\t\tAverage Waiting Time is: = %d",TWT/k);
	printf("\n\n\t\t\t\tAverage Turn around Time is: = %d\n\n",TTAT/k);
}

void schedule(struct stu list[80], int k)
{
    int s, q;
    struct stu t;//temperary variable t
    
    for (s = 0; s < k - 1; s++)
    {
        for (q = 0; q < (k - 1-s); q++)
        {
            if (list[q].FTT < list[q + 1].FTT)
            {
                t = list[q];
                list[q] = list[q + 1];
                list[q + 1] = t;
            } 
            else if(list[q].FTT == list[q + 1].FTT)
            {
            	if(list[q].StuId > list[q + 1].StuId)
            	{
            	t = list[q];
                list[q] = list[q + 1];
                list[q + 1] = t;
                }
			}
        }
    }
}


void wT(struct stu list[80], int n)
{
	int q,total1;
    list[0].WT=0;
    for(q=1;q<n;q++)
    {
        list[q].WT=list[q-1].WT+list[q-1].FTT;
    }
}


void tAT(struct stu list[80], int n)
{
	int q,total1;
    
    for(q=0;q<n;q++)
    {
        list[q].TAT=list[q].WT+list[q].FTT;
    }
}
