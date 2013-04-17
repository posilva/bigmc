/*******************************************************************************
*
* Copyright (C) 2011 Gian Perrone (http://itu.dk/~gdpe)
* 
* BigMC - A bigraphical model checker (http://bigraph.org/bigmc).
* 
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
* USA.
*********************************************************************************/
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

	mc *m = new mc(b);

	m->check();
	
	delete m;

	query_predicate::cleanup();

	exit(0);
}

void driver::check_function(bigraph *b,results_map& results ) {
  if(!b || !b->get_root(0)) {
    cout << "driver::check(): NULL" << endl;
    return;
  }

  mc *m = new mc(b);
  m->setResults(&results);

  m->check();

  delete m;

  query_predicate::cleanup();
  if(global_cfg.function_mode)
    return;
  else
  exit(0);
}
