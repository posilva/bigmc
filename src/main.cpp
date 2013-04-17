using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <set>

#include <stdlib.h>
#include <string.h>
#include <bigmc.h>



/* getopt */
#ifdef _WIN32
#include <wingetopt.h>
#else
#include <unistd.h>
#endif

void
print_usage(char **argv)
{
  fprintf(stderr, "Usage: %s [options] <modelfile>\n"
          "  Options:\n"
          "\t-h\tDisplay this help and exit\n"
          "\t-V\tPrint verbose output\n"
          "\t-VV\tPrint even more verbose output\n"
          "\t-t n\tStart n concurrent checker threads (default: 2)\n"
          "\t-G x\tOutput graphviz dot file to x\n"
          "\t-A\tReport the the results of static analysis and then exit.\n"
          "\t-m x\tSpecify x maximum steps of graph unfolding (default: 1000)\n"
          "\t-p\tPrint new states as they are discovered.\n"
          "\t-l\tLocal check mode - do not build the reaction graph.\n"
          "\t-r x\tOutput statistics and graphs every x steps (default: 500)\n"
          "\t-v\tPrint version information and exit\n",
          argv[0]);
}

void
print_version()
{
  cout << "BigMC version " << "" << " (http://bigraph.org/bigmc)\n";
  cout << "Copyright (c) 2011 Gian Perrone <gdpe at itu.dk>\n";
}

int
main(int argc, char**argv)
{
  std::ifstream ifs("airport.bmg");
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));
  cout << functions::get_next_step(content) << "\n";
  return 0;
}
