# Data Structures in Java, C and C++

Welcome to my **Data Structures Project**! 🎉 This project provides a simple implementation of some well known data structures in Java, C and C++,  which I coded myself, with the objective of becoming more familiar with these three languages.

## 🚀 Running the Program

The original code is already compiled and ready to use. You just need to go to the folder of the language you want to run and execute the program with the commands provided below.
The available data structures for now are:

in C:
```bash
./ArrayList
```

in C++:
```bash
./ArrayList
./Queue
./Stack
```

in Java:
```bash
./ArrayList
./Queue
./Stack
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
```

### Java    
for java, you should go to the folder of the data structure you want to run and compile the code you want to run like this:

```bash
javac BinarySearchTree.java App.java
```

then run the program with:

```bash
java -cp out IntegerArrayList
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
└── README.md              # Project documentation (you are here!)
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
