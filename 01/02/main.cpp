#include <iostream>

int find_count(int *arr, int size, int numb) {
  if (arr[size - 1] < numb) {
    return (size - 1);
  } else if (arr[0] > numb) {
    return -1;
  }
  int left = 0;
  int right = size - 1;

  while (left < right) {
    int middle = (left + right) / 2;
    if (arr[middle] == numb) {
      left = middle + 1;         // ищем справа
    } else if (arr[left] > numb) // Если номер левого индекса превышает значение
    {
      right = left - 1;
      left = left - 1;
    } else if (arr[middle] > numb) {
      right = middle - 1; // ищем слева
    } else if (left == (right - 1)) {
      right = middle - 1;
    } else {
      left = middle + 1; // ищем справа
    }
  }

  return left;
};

int main() {
  int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
  int sizeArr = 9;

  int findNumber;

  std::cout << "Введите точку отсчёта: ";
  std::cin >> findNumber;

  std ::cout << "Количество элементов в массиве больших, чем " << findNumber
             << ": " << (sizeArr - (find_count(arr, sizeArr, findNumber) + 1));
}