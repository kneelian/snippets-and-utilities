#include "types.hpp"
#include <cstdio>

int main()
{
	/*
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
	*/

	/*
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
	*/

	unode x, y, z;
	x.add_child(&y); x.add_child(&z);
	y.add_child(&z); y.add_child(&x);
	z.add_child(&x);
	x.set(5); y.set(10); z.set(15);
	unode childless; z.add_child(&childless);

	unode orphan;

	printf("children of x(%d): ", x.data);
	for(auto i: x.children)
	{
		printf("%d ", i->data);
	}
	printf("\n");

	printf("grandchildren of x(%d): ", x.data);
	for(auto i: x.children)
	{
		printf(" from (%d): ",  i->data);
		for(auto j: i->children)
		{
			printf("%d ", j->data);
		}
	} printf("\n");

	unode f, g, h;
	f.add_child(&g); f.add_child(&h); g.add_child(&h);

	printf("x and y are%s connected\n", connected(&x,&y)?"":"n't");
	printf("z and c are%s connected\n", connected(&z,&childless)?"":"n't");
	printf("h and f are%s connected\n", connected(&h,&f)?"":"n't");
	printf("g and o are%s connected\n", connected(&g,&orphan)?"":"n't");
	printf("g and x are%s connected\n", connected(&g,&x)?"":"n't");
	printf("x %s a loop\n", x.loops()?"forms":"doesn't form");
	printf("h %s a loop\n", h.loops()?"forms":"doesn't form");
	printf("\n");
	return 0;
}