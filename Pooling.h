#include "common.h"

class Pooling
{
 public:
	Pooling();
	~Pooling();
		
 private:	
	string function;
	int pool_width;
	int pool_height;
	int pool_step;
};
