#include<stdio.h>

struct complex
{
    int real;
    int img;
}s[5];
int main(){
   int i,n,dreal=0,dcomp=0,sreal=0,scomp=0,preal=1,pcomp=1;
   for(i=0;i<2;i++)
      {
       printf("Enter real,imaginary part for %d\n",i+1 );
           scanf("%d %d",&s[i].real,&s[i].img);
           printf("Complex %d :%d+i(%d)\n",i+1,s[i].real,s[i].img);
      sreal+=s[i].real;
      scomp+=s[i].img;
      preal*=s[i].real;
      pcomp*=s[i].img;
       }
       dreal=s[0].real-s[1].real;
       dcomp=s[0].img-s[1].img;
       printf("\n\nSum of complex numbers:%d+i(%d)\n",sreal,scomp);
       printf("Difference of complex numbers:%d+i(%d)\n",dreal,dcomp);
      printf("Product of complex numbers:%d+i(%d)\n",preal,pcomp);
      printf("\nComparison of Complex Numbers\n");
      {
          if((s[0].real==s[1].real)&&(s[0].img==s[1].img)){
          printf("Both the complex numbers are equal\n");}
          else
            printf("\nComplex numbers are unequal\n");
      }
      printf("\nAssigning one complex variable to other\n");
      s[0].real=s[1].real;
      s[0].img=s[1].img;
      printf("%d+i(%d)\n",s[0].real,s[0].img);
}
