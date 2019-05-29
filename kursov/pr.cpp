#include <fstream>
#include <iostream>
using namespace std;

int main() {
  fstream file;
  file.open("out.txt", ios_base::out);
  file << "12345678910123456789012345678901234567890";
  file.seekp(0, ios_base::beg);
  file << "%";
}
