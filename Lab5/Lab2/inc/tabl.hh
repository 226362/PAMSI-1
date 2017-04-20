#ifndef _TABL_HH
#define _TABL_HH
#include <iostream>

#define SIZE 10

using namespace std;



class tabn {
private:
	int* tab;
	int allocatedSize;
	int numberOfElems;
public:
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new int[SIZE];
	}
	~tabn() {
		delete [] tab;
	}

	void addElemLast(int);
	void addElemDoubleTabl(int);
	void addElem1Tabl5(int);
	void showElems(void);
	int nOE(void);
	int aSize(void);
	int operator [] (int) const;
	int& operator [] (int);

};
#endif
