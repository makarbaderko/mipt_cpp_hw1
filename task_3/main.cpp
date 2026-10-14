#include <iostream>

const int cRows = 5;
const int cColumns = 10;

int StringLength(const char text[]) {
  int length = 0;
  while (text[length] != '\0') {
    length++;
  }
  return length;
}

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

bool IsOk(int x, int y, int length) {
  if (x < 0 || x >= cColumns || y < 0 || y >= cRows) {
    return false;
  }

  return x + length <= cColumns;
}

void Clear(char board[][cColumns]) {
  for (int y = 0; y < cRows; y++) {
    for (int x = 0; x < cColumns; x++) {
      board[y][x] = ' ';
    }
  }
}

bool Put(char board[][cColumns], int x, int y, char symbol) {
  if (!IsOk(x, y, 1)) {
    return false;
  }

  board[y][x] = symbol;
  return true;
}

bool Text(char board[][cColumns], int x, int y, const char word[]) {
  int length = StringLength(word);

  if (!IsOk(x, y, length)) {
    return false;
  }

  for (int i = 0; i < length; i++) {
    board[y][x + i] = word[i];
  }

  return true;
}

void Print(const char board[][cColumns]) {
  for (int y = 0; y < cRows; y++) {
    for (int x = 0; x < cColumns; x++) {
      std::cout << board[y][x];
    }

    std::cout << '\n';
  }
}

int main() {
  const int cCommandSize = 16;
  char board[cRows][cColumns];
  Clear(board);

  char command[cCommandSize];

  while (true) {
    std::cin.width(cCommandSize);
    std::cin >> command;
    if (!std::cin) {
      break;
    }

    if (StringsEqual(command, "quit")) {
      break;
    }

    if (StringsEqual(command, "clear")) {
      Clear(board);
      continue;
    }

    if (StringsEqual(command, "print")) {
      Print(board);
      continue;
    }

    if (StringsEqual(command, "put")) {
      int x;
      int y;
      char symbol;

      std::cin >> x >> y >> symbol;

      if (!Put(board, x, y, symbol)) {
        std::cout << "error\n";
      }

      continue;
    }

    if (StringsEqual(command, "text")) {
      int x;
      int y;
      char word[cColumns + 1];

      std::cin >> x >> y;
      std::cin.width(cColumns + 1);
      std::cin >> word;

      if (!Text(board, x, y, word)) {
        std::cout << "error\n";
      }
    }
  }

  return 0;
}
