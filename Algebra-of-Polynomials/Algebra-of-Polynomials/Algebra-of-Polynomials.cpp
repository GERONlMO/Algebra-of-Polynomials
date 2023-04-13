// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
#include "SyntaxTree.h"

using namespace std;

int main()
{
    int powers[] = {2, 2, 2};
    Monom monom = Monom(2, 3, powers);
    monom.toString();

    string key = "key";
    string value = "value";
    Node<string> node = Node(key, value);
    cout << node.getKey() << " " << node.getValue() << endl;


    string arr[] = {"x", "y", "^", "5", "z", "*", "/", "10", "+" };
    SyntaxTree<string, Monom> tree;
    tree.create(arr, 9);
    cout << tree.toString() << endl;
	return 0;
}
