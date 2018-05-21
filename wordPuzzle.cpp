//Dev Kumar, dk9nr, 10/15/2017, wordSearch.cpp
//The quad nested for loop makes Big Theta equal to n^4. Hash functions are constant speed.
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "HashNode.h"
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500

char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);




/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main(int argc, char* argv[]) {
  //Hashes the dictionary into the Hash Map!
  timer t;
  hashTable hash;
  hashTable p;
  string line;
  ifstream file(argv[1]);
  if (!file.is_open())
    return false;
  else
    {while(getline(file,line)){
	hash.Insert(line);
	p.Insert(line.substr(0,19));
      }
    }
  file.close();

  //Fills the char grid with the rows and columns!
  int rows, cols;
  readInGrid(argv[2],rows,cols);

  //Checks if the grid combinations are in the hashmap

  int count=0;
    t.start();
    for(int r = 0; r < rows; r++) {
      for(int c = 0; c < cols; c++) {
	for(int d = 0; d < 8; d++) {
	  for(int l = 3; l < 23; l++) {
	    string word(getWordInGrid(r, c, d, l, rows, cols));
	    if(l > word.length()){
	      break;
	    }
	    // if ((p.Search(getWordInGrid(r,c,d,l,500,500))==false))
	    // {break;
	    // }
	    else if ((hash.Search(getWordInGrid(r,c,d,l,500,500))==true)) {
	      char* x=(getWordInGrid(r,c,d,l,500,500));
	      count++;
	      if(d == 0){
		cout<<"N"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 1) {
		cout<<"NE"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 2) {
		cout<<"E"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 3) {
		cout<<"SE"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 4) {
		cout<<"S"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 5) {
		cout<<"SW"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 6) {
		cout<<"W"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      }
	      else if(d == 7) {
		cout<<"NW"<<"("<<r<<","<<c<<")"<<":"<<x<<endl;
	      } 
	      
	      
	    }
	  }
	}
      }
    }
    t.stop();
    cout << count << " words found" << endl;
    cout <<"Found all words in "<< t <<" seconds"<< endl;










  
  return 0;
}


  
  

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}



//find out length of word!____________________________________
// for (int r =0;r<rows;r++)
//   {
//     for (int c=0; c<cols; c++){
//       if (arr[r][c]!=word[0]){
// 	continue;
//       }
//       for ( int i = 0; i < 8; i++ ){
// 	char* x=getWordInGrid(r,c,wordlength,i,rows,columns);
// 	if (x==word){
// 	  cout << "Found at"<< arr[r][c]<<endl;
//       }
      

	
			  		    

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
      // if (len>strlen(output)){
      // 	break;
      // }
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
	//if (grid[r][c]==0){
	//break;}
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}










































