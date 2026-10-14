#include <iomanip>
#include <iostream>

struct MinMax {
  int min;
  int max;
};

double Average(const int* arr, int n) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return ((double)sum) / n;
}

MinMax FindBoundaries(const int* arr, int n) {
  int min_value = arr[0];
  int max_value = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    }
    if (arr[i] > max_value) {
      max_value = arr[i];
    }
  }

  return {min_value, max_value};
}

int CountFrostyDays(const int* arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      count++;
    }
  }
  return count;
}

int main() {
  std::cout << std::fixed << std::setprecision(1);
  int n;
  std::cin >> n;

  int* temperature = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> temperature[i];
  }

  std::cout << Average(temperature, n) << "\n";
  MinMax min_max = FindBoundaries(temperature, n);
  std::cout << min_max.min << " " << min_max.max << "\n";
  std::cout << CountFrostyDays(temperature, n) << "\n";
  delete[] temperature;
  return 0;
}
