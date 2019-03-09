#ifndef MYOBJ_H
#define MYOBJ_H

class myobj{
  public:
    int *p;
    int l;
    myobj(int);
    void show_l();
    void input();
    void output();
    void reverse();
    ~myobj();
};
#endif
