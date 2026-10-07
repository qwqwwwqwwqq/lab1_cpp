#include <iostream>
#include <clocale>
#include <string>

// Задание 1

// 1.1. Возвращает дробную часть числа x
double Fraction(double x) {
  int whole = static_cast<int>(x);
  return x - whole;
}

// 1.3. Преобразует символ цифры в число
int CharToNum(char x) {
  return x - '0';
}

// 1.5. Проверяет, является ли число двузначным
bool Is2Digits(int x) {
  if (x < 0) {
    x = -x;
  }
  return x >= 10 && x <= 99;
}

// 1.7. Проверяет, входит ли num в диапазон [a, b] (границы включительно)
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

// 1.9. Проверяет, равны ли все три числа
bool IsEqual(int a, int b, int c) {
  return a == b && b == c;
}

// Задание 2

// 2.1. Возвращает модуль числа x
int Abs(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

// 2.3. Проверяет делимость на 3 или 5, но не на оба одновременно
bool Is35(int x) {
  bool div3 = (x % 3 == 0);
  bool div5 = (x % 5 == 0);
  if (div3 && div5) {
    return false;
  }
  return div3 || div5;
}

// 2.5. Возвращает максимальное из трёх чисел
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

// 2.7. Возвращает сумму x и y, либо 20, если сумма в [10, 19].
int Sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 19) {
    return 20;
  }
  return sum;
}

// 2.9. Возвращает название дня недели по его номеру.
std::string Day(int x) {
  switch (x) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суббота";
    case 7: return "воскресенье";
    default: return "это не день недели";
  }
}

// Задание 3

// 3.1. Возвращает строку с числами от 0 до x включительно
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

// 3.3. Возвращает строку со всеми чётными числами от 0 до x включительно
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

// 3.5. Возвращает количество знаков в числе x
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

// 3.7. Выводит квадрат из символов "*" размером x
void Square(int x) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}


// Задание 4

// 4.1. Возвращает индекс первого вхождения x в arr, или -1
int FindFirst(int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

// 4.3. Возвращает наибольшее по модулю значение массива
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

// 4.5. Возвращает новый массив с вставленным ins на позицию pos
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

// 4.7. Возвращает новый массив — копию arr в обратном порядке
int* ReverseBack(int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

// 4.9. Возвращает массив индексов всех вхождений x в arr
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

// Вспомогательные функции

// Функции проверки ввода

// Чтение целого числа с проверкой корректности ввода
int ReadInt() {
  int value;
  while (true) {
    if (std::cin >> value) {
      if (std::cin.peek() == '\n' || std::cin.peek() == EOF) {
        std::cin.ignore(10000, '\n');
        return value;
      }
    }
    std::cout << "Ошибка: введите целое число.\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
}

// Чтение вещественного числа с проверкой корректности ввода
double ReadDouble() {
  double value;
  while (true) {
    if (std::cin >> value) {
      if (std::cin.peek() == '\n' || std::cin.peek() == EOF) {
        std::cin.ignore(10000, '\n');
        return value;
      }
    }
    std::cout << "Ошибка: введите число.\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
}

// Выводит массив в формате [a, b, c].
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
  setlocale(LC_ALL, "Russian");

  // Задание 1
  std::cout << "Задание 1. Методы\n\n";

  // 1.1 Дробная часть
  std::cout << "1.1 Дробная часть\n";
  std::cout << "Введите x: ";
  double x1 = ReadDouble();
  std::cout << "Результат: " << Fraction(x1) << "\n\n";

  // 1.3 Букву в число
  std::cout << "1.3 Букву в число\n";
  char c3;
  while (true) {
    std::cout << "Введите цифру: ";
    std::cin >> c3;
    std::cin.ignore(10000, '\n');
    if (c3 >= '0' && c3 <= '9') {
      break;
    }
    std::cout << "Ошибка: это не цифра.\n";
  }
  std::cout << "Результат: " << CharToNum(c3) << "\n\n";

  // 1.5 Двузначное
  std::cout << "1.5 Двузначное\n";
  std::cout << "Введите x: ";
  int x5 = ReadInt();
  std::cout << "Результат: " << (Is2Digits(x5) ? "true" : "false") << "\n\n";

  // 1.7 Диапазон
  std::cout << "1.7 Диапазон\n";
  std::cout << "Введите a: ";
  int a7 = ReadInt();
  std::cout << "Введите b: ";
  int b7 = ReadInt();
  std::cout << "Введите num: ";
  int n7 = ReadInt();
  std::cout << "Результат: " << (IsInRange(a7, b7, n7) ? "true" : "false") << "\n\n";

  // 1.9 Равенство
  std::cout << "1.9 Равенство\n";
  std::cout << "Введите a: ";
  int a9 = ReadInt();
  std::cout << "Введите b: ";
  int b9 = ReadInt();
  std::cout << "Введите c: ";
  int c9 = ReadInt();
  std::cout << "Результат: " << (IsEqual(a9, b9, c9) ? "true" : "false") << "\n\n";

  // Задание 2
  std::cout << "Задание 2. Условия\n\n";

  // 2.1 Модуль числа
  std::cout << "2.1 Модуль числа\n";
  std::cout << "Введите x: ";
  int x2 = ReadInt();
  std::cout << "Результат: " << Abs(x2) << "\n\n";

  // 2.3 Тридцать пять
  std::cout << "2.3 Тридцать пять\n";
  std::cout << "Введите x: ";
  int x3 = ReadInt();
  std::cout << "Результат: " << (Is35(x3) ? "true" : "false") << "\n\n";

  // 2.5 Тройной максимум
  std::cout << "2.5 Тройной максимум\n";
  std::cout << "Введите x: ";
  int m1 = ReadInt();
  std::cout << "Введите y: ";
  int m2 = ReadInt();
  std::cout << "Введите z: ";
  int m3 = ReadInt();
  std::cout << "Результат: " << Max3(m1, m2, m3) << "\n\n";

  // 2.7 Двойная сумма
  std::cout << "2.7 Двойная сумма\n";
  std::cout << "Введите x: ";
  int s1 = ReadInt();
  std::cout << "Введите y: ";
  int s2 = ReadInt();
  std::cout << "Результат: " << Sum2(s1, s2) << "\n\n";

  // 2.9 День недели
  std::cout << "2.9 День недели\n";
  std::cout << "Введите число (1-7): ";
  int d = ReadInt();
  std::cout << "Результат: " << Day(d) << "\n\n";

  // Задание 3
  std::cout << "Задание 3. Циклы\n\n";

  // 3.1 Числа подряд
  std::cout << "3.1 Числа подряд\n";
  std::cout << "Введите x: ";
  int n1 = ReadInt();
  std::cout << "Результат: " << ListNums(n1) << "\n\n";

  // 3.3 Чётные числа
  std::cout << "3.3 Чётные числа\n";
  std::cout << "Введите x: ";
  int n3 = ReadInt();
  std::cout << "Результат: " << Chet(n3) << "\n\n";

  // 3.5 Длина числа
  std::cout << "3.5 Длина числа\n";
  std::cout << "Введите x: ";
  long n5 = ReadInt();
  std::cout << "Результат: " << NumLen(n5) << "\n\n";

  // 3.7 Квадрат
  std::cout << "3.7 Квадрат\n";
  std::cout << "Введите x: ";
  int side7 = ReadInt();
  std::cout << "Результат:\n";
  Square(side7);
  std::cout << "\n";

  // Задание 4
  std::cout << "Задание 4. Массивы\n\n";

  // 4.1 Поиск первого значения
  std::cout << "4.1 Поиск первого значения\n";
  std::cout << "Введите размер массива: ";
  int size1 = ReadInt();
  int arr1[100];
  std::cout << "Введите " << size1 << " чисел:\n";
  for (int i = 0; i < size1; ++i) {
    arr1[i] = ReadInt();
  }
  std::cout << "Введите x: ";
  int f1 = ReadInt();
  std::cout << "Результат: " << FindFirst(arr1, size1, f1) << "\n\n";

  // 4.3 Поиск максимального по модулю
  std::cout << "4.3 Поиск максимального по модулю\n";
  std::cout << "Введите размер массива: ";
  int size3 = ReadInt();
  int arr3[100];
  std::cout << "Введите " << size3 << " чисел:\n";
  for (int i = 0; i < size3; ++i) {
    arr3[i] = ReadInt();
  }
  std::cout << "Результат: " << MaxAbs(arr3, size3) << "\n\n";

  // 4.5 Добавление массива в массив
  std::cout << "4.5 Добавление массива в массив\n";
  std::cout << "Введите размер массива arr: ";
  int size_arr = ReadInt();
  int arr5[100];
  std::cout << "Введите " << size_arr << " чисел arr:\n";
  for (int i = 0; i < size_arr; ++i) {
    arr5[i] = ReadInt();
  }
  std::cout << "Введите размер массива ins: ";
  int size_ins = ReadInt();
  int ins5[100];
  std::cout << "Введите " << size_ins << " чисел ins:\n";
  for (int i = 0; i < size_ins; ++i) {
    ins5[i] = ReadInt();
  }
  std::cout << "Введите позицию pos: ";
  int pos = ReadInt();
  int* result5 = AddArray(arr5, size_arr, ins5, size_ins, pos);
  std::cout << "arr: ";
  PrintArray(arr5, size_arr);
  std::cout << "\n";
  std::cout << "ins: ";
  PrintArray(ins5, size_ins);
  std::cout << "\n";
  std::cout << "Результат: ";
  PrintArray(result5, size_arr + size_ins);
  std::cout << "\n\n";
  delete[] result5;

  // 4.7 Возвратный реверс
  std::cout << "4.7 Возвратный реверс\n";
  std::cout << "Введите размер массива: ";
  int size7 = ReadInt();
  int arr7[100];
  std::cout << "Введите " << size7 << " чисел:\n";
  for (int i = 0; i < size7; ++i) {
    arr7[i] = ReadInt();
  }
  int* result7 = ReverseBack(arr7, size7);
  std::cout << "arr: ";
  PrintArray(arr7, size7);
  std::cout << "\n";
  std::cout << "Результат: ";
  PrintArray(result7, size7);
  std::cout << "\n\n";
  delete[] result7;

  // 4.9 Все вхождения
  std::cout << "4.9 Все вхождения\n";
  std::cout << "Введите размер массива: ";
  int size9 = ReadInt();
  int arr9[100];
  std::cout << "Введите " << size9 << " чисел:\n";
  for (int i = 0; i < size9; ++i) {
    arr9[i] = ReadInt();
  }
  std::cout << "Введите x: ";
  int x9 = ReadInt();
  int out_size = 0;
  int* result9 = FindAll(arr9, size9, x9, &out_size);
  std::cout << "Массив: ";
  PrintArray(arr9, size9);
  std::cout << "\n";
  std::cout << "Результат: ";
  PrintArray(result9, out_size);
  std::cout << "\n\n";
  delete[] result9;
}