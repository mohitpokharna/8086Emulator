#include<stdio.h>
#include<string.h>
#include<ctype.h>

int s=0,w=0,ind=0;

char* checkreg(char reg[])
{
    //printf("%s",reg);
    char* regs_code[] = {"000","001","010","011","100","101","110","111"}; 
    char* regs[] = {"al","cl","dl","bl","ah","ch","dh","bh"};
    char* wregs[] = {"ax","cx","dx","bx","sp","bp","si","di"};
    int i;
    for(i=0;i<8;++i)
    {
        if(strcmp(regs[i],reg)==0) {w=0; return regs_code[i];}
    }
    for(i=0;i<8;++i)
    {
        if(strcmp(wregs[i],reg)==0) {w=1; return regs_code[i];}
    }
}

int binToDec(int n)
{
    int num = n;
    int dec = 0;
    int base = 1;
    int temp = num;
    while(temp)
    {
        int last_dig = temp%10;
        temp = temp/10;
        dec += last_dig*base;
        base = base*2;
    }
    return dec;
}

int main()
{
    char a[20],b[20],c[20],bin[20],cw[20],cs[20],sy[200];
    int p,q,dec,dec1,dec2,ibin;
    int x;
    char reg[3],t[10];
    FILE *fp;
    printf("Give filename\n");
    scanf("%s",t);
    fp=fopen(t,"w");
    do {scanf("%s",a);
    if(strcmp(a,"mov")==0)
    {
        scanf("%s %s",b,c);
        //printf("%s %s\n",b,c);
        int var = atoi(c);
        //printf("var %d\n",var);
        //printf("isdigit(c) %d\n",isdigit(var));
        if(var)
        {
            ind += 2;
            printf("register number --> ");
            if(strcmp(b,"dl")==0) {strcpy(reg,"010"); p=atoi(c);}
            if(strcmp(b,"ah")==0) {strcpy(reg,"100"); q=atoi(c);}
            char *reg;
            reg = checkreg(b);
            if(w==0)
            {
                printf("1011%d%s %s\n",w,reg,c);
                x = 1011;
                snprintf(bin,sizeof(bin),"%d",x);
                sprintf(cw,"%d",w);
                strcat(strcat(bin,cw),reg);
                ibin = atoi(bin);
                //printf("%d\n",ibin);
                dec = binToDec(ibin);
                fprintf(fp,"%d %s\n",dec,c);
            }
            else
            {
                ind += 1;
                //printf("%d\n",var);
                printf("1011%d%s %d %d\n",w,reg,var%256,var/256);
                x = 1011;
                snprintf(bin,sizeof(bin),"%d",x);
                sprintf(cw,"%d",w);
                strcat(strcat(bin,cw),reg);
                ibin = atoi(bin);
                //printf("%d\n",ibin);
                dec = binToDec(ibin);
                fprintf(fp,"%d %d %d\n",dec,var%256,var/256);
            }
        }
        else
        {
            ind += 2;
            printf("register register --> ");
            char *reg1,*reg2;
            reg1 = checkreg(b);
            reg2 = checkreg(c);
            printf("1000101%d 11%s%s\n",w,reg1,reg2);
            x = 1000101;
            snprintf(bin,sizeof(bin),"%d",x);
            sprintf(cw,"%d",w);
            strcat(bin,cw);
            ibin = atoi(bin);
            dec1 = binToDec(ibin);
            x = 11;
            snprintf(bin,sizeof(bin),"%d",x);
            //sprintf(cw,"%d",w);
            strcat(strcat(bin,reg1),reg2);
            ibin = atoi(bin);
            dec2 = binToDec(ibin);
            fprintf(fp,"%d %d\n",dec1,dec2);
            //fprintf(fp,"1000101%d 11%s%s\n",w,reg1,reg2);
        }
    }
    if(strcmp(a,"add")==0)
    {
        scanf("%s %s",b,c);
        int var = atoi(c);
        if(var)
        {
            ind += 3;
            printf("register number --> ");
            //if(strcmp(b,"dl")==0) {strcpy(reg,"010"); p=atoi(c);}
            //if(strcmp(b,"ah")==0) {strcpy(reg,"100"); q=atoi(c);}
            char *reg;
            reg = checkreg(b);
            printf("100000%d%d 11000%s %s\n",s,w,reg,c);
            x = 100000;
            snprintf(bin,sizeof(bin),"%d",x);
            sprintf(cw,"%d",w);
            sprintf(cs,"%d",s);
            strcat(strcat(bin,cs),cw);
            ibin = atoi(bin);
            dec1 = binToDec(ibin);
            x = 11000;
            snprintf(bin,sizeof(bin),"%d",x);
            //sprintf(cw,"%d",w);
            //sprintf(cs,"%d",s);
            strcat(bin,reg);
            ibin = atoi(bin);
            dec2 = binToDec(ibin);
            fprintf(fp,"%d %d %s\n",dec1,dec2,c);
            //fprintf(fp,"100000%d%d 11000%s %s\n",s,w,reg,c);
        }
        else
        {
            ind += 2;
            printf("register register --> ");
            char *reg1,*reg2;
            reg1 = checkreg(b);
            reg2 = checkreg(c);
            printf("0000001%d 11%s%s\n",w,reg1,reg2);
            x = 0000001;
            snprintf(bin,sizeof(bin),"%d",x);
            sprintf(cw,"%d",w);
            strcat(bin,cw);
            ibin = atoi(bin);
            dec1 = binToDec(ibin);
            x = 100000;
            snprintf(bin,sizeof(bin),"%d",x);
            //sprintf(cw,"%d",w);
            //sprintf(cs,"%d",s);
            strcat(strcat(bin,reg1),reg2);
            ibin = atoi(bin);
            dec2 = binToDec(ibin);
            fprintf(fp,"%d %d\n",dec1,dec2);
            //fprintf(fp,"0000001%d 11%s%s\n",w,reg1,reg2);
        }

    }
    if(strcmp(a,"cmp")==0)
    {
        scanf("%s %s",b,c);
        int var = atoi(c);
        if(var)
        {
            ind += 2;
            printf("register number --> ");
            //if(strcmp(b,"dl")==0) {strcpy(reg,"010"); p=atoi(c);}
            //if(strcmp(b,"ah")==0) {strcpy(reg,"100"); q=atoi(c);}
            char *reg;
            reg = checkreg(b);
            printf("100000%d%d 11111%s %s\n",s,w,reg,c);
            x = 100000;
            snprintf(bin,sizeof(bin),"%d",x);
            sprintf(cw,"%d",w);
            sprintf(cs,"%d",s);
            strcat(strcat(bin,cs),cw);
            ibin = atoi(bin);
            dec1 = binToDec(ibin);
            x = 11111;
            snprintf(bin,sizeof(bin),"%d",x);
            //sprintf(cw,"%d",w);
            //sprintf(cs,"%d",s);
            strcat(bin,reg);
            ibin = atoi(bin);
            dec2 = binToDec(ibin);
            fprintf(fp,"%d %d %s\n",dec1,dec2,c);
            //fprintf(fp,"100000%d%d 11000%s %s\n",s,w,reg,c);
        }
    }
    if(strcmp(a,"jc")==0)
    {
        ind += 2;
        scanf("%s",b);
        int disp = sy[b[0]] - ind;
        printf("01110010 %d\n",disp);
        x = 01110010;
        snprintf(bin,sizeof(bin),"%d",x);
        ibin = atoi(bin);
        dec1 = binToDec(ibin);
        fprintf(fp,"%d %d\n",dec1,disp);
        //fprintf(fp,"100000%d%d 11000%s %s\n",s,w,reg,c);
    }
    if(a[1]==':')
    {
        sy[a[0]]=ind;
    }
    if(strcmp(a,"int")==0)
    {
        ind += 2;
        scanf("%s",b);
        printf("11001101 33\n");
        x = 11001101;
        snprintf(bin,sizeof(bin),"%d",x);
        //sprintf(cw,"%d",w);
        //strcat(strcat(bin,cw),reg);
        ibin = atoi(bin);
        dec = binToDec(ibin);
        fprintf(fp,"%d 33\n",dec);
        //if(q==2) printf("%c\n",p);
        if(q==76) {fprintf(fp,"End\n");break;}
    }
    }while(strcmp(a,"end")!=0);
    fclose(fp);

    return 0;
}
