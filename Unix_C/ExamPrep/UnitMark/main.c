

/*
 Program to calculate expected mark after the UCP Exam - 2015
 
 Written by Aidan Law
 Date: 17/11/2015
 
 Directions: Execute the following command in the Terminal if there is a Makefile
	make run
 
 To Do: Change option [3] to print out correct values when the following takes place
	Option [1] - completed
	Option [2] - completed
	Option [1] - repeated
	Option [3] - final mark printed is not changed from previous value
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE !FALSE

/*Called before entering exam marks*/
void printExamIntro()
{
	printf("\n\tUnix and C Programming: Final Exam - Semester 2, 2015\n");
	printf("\tThe format of the test is as follows:\n");
	printf("\t\tQuestion 1: Linked Lists    (19 marks)\n");
	printf("\t\tQuestion 2: Shell Scripts   (10 marks)\n");
	printf("\t\tQuestion 3: Pointer Diagram (20 marks)\n");
	printf("\t\tQuestion 4: Debugging       (21 marks)\n");
	printf("\t\tQuestion 5: File I/0        (30 marks)\n");
}

/*Prints the menu list*/
void printOptions()
{
	printf("\n\t--Enter an integer to select an option--\n");
	printf("\t\tOption [1]: Calculate Exam Mark\n");
	printf("\t\tOption [2]: Calculate Unit Mark\n");
	printf("\t\tOption [3]: Print Expected Final Result\n");
	printf("\t\tOption [4]: Exit the program\n");
	printf("\t\tEnter option: ");
}

/*Calculates and prints the final exam marks*/
float calculate(char name[21],float error, float question[2][5], int option)
{
	int max, i;
	float markMin, markMax, count;
	count = 0.0;
	max = 100;
	if(option == 1)
	{
		printf("\n\t=============================================================\n");
		printf("\t%s", name);
		printf("\t\tSection%%     SectionGained%%\tRunningTotal\n");
		printf("\t-------------------------------------------------------------\n");
		for(i = 0; i < 5; i++)
		{
			printf("\tQuestion %d\t%6.1f%%", (i+1), (question[0][i]/question[1][i])*100);
			count += (question[0][i]/max)*100;
			printf("\t\t%6.1f%%", question[0][i]);
			printf("\t\t%6.1f%%\n", count);
		}
		printf("\t=============================================================\n");
		printf("\n\t  Your expected percentage: %3.1f\n", count);
		markMin = count - (count * error);
		markMax = count + (count * error);
		printf("\tYour expected mark minimum: %3.1f\n", markMin);
		printf("\tYour expected mark maximum: %3.1f\n\n", markMax);
	}
	else if (option == 2)
	{
		for(i = 0; i < 5; i++)
		{
			count += (question[0][i]/max)*100;
		}
	}
	return count;
}

/*Reads in user terminal input for the final exam*/
float readInput(float question[2][5], int option)
{
	char name[21];
	int allGood, i;
	float error,mark;
	error = mark = 0.0;
	allGood = 0;
	printf("\n\tEnter Your First Name: ");
	scanf("%s", name);
	for(i = 0; i < 5; i++)
	{
		printf("\tEnter the expected mark for Question %d (out of %2.0f): ", (i+1), question[1][i]);
		scanf("%f", &question[0][i]);
		if((question[0][i] < 0) || (question[0][i] > question[1][i]))
		{
			printf("\n\t--QUESTION %d MARK NOT WITHIN EXPECTED RANGE--\n", (i+1));
			allGood = FALSE;
			i = 6;
		}
		else
		{
			allGood = TRUE;
		}
	}
	if(allGood == TRUE)
	{
		printf("\tEnter the expected error out of 100%%   (10%% = 10) : ");
		scanf("%f", &error);
		error /= 100;
		if((error >= 0) && (error <=1))
		{
			mark = calculate(name,error,question,option);
		}
	}
	return mark;
}

/*Reads in user terminal input for assessments that are NOT the final exam*/
void readOther(float other[2][4])
{
	printf("\n\tEnter your mark for Test 1 (out of 80): ");
	scanf("%f", &other[0][0]);
	printf("\tEnter your mark for Test 2 (out of 100): ");
	scanf("%f", &other[0][1]);
	printf("\tEnter your mark for the Assignment (out of 100): ");
	scanf("%f", &other[0][2]);
}

/*Calculates the FINAL mark for the unit*/
float processOther(float other[2][4])
{
	float totalMark;
	totalMark = 0.0;
	for(i = 0; i < 4; i++)
	{
		if((i == 0) || (i == 1))
			totalMark += 0.15 * (other[0][i]/other[1][i]);
		else if(i == 2)
			totalMark += 0.20 * (other[0][i]/other[1][i]);
		else if(i == 3)
			totalMark += 0.50 * (other[0][i]/other[1][i]);
	}
	totalMark *= 100;
	
	printf("\n\tYour FINAL mark is expected to be around: %3.0f%%\n", totalMark);
	if(totalMark >= 50.0)
	{
		printf("\t--YOU ARE LIKELY TO PASS THE UNIT (ACCORDING TO YOURSELF)--\n");
	}
	return totalMark;
}

/*Main function that takes in user terminal input to select options which call different functions*/
int main(void)
{
	float question[2][5] = {{0.0 ,0.0 ,0.0 ,0.0 ,0.0 },
							{19.0,10.0,20.0,21.0,30.0}};
	float other[2][4] =	   {{0.0 , 0.0, 0.0, 0.0 },
							{80.0,100.0,100.0,100.0}};
	int option;
	float totalMark;
	option = 0;
	totalMark = 0.0;
	
	do
	{
		printOptions();
		scanf("%d", &option);
		if(option == 2)
		{
			if((other[0][3] > 0.0) && (other[0][3] <= 100.0))
			{
				readOther(other);
				totalMark= processOther(other);
			}
			else
			{
				printExamIntro();
				other[0][3] = readInput(question, option);
				readOther(other);
				totalMark = processOther(other);
			}
			option = TRUE;
		}
		else if(option == 1)
		{
			printExamIntro();
			other[0][3] = readInput(question, option);
			option = TRUE;
		}
		else if(option == 4)
		{
			printf("\n\t--SHUTTING PROGRAM DOWN--\n\n");
			option = FALSE;
		}
		else if(option == 3)
		{
			if((other[0][3] > 0.0) && (other[0][3] <= 100.0))
			{
				printf("\n\tExpected Exam Mark: %3.0f%%\n", other[0][3]);
				if((totalMark > 0.0) && (totalMark <= 100.0))
				{
					printf("\tExpected Final Mark: %3.0f%%\n", totalMark);
				}
			}
			else
			{
				printf("\n\t--OPTION [1] OR OPTION [2] MUST BE ENTERED AT LEAST ONCE--\n");
			}
			option = TRUE;
		}
		else
		{
			printf("\n\t--INCORRECT OPTION CHOICE--\n");
			printf("\t--SHUTTING PROGRAM DOWN--\n\n");
			option = FALSE;
		}
	} while(option == TRUE);
}

