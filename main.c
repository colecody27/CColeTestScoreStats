/*
 ============================================================================
 Name        : CColeTestScoreStats.c
 Author      : Cody Cole
 Version     :
 Copyright   : 26 August 20
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	puts(
			"Enter scores without spaces, when finished press enter on a BLANK line");
	char input[6]; //Used for initial input from user
	float grade; //Variable for each grade
	float max_score;
	float min_score;
	float sum_squares = 0;
	float sum = 0;
	float avg = 0;
	int gradeCount = 0; //Count for grade array
	int flag = 0; //Flag used for newline character
	do {
		fgets(input, 6, stdin);
		if (input[0] == '\n') { //Check to see if input is newline
			flag++;
			continue;
		}
		//Convert grade to float
		grade = strtof(input, NULL);
		if (grade < 0.0) { //Check grade conditions
			puts("Grade must be greater than 0.0");
			continue;
		}
		if(!gradeCount) { //true or false? Should be false
			//assign min and max value
			min_score = grade;
			max_score = grade;
		}
		else if(min_score > grade) {
			min_score = grade;
		} else if(max_score < grade) {
			max_score = grade;
		}
		sum_squares += pow(grade, 2);
		sum += grade;
		gradeCount++;
	}while (flag != 1);

	//If user did not enter any values
	if (gradeCount == 0) {
		printf("0 \t 0.0 \t 0.0 \t 0.0 \t 0.0 \n");
	} else {
		//Standard deviation*
		float standard_deviation = sqrt(
				(sum_squares - (pow(sum, 2) / gradeCount)) / gradeCount);
		avg = sum/gradeCount;
	printf("%d%s %f%s %f%s %f%s %f%s", gradeCount,"\t", min_score,"\t", max_score,"\t",
			avg,"\t", standard_deviation, "\n");

	}
	return EXIT_SUCCESS;
}
