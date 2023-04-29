// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
#include "Polynom.h"
#include "ChainMethodTable.h"
#include "OpenShuffleTable.h"
#include "LinearListTable.h"

using namespace std;

int main()
{
    int powers[] = {2, 0, 2};
    Monom monom = Monom(2, 3, powers);
    monom.toString();
    cout << endl;

    string key = "key";
    string value = "value";
    Node<string> node = Node(key, value);
    cout << node.getKey() << " " << node.getValue() << endl;

    string pol1 = "3.2x^2y^3z - 1.3xz^4";
    Polynom polynom1 = Polynom(pol1);
    polynom1.toString();
    cout << endl << endl;

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



	return 0;
}
