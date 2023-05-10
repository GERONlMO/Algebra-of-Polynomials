// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
#include "Polynom.h"
#include "ChainMethodTable.h"
#include "OpenShuffleTable.h"
#include "LinearListTable.h"
#include "LinearArrayTable.h"
#include "SortedArrayTable.h"

using namespace std;

int main()
{
    int powers[] = {2, 0, 2};
    Monom monom = Monom(2, 3, powers);
    monom.toString();
    cout << endl;

    string pol1 = "3.2x^2y^3z - 1.3xz^4 + 1.3xz^4";
    Polynom polynom1 = Polynom(pol1);
    cout << "Polynom1 = " << polynom1.toString() << endl;

    Polynom polynom2 = Polynom("-3.2x^2y^3z");
    cout << "Polynom2 = " << polynom2.toString() << endl;

    Polynom polynom3 = Polynom("-1.3xz^4");
    cout << "Polynom3 = " << polynom3.toString() << endl;

    cout << "Polynom1 at (1,1,1) = " << polynom1.evaluate(1,1,1) << endl;

    Polynom plusPolynom = polynom1 + polynom2;
    cout << "Polynom1 + Polynom2 = " << plusPolynom.toString() << endl;

    Polynom minusPolynom = polynom1 - polynom2;
    cout << "Polynom1 - Polynom2 = " << minusPolynom.toString() << endl;

    Polynom multPolynom = polynom1 * 10;
    cout << "Polynom1 * 10 = " << multPolynom.toString() << endl;

    Polynom multPPolynom = polynom1 * polynom3;
    cout << "Polynom1 * Polynom3 = " << multPPolynom.toString() << endl;
   /* string key = "key";
    string value = "value";
    Node<string> node = Node(key, value);
    cout << node.getKey() << " " << node.getValue() << endl;
    cout << "Test";



    ChainMethodTable<int, std::string> chainTable;

    chainTable.insert(1, "one");
    chainTable.insert(2, "two");
    chainTable.insert(3, "three");
    chainTable.insert(6, "six");
    chainTable.print();
    cout << endl << endl;

    chainTable.remove(6);
    chainTable.print();
    cout << endl << endl << endl << endl;

    OpenShuffleTable<std::string, std::string> shuffleTable;

    shuffleTable.insert("1", "one");
    shuffleTable.insert("2", "two");
    shuffleTable.insert("3", "three");
    shuffleTable.insert("6", "six");
    shuffleTable.print();
    cout << endl << endl;

    shuffleTable.remove("10");
    shuffleTable.print();
    cout << endl << endl << endl << endl;

    LinearListTable<int, std::string> linearListTable;


    LinearArrayTable<std::string, std::string> linearArrayTable;

    linearArrayTable.insert("1", "one");
    linearArrayTable.insert("2", "two");
    linearArrayTable.insert("3", "three");
    linearArrayTable.insert("6", "six");
    linearArrayTable.print();
    cout << endl << endl;
    linearArrayTable.find("4");

    cout << endl;
    linearArrayTable.print();
    cout << endl << endl << endl << endl;

    SortedArrayTable<std::string, std::string> sortedArrayTable;
    sortedArrayTable.insert("1", "one");
    sortedArrayTable.insert("6", "six");
    sortedArrayTable.insert("3", "three");
    sortedArrayTable.insert("2", "two");
    sortedArrayTable.print();

    cout << endl << endl;
    sortedArrayTable.remove("3");
    sortedArrayTable.print();

    cout << endl << endl;
    sortedArrayTable.find("4");
    sortedArrayTable.print();*/

	return 0;
}
