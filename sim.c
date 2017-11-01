#include<stdio.h>

void main()
{
    int i=0,cy=1,x,y,y1,y2,z,p,q,r[8],a[10000],pc=0;char t[10],c;FILE *fp;
    printf("Give filename\n");scanf("%s",t);fp=fopen(t,"r");
    for(i=0;i<1000;i++) fscanf(fp,"%d",&a[i]);
    while(1)
    { x=a[pc++];
      if((x>175)&&(x<184)) {y=a[pc++];z=x%8;r[z]=y;}
      if((x>183)&&(x<192)) {y1=a[pc++];z=x%8;r[z]=y1;y2=a[pc++];r[z+4]=y2;}
      if(x==138) {y=a[pc++];p=y%64/8;q=y%8;r[p]=r[q];}
      if((x==205)&&(r[4]==2)){y=a[pc++];printf("%c",r[2]);fflush(stdout);}
      if((x==205)&&(r[4]==76)){y=a[pc++];break;}
      if((x==205)&&(r[4]==1)){y=a[pc++];do{c=getchar();}while(c<20);r[0]=c;}
      if(x==128){y=a[pc++];z=a[pc++];p=y%8;q=r[p];
        if((y>191)&&(y<200))r[p]+=z;
        if(y>247) if(q<z) cy=1;else cy=0;}
      if(x==114){y=a[pc++];if(cy==1) pc=pc+y;}
    }
}
