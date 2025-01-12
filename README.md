# Data Structures in Java, C and C++

Welcome to my **Data Structures Project**! 🎉 This project provides a simple implementation of some well known data structures in Java, C and C++,  which I coded myself, with the objective of becoming more familiar with these three languages.

## 🚀 Running the Program

The original code is already compiled and ready to use. You just need to go to the folder of the language you want to run and execute the program with the commands provided below.
The available data structures for now are (work in progress):

in C:
```bash
./ArrayList
```

in C++:
```bash
./ArrayList
./Queue
./Stack
./BinarySearchTree
```

in Java:
```bash
./ArrayListTest
./BinarySearchTreeTest
./StackTest
```

---

## 🛠️ Compiling the Code Yourself

If you'd prefer to compile the code on your own, follow these steps:

### C
1. Open a terminal in the project directory.
2. Run the following command:

```bash
gcc -Iinclude src/IntegerArrayList.c tests/test_IntegerArrayList.c -o ArrayList
```

3. Once compiled, execute the program:

```bash
./ArrayList
```

### C++

```bash
g++ -std=c++17 -o ArrayList tests/test_ArrayList.cpp src/ArrayList.cpp -I include/
g++ -std=c++17 -o Queue tests/test_Queue.cpp src/Queue.cpp -I include/
g++ -std=c++17 -o Stack tests/test_Stack.cpp src/Stack.cpp -I include/
g++ -std=c++17 -o BinarySearchTree tests/test_BinarySearchTree.cpp src/BinarySearchTree.cpp -I include/
```

### Java    
for java, you should go to the java folder and compile the code with:

```bash
javac -d . src/*.java tests/*.java
```

then run the program you wish (in the java directory).
for example:
```bash
java ArrayListTest
```

---

## 📂 Project Structure

```
### C
C/
├── include/               # Header files
│   └── IntegerArrayList.h
├── src/                   # Source code
│   └── IntegerArrayList.c
├── tests/                 # Test cases
│   └── test_IntegerArrayList.c
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
├── src/                   # Source code
│   └── ArrayList.cpp
│   └── Queue.cpp
│   └── Stack.cpp
│   └── BinarySearchTree.cpp
├── tests/                 # Test cases
── test_ArrayList.cpp
│   └── test_Queue.cpp
│   └── test_Stack.cpp
│   └── test_BinarySearchTree.cpp
└── README.md              # Project documentation 
```
```
### Java
java/
├── src/                   # Source code
│   └── ArrayList.java
│   └── BinarySearchTree.java
│   └── Stack.java
├── tests/                 # Test cases
│   └── ArrayListTest.java
│   └── BinarySearchTreeTest.java
│   └── StackTest.java
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
