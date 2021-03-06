#include <iostream>
#include "../inc/main.hh"
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>
#define SIZE 10
#define ROZMIAR 20

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

void NaprawKopiec(tabn &tab,int i, int n)
{
    int l=2*i, p=2*i+1;
    int wiekszy;
    if(l<n&&tab[l]>tab[i])
        wiekszy=l;
    else
        wiekszy=i;
    if(p<n&&tab[p]>tab[wiekszy])
        wiekszy=p;
    if(wiekszy!=i)
    {
        int temp=tab[i];
        tab[i]=tab[wiekszy];
        tab[wiekszy]=temp;
        NaprawKopiec(tab,wiekszy,n);
    }
}
void StworzKopiec(tabn &tab, int n)
{
    for(int i=(n-1)/2;i>=0;i--)
        NaprawKopiec(tab,i,n);
}


void SortowaniePrzezKopcowanie(tabn &tab, int n)
{
    StworzKopiec(tab,n);
    for(int i=n-1;i>=0;i--)
    {
        int temp=tab[1];
        tab[1]=tab[i];
        tab[i]=temp;
        NaprawKopiec(tab,1,i);
    }
}

/*void merge(int pocz, int sr, int kon, tabn &tab) {
  int i,j,q;
  int T[tab.nOE()];
  for (i=pocz; i<=kon; i++)
    T[i] = tab[i];

*/

int main (void) {
  struct timeval t1, t2;
 double elapsedTime;
 srand (time(NULL));
 gettimeofday(&t1, NULL); //time start

 tabn tablica;
 for(int i=0; i<ROZMIAR; i++)
   {
     tablica.addElemDoubleTabl(rand()%10);
   }
 tablica.showElems();

 SortowaniePrzezKopcowanie(tablica, tablica.nOE());

 
 cout <<"\n\n\n";
 tablica.showElems();






 
 
 //tabn tablica_dynamiczna;
 
 
 
 
 /*for(int i=0;i<+20;i++)
  {
    
    //cout<<"przerwa  "<<i<<endl;
//cout<<endl;
    tablica_dynamiczna.addElemLast(5);
    
    //tablica_dynamiczna.addElemDoubleTabl(liczba);
    //tablica_dynamiczna.addElem1Tabl5(liczba);
  }
 tablica_dynamiczna[10]=8;
 tablica_dynamiczna.showElems();
 gettimeofday(&t2, NULL);
 elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
 elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
 cout<<tablica_dynamiczna.nOE()<<endl;
 cout<<elapsedTime<<"ms."<<endl;*/

}
