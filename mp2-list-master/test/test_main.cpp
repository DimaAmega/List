#include <gtest.h>
#include <iostream>
#include "list.h"
using namespace std;
int main(int argc, char **argv) {

	
	cout << "Testsaa"<<endl;
	List a;
	a.InsertToTail(5);
	a.InsertToTail(6);
	a.InsertToTail(7);
	a.InsertToHead(12);
	cout << a;
	List b;
	b.InsertToTail(2);
	b.InsertToTail(0);
	b.InsertToTail(1);
	cout << b;
	List c = a.Merge(NULL, b);
	cout << c;


	


	
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
