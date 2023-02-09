#include "array.h"
#include "array_helpers.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {

  // Create an array of size 0
  array arr(0);

  // Populate the array from the file `input.txt`, catching the error and ending the program if the file is not found
  try {
    input_file("input.txt", arr);
  } catch (runtime_error &e) {
    cerr << e.what() << endl;
    return 1;
  }

  char option;
  int value, index;
  
  // Loop until the user wants to quit
  do {
    // Prompt the user and save that value
    option = prompt_options();
    cout << endl;

    // Decide what to do based on the inputted option
    switch(option) {
    case 'S':
      // Prompt the user for a value to search
      cout << "\tEnter a value to search for: ";
      cin >> value;

      // Search the array, saving the value to `index`
      index = arr.search(value);

      // Output either the index, or that the value could not be found
      cout << "\t";
      if (index == -1) {
	cout << value << " could not be found." << endl;
      } else {
	cout << value << " was first found at index " << index << endl;
      }
      
      break;
    case 'R':
      // Prompt the user for the index to replace and the value to replace it with
      cout << "\tEnter an index to replace: ";
      cin >> index;
      cout << "\tEnter a value to replace: ";
      cin >> value;

      // Try to replace that value and output the old value, if failed, output invalid index
      try {
	cout << "\tThe replaced value was: " << arr.modify(index, value) << endl;
      } catch (runtime_error &e) {
	cout << "Invalid index" << endl;
      }
      
      break;
    case 'A':
      // Prompt the user for a value to append
      cout << "\tEnter a value to add to the end of the array: ";
      cin >> value;

      // Append the value
      arr.push_back(value);
      
      break;
    case 'D':
      // Prompt the user for an index to delete
      cout << "\tEnter index to delete: ";

      // Try to delete the index, and output whether or not it was successful
      try {
	cin >> index;
	arr.remove(index);
	cout << "\t" << index << " was successfully deleted" << endl;
      } catch (runtime_error &e) {
	cout << "\tInvalid index" << endl;
      }
      break;
    case 'P':
      // Print the array
      cout << "\tArray contents:" << endl;
      cout << "\t" << arr << endl;
      break;
    case 'Q':
      // End the loop
      break;
    default:
      // Output invalid option
      cout << "Invalid option; please enter a valid option." << endl;
      break;
    }
    cout << endl;
  } while (option != 'Q');
  
  return 0;
}
