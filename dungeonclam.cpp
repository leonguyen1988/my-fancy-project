// Tho Huu Nguyen

#include <iostream>

using namespace std;

// function will run to checking whether has barries or not
bool isSafe(string *maze,int locX, int locY);

// It will print the solution
void printMap(string *maze, int rs);


int main()
{
  // Pointer will be used for dynamic programming  
  string* maze;
  int cs,rs;
  
  // the programm will stop running when get 0 colum and 0 rows
  do
  {
    // Get number of rows and numbers of columns  
    cin>>cs>>rs;
    cout<<cs << " " <<rs <<endl; ;
    cin.ignore();

    //set new dynamic string array
    maze = new string [rs];

    // Input string into string array
    for (int k =0 ; k< rs; k++)
    {
      getline(cin,maze[k]);
    }

    // this function will find DrZ (or the starting point)
    // and check the neighbor locations arround Dr.Z(or the starting point)
    for(int k =0 ; k < rs;k++)
    {
        for(int z= 0; z < cs ;z++)
        {
            if(maze[k][z] == 'Z')
                isSafe(maze,k,z);
        }
    }
   
   // Print the map with pathfinders are bread crums
   printMap(maze,rs);

    //Delete the pointer array
    delete [] maze;
  }
  while(cs!=0 && rs!=0);
    return 0;
}

// The function will return true if find the exit 
// or find availble spaces, otherwise it will return false
// This function use recursion and back tracking to make
// it work corrrectly

bool isSafe(string *maze, int locY, int locX)
{
  bool result;
  // Base case of function, It will done if id find Exit 'E'
  if(maze[locY][locX] == 'E')
        {return true;}
        
  // Case for recursion
  else if(maze[locY][locX] == '#' 
          || maze[locY][locX] =='.'
          || maze[locY][locX] == 'C')
        {return false;}

  // If it find avai spaces, it will put a dot to mark
  // to avoid the situation when we override the Dr.Z
  if(maze[locY][locX]=='Z')
    maze[locY][locX]='Z';
  else
    maze[locY][locX]='.';

  // Checking up 
  result = isSafe(maze,locY+1,locX);
  if(result)
    return true;
   
  // Checking down
  result = isSafe(maze,locY-1,locX);
  if(result)
    return true;
 
  // Check right
  result = isSafe(maze,locY,locX+1);
  if(result)
  {
    return true;
  }
  //Checking left
  result = isSafe(maze,locY,locX-1);
  if(result)
    return true;

  //we will undo steps if we find wrong path
  if(maze[locY][locX]=='Z')
    maze[locY][locX]='Z';
  else
    maze[locY][locX] = ' ';

  return false; 
}

// This function will print finnal solution with pathfinders
void printMap(string *maze,int rs)
{
    for(int row =0; row<rs;row++ )
    {
        cout<<maze[row]<<endl;
    }
}