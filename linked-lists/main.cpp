#include "types.hpp"
#include <cstdio>

int main()
{
	s_list a; a.set(15);
	s_list b; b.set(20); a.add_child(&b);
	s_list c; c.set(30); b.add_child(&c);
	s_list d; d.set(50); c.add_child(&d);
	d.add_child(&a);

	s_list temp = a;

	for(int i = 0; i < 20; i++)
	{
		printf("%d ", temp.data);
		temp = *temp.next;
	}

	return 0;
}