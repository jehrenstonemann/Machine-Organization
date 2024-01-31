///////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
// Used by permission, CS 354 Spring 2022, Deb Deppeler
////////////////////////////////////////////////////////////////////////////////
   
////////////////////////////////////////////////////////////////////////////////
// Main File:        my_magic_square.c
// This File:        my_magic_square.c
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Lecture 002 Fall 2023
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

// Structure that represents a magic square
typedef struct {
    int size;           // dimension of the square
    int **magic_square; // pointer to heap allocated magic square
} MagicSquare;

/* 
 * Promps the user for the magic square's size, read it,
 * check if it's an odd number >= 3 (if not, display the required
 * error message and exit)
 *
 * return the valid number
 */
int getSize() {
    int size;
    printf("Enter the size of the magic square (odd number >= 3)\n");
    scanf("%d", &size);
	
	// check size
	if(size % 2 == 0){
		printf("Magic square size must be odd.\n");
		exit(1);
	}
	if(size < 3){
		printf("Magic square size must be >= 3.\n");
		exit(1);
	}

    return size;   

} 
   
/* 
 * Makes a magic square of size n,
 * and stores it in a MagicSquare (on the heap)
.*
 * It may use the Siamese magic square algorithm 
 * or alternate from assignment 
 * or another valid algorithm that produces a magic square.
 *
 * n - the number of rows and columns
 *
 * returns a pointer to the completed MagicSquare struct.
 */
MagicSquare *generateMagicSquare(int n) {
    MagicSquare *ms = malloc(sizeof(MagicSquare));
	if (ms == NULL) {
		printf("Malloc Failed\n");
		exit(1);
	}
    ms->size = n;
    ms->magic_square = malloc(n * sizeof(int *));
	if (ms -> magic_square == NULL){
		printf("Malloc Failed\n");
        exit(1);
	}
    for (int i = 0; i < n; i++) {
        *(ms->magic_square + i) = malloc(n * sizeof(int));
        if (*(ms -> magic_square + i) == NULL){
		printf("Malloc Failed\n");
		exit(1);
		}
		for (int j = 0; j < n; j++) {
			*(*(ms->magic_square + i)+j) = 0;
		}
    }

	// Siamese Method to generate magic square
    int i = 0;
    int j = n / 2;
    for (int num = 1; num <= n*n; num++) {
        *(*(ms->magic_square + i) + j) = num;
        
        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;
        if (*(*(ms->magic_square + next_i) + next_j) != 0) {
            i = (i + 1) % n;
        } else {
            i = next_i;
            j = next_j;
        }
    }
    return ms;    

} 

/*   
 * Opens a new file (or overwrites the existing file)
 * and writes the magic square values to the file
 * in the specified format.
 *
 * magic_square - the magic square to write to a file
 * filename - the name of the output file
 */
void fileOutputMagicSquare(MagicSquare *magic_square, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp==NULL) {
        fprintf(stderr, "Can't open output file: %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%d\n", magic_square->size);

    for (int i = 0; i < magic_square->size; i++) {
        for (int j = 0; j < magic_square->size; j++) {
            fprintf(fp, "%d", *(*(magic_square->magic_square + i) + j));
            if (j < magic_square->size - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "\n");
    }

    // fclose(fp);
	if (fclose(fp) != 0){
		printf("Unable to Close File\n");
		exit(1);
	}	
}


/* 
 * Generates a magic square of the user specified size and
 * outputs the square to the output filename.
 * 
 * argc - number of arguments provided
 * argv - array of arguments
 */
int main(int argc, char **argv) {
    // Check input arguments to get output filename
	if(argc!=2){
		printf("Usage: ./my_magic_square <output_filename>\n");
		exit(1);
	}
    // Get magic square's size from user
	int size = getSize();
    // Generate the magic square by correctly interpreting 
    //       the algorithm(s) in the write-up or by writing or your own.
	MagicSquare *ms = generateMagicSquare(size);
    //       You must confirm that your program produces a 
    //       Magic Sqare as described in the linked Wikipedia page.

    // Output the magic square
    fileOutputMagicSquare(ms, *(argv + 1));
    for (int i = 0; i < size; i++) {
        free(*(ms->magic_square + i));
    }
    free(ms->magic_square);
    free(ms);
    return 0;
} 

//    F23


