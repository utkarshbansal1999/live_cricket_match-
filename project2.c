/*#include <stdio.h>
#include <stdlib.h>
struct name
{
    char nm[20];
};
int main()
{
    int i;
    struct name b1;
    FILE *fp,*kl;
    fp=fopen("team A.txt","w+");
    fclose(fp);
    fp=fopen("team A.txt","a");
    printf("enter eleven names of players with atleast five bowlers \n");
    fprintf(fp,"team A:\n");
    for(i=1;i<=11;i++)
        {
            gets(b1.nm);
            if(i<6)
            fprintf(fp,"%d\t%s(bat)\n",i,b1.nm);
            else if (i==6)
               fprintf(fp,"%d\t%s(c & bat)\n",i,b1.nm);
            else
                fprintf(fp,"%d\t%s(bowl)\n",i,b1.nm);
        }
        fclose(fp);
        kl=fopen("team B.txt","w+");
        fclose(kl);
        kl=fopen("team B.txt","a");
        printf("enter eleven names of players with atleast five bowlers \n");
        fprintf(kl,"team B:\n");
    for(i=1;i<=11;i++)
        {
            gets(b1.nm);
            if(i<6)
            fprintf(kl,"%d\t%s(bat)\n",i,b1.nm);
            else if (i==6)
               fprintf(kl,"%d\t%s(c & bat)\n",i,b1.nm);
            else
                fprintf(kl,"%d\t%s(bowl)\n",i,b1.nm);
        }
        fclose(kl);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int *wbat,*wbowl,*sbat,*sbowl;
int team();
int toss();
int bat(int i,int *sbat,int *wbat);
int bowl(int z,int run,int *sbowl,int *wbowl);
int scorebat();
int scorebowl();
int details(int z,int run,int chase);
int manmatch(int z,int net);
int main()
{
    int i,c,g,run,chase;
    printf("****************    A   T20    MATCH      **************\n\n");
    while(1)
    {
        printf("choose a type\n");
        printf("1 : team details\n");
        printf("2 : toss details\n");
        printf("3 : view batting\n");
        printf("4 : view bowling\n");
        printf("5 : scorecard for batting\n");
        printf("6 : scorecard for bowling\n");
        printf("7 : view details\n");
        printf("8 : exit\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:team() ;break;
        case 2:g=toss() ;break;
        case 3:run=bat(g,sbat,wbat) ;break;
        case 4:chase=bowl(g,run,sbowl,wbowl) ;break;
        case 5:scorebat() ;break;
        case 6:scorebowl() ;break;
        case 7:details(g,run,chase) ;break;
        case 8:exit(0) ;
        }
    }
    return 0;
}
int team()
{
    char c;
    FILE *fp;
    fp=fopen("team A.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
        //g++;
    }
    fclose(fp);
    fp=fopen("team B.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
        //g++;
    }
    fclose(fp);
    printf("\n\n");
    return 0;
}
int toss()
{
    int d,e,f,g=0;
    FILE *fp;
    fp=fopen("toss.txt","w");
    srand(time(NULL));
    d=rand()%2;
    if(d==0)
    {
        fprintf(fp,"\nteam A has chosen heads\n");
        printf("\nteam A has chosen heads\n");
    }
    else
    {
        fprintf(fp,"\nteam A has chosen tails\n");
        printf("\nteam A has chosen tails\n");
    }
    e=rand()%2;
    if(e==0)
    {
        fprintf(fp,"team A has won the toss\n");
        printf("team A has won the toss\n");
         f=rand()%2;
      if(f==0)
    {
        fprintf(fp,"team A has elected to bat first\n\n");
        g=1;
        printf("team A has elected to bat first\n\n");
    }
      else
    {
        fprintf(fp,"team A has elected to bowl first\n\n");
        g=2;
        printf("\nteam A has elected to bowl first\n\n");
    }
    }
    else
    {
        fprintf(fp,"team B has won the toss\n");
        printf("team B has won the toss\n");
         f=rand()%2;
    if(f==0)
    {
        fprintf(fp,"team B has elected to bat first\n\n");
        g=2;
        printf("team B has elected to bat first\n\n");
    }
    else
    {
        fprintf(fp,"team B has elected to bowl first\n\n");
        g=1;
        printf("\nteam B has elected to bowl first\n\n");
    }
    }
    fclose(fp);
    return g;
}
int bat(int z,int *sbat,int *wbat)
{
    time_t currenttime;
    char s[50];
    int b=0,a,c=0,i,m[120],total=0;
    FILE *fp,*kl;
    int j,r=0,w=0,points,n[11],y=0,q[10],qw=0;
    if(z==2)
    {
      kl=fopen("bat B.txt","w");
      fclose(kl);
      kl=fopen("bat B.txt","a");
      fp=fopen("team B.txt","r");
      printf("\n\n");
      fgets(s,49,fp);
      puts(s);
      fprintf(kl,"%s",s);
      while((fgets(s,49,fp))!=NULL)
      {
          fputs(s,kl);
          puts(s);
          points=points+10210;
          srand(time(&currenttime)+points);
          b=0;
          for(i=0;i<60;i++)
         {
          a=rand()%8;
          if(w==9 && a==7)
            c--;
          else
          m[c]=a;
          c++;
          if(c>120)
          break;
          if(a==7)
            {
                if(w==10)
                {w++;
                break;}
                    else
                {printf("out\t");
            fprintf(kl,"out\t");
            w++;
            break;}}
            b=b+a;
            total=total+a;
            fprintf(kl,"%d,",a);
          printf("%d,",a);
        }
          n[y++]=b;
          if(w==11)
          {fprintf(kl,"  :  %d(%d)\n\n",b,i);
          printf("  :  %d(%d)\n\n",b,i);}
          else{
          fprintf(kl,"  :  %d(%d)\n\n",b,i+1);
          printf("  :  %d(%d)\n\n",b,i+1);}
         if(c>=120)
             break;
         else
            continue;
      }
      fprintf(kl,"\n total : %d\n",total);
    printf("\ntotal : %d\n",total);
    fclose(fp);
    j=n[0];
    for(i=1;i<y;i++)
        if(j<n[i])
        j=n[i];
        sbat=j;
    fprintf(kl,"\n\nhighest score = %d\n",j);
    printf("\n\nhighest score = %d\n",j);
    fclose(kl);
    kl=fopen("bowl A.txt","w");
    fclose(kl);
    kl=fopen("bowl A.txt","a");
    fp=fopen("team A.txt","r");
    printf("\n");
    fgets(s,49,fp);
    fputs(s,kl);
    puts(s);
    y=0;
    while((fgets(s,49,fp))!=NULL)
        if(strstr(s,"bowl")!=NULL)
    {
        fputs(s,kl);
        puts(s);
        b=0;w=0;
        fprintf(kl," : ");
        printf(" : ");
        for(i=0;i<4;i++)
        {
            for(j=0;j<6;j++)
            {
                if(r<c)
            {
                if(m[r]==7)
                {
                    if(y==9)
                    {y++;
                    j--;
                    break;}
                    else{
                    printf("W,");
                    fprintf(kl,"W,");
                    w++;y++;}
                }
                else{
                printf("%d,",m[r]);
                fprintf(kl,"%d,",m[r]);
               b=b+m[r];}
            }
            r++;
            }
            fprintf(kl,"\t");
            printf("\t");
            if(r>=c)
                break;
        }
        q[qw++]=w;
        fprintf(kl," :  %d-%d\n\n",b,w);
        printf("  :  %d-%d\n\n",b,w);
        if(r>=c)
            break;
    }
    fclose(fp);
    r=q[0];
    for(j=1;j<qw;j++)
        if(q[j]>r)
            r=q[j];
    wbat=r;
    fclose(kl);
    }
    if(z==1)
    {
      kl=fopen("bat A.txt","w");
      fclose(kl);
      kl=fopen("bat A.txt","a");
      fp=fopen("team A.txt","r");
      printf("\n\n");
      fgets(s,49,fp);
      puts(s);
      fprintf(kl,"%s",s);
      while((fgets(s,49,fp))!=NULL)
      {
          fputs(s,kl);
          puts(s);
          points=points+10210;
          srand(time(&currenttime)+points);
          b=0;
          for(i=0;i<60;i++)
         {
          a=rand()%8;
          if(w==9 && a==7)
            c--;
          else
          m[c]=a;
          c++;
          if(c>120)
          break;
          if(a==7)
            {
                if(w==10)
                {w++;
                break;}
                    else
                {printf("out\t");
            fprintf(kl,"out\t");
            w++;
            break;}}
            b=b+a;
            total=total+a;
            fprintf(kl,"%d,",a);
          printf("%d,",a);
        }
          n[y++]=b;
          if(w==11)
          {fprintf(kl,"  :  %d(%d)\n\n",b,i);
          printf("  :  %d(%d)\n\n",b,i);}
          else{
          fprintf(kl,"  :  %d(%d)\n\n",b,i+1);
          printf("  :  %d(%d)\n\n",b,i+1);}
         if(c>=120)
             break;
         else
            continue;
      }
      fprintf(kl,"\n total : %d\n",total);
    printf("\ntotal : %d\n",total);
    fclose(fp);
    j=n[0];
    for(i=1;i<y;i++)
        if(j<n[i])
        j=n[i];
        sbat=j;
    fprintf(kl,"\n\nhighest score = %d\n",j);
    printf("\n\nhighest score = %d\n",j);
    fclose(kl);
    kl=fopen("bowl B.txt","w");
    fclose(kl);
    kl=fopen("bowl B.txt","a");
    fp=fopen("team B.txt","r");
    printf("\n\n");
    fgets(s,49,fp);
    fputs(s,kl);
    puts(s);
    y=0;
    while((fgets(s,49,fp))!=NULL)
        if(strstr(s,"bowl")!=NULL)
    {
        fputs(s,kl);
        puts(s);
        b=0;w=0;
        fprintf(kl," : ");
        printf(" : ");
        for(i=0;i<4;i++)
        {
            for(j=0;j<6;j++)
            {
                if(r<c)
            {
                if(m[r]==7)
                {
                    if(y==9)
                    {y++;
                    j--;
                    break;}
                    else{
                    printf("W,");
                    fprintf(kl,"W,");
                    w++;y++;}
                }
                else{
                printf("%d,",m[r]);
                fprintf(kl,"%d,",m[r]);
               b=b+m[r];}
            }
            r++;
            }
            fprintf(kl,"\t");
            printf("\t");
            if(r>=c)
                break;
        }
        fprintf(kl," :  %d-%d\n\n",b,w);
        printf("  :  %d-%d\n\n",b,w);
        if(r>=c)
            break;
    }
    fclose(fp);
    r=q[0];
    for(j=1;j<qw;j++)
        if(q[j]>r)
            r=q[j];
    wbat=r;
    fclose(kl);
    }
return total;
}
int bowl(int z,int run,int *sbowl,int *wbowl)
{
   time_t currenttime;
    char s[50];
    int b=0,a,c=0,i,m[120],total=0;
    FILE *fp,*kl;
    int j,r=0,w=0,points,n[11],y=0,q[10],qw=0;
    if(z==2)
    {
     kl=fopen("bat A.txt","w");
      fclose(kl);
      kl=fopen("bat A.txt","a");
      fp=fopen("team A.txt","r");
      printf("\n\n");
      fgets(s,49,fp);
      puts(s);
      fprintf(kl,"%s",s);
      while((fgets(s,49,fp))!=NULL)
      {
          fputs(s,kl);
          puts(s);
          points=points+10210;
          srand(time(&currenttime)+points);
          b=0;
          for(i=0;i<60;i++)
         {
          a=rand()%8;
          if(w==9 && a==7)
            c--;
          else
          m[c]=a;
          c++;
          if(c>120)
          break;
          if(a==7)
            {
                if(w==10)
                {w++;
                break;}
                    else
                {printf("out\t");
            fprintf(kl,"out\t");
            w++;
            break;}}
            b=b+a;
            total=total+a;
            fprintf(kl,"%d,",a);
          printf("%d,",a);
          if(total>run)
                break;
        }
          n[y++]=b;
          if(w==11)
          {fprintf(kl,"  :  %d(%d)\n\n",b,i);
          printf("  :  %d(%d)\n\n",b,i);}
          else{
          fprintf(kl,"  :  %d(%d)\n\n",b,i+1);
          printf("  :  %d(%d)\n\n",b,i+1);}
         if(c>=120 || total>run)
             break;
         else
            continue;
      }
      fprintf(kl,"\n total : %d\n",total);
    printf("\ntotal : %d\n",total);
    fclose(fp);
    j=n[0];
    for(i=1;i<y;i++)
        if(j<n[i])
        j=n[i];
        sbowl=j;
    fprintf(kl,"\n\nhighest score = %d\n",j);
    printf("\n\nhighest score = %d\n",j);
    fclose(kl);
    kl=fopen("bowl B.txt","w");
    fclose(kl);
    kl=fopen("bowl B.txt","a");
    fp=fopen("team B.txt","r");
    printf("\n\n");
    fgets(s,49,fp);
    fputs(s,kl);
    puts(s);
    y=0;
    while((fgets(s,49,fp))!=NULL)
        if(strstr(s,"bowl")!=NULL)
    {
        fputs(s,kl);
        puts(s);
        b=0;w=0;
        fprintf(kl," : ");
        printf(" : ");
        for(i=0;i<4;i++)
        {
            for(j=0;j<6;j++)
            {
                if(r<c)
            {
                if(m[r]==7)
                {
                    if(y==9)
                    {y++;
                    j--;
                    break;}
                    else{
                    printf("W,");
                    fprintf(kl,"W,");
                    w++;y++;}
                }
                else{
                printf("%d,",m[r]);
                fprintf(kl,"%d,",m[r]);
               b=b+m[r];}
            }
            r++;
            }
            fprintf(kl,"\t");
            printf("\t");
            if(r>=c)
                break;
        }
        fprintf(kl," :  %d-%d\n\n",b,w);
        printf("  :  %d-%d\n\n",b,w);
        if(r>=c)
            break;
    }
    fclose(fp);
    r=q[0];
    for(j=1;j<qw;j++)
        if(q[j]>r)
            r=q[j];
    wbowl=r;
    fclose(kl);
    }
    if(z==1)
    {
      kl=fopen("bat B.txt","w");
      fclose(kl);
      kl=fopen("bat B.txt","a");
      fp=fopen("team B.txt","r");
      printf("\n\n");
      fgets(s,49,fp);
      puts(s);
      fprintf(kl,"%s",s);
      while((fgets(s,49,fp))!=NULL)
      {
          fputs(s,kl);
          puts(s);
          points=points+10210;
          srand(time(&currenttime)+points);
          b=0;
          for(i=0;i<60;i++)
         {
          a=rand()%8;
          if(w==9 && a==7)
            c--;
          else
          m[c]=a;
          c++;
          if(c>120)
          break;
          if(a==7)
            {
                if(w==10)
                {w++;
                break;}
                    else
                {printf("out\t");
            fprintf(kl,"out\t");
            w++;
            break;}}
            b=b+a;
            total=total+a;
            fprintf(kl,"%d,",a);
          printf("%d,",a);
          if(total>run)
                break;
        }
          n[y++]=b;
          if(w==11)
          {fprintf(kl,"  :  %d(%d)\n\n",b,i);
          printf("  :  %d(%d)\n\n",b,i);}
          else{
          fprintf(kl,"  :  %d(%d)\n\n",b,i+1);
          printf("  :  %d(%d)\n\n",b,i+1);}
         if(c>=120 || total>run)
             break;
         else
            continue;
      }
      fprintf(kl,"\n total : %d\n",total);
    printf("\ntotal : %d\n",total);
    fclose(fp);
    j=n[0];
    for(i=1;i<y;i++)
        if(j<n[i])
        j=n[i];
        sbowl=j;
    fprintf(kl,"\n\nhighest score = %d\n",j);
    printf("\n\nhighest score = %d\n",j);
    fclose(kl);
    kl=fopen("bowl A.txt","w");
    fclose(kl);
    kl=fopen("bowl A.txt","a");
    fp=fopen("team A.txt","r");
    printf("\n\n");
    fgets(s,49,fp);
    fputs(s,kl);
    puts(s);
    y=0;
    while((fgets(s,49,fp))!=NULL)
        if(strstr(s,"bowl")!=NULL)
    {
        fputs(s,kl);
        puts(s);
        b=0;w=0;
        fprintf(kl," : ");
        printf(" : ");
        for(i=0;i<4;i++)
        {
            for(j=0;j<6;j++)
            {
                if(r<c)
            {
                if(m[r]==7)
                {
                    if(y==9)
                    {y++;
                    j--;
                    break;}
                    else{
                    printf("W,");
                    fprintf(kl,"W,");
                    w++;y++;}
                }
                else{
                printf("%d,",m[r]);
                fprintf(kl,"%d,",m[r]);
               b=b+m[r];}
            }
            r++;
            }
            fprintf(kl,"\t");
            printf("\t");
            if(r>=c)
                break;
        }
        fprintf(kl," :  %d-%d\n\n",b,w);
        printf("  :  %d-%d\n\n",b,w);
        if(r>=c)
            break;
    }
    fclose(fp);
    r=q[0];
    for(j=1;j<qw;j++)
        if(q[j]>r)
            r=q[j];
    wbowl=r;
    fclose(kl);
    }
    return total;
}
int scorebat()
{
    int i;
  char c;
    FILE *fp;
    fp=fopen("bat A.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
        putchar(c);
    fclose(fp);
    fp=fopen("bat B.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
        putchar(c);
    fclose(fp);
    printf("\n\n");
}
int scorebowl()
{
    char c;
    FILE *fp;
    fp=fopen("bowl A.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
        putchar(c);
    fclose(fp);
    fp=fopen("bowl B.txt","r");
    printf("\n\n");
    while((c=fgetc(fp))!=EOF)
        putchar(c);
    fclose(fp);
    printf("\n\n");
}
int details(int z,int run,int chase)
{
    int net;
  if(z==1)
  {
      net=run-chase;
      if(net>0)
        printf("\n\n\n******   team A has won the game by %d runs  *******\n\n",net);

        else if (net<0)
        printf("\n\n\n*******  team B has won the game by %d runs  ********\n\n",chase-run);

        else
            printf("\n\n\n*******  match draw  ********\n\n");
}
  else
  {
      net=run-chase;
      if(net>0)
        printf("\n\n\n******   team B has won the game by %d runs  ********\n\n",net);

        else if (net<0)
        printf("\n\n\n******    team A has won the game by %d runs  *********\n\n",chase-run);

        else
            printf("\n\n\n******     match draw  **********\n\n");
  }
}
