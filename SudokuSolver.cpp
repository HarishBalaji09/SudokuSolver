#include<iostream>

using namespace std;
#define n 9


void printSudoku(int Sudoku[n][n]){
	for(int i=0;i<n;i++){
		cout<<"\n_____________________________\n";
		for(int j=0;j<n;j++){
			cout<<"| "<<Sudoku[i][j]<<"";
		}
		cout<<" |";
	}
	cout<<"\n_____________________________\n";		
}



bool isSafe(int Sudoku[n][n],int row,int col,int val){
	for(int i=0;i<n;i++){
		if(Sudoku[i][col]==val){
			return false;
		}
	}
	for(int i=0;i<n;i++){
		if(Sudoku[row][i]==val){
			return false;
		}
	}
	int startRow=row-row%3;
	int startCol=col-col%3;
	
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(Sudoku[startRow+i][startCol+j]==val){
				return false;
			}
		}
	}
	return true;
	
}



bool solveSudoku(int Sudoku[n][n],int row,int col){
	if(row==n-1 && col == n){
		return true;
	}
	
	if (col==n){
		row++;
		col=0;
	}
	
	if(Sudoku[row][col]>0){
		return solveSudoku(Sudoku,row,col+1);
	}
	
	for(int val=1;val<=n;val++){
		
		if (isSafe(Sudoku,row,col,val)){
			
			Sudoku[row][col]=val;
						
			if(solveSudoku(Sudoku,row,col+1)){
				
				return true;
			}
			
		}
		Sudoku[row][col]=0;
	}
	
	return false;	
}

int main()
{
   
    int grid[n][n] = { { 0, 0, 0, 5, 0, 0, 6, 0, 0 },
                       { 5, 0, 0, 0, 0, 0, 0, 4, 3 },
                       { 0, 3, 0, 4, 0, 0, 0, 5, 8 },
                       { 0, 0, 9, 0, 7, 0, 0, 8, 6 },
                       { 0, 0, 5, 0, 4, 0, 9, 0, 0 },
                       { 6, 1, 0, 0, 8, 0, 4, 0, 0 },
                       { 9, 5, 0, 0, 0, 2, 0, 3, 0 },
                       { 1, 6, 0, 0, 0, 0, 0, 0, 9 },
                       { 0, 0, 4, 0, 0, 7, 0, 0, 0 } };
 
    if (solveSudoku(grid, 0, 0))
        printSudoku(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
    
}
