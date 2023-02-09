#include "array.h"
#include "array_helpers.h"
#include <iostream>
#include <fstream>

using namespace std;

void input_file(string file, array &arr) {
  ifstream fin(file);
  if (!fin.is_open()) {
    throw runtime_error("File not found");
  }

  int tmp;
  while (fin >> tmp) {
    arr.push_back(tmp);
  }

  fin.close();
}

char prompt_options() {
  char input;
  cout << "ENTER OPTION:" << endl;
  cout << "(S)earch array and return index of number (-1 if not there)" << endl;
  cout << "(R)eplace a value at an index" << endl;
  cout << "(A)dd a new value at the end of the array" << endl;
  cout << "(D)elete a value at an index" << endl;
  cout << "(P)rint the array" << endl;
  cout << "(Q)uit" << endl;
  cout << " >> ";
  cin >> input;
  input = toupper(input);
  return input;
}
