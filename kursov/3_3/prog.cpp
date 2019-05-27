#include "cl_application.h"
#include "cl_base.h"

int main() {
  cl_application app;
  app.build_tree_objects();
  app.exec_app();
  return 0;
}
