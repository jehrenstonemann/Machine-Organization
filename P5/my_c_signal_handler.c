////////////////////////////////////////////////////////////////////////////////
// Main File:        my_c_signal_handler.c; send_signal.c; my_div0_handler.c
// This File:        my_c_signal_handler.c
// Other Files:      send_signal.c; my_div0_handler.c
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


#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int alarm_time = 5;   // global variable for the duration of alarm
int counter = 0;      // count to keep the number of time sigusr1 is triggered

/* Signal handler for sigalrm
 */
void handler_SIGALRM(){
	time_t now;
	// check time return value
	if(time(&now) == -1){
		printf("Time Error\n");
		exit(1);
	}
	char *s = asctime(localtime(&now));
	if(s == NULL){
		printf("Error Asctime\n");
		exit(1);
	}
	printf("PID: %d CURRENT TIME: %s", getpid(), s);
	alarm(alarm_time);
}

/* Signal handler for sigusr1
 */
void handler_SIGUSR1(){
	printf("SIGUSR1 handled and counted!\n");
	counter++;
}

/* Signal handler for sigint
 */
void handler_SIGINT(){
	printf("\nSIGINT handled.\n");
	printf("SIGUSR1 was handled %d times. Exiting now.\n", counter);
	exit(0);
}

/* Main function that creates an infinite loop
 *
 * argc number of input arguments
 * argv input argument array
 * retval return 0
 */
int main(int argc, char *argv[]){
	alarm(alarm_time);
	struct sigaction sa;
	// register sigalrm
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGALRM;
	if(sigaction(SIGALRM, &sa, NULL)!=0){
		printf("Error binding SIGALRM handler\n");
	}
	// register sigusr1
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = handler_SIGUSR1;
	if(sigaction(SIGUSR1, &sa, NULL)!=0){
		printf("Error binding SIGUSR1 handler\n");
	}
	// register sigint
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = handler_SIGINT;
	if(sigaction(SIGINT, &sa, NULL)!=0){
		printf("Error binding SIGINT handler\n");
	}
	printf("PID and time print every 5 seconds.\n");
	printf("Type Ctrl-C to end the program.\n");
	// infinite loop
	while (1) {
	}
	return 0;
}
