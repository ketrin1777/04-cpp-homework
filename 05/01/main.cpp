#include <iostream>

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

int main() {
  long size = 10;
  long *arr = new long[size]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
  std::cout << "Исходный массив: ";
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n\nПирамида:\n";

  print_pyramid(arr, size);

  delete[] arr;
}