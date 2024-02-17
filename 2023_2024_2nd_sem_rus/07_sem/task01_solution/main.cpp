#include <iostream>

union MyUnion {
  long longMember;
  unsigned char bytes[sizeof(long)];
};
/*
00010001
01111101
01000111
11100010*/
int main() {
  MyUnion testUnion;
  testUnion.longMember = 293423074;
  for (int i = 0; i < sizeof(long); i++) {
    std::cout << static_cast<int>(testUnion.bytes[i]) << " ";
  }
  return 0;
}