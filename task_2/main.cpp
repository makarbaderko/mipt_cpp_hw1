#include <iostream>

bool StringsEqual(const char first[], const char second[]) {
  int i = 0;

  while (first[i] != '\0' && second[i] != '\0') {
    if (first[i] != second[i]) {
      return false;
    }

    i++;
  }

  return first[i] == second[i];
}

void Deposit(long long& sum) {
  long long k;
  std::cin >> k;

  if (k <= 0) {
    std::cout << "error\n";
    return;
  }

  sum += k;
}

void Withdraw(long long& sum) {
  long long k;
  std::cin >> k;

  if (k <= 0 || k > sum) {
    std::cout << "error\n";
    return;
  }

  sum -= k;
}

void Balance(long long& sum) { std::cout << sum << '\n'; }

void Reset(long long& sum) { sum = 0; }

void Inc(long long& sum) { sum++; }

struct Command {
  const char* name;
  void (*function)(long long&);
};

int main() {
  const int cComSize = 16;

  Command commands[] = {
      {"deposit", Deposit}, {"withdraw", Withdraw}, {"balance", Balance},
      {"reset", Reset},     {"inc", Inc},
  };
  const int cComCount = sizeof(commands) / sizeof(commands[0]);

  long long sum = 0;
  char command[cComSize];

  while (true) {
    std::cin.width(cComSize);
    std::cin >> command;

    if (!std::cin) {
      break;
    }

    if (StringsEqual(command, "stop")) {
      break;
    }

    int command_index = 0;

    while (command_index < cComCount &&
           !StringsEqual(command, commands[command_index].name)) {
      command_index++;
    }

    if (command_index < cComCount) {
      commands[command_index].function(sum);
    } else {
      std::cout << "error\n";

      char c;
      while (std::cin.get(c) && c != '\n') {
      }
    }
  }

  return 0;
}
