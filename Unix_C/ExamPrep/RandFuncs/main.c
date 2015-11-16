
						/*RAND QUESTIONS*/
/*================================================================*/
/*  Uncomment a section of code and execute the following commmand	
|
|		make run
|
| NOTE:	This will only function when arguments are not required.
|		If arguments are required during execution execute:
|
|		make <enter>
|		./prog <arg> <arg> ...
|
| NOTE:	Some questions only require the function itself so the
|		main function is not required in the exam. For the purpose
|		of testing, the main function is included in the examples.
/*================================================================*/
						/* 2010 QUESTION 2*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char* argv[])
 {
	int check;
	srand(time(NULL));
	check = rand()%(argc - 1);
	check++;
	printf("\t%s\n", argv[check]);
 }
 */
		/*=================================================*/
		/*=================================================*/
						/* 2010 QUESTION 2*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char* argv[])
 {
	int min;
	int max;
	int num;
 
	min = 0;
	max = 0;
	num = 0;
 
	srand(time(NULL));
 
	min = atoi(argv[1]);
	max = atoi(argv[2]);
 
	num = rand()%(max + 1 - min);
	printf("\t%d\n", num+min);
 
 }
 */
		/*=================================================*/
		/*=================================================*/
							/*2012*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 
 void loadedDice(int* dice1, int* dice2)
 {
	static int check;
 
	if(check == 0)
	{
		 *dice1 = rand()%6;
		 *dice1 += 1;
		 *dice2 = rand()%6;
		 *dice2 += 1;
		 check = 1;
	}
 
	else
	{
		 *dice1 = 6;
		 *dice2 = 6;
		 check = 0;
	}
 }
 
 int main(int argc, char* argv[])
 {
	int i;
	int rolls;
	int dice1;
	int dice2;
 
	i =0;
	rolls = 0;
	dice1 = 0;
	dice2 = 0;
 
	rolls = atoi(argv[1]);
	srand(time(NULL));
 
	for (i = 0; i < rolls; i++)
	{
		 loadedDice(&dice1, &dice2);
		 printf("\t Dice 1: %d\n", dice1);
		 printf("\t Dice 2: %d\n", dice2);
	}
 }
 */
		/*=================================================*/
		/*=================================================*/
							/*2012*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 
 void myRand(int max, int* retval)
 {
	static int min;
	*retval = rand()%(max-min-1);
	*retval += 1 + min;
	min = max;
 }
 
 int main()
 {
	int num;
	int retval;
 
	num = 0;
	retval = 0;
 
	srand(time(NULL));
 
	myRand(num, &retval);
	num += 10;
	myRand(num, &retval);
	printf("\t%d\n", retval);
	num += 10;
	myRand(num, &retval);
	printf("\t%d\n", retval);
	num += 10;
	myRand(num, &retval);
	printf("\t%d\n", retval);
	num += 10;
	myRand(num, &retval);
	printf("\t%d\n", retval);
 }
 */
		/*=============================================================*/
		/*=============================================================*/
		/*====================ComSSA Help==============================*/
		/*=============================================================*/
		/*=====================QUESTION 3==============================*/
		/*=============================================================*/
		/*=============================================================*/
								/*A*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>
 
 double twoRand(double num)
 {
	num = rand()%(31);
	num = pow(2, num);
	return num;
 }
 
 int main()
 {
	double num;
	num = 0;
	srand(time(NULL));
	num = twoRand(num);
	printf("\t%.0lf\n", num);
 }
 */
		/*=================================================*/
		/*=================================================*/
								/*B*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>
 
 double threeRand(double num)
 {
	num = rand()%(19-6+1)+6;
	printf("\t%lf\n", num);
	num = pow(3.0, num);
	return num;
 }
 int main()
 {
	double num;
	num = 0.0;
	srand(time(NULL));
	num = threeRand(num);
	printf("\t%.0lf\n", num);
 }
 */
		/*=================================================*/
		/*=================================================*/
								/*C*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 void twoDice(int* dicea, int* diceb)
 {
	static int count;
	if(count < 12)
	{
		 *dicea = rand()%(6)+1;
		 *diceb = rand()%(6)+1;
		 count++;
	}
	else
	{
		 *dicea = 8;
		 *diceb = 8;
		 count = 0;
	}
 }
 
 int main()
 {
	int dicea, diceb, i;
	dicea = diceb = i = 0;
	srand(time(NULL));
	
	for (i = 0; i < 28; i++)
	{
		 twoDice(&dicea, &diceb);
		 printf("\tdice%dA:  \t%d\tdice%dB:  \t%d\n", i+1, dicea, i+1, diceb);
	}
 }
 */
		/*=================================================*/
		/*=================================================*/
								/*D*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 int between(int max, int min)
 {
	int retval;
	retval = 0;
	retval = rand()%(max-min-1)+min;
	return retval;
 }
 int main()
 {
	int retval, max, min;
	max = 100;
	min = 0;
	retval = 0;
	srand(time(NULL));
	retval = between(max, min);
	printf("\t%d\n", retval);
 }
 */
		/*=================================================*/
		/*=================================================*/
								/*E*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define length 6
 void sumArray(int *array, int count, int* sum)
 {
	int i;
	for(i=0;i<count;i++)
	{
		*sum = *sum + array[rand()%(length)];
	}
 }
 int main()
 {
	int count, sum, i;
	int array[length];
	sum = 0;
	count = 3;
	for (i = 0; i < length; i++)
	{
		array[i] = i;
	}
	srand(time(NULL));
	sumArray(array, count, &sum);
	printf("\tTOTAL: %d\n", sum);
 }
 */
		/*=================================================*/
		/*=================================================*/
								/*F*/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 void myrand(int max, int* address)
 {
	static int min;
	*address = rand()%(max-min-1)+min+1;
	min = max;
 }
 int main()
 {
	int max, i, j;
	i=j=0;
	max=10;
	srand(time(NULL));
	myrand(max, &i);
	max += 10;
	myrand(max, &j);
	printf("\ti: %d\t\tj: %d\n", i, j);
 }
 */
