# cs303-assignment01

## Building
Run `make all` to build. `./main` to run the program.

## Interaction
A menu is given to the user as shown below:
![The program's prompt](/pictures/prompt.png)

Choose an option (either case works. Fill in prompts as requested.

## Data Structure
The array is wrapped in a class (array.h). The class provides a few functions to interact with the array.
There is a `push_back` function to append a value to the array. `remove` takes in an index and removes the value at that index.
`modify` replaces a value at an index with a given value and returns the value originally in the array.
`search` takes a value and returns the index of the first occurance in the array or -1 if the value is not present.

The constructor can be called with an initial value, and if not supplied will default to 25.
There is a private `resize` function that is automatically called if the array needs more space, properly deleting the old array.
The destructor will delete the array to prevent memory leaks.
Deleting a value will shift the values to ensure contiguous arrays.

## Demo
Here is a screenshot of a short demo showing the functionality:

!(/pictures/demo1.png)
!(/pictures/demo2.png)
