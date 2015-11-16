			/*=============================================================*/
			/*=============================================================*/
			/*====================ComSSA Help==============================*/
			/*=============================================================*/
			/*=====================QUESTION 4==============================*/
			/*=============================================================*/
			/*=============================================================*/
									/*A*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 int main(int argc, char* argv[])
 {
	int i;
	for (i = 0; i < (argc-1); i++)
	{
 printf("\t%s\n", argv[argc-1-i]);
	}
 }
 */
			/*=================================================*/
			/*=================================================*/
									/*B*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int minMaxFunc(int min, int max)
 {
	int num;
	num = 0;
	num = rand()%(max-min-1)+min+1;
	return num;
 }
 void numPrint(int count, int max)
 {
	int i;
	for (i=0;i<count;i++)
	{
 printf("\t%d\n", rand()%(max));
	}
 }
 int main(int argc, char* argv[])
 {
	int x, y, count;
	count=x=y=0;
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	srand(time(NULL));
	printf("\tRandNum between %d and %d: %d", x,y,minMaxFunc(x,y));
 
	count = rand()%(x);
	numPrint(count, y);
 }
 */
			/*=================================================*/
			/*=================================================*/
									/*C*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int myRand(int max, int min)
 {
	int num;
	num = 0;
	num = rand()%(max-min-1)+min+1;
	return num;
 }
 int main(int argc, char* argv[])
 {
	int in1, in2, num;
	in1=in2=num=0;
	srand(time(NULL));
	in1 = atoi(argv[1]);
	in2 = atoi(argv[2]);
	if(in1>in2)
	{
 num = myRand(in1,in2);
 printf("\t%d\n", num);
	}
	else if(in1<in2)
	{
 num = myRand(in2,in1);
 printf("\t%d\n", num);
	}
	else
	{
 printf("\tNumbers are the equivalent\n");
	}
 }
 */

