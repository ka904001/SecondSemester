#include "cl_1.h"
#include <iostream>
using namespace std;

void cl_1::get_name_by_addr(string path) {
  cout << "Object name: " << (get_object(path))->get_object_name() << endl;
}
