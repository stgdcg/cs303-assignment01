#pragma once
#include <iostream>

using namespace std;

class array {
 private:
  // Pointer to the array contained within the class
  int *data;

  // Amount of array used
  int size;

  // Total size of the array (used & unused)
  int max_size;

  // Default starting size
  static const int STARTING_MAX = 25;

  // Helper function to resize the array
  void resize();
  
 public:
  // Constructor for the array, if no value is supplied, use STARTING_MAX
  array(int size = STARTING_MAX);

  // Destructor to make sure the array * is deleted after use
  ~array();

  // Function to replace a value with a new one, returns the old value
  int modify(int index, int new_number);

  // Function to append a value to the array
  void push_back(int number);

  // Function to remove an index from the array, shifting the data afterwards
  void remove(int index);

  // Function to return the index of the first occurance of a value in the array. Returns -1 if not found
  int search(int value);

  // Bound-checked subscript operator
  int& operator[](int index);

  // Insertion operator for pretty printing of the array
  friend ostream& operator<<(ostream &out, const array &arr);
};
