#include "../inc/tabl.hh"


void tabn::addElemLast(int elem) {
		 numberOfElems++;   //poczatkowo 0
		 if (numberOfElems <= allocatedSize) {  //petla do zapelniania tablicy
			 	 	tab[numberOfElems-1] = elem;   // wypelnienie 10 elementami az do tab[9]
		 }
		 else {  //po przekroczeniu 10 elementow
		 	int* nowy = new int[numberOfElems];   //dynamiczne alokowanie pamieci
		 	allocatedSize++;   //powieksz o jedna komorke
		 	for (int i=0; i<=(numberOfElems-2); i++) {   //kopiowanie tablicy z dodatkowym slotem
		 		nowy[i] = tab[i];
		 	}
		 	nowy[numberOfElems-1] = elem;  //wpisanie nowego elementu
		 	delete [] tab;  ///zwolnienie pamieci po starej tablicy
		 	tab = nowy;  // podmiana wskaznikow
		 }
	}

void tabn::addElemDoubleTabl(int elem) {
		numberOfElems++;
		if (numberOfElems <= allocatedSize) {
			tab[numberOfElems-1] = elem;
		}
		else {
			int* nowy = new int[allocatedSize*2];   //zalokowanie pamieci na 2x wieksza tablice
		 	allocatedSize*=2;   // powieksz 2-krotnie
		 	for (int i=0; i<=(numberOfElems-2); i++) {
		 		nowy[i] = tab[i];
		 	}
		 	nowy[numberOfElems-1] = elem;
		 	delete [] tab;
		 	tab = nowy;
		}
}

void tabn::addElem1Tabl5 (int liczba) {
		numberOfElems++;
		if (numberOfElems <= allocatedSize) {
			tab[numberOfElems-1] = liczba;
			
		}
		else {
			int* nowy = new int[allocatedSize+(allocatedSize/2)];  //zalokowanie pamieci na tablice powiekszona o polowe
		 	allocatedSize=allocatedSize+(allocatedSize/2);   //powieksz o polowe
		 	for (int i=0; i<=(numberOfElems-2); i++) {
		 		nowy[i] = tab[i];
		 	}

		 	nowy[numberOfElems-1] = liczba;
		 	delete [] tab;
		 	tab = nowy;
		}
}

int& tabn::operator [] (int index) {
	return tab[index];
}

int tabn::operator [] (int index) const {
	return tab[index];
}

void tabn::showElems (void) {
		for (int i=0; i<numberOfElems; i++) {
			cout << tab[i] << " ";
		}
		cout << endl;
	}

int tabn::nOE(void) {
		return numberOfElems;
	}

int tabn::aSize(void) {
		return allocatedSize;
}
