#include "array.h"
#include <stdexcept>

using namespace std;

void array::resize() {
  int new_max_size;
  if (max_size == 0) {
    new_max_size = 8;
  } else {
    new_max_size = max_size * 2;
  }
  
  cout << "Resizing from " << max_size << " to " << new_max_size << endl;
  int *tmp_array = new int[new_max_size];

  for (int i = 0; i < size; i++) {
    tmp_array[i] = data[i];
  }

  max_size = new_max_size;
  delete[] data;
  data = tmp_array;
}

array::array(int size) {
  data = new int[size];
  max_size = size;
  this->size = 0;
}

array::~array() {
  delete[] data;
}

int& array::operator[](int index) {
  if (index >= size) {
    throw runtime_error("Cannot modify outside of array size");
  }

  return data[index];
}
  
int array::modify(int index, int new_number) {
  if (index >= size) {
    throw runtime_error("Cannot modify outside of array size");
  }

  int return_value = data[index];
  data[index] = new_number;
  return return_value;
}

void array::push_back(int number) {
  if (size == max_size) {
     resize();
  }

  data[size] = number;
  size++;
}

void array::remove(int index) {
  if (index >= size) {
    throw runtime_error("Cannot remove an index outside of the array");
  }
  
  if (index == size-1) {
    size--;
  } else {
    for (int i = index; i < size-1; i++) {
      data[i] = data[i+1];
    }
    size--;
  }
}

int array::search(int value) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (data[i] == value) {
      index = i;
      break;
    }
  }

  return index;
}

ostream& operator<<(ostream &out, const array &arr) {
  for (int i = 0; i < arr.size; i++) {
    out << arr.data[i] << " ";
  }
  
  return out;
}
