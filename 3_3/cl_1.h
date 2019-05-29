#ifndef CL_1_H
#define CL_1_H


#include "cl_base.h"

class cl_1: public cl_base{
public:
	void get_name_by_addr(string);
	static void signal_1(string &){};
	static void signal_2(string &){};
	static void signal_3(string &){};
};

#endif 
