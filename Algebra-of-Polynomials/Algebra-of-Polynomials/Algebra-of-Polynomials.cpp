// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
//#include "SyntaxTree.h"
#include "Polynom.h"

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

    string pol = "3.2x^2y^3z - 1.3xz^4 + 1.3xz^4";
    Polynom polynom1 = Polynom(pol);
    polynom1.toString();
    cout << endl;

    Polynom polynom2 = polynom1;
    polynom2.toString();
    cout << endl;
	return 0;
}
