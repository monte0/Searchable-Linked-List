#include <iostream>
#include "slist.h"
#include <stdlib.h>

using namespace std;

//PURPOSE: Testing search and replace functions
void testOne()
{
	slist L;	  // the list 
	int foundPos; // to hold the found position from Search  
	int counter = 1; // used to display test line number
	try
	{
		//  1)add to front once (element 4)
		cout << "Step " << counter << endl;
		counter++;
		L.addFront(4);

		//  2)add to rear 3 times (elements 6,7,8)
		cout << "Step " << counter << endl;
		counter++;
		L.addRear(6);
		L.addRear(7);
		L.addRear(8);

		//  3)displayAll    - 4 6 7 8
		cout << "Step " << counter << endl;
		counter++;
		L.displayAll();

		//  4)search for 6, report the result  - found in pos 2
		cout << "Step " << counter << endl;
		counter++;
		foundPos = L.search(6);
		cout << "Found 6 in location " << foundPos << endl;

		//  5)replace the 6 with 0 using the search result (foundPos)
		cout << "Step " << counter << endl;
		counter++;
		L.replace(0, foundPos);

		// 6)displayAll - 4 0 7 8
		cout << "Step " << counter << endl;
		counter++;
		L.displayAll();

		// 7)search for 8 and report the result - found in pos 4
		cout << "Step " << counter << endl;
		counter++;
		foundPos = L.search(8);
		cout << "Found 8 in location " << foundPos << endl;

		// 8)replace the 8 with 2 using the search result (foundPos)
		cout << "Step " << counter << endl;
		counter++;
		L.replace(2, foundPos);

		// 9)displayAll                       - 4 0 7 2
		cout << "Step " << counter << endl;
		counter++;
		L.displayAll();

		// 10)search for 5 and report the result   - not found
		cout << "Step " << counter << endl;
		counter++;
		foundPos = L.search(5);
		if (foundPos == 0)
			cout << "not found." << endl;

		// 11) replace postion 7 with 10
		cout << "Step " << counter << endl;
		counter++;
		L.replace(7, foundPos);

	}//end of try
	catch (llist::OutOfRange)
	{
		cout << "ERROR: Bad position was given" << endl;
	}

}//end of testOne

// PURPOSE: Testing overloading of ==
void testTwo()
{
	//1. L1 is empty and L2 is empty 
	slist L1, L2;
	cout << "Step 1: ";
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//2. L1 is empty and L2 with 4, 5 
	cout << "Step 2: ";
	L2.addRear(4);
	L2.addRear(5);
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//3.  The opposite 
	cout << "Step 3: ";
	if (L2 == L1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//4. L1 with 1,2,3 and L2 with  1,2,3
	cout << "Step 4: ";
	L1.addRear(1);
	L1.addRear(2);
	L1.addRear(3);
	int x;
	L2.deleteFront(x);
	L2.deleteFront(x);
	L2.addRear(1);
	L2.addRear(2);
	L2.addRear(3);
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//5. L1 with 1,2,3 and L2 with  1,2
	cout << "Step 5: ";
	L2.deleteRear(x);
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//6. L1 has 1,2,3 and L2 has 1,2,3,4
	cout << "Step 6: ";
	L2.addRear(4);
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//7. L1 has 1,2,3 and L2 has 1,2,4
	cout << "Step 7: ";
	L2.deleteRear(x);
	L2.deleteRear(x);
	L2.addRear(4);
	if (L1 == L2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

}//end of testTwo


//PURPOSE: to test slist thoroughly
int main()
{
	testOne(); // for search and replace

	cout << "---- First Part testing done ----- " << endl;

	testTwo();  // for testing ==

}// end of program