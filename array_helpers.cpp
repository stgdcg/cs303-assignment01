#include "array.h"
#include "array_helpers.h"
#include <iostream>
#include <fstream>

using namespace std;

void input_file(string file, array &arr) {
  // Open a file
  ifstream fin(file);

  // Throw an error if the file is not found
  if (!fin.is_open()) {
    throw runtime_error("File not found");
  }

  // Input all of the values in the file and push each new one to the back of tmp
  int tmp;
  while (fin >> tmp) {
    arr.push_back(tmp);
  }

  // Close the file stream
  fin.close();
}

char prompt_options() {
  // Prompt the user
  char input;
  cout << "ENTER OPTION:" << endl;
  cout << "(S)earch array and return index of number (-1 if not there)" << endl;
  cout << "(R)eplace a value at an index" << endl;
  cout << "(A)dd a new value at the end of the array" << endl;
  cout << "(D)elete a value at an index" << endl;
  cout << "(P)rint the array" << endl;
  cout << "(Q)uit" << endl;
  cout << " >> ";

  // Take input
  cin >> input;
  
  // Uppercase the character inputted
  input = toupper(input);
  return input;
}
