#pragma once
#include <iostream>

using namespace std;

class array {
 private:
  int *data;
  int size;
  int max_size;

  static const int STARTING_MAX = 25;

  void resize();
  
 public:
  array(int size = STARTING_MAX);
  ~array();

  int modify(int index, int new_number);
  void push_back(int number);
  void remove(int index);
  int search(int value);

  int& operator[](int index);
  friend ostream& operator<<(ostream &out, const array &arr);
};
