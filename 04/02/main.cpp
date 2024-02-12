#include <iostream>

void print_dynamic_array(int *arr, int logical_size, int actual_size) {
  if (actual_size > 0) {

    for (size_t i = 0; i < actual_size; i++) {
      if (i < logical_size) {
        std::cout << arr[i] << " ";
      } else {
        std::cout << "_ ";
      }
    }
  }
}

void append_to_dynamic_array(int *&arr, int &logical_size, int &actual_size,
                             int numb) {
  if (logical_size == actual_size) {
    actual_size += actual_size;
  }

  int *newArr = new int[actual_size]{};
  for (size_t i = 0; i < logical_size; i++) {
    newArr[i] = arr[i];
  }
  newArr[logical_size] = numb;
  logical_size++;
  delete[] arr;
  arr = newArr;
}

int main() {
  int logical_size;
  int actual_size;

  std::cout << "Введите фактичеcкий размер массива: ";
  std::cin >> actual_size;

  std::cout << "Введите логический размер массива: ";
  std::cin >> logical_size;

  if (logical_size > actual_size) {
    std::cout
        << "Ошибка! Логический размер массива не может превышать фактический!";
    return 1;
  }
  int *arr = new int[actual_size]{};
  if (logical_size > 0) {
    for (size_t i = 0; i < logical_size; i++) {
      std::cout << "Введите arr[" << i << "]: ";
      std::cin >> arr[i];
    }
  }

  int new_numb = 1;
  while (new_numb != 0) {
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << "\n";

    std::cout << "Введите элемент для добавления: ";
    std::cin >> new_numb;

    if (new_numb != 0) {
      append_to_dynamic_array(arr, logical_size, actual_size, new_numb);
    }
  }
  std::cout << "Спасибо! Ваш массив: ";
  print_dynamic_array(arr, logical_size, actual_size);
  std::cout << "\n";

  delete[] arr;
}