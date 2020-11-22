#include <iostream>
#define N 9
using namespace std;

int a[N][N] = {
   {0, 4, 0, 7, 0, 0, 1, 3, 0},
   {0, 0, 2, 0, 0, 0, 6, 0, 0},
   {0, 0, 0, 4, 2, 0, 0, 0, 0},
   {6, 0, 0, 0, 0, 2, 0, 0, 3},
   {2, 3, 1, 0, 7, 0, 0, 8, 0},
   {4, 0, 0, 3, 1, 0, 0, 0, 0},
   {0, 7, 0, 0, 0, 8, 0, 0, 0},
   {0, 0, 6, 0, 3, 0, 0, 0, 4},
   {8, 9, 0, 0, 5, 0, 0, 0, 6}
};


// function checks whether the same colored vertice is in the same column
bool isPresentInCol(int col, int num){ 
   for (int row = 0; row < N; row++)
      if (a[row][col] == num)
         return true;
   return false;
}


// function checks whether the same colored vertice is in the same row
bool isPresentInRow(int row, int num){
   for (int col = 0; col < N; col++)
      if (a[row][col] == num)
         return true;
   return false;
}


// function checks whether the same colored vertice is in the same box
bool isPresentInBox(int srow, int scol, int num){
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (a[row+srow][col+scol] == num)
            return true;
   return false;
}


// Function to print the sudoku
void printSudoku(){ 
   	for(int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 3; col < 6; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 6; col < 9; col++) cout<<" "<<a[row][col];
		cout<<endl;
    }
    cout<<" --------------------- "<<endl;
    for(int row = 3; row < 6; row++){
		for (int col = 0; col < 3; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 3; col < 6; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 6; col < 9; col++) cout<<" "<<a[row][col];
		cout<<endl;
    }
    cout<<" --------------------- "<<endl;
    for(int row = 6; row < 9; row++){
		for (int col = 0; col < 3; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 3; col < 6; col++) cout<<" "<<a[row][col];
		cout<<" "<<"|";
	    for (int col = 6; col < 9; col++) cout<<" "<<a[row][col];
		cout<<endl;
    }
}


// this function gets a vertice that has been not colored
bool getEmptyPlace(int &row, int &col){ 
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (a[row][col] == 0) 
            return true;
   return false;
}


// function to check whether a color can be assigned to a vertice
bool isSafe(int row, int col, int num){
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}


// fuction for solving
bool solveSudoku(){
   int row, col;
   if (!getEmptyPlace(row, col))
      return true; 
   for (int num = 1; num <= 9; num++){ 
      if (isSafe(row, col, num)){ 
         a[row][col] = num;
         if (solveSudoku()) 
            return true;
         a[row][col] = 0; 
      }
   }
   return false;
}


// The main function 
int main(){
    cout<<"Before solving : "<<endl;
    cout<<endl<<endl;
    printSudoku();
    cout<<endl<<endl;
    cout<<"After solving : "<<endl;
    cout<<endl<<endl;
   if (solveSudoku() == true)
      printSudoku();
   else
      cout << "No solution exists";
}


