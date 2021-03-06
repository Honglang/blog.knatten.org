#include "c.h"
#include "lib.h"
#include "lib2.h"

#include <iostream>
#include <vector>

using namespace std;

int copies = 0;
int ctors = 0;

void print_copies(const string& action) {
	cout << action << " used " << copies << " copies, " << ctors << " constructors." << endl;
	copies = ctors = 0;
}

int main() {
	C c1;
	print_copies("1: Constructing");
	C c2(c1);
	print_copies("2: Copy constructing");
	C c4 = getTemporaryC();
	print_copies("3: Returning a temporary");
	C c5 = getLocalC();
	print_copies("4: Returning a local");
	C c6 = getDelegatedC();
	print_copies("5: Returning through a delegate");
	vector<C> v = getVectorOfC();
	print_copies("6: Returning a local vector");
}

void doSomethingWith(const vector<C>& objs) {}
void getObjects(vector<C>& objs) {}
vector<C> getObjects() {return vector<C>();}

void example() {
	doSomethingWith(getObjects());

	vector<C> temp;
	getObjects(temp);
	doSomethingWith(temp);

}

