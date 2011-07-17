using namespace std;
#include <string>
#include <set>
#include <iostream>
#include <map>

#include <bigmc.h>

void driver::check(bigraph *b) {
	if(!b || !b->get_root(0)) {
		cout << "driver::check(): NULL" << endl;
		return;
	}

	cout << "driver::check(): " << b->get_root(0)->to_string() << endl;
}