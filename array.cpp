#include "array.h"
#include <stdexcept>

using namespace std;

void array::resize() {
  // Define the new max size
  int new_max_size;
  if (max_size == 0) {
    // If the current max size is 0, set the new max to 25
    new_max_size = 25;
  } else {
    // Othersize, double the new max size
    new_max_size = max_size * 2;
  }

  // Create the new dynamic array
  int *tmp_array = new int[new_max_size];


  // Iterate through the used values of the array, copying them to the new, larger array
  for (int i = 0; i < size; i++) {
    tmp_array[i] = data[i];
  }

  // Delete the old array
  delete[] data;
  
  // Update max size and make the data point to the new array
  max_size = new_max_size;
  data = tmp_array;
}

array::array(int size) {
  // Create a dynamic array of size `size`
  data = new int[size];

  // Set the size & max size variables to 0 and `size`
  max_size = size;
  this->size = 0;
}

array::~array() {
  // Delete the array
  delete[] data;
}

int& array::operator[](int index) {
  // Throw an error if the index is not in the list
  if (index >= size) {
    throw runtime_error("Cannot modify outside of array size");
  }

  // Return the value at the given index
  return data[index];
}
  
int array::modify(int index, int new_number) {
  // Throw an error if the index is not in the list
  if (index >= size) {
    throw runtime_error("Cannot modify outside of array size");
  }

  // Save the old value at that index
  int return_value = data[index];

  // Replace the old value with the new one
  data[index] = new_number;

  // Return the old value
  return return_value;
}

void array::push_back(int number) {
  // If the array is full, resize
  if (size == max_size) {
     resize();
  }

  // Add a number to the back of the array
  data[size] = number;

  // Increment size to keep track of that new value
  size++;
}

void array::remove(int index) {
  // Throw an error if the index is not in the list
  if (index >= size) {
    throw runtime_error("Cannot remove an index outside of the array");
  }

  // If the index is at the back of the used array, simply decrement the size.
  if (index == size-1) {
    size--;
  } else {
    // Otherwize, iterate from the index to the end of the array, shifting the values left, deleting the index
    for (int i = index; i < size-1; i++) {
      data[i] = data[i+1];
    }

    // Decrement the size
    size--;
  }
}

int array::search(int value) {
  // Set the found index to -1 (this will be unchanged if the value is not found)
  int index = -1;

  // Iterate through the array
  for (int i = 0; i < size; i++) {
    // If the value is found, set the index to the found index and break out of the loop
    if (data[i] == value) {
      index = i;
      break;
    }
  }

  // Return the index (-1 if not found)
  return index;
}

ostream& operator<<(ostream &out, const array &arr) {
  // Iterate through the used list
  for (int i = 0; i < arr.size; i++) {
    // Output the ith value to the stream
    out << arr.data[i] << " ";
  }

  // Return the modified stream
  return out;
}
