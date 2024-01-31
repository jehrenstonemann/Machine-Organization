////////////////////////////////////////////////////////////////////////////////
// Main File:        my_c_signal_handler.c; send_signal.c; my_div0_handler.c
// This File:        my_div0_handler.c
// Other Files:      send_signal.c; my_c_signal_handler.c
// Semester:         CS 354 Lecture 002 Fall 2023
// Grade Group:      gg08  (See canvas.wisc.edu/groups for your gg#)
// Instructor:       deppeler
// 
// Author:           Xiangyu Huang
// Email:            xhuang438@wisc.edu
// CS Login:         xiangyuh
//
///////////////////////////  WORK LOG  //////////////////////////////
//  Document your work sessions on your copy http://tiny.cc/work-log
//  Download and submit a pdf of your work log for each project.
/////////////////////////// OTHER SOURCES OF HELP ////////////////////////////// 
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
// 
// AI chats:         save a transcript and submit with project.
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int count = 0;  // global value to keep the count of div by 0

/* signal handler for sigfpe
 */
void handler_SIGFPE(){
	printf("Error: a division by 0 operation was attempted.\n");
	printf("Total number of operations completed successfully: %d\n", count);
	printf("The program will be terminated.\n");
	exit(0);
}

/* signal handler for sigint
 */
void handler_SIGINT(){
	printf("\nTotal number of operations completed successfully: %d\n", count);
	printf("The program will be terminated.\n");
	exit(0);
}

/* Main function that creates infinite loop for user input of a division
 *
 * argc number of input arguments
 * argv input argument array
 * retval return 0
 */
int main(int argc, char *argv[]) {
	char buffer[100];
	struct sigaction sa;
	// register sigfpe
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGFPE;
	if(sigaction(SIGFPE, &sa, NULL)!=0){
		printf("Error binding SIGFPE handler\n");
	}
	// register sigint
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = handler_SIGINT;
	if(sigaction(SIGINT, &sa, NULL)!=0){
		printf("Error binding SIGINT handler\n");
	}
	// infinite loop for user input of a division
	while(1){
		int int1, int2, quotient, remainder;
		printf("Enter first integer: ");
		// check fgets
        if (fgets(buffer, 100, stdin) == NULL){
			printf("fgets Error\n");
			exit(1);
		}
        int1 = atoi(buffer);
		printf("Enter second integer: ");
		// check fgets
        if (fgets(buffer, 100, stdin) == NULL){
			printf("fgets Error\n");
			exit(1);
		}
        int2 = atoi(buffer);
		quotient = int1 / int2;
        remainder = int1 % int2;
		printf("%d / %d is %d with a remainder of %d\n", int1, int2, quotient, remainder);
		count++;
	}
	return 0;
}
