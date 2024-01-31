////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Drows.c
// This File:        cache2Drows.c
// Other Files:      
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

int arr2D[3000][500];
int main(){
	for (int row = 0; row < 3000; row++){
		for (int col = 0; col < 500; col++){
			arr2D[row][col] = row + col;
		}
	}
	return 0;
}
