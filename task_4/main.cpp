#include <iostream>

int main() {
  // Решаю задачу в контексте ML и временных данных.
  // У объектов может быть разное количество временных шагов, поэтому data[i]
  // имеет свой размер. int*** хранит для каждого объекта отдельный
  // двумерный массив, где строки это временные шаги, а столбцы признаки.
  //
  // После чтения данных считаю среднее значение каждого признака по всем
  // временным шагам объекта. Так можно получить описание объекта
  // фиксированного размера, даже если число временных шагов разное.
  //
  // Таргеты могут быть int для классификации или double для регрессии,
  // их тип определяется во время выполнения, поэтому общий указатель
  // targets хранится как void* и потом приводится к нужному типу.
  //
  // Для классификации дополнительно считаю долю объектов класса 1,
  // а для регрессии среднее значение таргета.

  int count;
  int features;
  char task;

  std::cin >> count >> features >> task;

  int* steps = new int[count];
  int*** data = new int**[count];

  for (int i = 0; i < count; i++) {
    std::cin >> steps[i];

    data[i] = new int*[steps[i]];

    for (int j = 0; j < steps[i]; j++) {
      data[i][j] = new int[features];

      for (int k = 0; k < features; k++) {
        std::cin >> data[i][j][k];
      }
    }
  }

  void* targets;

  if (task == 'C') {
    targets = new int[count];
    int* labels = (int*)targets;

    for (int i = 0; i < count; i++) {
      std::cin >> labels[i];
    }
  } else {
    targets = new double[count];
    double* values = (double*)targets;

    for (int i = 0; i < count; i++) {
      std::cin >> values[i];
    }
  }

  for (int i = 0; i < count; i++) {
    std::cout << "Объект " << i << '\n';
    std::cout << "Средние значения признаков: ";

    for (int k = 0; k < features; k++) {
      double sum = 0;

      for (int j = 0; j < steps[i]; j++) {
        sum += data[i][j][k];
      }

      double average = sum / steps[i];
      std::cout << average << ' ';
    }

    std::cout << '\n';
    std::cout << "Таргет: ";

    if (task == 'C') {
      std::cout << ((int*)targets)[i];
    } else {
      std::cout << ((double*)targets)[i];
    }

    std::cout << '\n';
  }

  if (task == 'C') {
    int* labels = (int*)targets;
    int positive = 0;

    for (int i = 0; i < count; i++) {
      if (labels[i] == 1) {
        positive++;
      }
    }

    double part = (double)positive / count;

    std::cout << "Доля объектов класса 1: " << part << '\n';

    delete[] labels;
  } else {
    double* values = (double*)targets;
    double sum = 0;

    for (int i = 0; i < count; i++) {
      sum += values[i];
    }

    double average_target = sum / count;

    std::cout << "Среднее значение таргета: " << average_target << '\n';

    delete[] values;
  }

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < steps[i]; j++) {
      delete[] data[i][j];
    }

    delete[] data[i];
  }

  delete[] data;
  delete[] steps;

  return 0;
}