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
	puts("Enter scores without spaces, when finished press enter on a BLANK line");
	double grades[20]; //Might need to add size of array
	char input[6]; //Used for initial input from user
	int gradeCount = 0; //Count for grade array
	float grade; //Variable for each grade
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
		grades[gradeCount] = grade;
		gradeCount++;
	} while (flag != 1);

	//If user did not enter any values
	if (gradeCount == 0) {
		printf("0 \t 0.0 \t 0.0 \t 0.0 \t 0.0 \n");
	} else {
		//Count of scores
		printf("%d %s", gradeCount, "\t");
		//Min score
		float min_score = grades[0];
		for (int i = 1; i < gradeCount; i++) {
			if (min_score > grades[i]) {
				min_score = grades[i];
			}
		}
		printf("%f %s", min_score, "\t");
		//Max score
		float max_score = grades[0];
		for (int i = 1; i <= gradeCount; i++) {
			if (max_score < grades[i]) {
				max_score = grades[i];
			}
		}
		printf("%f %s", max_score, "\t");
		//Avg score
		float sum = grades[0];
		float avg;
		float sum_squares = pow(grades[0], 2);

		for (int i = 1; i <= gradeCount; i++) {
			sum += grades[i];
			sum_squares += pow(grades[i], 2);
		}
		avg = sum/gradeCount;
		printf("%f %s", avg, "\t");
		//Standard deviation*
		float standard_deviation = sqrt(
				(sum_squares - (pow(sum, 2) / gradeCount)) / gradeCount);
		printf("%f %s", standard_deviation, "\n");
	}
	return EXIT_SUCCESS;
}
