#ifndef MYOBJ_H
#define MYOBJ_H

class myobj{
private:
    int *p;
    int l;
  public:
    myobj(int);
    void show_l();
    void input();
    void output();
    void reverse();
    ~myobj();
};
#endif
