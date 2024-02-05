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
	} printf("\n");

	d_list e; e.set(15);
	d_list f; f.set(20); e.add_child(&f); f.add_parent(&e);
	d_list g; g.set(30); f.add_child(&g); g.add_parent(&f);
	d_list h; h.set(50); g.add_child(&h); h.add_parent(&g);
	h.add_child(&e); e.add_parent(&h);

	d_list tempb = e;

	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", tempb.data);
		tempb = *tempb.next;
	} printf("and then: ");
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", tempb.data);
		tempb = *tempb.prev;
	} printf("\n");

	return 0;
}