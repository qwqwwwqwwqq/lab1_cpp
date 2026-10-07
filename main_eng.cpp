#include <iostream>
#include <string>

// Task 1

// 1.1. Returns the fractional part of x
double Fraction(double x) {
  int whole = static_cast<int>(x);
  return x - whole;
}

// 1.3. Converts a digit character to a number
int CharToNum(char x) {
  return x - '0';
}

// 1.5. Checks if the number is two-digit
bool Is2Digits(int x) {
  if (x < 0) {
    x = -x;
  }
  return x >= 10 && x <= 99;
}

// 1.7. Checks if num is in range [a, b] (inclusive)
bool IsInRange(int a, int b, int num) {
  int min_val;
  int max_val;
  if (a < b) {
    min_val = a;
    max_val = b;
  } else {
    min_val = b;
    max_val = a;
  }
  return num >= min_val && num <= max_val;
}

// 1.9. Checks if all three numbers are equal
bool IsEqual(int a, int b, int c) {
  return a == b && b == c;
}

// Task 2

// 2.1. Returns the absolute value of x
int Abs(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

// 2.3. Checks divisibility by 3 or 5, but not both
bool Is35(int x) {
  bool div3 = (x % 3 == 0);
  bool div5 = (x % 5 == 0);
  if (div3 && div5) {
    return false;
  }
  return div3 || div5;
}

// 2.5. Returns the maximum of three numbers
int Max3(int x, int y, int z) {
  int max_val = x;
  if (y > max_val) {
    max_val = y;
  }
  if (z > max_val) {
    max_val = z;
  }
  return max_val;
}

// 2.7. Returns sum of x and y, or 20 if sum is in [10, 19]
int Sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 19) {
    return 20;
  }
  return sum;
}

// 2.9. Returns the day of the week name by its number
std::string Day(int x) {
  switch (x) {
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    case 7: return "Sunday";
    default: return "not a day of the week";
  }
}

// Task 3

// 3.1. Returns a string with numbers from 0 to x inclusive
std::string ListNums(int x) {
  std::string result;
  for (int i = 0; i <= x; ++i) {
    result += std::to_string(i);
    if (i < x) {
      result += " ";
    }
  }
  return result;
}

// 3.3. Returns a string with all even numbers from 0 to x inclusive
std::string Chet(int x) {
  std::string result;
  for (int i = 0; i <= x; i += 2) {
    result += std::to_string(i);
    result += " ";
  }
  if (!result.empty()) {
    result.pop_back();
  }
  return result;
}

// 3.5. Returns the number of digits in x
int NumLen(long x) {
  if (x < 0) {
    x = -x;
  }
  if (x == 0) {
    return 1;
  }
  int count = 0;
  while (x > 0) {
    x = x / 10;
    count++;
  }
  return count;
}

// 3.7. Prints a square of '*' symbols of size x
void Square(int x) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

// 3.9. Prints a right triangle of '*' symbols of height x
void RightTriangle(int x) {
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= x - i; ++j) {
      std::cout << " ";
    }
    for (int j = 1; j <= i; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

// Task 4

// 4.1. Returns the index of the first occurrence of x in arr, or -1
int FindFirst(int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

// 4.3. Returns the value with the maximum absolute value in arr
int MaxAbs(int arr[], int size) {
  int max_val = arr[0];
  for (int i = 1; i < size; ++i) {
    int cur = arr[i];
    int max_copy = max_val;
    if (cur < 0) {
      cur = -cur;
    }
    if (max_copy < 0) {
      max_copy = -max_copy;
    }
    if (cur > max_copy) {
      max_val = arr[i];
    }
  }
  return max_val;
}

// 4.5. Returns a new array with ins inserted at position pos
int* AddArray(int arr[], int size_arr, int ins[], int size_ins, int pos) {
  int size_total = size_arr + size_ins;
  int* result = new int[size_total];
  for (int i = 0; i < pos; ++i) {
    result[i] = arr[i];
  }
  for (int i = 0; i < size_ins; ++i) {
    result[pos + i] = ins[i];
  }
  for (int i = pos; i < size_arr; ++i) {
    result[size_ins + i] = arr[i];
  }
  return result;
}

// 4.7. Returns a new array — a reversed copy of arr
int* ReverseBack(int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

// 4.9. Returns an array of indices of all occurrences of x in arr
int* FindAll(int arr[], int size, int x, int* out_size) {
  int* result = new int[size];
  int idx = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      result[idx] = i;
      idx++;
    }
  }
  *out_size = idx;
  return result;
}

// Helper functions

// Reads an integer with input validation
int ReadInt() {
  int value;
  while (true) {
    if (std::cin >> value) {
      if (std::cin.peek() == '\n' || std::cin.peek() == EOF) {
        std::cin.ignore(10000, '\n');
        return value;
      }
    }
    std::cout << "Error: enter an integer.\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
}

// Reads a real number with input validation
double ReadDouble() {
  double value;
  while (true) {
    if (std::cin >> value) {
      if (std::cin.peek() == '\n' || std::cin.peek() == EOF) {
        std::cin.ignore(10000, '\n');
        return value;
      }
    }
    std::cout << "Error: enter a number.\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
}

// Prints an array in format [a, b, c]
void PrintArray(int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i];
    if (i < size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]";
}

int main() {
  // Task 1
  std::cout << "Task 1. Methods\n\n";

  // 1.1 Fractional part
  std::cout << "1.1 Fractional part\n";
  std::cout << "Enter x: ";
  double x1 = ReadDouble();
  std::cout << "Result: " << Fraction(x1) << "\n\n";

  // 1.3 Char to number
  std::cout << "1.3 Char to number\n";
  char c3;
  while (true) {
    std::cout << "Enter a digit: ";
    std::cin >> c3;
    std::cin.ignore(10000, '\n');
    if (c3 >= '0' && c3 <= '9') {
      break;
    }
    std::cout << "Error: not a digit.\n";
  }
  std::cout << "Result: " << CharToNum(c3) << "\n\n";

  // 1.5 Two digits
  std::cout << "1.5 Two digits\n";
  std::cout << "Enter x: ";
  int x5 = ReadInt();
  std::cout << "Result: " << (Is2Digits(x5) ? "true" : "false") << "\n\n";

  // 1.7 In range
  std::cout << "1.7 In range\n";
  std::cout << "Enter a: ";
  int a7 = ReadInt();
  std::cout << "Enter b: ";
  int b7 = ReadInt();
  std::cout << "Enter num: ";
  int n7 = ReadInt();
  std::cout << "Result: " << (IsInRange(a7, b7, n7) ? "true" : "false") << "\n\n";

  // 1.9 Equality
  std::cout << "1.9 Equality\n";
  std::cout << "Enter a: ";
  int a9 = ReadInt();
  std::cout << "Enter b: ";
  int b9 = ReadInt();
  std::cout << "Enter c: ";
  int c9 = ReadInt();
  std::cout << "Result: " << (IsEqual(a9, b9, c9) ? "true" : "false") << "\n\n";

  // Task 2
  std::cout << "Task 2. Conditions\n\n";

  // 2.1 Absolute value
  std::cout << "2.1 Absolute value\n";
  std::cout << "Enter x: ";
  int x2 = ReadInt();
  std::cout << "Result: " << Abs(x2) << "\n\n";

  // 2.3 Divisible by 3 or 5
  std::cout << "2.3 Divisible by 3 or 5\n";
  std::cout << "Enter x: ";
  int x3 = ReadInt();
  std::cout << "Result: " << (Is35(x3) ? "true" : "false") << "\n\n";

  // 2.5 Max of three
  std::cout << "2.5 Max of three\n";
  std::cout << "Enter x: ";
  int m1 = ReadInt();
  std::cout << "Enter y: ";
  int m2 = ReadInt();
  std::cout << "Enter z: ";
  int m3 = ReadInt();
  std::cout << "Result: " << Max3(m1, m2, m3) << "\n\n";

  // 2.7 Double sum
  std::cout << "2.7 Double sum\n";
  std::cout << "Enter x: ";
  int s1 = ReadInt();
  std::cout << "Enter y: ";
  int s2 = ReadInt();
  std::cout << "Result: " << Sum2(s1, s2) << "\n\n";

  // 2.9 Day of week
  std::cout << "2.9 Day of week\n";
  std::cout << "Enter number (1-7): ";
  int d = ReadInt();
  std::cout << "Result: " << Day(d) << "\n\n";

  // Task 3
  std::cout << "Task 3. Loops\n\n";

  // 3.1 Numbers in a row
  std::cout << "3.1 Numbers in a row\n";
  std::cout << "Enter x: ";
  int n1 = ReadInt();
  std::cout << "Result: " << ListNums(n1) << "\n\n";

  // 3.3 Even numbers
  std::cout << "3.3 Even numbers\n";
  std::cout << "Enter x: ";
  int n3 = ReadInt();
  std::cout << "Result: " << Chet(n3) << "\n\n";

  // 3.5 Number length
  std::cout << "3.5 Number length\n";
  std::cout << "Enter x: ";
  long n5 = ReadInt();
  std::cout << "Result: " << NumLen(n5) << "\n\n";

  // 3.7 Square
  std::cout << "3.7 Square\n";
  std::cout << "Enter x: ";
  int side7 = ReadInt();
  std::cout << "Result:\n";
  Square(side7);
  std::cout << "\n";

  // 3.9 Right triangle
  std::cout << "3.9 Right triangle\n";
  std::cout << "Enter x: ";
  int tri9 = ReadInt();
  std::cout << "Result:\n";
  RightTriangle(tri9);
  std::cout << "\n";

  // Task 4
  std::cout << "Task 4. Arrays\n\n";

  // 4.1 Find first
  std::cout << "4.1 Find first\n";
  std::cout << "Enter array size: ";
  int size1 = ReadInt();
  int arr1[100];
  std::cout << "Enter " << size1 << " numbers:\n";
  for (int i = 0; i < size1; ++i) {
    arr1[i] = ReadInt();
  }
  std::cout << "Enter x: ";
  int f1 = ReadInt();
  std::cout << "Result: " << FindFirst(arr1, size1, f1) << "\n\n";

  // 4.3 Max absolute
  std::cout << "4.3 Max absolute\n";
  std::cout << "Enter array size: ";
  int size3 = ReadInt();
  int arr3[100];
  std::cout << "Enter " << size3 << " numbers:\n";
  for (int i = 0; i < size3; ++i) {
    arr3[i] = ReadInt();
  }
  std::cout << "Result: " << MaxAbs(arr3, size3) << "\n\n";

  // 4.5 Add array into array
  std::cout << "4.5 Add array into array\n";
  std::cout << "Enter arr size: ";
  int size_arr = ReadInt();
  int arr5[100];
  std::cout << "Enter " << size_arr << " numbers for arr:\n";
  for (int i = 0; i < size_arr; ++i) {
    arr5[i] = ReadInt();
  }
  std::cout << "Enter ins size: ";
  int size_ins = ReadInt();
  int ins5[100];
  std::cout << "Enter " << size_ins << " numbers for ins:\n";
  for (int i = 0; i < size_ins; ++i) {
    ins5[i] = ReadInt();
  }
  std::cout << "Enter pos: ";
  int pos = ReadInt();
  int* result5 = AddArray(arr5, size_arr, ins5, size_ins, pos);
  std::cout << "arr: ";
  PrintArray(arr5, size_arr);
  std::cout << "\n";
  std::cout << "ins: ";
  PrintArray(ins5, size_ins);
  std::cout << "\n";
  std::cout << "Result: ";
  PrintArray(result5, size_arr + size_ins);
  std::cout << "\n\n";
  delete[] result5;

  // 4.7 Reverse back
  std::cout << "4.7 Reverse back\n";
  std::cout << "Enter array size: ";
  int size7 = ReadInt();
  int arr7[100];
  std::cout << "Enter " << size7 << " numbers:\n";
  for (int i = 0; i < size7; ++i) {
    arr7[i] = ReadInt();
  }
  int* result7 = ReverseBack(arr7, size7);
  std::cout << "arr: ";
  PrintArray(arr7, size7);
  std::cout << "\n";
  std::cout << "Result: ";
  PrintArray(result7, size7);
  std::cout << "\n\n";
  delete[] result7;

  // 4.9 Find all
  std::cout << "4.9 Find all\n";
  std::cout << "Enter array size: ";
  int size9 = ReadInt();
  int arr9[100];
  std::cout << "Enter " << size9 << " numbers:\n";
  for (int i = 0; i < size9; ++i) {
    arr9[i] = ReadInt();
  }
  std::cout << "Enter x: ";
  int x9 = ReadInt();
  int out_size = 0;
  int* result9 = FindAll(arr9, size9, x9, &out_size);
  std::cout << "Array: ";
  PrintArray(arr9, size9);
  std::cout << "\n";
  std::cout << "Result: ";
  PrintArray(result9, out_size);
  std::cout << "\n\n";
  delete[] result9;

  std::cout << "All tasks completed.\n";
  return 0;
}