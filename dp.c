#include<stdio.h>
 
#define n 4
 
int cP = 0,t;//completed philosopher
 
struct f{//fork
	int ta;//taken 
/*fork avail*/}FkAl[n];//ForkAvail
 
struct phi{//philosp
	int R;//right
	int L;//left
}Phista[n];//Philostatus
 
void gFD(int phID){ //same like threads concept here cases implemented
	if(Phista[phID].L==10 && Phista[phID].R==10)
        printf("Philosopher  %d completed his dinner\n",phID+1);
	//if already completed dinner
	else if(Phista[phID].L==1 && Phista[phID].R==1){
            //if just taken two forks
            printf("Philosopher %d completed his dinner\n",phID+1);
 
            Phista[phID].L = Phista[phID].R = 10; //remembering that he completed dinner by assigning value 10
            int oFork = phID-1;//otherFork
 
            if(oFork== -1)
                oFork=(n-1);
 
            FkAl[phID].ta = FkAl[oFork].ta = 0; //releasing forks
            printf("Philosopher %d released fork %d and fork %d\n",phID+1,phID+1,oFork+1);
            cP++;
        }
        else if(Phista[phID].L==1 && Phista[phID].R==0){ //left already taken, trying for right fork
                if(phID==(n-1)){
                    if(FkAl[phID].ta==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                        FkAl[phID].ta = Phista[phID].R = 1;
                        printf("Fork %d taken by philosopher %d\n",phID+1,phID+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",phID+1,phID+1);
                    }
                }else{ //except last philosopher case
                    int dupphID = phID;
                    phID-=1;
 
                    if(phID== -1)
                        phID=(n-1);
 
                    if(FkAl[phID].ta == 0){
                        FkAl[phID].ta = Phista[dupphID].R = 1;
                        printf("Fork %d taken by Philosopher %d\n",phID+1,dupphID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupphID+1,phID+1);
                    }
                }
            }
            else if(Phista[phID].L==0){ //nothing taken yet
                    if(phID==(n-1)){
                        if(FkAl[phID-1].ta==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                            FkAl[phID-1].ta = Phista[phID].L = 1;
                            printf("Fork %d taken by philosopher %d\n",phID,phID+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",phID+1,phID);
                        }
                    }else{ //except last philosopher case
                        if(FkAl[phID].ta == 0){
                            FkAl[phID].ta = Phista[phID].L = 1;
                            printf("Fork %d taken by Philosopher %d\n",phID+1,phID+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",phID+1,phID+1);
                        }
                    }
        }else{}
}
 
int main(){
	for(t=0;t<n;t++)
        FkAl[t].ta=Phista[t].L=Phista[t].R=0;
 
	while(cP<n){
		/* Observe here carefully, while loop will run until all philosophers complete dinner
		Actually problem of deadlock occur only thy try to take at same time
		This for loop will say that they are trying at same time. And remaining status will print by go for dinner function
		*/
		for(t=0;t<n;t++)
            gFD(t);
		printf("\nTill now num of philosophers completed dinner are %d\n\n",cP);
	}
 
	return 0;


}
