#include <stdio.h>
#include "mheap.h"
void test1()
{
	heap<int>aa;
	aa.push_back(1);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.push_back(2);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.push_back(3);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.push_back(4);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.push_back(5);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.push_back(6);
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");
	
	aa.sort();
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

	aa.make_heap();
	printf("%d %d\n", aa.size(), aa.capacity());
	for (int i = 0; i < aa.size(); i++)
		printf("%d ", aa[i]);
	printf("\n");

}
int main()
{
	test1();
	int a;

	scanf("%d", &a);
	return 1;
}