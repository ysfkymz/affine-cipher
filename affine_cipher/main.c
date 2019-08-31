#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int asalmi(int k1)
{
 int x;
   int temp1=k1;
   int temp2=26;

     while(temp2!=0)
      {
        x=temp2;
        temp2=temp1%temp2;
        temp1=x;
      }
     return(temp1);
}

main()
{
 int i,j,k,ort,k1,k2,numstr[100],numcipher[100];
 char str[100],cipher[100];
 printf("Kelimeyi giriniz \n");
 gets(str);
 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 printf("Girilen kelime: %s \n",str);
 printf("k1 anahtar degerini giriniz (1 ile 25 arasinda olmali)\n");
 scanf("%d",&k1);
 //Checking consitions
 if(k1<1 || k1>25)
 {
  printf("k1 1 ile 25 arasinda olmali\n Tekrar deneyiniz!\n");
  exit(0);
 }
 ort=asalmi(k1);
 if(ort!=1)
 {
  printf("26 ile aralarinda asal olan bir deger giriniz!\n");
  exit(0);
 }
 printf("k2 anahtar degerini giriniz (0 ile 25 arasinda olmali)\n");
 scanf("%d",&k2);
 if(k2<0 || k2>25)
 {
  printf("k2 0 ile 25 arasinda olmali\n Tekrar deneyiniz!\n");
  exit(0);
 }
 //Conditions Over
 //Program Starts
 //Storing string in terms of ascii and to restore spaces I used -20
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
 //Ciphering Process
    //If numcipher is more than 25 .We need to convert and ensure that lie in between 0 and 25.(indicating Alphabets)
    //A-0,B-1,C-2,.....Y-24,Z-25
    printf("Sifrelenmis veri\n");
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=((k1*numstr[i])+k2)%26;
          printf("%c",(numcipher[i]+'A'));
     }
     else
     {
          printf(" ");
     }
    }
printf("\n");

}

