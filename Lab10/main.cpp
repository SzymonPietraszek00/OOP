//Celem zadania jest przećwiczenie podstawowych algorytmów STL. Proszę stworzyć klasę reprezentującą tablicę danych, którą można sortować na różne sposoby.

//Zadanie należy wykonać bez żadnych tradycyjnych pętli (nawet w print), lecz z użyciem algorytmów STL. Użycie w kodzie pętli (for, while, do-while) skutkuje niezaliczeniem zadania.

//Tips:
//- wypisanie równej liczby znaków: std::cout << std::setw(liczba) -- nagłówek iomanip
//- może się przydać namespace std::placeholders
//- można korzystać z dokumentacji na stronie https://en.cppreference.com/w/ (tylko dokumentacja, bez tutoriali!)

#include "include/Sum.h"
#include "include/Product.h"
#include "include/Table.h"
#include <iostream>

bool greaterSum(const Product& p1, const Product& p2){
	return sumData(p1).value() < sumData(p2).value();
}

int main(){
	const Product p1("Produkt 1", {1.5, 2, -3.2});
	p1.print();

	Sum suma = sumData(p1);
	std::cout << "suma dla produktu 1: " << suma.value() << std::endl;
	suma(2); // to pokazuje co robi Sum
	std::cout << "suma dla produktu 1 po dodaniu 2: " << suma.value() << std::endl;

	std::cout << "   ============= Tablica =============" << std::endl;
 	Table table;
	table += p1;
	table += Product("Produkt 2", {3, 2.5, 13, 2});
	table += Product("Produkt 3", {1, -12.5, 1.3, 1.5, 12.3});
  table += Product("Produkt 4", {1, -12.5});
	std::cout << "min row length: " << table.minRow << std::endl;

	table.print();
	std::cout << "======= sortowanie po kolumnie 3 =======" << std::endl;
	table.sort(2).print(); 

	std::cout << "======= sortowanie po kolumnie 2 =======" << std::endl;
	table.sort(1).print(); 

	table.sort(3); // uwaga, tutaj niedozwolony indeks 
	std::cout << "========= sortowanie po sumach =========" << std::endl;
	table.sortBy(greaterSum).print(); // sortowanie po zsumowanych kolumnach, rosnąco
}

/* //OUTPUT:
Produkt 1:    1.5     2  -3.2
suma dla produktu 1: 0.3
suma dla produktu 1 po dodaniu 2: 2.3
   ============= Tablica =============
min row length: 2
Produkt 1:    1.5     2  -3.2
Produkt 2:      3   2.5    13     2
Produkt 3:      1 -12.5   1.3   1.5  12.3
Produkt 4:      1 -12.5

======= sortowanie po kolumnie 3 =======
Indeks 2 nieprawidlowy! 
Produkt 1:    1.5     2  -3.2
Produkt 2:      3   2.5    13     2
Produkt 3:      1 -12.5   1.3   1.5  12.3
Produkt 4:      1 -12.5

======= sortowanie po kolumnie 2 =======
Produkt 3:      1 -12.5   1.3   1.5  12.3
Produkt 4:      1 -12.5
Produkt 1:    1.5     2  -3.2
Produkt 2:      3   2.5    13     2

Indeks 3 nieprawidlowy! 
========= sortowanie po sumach =========
Produkt 4:      1 -12.5
Produkt 1:    1.5     2  -3.2
Produkt 3:      1 -12.5   1.3   1.5  12.3
Produkt 2:      3   2.5    13     2

*/
