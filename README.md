Nicolas Corfmat<br>
CruzID: ncorfmat<br>
Assignment: pa5

```
DESCRIPTION
``` 
This program implements a List ADT to perform shuffling operations and determine how many shuffles are needed to return a List back into its original order.

```
FILES
```
+ `List.h` Header file containing the interface for the List ADT.
+ `List.cpp` C++ file containing the List ADT.
+ `ListTest.cpp` C++ file containing code for testing the List ADT.
+ `Shuffle.cpp` Contains the main() function that performs shuffling operations.
+ `Makefile` Supports the compilation of all the .cpp programs in the pa5 directory.
+ `README.md` Contains information regarding the files in the pa5 directory and how to run them.

```
BUILD
``` 
To build, run `make` on the terminal command line within the pa5 assignment directory followed by `Shuffle` and/or `ListTest`. This creates respective executable files which can then be run.
```
CLEAN
```
Running `make clean` will remove all the executable (.o) files from the pa5 assignment directory as well as other compiler-generated files.
```
RUNNING
```
To run, type `./Shuffle` followed by a positive integer value specifying the maximum number of cards in a deck.
