#ifndef OBJ_H
#define OBJ_H

class first;
class second;
class first {
  friend void maxint(first &, second &);

private:
  int a = 0;

public:
  first(int);
};

class second {
  friend void maxint(first &, second &);

private:
  int b = 0, c = 0;

public:
  void input();
};

#endif
