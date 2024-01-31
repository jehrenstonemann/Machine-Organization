////////////////////////////////////////////////////////////////////////////////
// Main File:        my_c_signal_handler.c; send_signal.c; my_div0_handler.c
// This File:        send_signal.c
// Other Files:      my_c_signal_handler.c; my_div0_handler.c
// Semester:         CS 354 Lecture 00? Fall 2023
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

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function to send signals
 *
 * argc number of input arguments
 * argv input argument array
 * retval return 0
 */
int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: send_signal <signal type> <pid>\n");
        exit(1);
    }

    int pid = atoi(argv[2]);
    int signalType;

    if (strcmp(argv[1], "-i") == 0) {
        signalType = SIGINT;
    }
	if (strcmp(argv[1], "-u") == 0) {
        signalType = SIGUSR1;
    }

    if (kill(pid, signalType) == -1) {
        printf("Kill Failed\n");
		exit(1);
    }

    return 0;
}
