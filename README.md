# Data Structures in Java, C and C++

Welcome to my **Data Structures Project**! 🎉 This project provides a simple implementation of some well known data structures in Java, C and C++,  which I coded myself, with the objective of becoming more familiar with these three languages.

## 🚀 Running the Program

The original code is already compiled and ready to use. You just need to go to the folder of the language you want to run and execute the program with the commands provided below.
The available data structures for now are (work in progress):

in C:
```bash
./ArrayList
./Stack
./Queue
./BST
./MinHeap
./MaxHeap
```

in C++:
```bash
./ArrayList
./Queue
./Stack
./BinarySearchTree
./MinHeap
./MaxHeap
```

in Java:
```bash
./ArrayListTest
./BinarySearchTreeTest
./StackTest
./QueueTest
./MinHeapTest
```

---

## 🛠️ Compiling the Code Yourself

If you'd prefer to compile the code on your own, follow these steps:

### C
1. Open a terminal in the C directory.
2. Run the following command:

```bash
gcc -Iinclude src/IntegerArrayList.c tests/test_IntegerArrayList.c -o ArrayList
```

3. Once compiled, execute the program:

```bash
./ArrayList
```

(replace every occurence of "ArrayList" with the name of the data structure you want to compile and run)

### C++
1. Open a terminal in the C++ directory.
2. Run the following command:
```bash
g++ -std=c++17 -o ArrayList tests/test_ArrayList.cpp src/ArrayList.cpp -I include/
```

3. Once compiled, execute the program:
```bash
./ArrayList
```
(replace every occurence of "ArrayList" with the name of the data structure you want to compile and run)


### Java    
1. Open a terminal in the java directory.
2. Run the following command:

```bash
javac -d . src/*.java tests/*.java
```

or, for compiling and running a specific test:

```bash
javac -d . src/ArrayList.java tests/test_ArrayList.java
```

3. Run the following command:
```bash
java ArrayListTest
```
(replace every occurence of "ArrayList" with the name of the data structure you want to run)
---

## 📂 Project Structure

```
### C
C/
├── include/               # Header files
│   └── IntegerArrayList.h
│   └── IntegerStack.h
│   └── IntegerQueue.h
│   └── BinarySearchTree.h
│   └── MinHeap.h
│   └── MaxHeap.h
├── src/                   # Source code
│   └── IntegerArrayList.c
│   └── IntegerStack.c
│   └── IntegerQueue.c
│   └── BinarySearchTree.c
│   └── MinHeap.c
│   └── MaxHeap.c
├── tests/                 # Test cases
│   └── test_IntegerArrayList.c
│   └── test_IntegerStack.c
│   └── test_IntegerQueue.c
│   └── test_BST.c
│   └── test_MinHeap.c
│   └── test_MaxHeap.c
└── README.md              # Project documentation 
```
```
### C++
C++/
├── include/               # Header files
│   └── ArrayList.h
│   └── Queue.h
│   └── Stack.h
│   └── BinarySearchTree.h
│   └── MinHeap.h
│   └── MaxHeap.h
├── src/                   # Source code
│   └── ArrayList.cpp
│   └── Queue.cpp
│   └── Stack.cpp
│   └── BinarySearchTree.cpp
│   └── MinHeap.cpp
│   └── MaxHeap.cpp
├── tests/                 # Test cases
│   └── test_ArrayList.cpp
│   └── test_Queue.cpp
│   └── test_Stack.cpp
│   └── test_BinarySearchTree.cpp
│   └── test_MinHeap.cpp
│   └── test_MaxHeap.cpp
└── README.md              # Project documentation 
```
```
### Java
java/
├── src/                   # Source code
│   └── ArrayList.java
│   └── BinarySearchTree.java
│   └── Stack.java
│   └── Queue.java
│   └── MinHeap.java
├── tests/                 # Test cases
│   └── ArrayListTest.java
│   └── BinarySearchTreeTest.java
│   └── StackTest.java
│   └── QueueTest.java
│   └── MinHeapTest.java
└── README.md              # Project documentation
```

---

## 📝 Notes

- Make sure you have GCC, G++ and Java installed before compiling the code. You can verify this with:
  ```bash
  gcc --version
  g++ --version
  java --version
  ```
- Feel free to modify the code and explore its implementation!

---

Thanks for reading! 💻✨
