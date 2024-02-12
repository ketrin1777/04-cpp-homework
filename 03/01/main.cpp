#include <iostream>

void print_sort(int *arr, int size)
{
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      std::cout << arr[i] << " ";
    }
  }
}

void count_sort(int *arr, int size)
{
  // Мин 10; макс 24; смещаем на -10 (0 - 14) количество 15
  int counts[15]{};
  for (size_t i = 0; i < size; i++)
  {
    counts[arr[i] - 10]++;
  }

  int indx = 0;

  for (size_t i = 0; i < size; i++)
  {
    // Если в счетчике 0 то переходим на следующий
    while (counts[indx] == 0)
    {
      indx++;
    }
    arr[i] = indx + 10;
    counts[indx] -= 1;
  }
}

int main()
{
  int arr1[30] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17,
                  20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
  int size1 = 30;

  std::cout << "Исходный массив: ";
  print_sort(arr1, size1);
  std::cout << "\n";

  count_sort(arr1, size1);

  std::cout << "Отсортированный массив: ";
  print_sort(arr1, size1);
  std::cout << "\n\n";

  int arr2[40] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22,
                  21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17,
                  11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
  int size2 = 40;

  std::cout << "Исходный массив: ";
  print_sort(arr2, size2);
  std::cout << "\n";

  count_sort(arr2, size2);

  std::cout << "Отсортированный массив: ";
  print_sort(arr2, size2);
  std::cout << "\n\n";

  int arr3[45] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21,
                  18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22,
                  19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
  int size3 = 45;

  std::cout << "Исходный массив: ";
  print_sort(arr3, size3);
  std::cout << "\n";

  count_sort(arr3, size3);

  std::cout << "Отсортированный массив: ";
  print_sort(arr3, size3);
  std::cout << "\n\n";
}