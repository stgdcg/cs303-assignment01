#include "array.h"
#include "array_helpers.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {

  array arr(0);

  try {
    input_file("input.txt", arr);
  } catch (runtime_error &e) {
    cerr << e.what() << endl;
    return 1;
  }

  char option;
  do {
    option = prompt_options();
    cout << endl;

    int value, index;
    switch(option) {
    case 'S':
      cout << "\tEnter a value to search for: ";
      cin >> value;

      index = arr.search(value);
      
      cout << "\t";
      if (index == -1) {
	cout << value << " could not be found." << endl;
      } else {
	cout << value << " was first found at index " << index << endl;
      }
      
      break;
    case 'R':
      cout << "\tEnter an index to replace: ";
      cin >> index;
      cout << "\tEnter a value to replace: ";
      cin >> value;

      cout << "\tThe replaced value was: " << arr.modify(index, value) << endl;
      
      break;
    case 'A':
      cout << "\tEnter a value to add to the end of the array: ";
      cin >> value;
      arr.push_back(value);
      break;
    case 'D':
      cout << "\tEnter index to delete: ";

      try {
	cin >> index;
	arr.remove(index);
      } catch (runtime_error &e) {
	cout << "Invalid index" << endl;
      }
      break;
    case 'P':
      cout << "\tArray contents:" << endl;
      cout << "\t" << arr << endl;
      break;
    case 'Q':
      break;
    default:
      cout << "Invalid option; please enter a valid option." << endl;
      break;
    }
    cout << endl;
  } while (option != 'Q');
  
  return 0;
}
