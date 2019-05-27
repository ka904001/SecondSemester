#include "cl_application.h"

cl_application::cl_application() { set_object_name("root"); }
void cl_application::build_tree_objects() {
  p_ob_1 = new cl_1;
  p_ob_1->set_object_name("ob_1");
  p_ob_1->set_parent(this);

  p_ob_2 = new cl_2;
  p_ob_2->set_object_name("ob_2");
  p_ob_2->set_parent(p_ob_1);

  p_ob_3 = new cl_3;
  p_ob_3->set_object_name("ob_3");
  p_ob_3->set_parent(p_ob_2);

  p_ob_4 = new cl_4;
  p_ob_4->set_object_name("ob_4");
  p_ob_4->set_parent(p_ob_2);

  p_ob_5 = new cl_2;
  p_ob_5->set_object_name("ob_5");
  p_ob_5->set_parent(p_ob_1);

  p_ob_1 = new cl_1;
  p_ob_1->set_object_name("ob_6");
  p_ob_1->set_parent(this);

  p_ob_2 = new cl_2;
  p_ob_2->set_object_name("ob_7");
  p_ob_2->set_parent(this);

  p_ob_3 = new cl_3;
  p_ob_3->set_object_name("ob_8");
  p_ob_3->set_parent(p_ob_2);
}
int cl_application::exec_app() {
  // output from other lab
  string command;
  p_ob_1->set_connect(SIGNAL_D(p_ob_1->signal_1), p_ob_5,
                      HENDLER_D(p_ob_5->hendler_1));
  p_ob_1->set_connect(SIGNAL_D(p_ob_1->signal_2), p_ob_5,
                      HENDLER_D(p_ob_5->hendler_2));
  p_ob_1->set_connect(SIGNAL_D(p_ob_1->signal_2), p_ob_3,
                      HENDLER_D(p_ob_3->hendler_1));
  int choice = 0;
  do {
    cin >> choice;
    switch (choice) {
    case 1:
      cin >> command;
      p_ob_1->emit_signal(SIGNAL_D(p_ob_1->signal_1), command);
      break;
    case 2:
      cin >> command;
      p_ob_1->emit_signal(SIGNAL_D(p_ob_1->signal_2), command);
      break;
    case 3:
      cin >> command;
      p_ob_1->emit_signal(SIGNAL_D(p_ob_1->signal_3), command);
      break;
    default:
      break;
    }
  } while (choice != 0);
  return 0;
}
