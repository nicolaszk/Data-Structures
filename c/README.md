# Data Structures in C

Welcome to the **Data Structures in C**! 🎉 This project provides a simple implementation of some well known data structures in C, complete with test functionality. 

## 🚀 Running the Program

The original code is already compiled and ready to use. The available data structures for now are:

```bash
./ArrayList
```


---

## 🛠️ Compiling the Code Yourself

If you'd prefer to compile the code on your own, follow these steps:

1. Open a terminal in the project directory.
2. Run the following command:

```bash
gcc -Iinclude src/IntegerArrayList.c tests/test_IntegerArrayList.c -o ArrayList
```

3. Once compiled, execute the program:

```bash
./ArrayList
```

---

## 📂 Project Structure

```
project/
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

- Make sure you have GCC installed before compiling the code. You can verify this with:
  ```bash
  gcc --version
  ```
- Feel free to modify the code and explore its implementation!

---

Thanks for reading! 💻✨
