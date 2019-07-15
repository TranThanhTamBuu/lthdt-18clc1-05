#include "Leaves.h"

Leaves::Leaves()
{
	pleaf = leaf;
}

Leaves::Leaves(int x, int y, int speed) : River(x, y, speed) {
	pleaf = leaf;
}


Leaves::~Leaves()
{
	pleaf = NULL;
}

