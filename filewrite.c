#include<stdio.h>
void main()
{
    FILE *fp;
    char ch[20],c;
    fp=fopen("write.txt","w");
    scanf("%s",&ch);
    fprintf(fp,"%s",ch);
    fclose(fp);

    fp=fopen("write.txt","r");
    while(ch!=EOF)
    {
        c=getc(fp);
        printf("%c",c);
    }
fclose(fp);
}
