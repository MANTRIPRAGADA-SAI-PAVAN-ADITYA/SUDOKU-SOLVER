/*
   This code is to solve a traditional 9X9 Sudoku puzzle give by User.
   In this code we use a sloving method called Backtracking algorithm which is a more effective way of solving Sudoku compared to 'Brute Force Algorithm'(General method).
*/

#include<iostream>
using namespace std;

#define UNASSIGNED 0 //this makes defined every unassigned location in grid with '0'.
#define N 9          //This is to define the size of sudoku grid.

// To find an unassigned location in grid ,we use FindUnassignedLocation method
bool FindUnassignedLocation(int grid[N][N],int &row,int &col);
 
// To find out whether it is safe to place a number in that location
 bool isSafe(int grid[N][N], int row , int col, int num);
 
// to solve the grid
bool SolveSudoku(int grid[N][N])
{ 
   int row,col;
   if(!FindUnassignedLocation(grid,row,col))
      {
	   return true;
      }
      for(int num=1;num<=9;num++)	  
	  {
	     if(isSafe(grid,row,col,num))
		 {
		   grid[row][col]=num;
		   if(SolveSudoku(grid))
		       
			    return true;
 				
           grid[row][col]=UNASSIGNED;
		 }
	   }
    return false;
}	

//To find an unassigned location in grid ,we use FindUnassignedLocation method t ocheck whether the specified ocation is already assigned with a number or not
bool FindUnassignedLocation(int grid[N][N],int &row,int &col)
{
   for(row=0;row<N;row++)
     for(col=0;col<N;col++)
       if(grid[row][col]==UNASSIGNED)
          return true;
		  
   return false;  
}		 
		 
// To find out whether the given number is in the present row
bool UsedInRow(int grid[N][N],int row, int num) 		 
{
    for(int col=0;col<N;col++)
      if(grid[row][col]==num)
	      return true;
          
    return false;
}
		 
// To find out whether the given number is in the present col
bool UsedInCol(int grid[N][N],int col, int num) 		 
{
    for(int row=0;row<N;row++)
      if(grid[row][col]==num)
	      return true;
          
    return false;
}		 
		 		 
// To find out whether the given number is in the present row
bool UsedInBox(int grid[N][N],int boxStartRow, int boxStartCol, int num) 		 
{

    for(int row=0;row<3;row++)
    for(int col=0;col<3;col++)
      if(grid[row+boxStartRow][col+boxStartCol]==num)
	      return true;
          
    return false;
}		 

// isSafe method is set to true when the above methods UsedInRow , UsedInCol , UsedInBox are set to false
bool isSafe(int grid[N][N],int row, int col, int num)  
{
   return !UsedInRow(grid,row,num)&&
          !UsedInCol(grid,col,num)&&
		  !UsedInBox(grid,row-row%3,col-col%3,num)&&
		  grid[row][col]==UNASSIGNED;	
}
   
// The following method is to print the grid on the console for easy entry of elements.
void printGrid(int grid[N][N]) 
{
  int row,col;
   
    for(int row=0;row<N;row++)
    {
	  for(int col=0;col<N;col++)
      {
	    cout<<""<<grid[row][col];
		 if(col==2||col==5)
	        cout<<"   ";
	 
	     if(row==2||row==5)
	      {
		     if(col==8)
	         {
			   cout<<endl<<endl;
			 }
          }
      } cout<<endl;
   }  
}
// this is main 
int main()
{
	int x,y,n,di,c;
	int grid[N][N]; 
	
	l2:cout<<"How many numbers are to be entered into Grid? ";
	cin>>n;
	while(n<17){cout<<"Enter more than 17 for unique solution "<<endl; goto l2;}
	while(n>81){cout<<"You have exceed the limits of Grid"<<endl; goto l2;}
	
	for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	{
		grid[i][j]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		l1: cout<<"Enter co-ordinates of x,y from 0,0"<<endl;
		   cin>>x>>y;
		   
		   if(x>9||y>9||x<0||y<0)
		   {
			   cout<<"Wrong Input "<<endl;
			   goto l1;   			   
		   }
		   cout<<"Enter Digit "<<endl;
		   cin>>di;
		   
		   if(!isSafe(grid,x,y,di))
		   {
			   cout<<"You have entered a number which is repeated"<<endl;
			   goto l1;
		   }
		
		   if(di<1||di>9)
		   {
			   cout<<"The given input is not in the range of 1 to 9 "<<endl;
			   goto l1;
		   }
		   
		grid[x][y]=di;
		printGrid(grid);
		cout<<"Finished entering  yes=1/no=0?? ";
		cin>>c;
		
		  if(c)
			   break;
		   
	}	   
		
		if(SolveSudoku(grid)==true)
		   printGrid(grid);
        else
           cout<<" No solution exists";			
		
		
		return 0;
}	
