#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main(){
  int que[20], h/*head*/, qsize, m,n, seek=0, dif,  t, que1[20], que2[20], t1=0, t2=0;//temporary t
  float average;

  printf("%s\t", "Input the number of disk locations");
  scanf("%d", &qsize);

  printf("%s\t", "Enter initial head position");
  scanf("%d", &h);

  printf("%s\n", "Enter disk positions to read");

  for(m=0; m<qsize; m++){
    scanf("%d", &t);
    if(t >= h){
      que1[t1] = t;
      t1++;
    } else {
      que2[t2] = t;
      t2++;
    }
  }


 
  for(m=0; m<t1-1; m++){
    for(n=m+1; n<t1; n++){
      if(que1[m] > que1[n]){
        t = que1[m];
        que1[m] = que1[n];
        que1[n] = t;
      }
    }
  }

  
  for(m=0; m<t2-1; m++){
    for(n=m+1; n<t2; n++){
      if(que2[m] > que2[n]){
        t = que2[m];
        que2[m] = que2[n];
        que2[n] = t;
      }
    }
  }

  if(abs(h-LOW) <= abs(h-HIGH)){

    for(m=1,n=t2-1; n>=0; m++,n--){
        que[m] = que2[n];
    }

    que[m] = LOW;
    que[m+1] = HIGH;

    for(m=t2+3,n=t1-1; n>=0; m++,n--){
        que[m] = que1[n];
    }

  } else {

    for(m=1,n=0; n<t1; m++,n++){
        que[m] = que1[n];
    }

    que[m] = HIGH;
    que[m+1] = LOW;

    for(m=t1+3,n=0; n<t2; m++,n++){
        que[m] = que2[n];
    }


  }
  que[0] = h;

  for(n=0; n<qsize; n++){
    dif=abs(que[n+1] - que[n]);
    seek += dif;
    printf("Disk head moves from %d to %d with seek %d\n",que[n],que[n+1],dif);

  }

  
  printf("Total seek time is %d\n", seek);
  average = seek/(float)qsize;
  printf("Average seek time is %f\n", average);

  return 0;
}
