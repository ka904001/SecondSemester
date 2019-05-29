#include "cl_application.h"
#include <iostream>
#include <string>
using namespace std;

cl_application::cl_application() { set_object_name("root"); }

void cl_application::initial_output() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      get_stream() << '8';
      if (j != 9)
        get_stream() << ' ';
    }
    if (i != 9)
      get_stream() << endl;
  }
}

void cl_application::bild_tree_objects() {
  p_ob_position = new cl_pos;
  p_ob_position->set_object_name("ob_position");
  p_ob_position->set_parent(this);

  p_ob_write = new cl_write;
  p_ob_write->set_object_name("ob_write");
  p_ob_write->set_parent(this);

  p_ob_console = new cl_con;
  p_ob_console->set_object_name("ob_console");
  p_ob_console->set_parent(this);
}

int cl_application::exec_app() {
  set_stream();
  initial_output();
  int a, b;
  char c;
  cin >> a >> b >> c;

  p_ob_position->set_connect(SIGNAL_D(p_ob_position->position_secure),
                             p_ob_write,
                             HENDLER_D(p_ob_write->hendler_pos_secure));
  while (a != 0 && b != 0) {
    p_ob_position->work_position(a, b, c);
    cin >> a >> b >> c;
  }
  p_ob_console->out_to_console();
  return 0;
}
