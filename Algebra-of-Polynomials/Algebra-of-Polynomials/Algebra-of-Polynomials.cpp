// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
#include "../libs/Functional/lib_SyntaxTree/SyntaxTree.h"

using namespace std;

int main()
{
    SyntaxTree<string, Monom> tree = SyntaxTree<string, Monom>();
    string arr[] = {"x", "y", "^", "5", "z", "*", "/", "10", "+" };
    tree.create(arr, 9);
    cout << tree.toString() << endl;
	return 0;
}
