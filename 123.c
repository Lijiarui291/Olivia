/*#include <stdio.h>
int main(void)
{
	int dogs;
	
	printf("How many dogs do you have?\n");
	scanf("%d", &dogs);
	printf("So you have %d dog(s)!\n", dogs);
	
	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	int num;
	num = 1;
	
	printf("I am a simple");
	printf("computer.\n");
	printf("My favorite number is %d because it is first.\n", num);
	
	return 0;
 }*/
 
 /*#include <stdio.h>
 int main()
 {
 	int h, j;
 	int num;
 	scanf("%d", &num);
	printf("\n", num);
 	
 	for (h = 1; h <= num ; h++){
 		for (j = 0; j < h; j++)
          printf("* ");
		  printf("\n");
		  	 }
		  	 return 0;
 }*/
 
/* #include <stdio.h>
  int main(){    
  int n,h=0;//符号数空格数    
  int i=0;    
  scanf("%d",&n);    
  n=n*2-1;         
  while(n>0)    
  {              
  for(i=0; i<h; i++)//输空格                                
  printf(" ");              
  for(i=0; i<n; i++)                    
  printf("*");//输符号               
  printf("\n");              
  n=n-2;              
  h++;    }          
  return 0;
  }*/
  
   /*#include<stdio.h>
   #include<math.h>
   int main()
   {int i,j,h;
   scanf("%d",&h);
   for(i=1;i<=h;i++)
   {
   for(j=1;j<i;j++)
   printf(" ");
   if(i==1||i==h)
   {for(j=1;j<=2*(h-i)+1;j++)
   printf("*");
   printf("\n");}
   else
   {printf("*");
   for(j=1;j<=2*(h-i)-1;j++)
   printf(" ");
   printf("*\n");}
   }
   return 0;
   }*/
   
    #include<stdio.h>
/*int num(int a);
int main()
{
    int a;//输入值
    int i;//局部变量
    int s;//全局递减变量
    int n;//全局递加变量
    scanf("%d",&a);
    s=a;
    n=1;
    if(s>=1)
    {for(i=1;i<=num(a);i++)
    {printf("*");}
    printf("\n");
    s--;n++;
    while(s>0)
      {for(i=1;i<=num(a)-n+1;i++)
          {if(i==n||i==(2*a-n))
           printf("*");
           else printf(" ");}
        printf("\n");
        s--;n++;
       }   
    }
    
    return 0;
}

int num(int a)
{a=2*a-1;
return a;
}*/

 /*#include <stdio.h>
 int main()
 {
 	int height = 3, length = 2;
 	printf("Height: %d Length: %d\n", height, length);
 	return 0;
  } */
  
 /*#include <stdio.h>
  int main()
  {
    int x;
	int n;
	
	scanf("%d", &x);//发现引号里面%d前面加标点符号不影响 输出（但好像不建议这么乱加）
	//这里注意，scanf要在n的计算式之前完成，否则无法输出计算出的n的值 
	n = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
	printf("n : %d", n);//这里注意，引号后要把n写出来，否则得不到正确的输出值 
	getchar();//表示在程序完成后，要随意敲一个键才能结束程序 
	return 0;

}*/ 

/*#include <stdio.h>
int main()
{
	int i;
	int j;
	float x;
	float y;
	
	i = 10; 
	x = 43.2892f;
	
	printf(" %d %f\n", i, x);//在这里如果转换声明出错，将会输出两个无意义的值 
	return 0;
}*/

/*#include<stdio.h>
int main(void)
{
	int i;
	float x;
	
	i = 40;
	x = 839.21f;
	
	printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
	
	return 0;
	
}*/

//2020.11.03
/*#include<stdio.h>
int main()
{
	int i = 1, j = 2, max;
	
	if (i > j)
	  max = i;
	else 
	  max = j;
	printf("%d\n", max);
	
	return 0; 
	}*/
	
/*#include<stdio.h>
int main()
{
	int i = 1, j = 2, k = 3;
	int max;
	
	if (i > j)
	  if (i > k)
	    max = i;
	  else
	    max = k;
	else
	  if(j > k)
	    max = j;
	  else
	    max = k;
	printf("%d\n", max);//不要忘记输出这一行，并且后面注意要加分号 
	return 0;
	  
}*/

/*#include<stdio.h>
int main()
{
	int n = 1;
	if (n < 0)
	  printf("n is less than 0\n", n);
	else if (n == 0)
	  printf("n is equal to 0\n", n);
	else //这里只用else,下一行直接输出即可 
	  printf("n is greater than 0\n", n);
	
	return 0;
	  
} */

/*
这个程序略有问题，还没发现 
#include<stdio.h>
int main()
{
	int x = 1, y = 1;
	int result;
	int Error;	
	
  if (y != 0){
  	if (x != 0)
  	  result = x / y;}
  else 
      printf("Error: y is equal to 0\n");
      
  return 0;
  }*/   
  
/*
第二次
#include<stdio.h>
int main()
{
	int i = 1, j = 2, k = 3;
	if (i > j)
	  if (i > k)
	   printf("%d", i);
	  else
	   printf("%d", k);
	else
	  if (j > k)
	    printf("%d", j);
	  else
	    printf("%d", k);
	return 0;
}*/

/*???
#include<stdio.h>
int main()
{   int grade;
	switch (grade) {
		case 4:
		case 3:
		case 2: 
		case 1:
		case 0: printf("");
		default: printf("");
		        break;
	}
 } */
 
#include <stdio.h>
int main(void)
{
  int  time, month, day, year;

  printf("Enter date (tt/mm/dd/yy): ");
  scanf("%d /%d /%d /%d", &time, &month, &day, &year);

  printf("Dated this %d", time);
  switch(time){
  	case 1:  printf("星期一");
    break;
    case 2:  printf("星期二");  
	break;
    case 3:  printf("星期三");     
	break;
    case 4:  printf("星期四");     
	break;
    case 5:  printf("星期五");       
	break;
    case 6:  printf("星期六");      
	break;
    case 7:  printf("星期日");      
	break;
  }
  printf(" day of ");
  switch (day) {
    case 1: case 21: case 31:
      printf("st"); break;
    case 2: case 22:
      printf("nd"); break;
    case 3: case 23:
      printf("rd"); break;
    default: printf("th"); break;
  }
  printf(" of ");
  switch (month) {
    case 1:  printf("January");
    break;
    case 2:  printf("February");  
	break;
    case 3:  printf("March");     
	break;
    case 4:  printf("April");     
	break;
    case 5:  printf("May");       
	break;
    case 6:  printf("June");      
	break;
    case 7:  printf("July");      
	break;
    case 8:  printf("August");    
	break;
    case 9:  printf("September"); 
	break;
    case 10: printf("October");   
	break;
    case 11: printf("November");  
	break;
    case 12: printf("December");  
	break;
  }

  printf(", 20%.2d.\n", year);
  getchar();
  return 0;
}


  
 
	
	

 
   



  
 




