#include <stdio.h>
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
