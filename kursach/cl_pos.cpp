#include "cl_pos.h"

void cl_pos::work_position(int &a, int &b, char &c) {
  if ((a > 0 && a < 11) && (b > 0 && b < 11)) {
    ((get_root())->get_stream())
        .seekp(2 * (b - 1) + 20 * (a - 1), ios_base::beg);
    emit_signal(SIGNAL_D(position_secure), c);
  } else {
    ((get_root())->get_stream()).seekp(0, ios_base::end);
    ((get_root())->get_stream())
        << endl
        << "Coordinate is wrong (" << a << ',' << b << ')';
  }
}
