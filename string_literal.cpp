#include <cstring>  // std::size_t strlen( const char* str );
#include <iostream>

// char *
void f() {
  // same as
  const char* pc = "Bonjour";
  char* p = const_cast<char*>(pc);
  // the number of characters up to and not including
  std::size_t L = std::strlen(p);

  // Attempting to modify a string literal results in undefined behavior:
  // they may be stored in read-only storage (such as .rodata)
  // or combined with other string literals:
  // p[0]=p[L-1];
  std::cout << L << '\n';
}

void g() {
  // String literals can be used to initialize character arrays.
  char str[] = "foo";  // str will contain copy of the string "foo"

  std::size_t L = std::strlen(str);
  str[0] = str[L];
  std::cout << str;
}

int main() { g(); }
