#include <iostream>

unsigned long long fibo(unsigned long long *arrFib, int size, int n) {

  if (n == 0) {
    return 0;
  }
  if (n == 1 || n == 2) {
    arrFib[n] = 1;
    return 1;
  }
  // Проверяем если в данном ряду есть число то не выпоняем рекурсию
  if (arrFib[n] > 0) {
    return arrFib[n];
  }

  // Запоминаем рукурсию
  arrFib[n] = fibo(arrFib, size, n - 1) + fibo(arrFib, size, n - 2);

  return arrFib[n];
}

int main() {
  int numb;

  std::cout << "Введите число: ";
  std::cin >> numb;

  std::cout << "Числа Фибоначчи: ";

  // Выделяем память (массив) для чисел фибоначи
  unsigned long long *arrFib{new unsigned long long[numb]{}};

  for (size_t i = 0; i < numb; i++) {
    std ::cout << fibo(arrFib, numb, i) << " ";
  }
  delete[] arrFib;
  std ::cout << std::endl;
}