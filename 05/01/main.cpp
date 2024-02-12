#include <cmath>
#include <iostream>
#include <string>

void print_element(long *arr, long size, long root_index, long level_pyr) {
  long left_index = (2 * root_index) + 1;
  long rigt_index = (2 * root_index) + 2;
  if (left_index < size) {
    std::cout << level_pyr << " lef(" << arr[root_index] << ") "
              << arr[left_index] << std::endl;
  }
  if (rigt_index < size) {
    std::cout << level_pyr << " right(" << arr[root_index] << ") "
              << arr[rigt_index] << std::endl;
  }
}

void print_pyramid(long *arr, long size) {
  long level_pyr = 1;
  long root_index = 0;

  if (size > root_index) {
    std::cout << root_index << " root " << arr[root_index] << std::endl;

    print_element(arr, size, root_index, level_pyr);
    root_index++;

    long long size_level = 3;

    while (root_index < size) {
      level_pyr++;

      while (root_index < size_level) {
        print_element(arr, size, root_index, level_pyr);
        root_index++;
      }
      size_level = (root_index * root_index) + root_index;
    }
  }
}

// Получаем левый дочерний
bool get_left(long *arr, long size, long &index, std::string &position_name) {
  long new_indx = (2 * index) + 1;
  if (new_indx < size) {
    position_name = "left(" + std::to_string(arr[index]) + ")";
    index = new_indx;
    return true;
  }

  return false;
}

// Получаем правый дочерний
bool get_right(long *arr, long size, long &index, std::string &position_name) {
  long new_indx = (2 * index) + 2;
  if (new_indx < size) {
    position_name = "right(" + std::to_string(arr[index]) + ")";
    index = new_indx;
    return true;
  }

  return false;
}

// Получаем правый дочерний
bool get_up(long *arr, long size, long &index, std::string &position_name) {
  double d_indx = (static_cast<double>(index) - 1) / 2;
  long new_indx = floor(d_indx);
  if (new_indx == 0) {
    position_name = "root";
    index = new_indx;
    return true;
  } else if (new_indx > 0) {
    // Находим еще один родитель
    d_indx = (static_cast<double>(new_indx) - 1) / 2;

    // Проверяем левый потомок
    long old_inx = floor(d_indx);
    if (get_left(arr, size, old_inx, position_name) && old_inx == new_indx) {
      index = new_indx;
      return true;
    }

    // Проверяем правый потомок
    old_inx = floor(d_indx);
    if (get_right(arr, size, old_inx, position_name) && old_inx == new_indx) {
      index = new_indx;
      return true;
    }

    return false;
  }

  return false;
}

int main() {

  long size = 10;
  long *arr = new long[size]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
  std::cout << "Исходный массив: ";
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n\nПирамида:\n";

  print_pyramid(arr, size);

  long position_index = 0; // Текущая позиция в перамиде
  std::string position_name = "root";
  long level_pyr = 0;
  std::string command;
  while (command != "exit") {
    std::cout << "Вы находитесь здесь: ";
    std::cout << level_pyr << " " << position_name << " " << arr[position_index]
              << std::endl;

    std::cout << "Введите команду: ";
    std::cin >> command;

    if (command == "left") {
      if (get_left(arr, size, position_index, position_name)) {
        std::cout << "Ок" << std::endl;
        level_pyr++;
      } else {
        std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
      }
    } else if (command == "right") {
      if (get_right(arr, size, position_index, position_name)) {
        std::cout << "Ок" << std::endl;
        level_pyr++;
      } else {
        std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
      }
    } else if (command == "up") {
      if (get_up(arr, size, position_index, position_name)) {
        std::cout << "Ок" << std::endl;
        level_pyr--;
      } else {
        std::cout << "Ошибка! Отсутствует родитель" << std::endl;
      }
    }
  }

  delete[] arr;
}
