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

void remove_dynamic_array_head(int *&arr, int &logical_size, int &actual_size) {
  int new_actual_size = (actual_size / 3) > 0 ? (actual_size / 3) : 1;
  if ((logical_size - 1) <= new_actual_size) {
    actual_size = new_actual_size;
  }

  logical_size--;

  int *newArr = new int[actual_size]{};
  for (size_t i = 0; i < logical_size; i++) {
    newArr[i] = arr[i + 1];
  }
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

  std::string is_remove = "да";
  while (is_remove != "нет") {
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << "\n";

    is_remove = "";

    while (!(is_remove == "нет" || is_remove == "да")) {
      std::cout << "Удалить первый элемент? ";
      std::cin >> is_remove;
    }

    if (is_remove == "да") {
      if (logical_size == 0) {
        std::cout << "Невозможно удалить первый элемент, так как массив "
                     "пустой. До свидания!\n";
        break;
      }
      remove_dynamic_array_head(arr, logical_size, actual_size);
    } else {
      std::cout << "Спасибо! Ваш массив: ";
      print_dynamic_array(arr, logical_size, actual_size);
      std::cout << "\n";
    }
  }

  delete[] arr;
}