#ifndef SPLAYTREE_H_
#define SPLAYTREE_H_

#include <iostream>

class splaytree{

	int _d;
	splaytree* _l;
	splaytree* _r;
	splaytree* _p;

	enum child{
		left,
		right
	};

public:
	splaytree();
	splaytree(int d);

	splaytree* insert(splaytree* v);
	splaytree* splay(splaytree* v);
	void print();
	void d(){std::cout << _d << " ";}
	void add(child c, splaytree* child);

	splaytree* l_zig(splaytree* v);
	splaytree* l_zigzig(splaytree* v);
	splaytree* l_zigzag(splaytree* v);

	splaytree* r_zig(splaytree* v);
	splaytree* r_zigzig(splaytree* v);
	splaytree* r_zigzag(splaytree* v);
	void take_care_of_great_grand_parents(splaytree* g, splaytree* gg, splaytree* x);
};

#endif
