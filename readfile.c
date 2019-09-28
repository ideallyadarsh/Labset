#include<stdio.h>
void main()
{
    FILE *fp; char ch;
    fp=fopen("ad.txt","r");
    while(ch!=EOF){
        ch=getc(fp);
        printf("%c",ch);
    }
fclose(fp);
}
