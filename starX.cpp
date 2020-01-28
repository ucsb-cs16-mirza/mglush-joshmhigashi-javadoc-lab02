// Michael Glushchenko and Josh Higashi
// Last modified: 1.27.20
// starX.cpp - a program that takes an input of 1 integer n and uses
// spaces ( ) and stars (*) to draw an a shape of an X, with each
// diagonal having n stars in it

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

string starX(int width)
{
  string result = "";
  // if an even number of stars is given, don't draw anything
  if (width % 2 == 0) {
	  return result;
  }

  // draw the X
  for (int i = 0; i < width; i++) {
	  for (int j = 0; j < width; j++) {
		if (i == j || width - 1 - i == j) {
			result += "*";
		} else {
			result += " ";
		}
	  }
	  result += "\n";
  }
  
  return result;
}

// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function

int main(int argc, char *argv[])
{
  // If the user doesn't enter a number when calling the function,
  // return an error
  if (argc < 2) {
	  cerr << "Usage: ./starX width" << endl;
	  exit(1);
  }

  int width = stoi(argv[1]);
  //run tests if user enters -1
  if (width == -1) {
	  runTests();
 	  exit(1);
  }

  // if the width is less than 3 ask for another input
  if (width < 3) {
	  cerr << "Enter a number n >= 3" << endl;
	  exit(1);
  }

  cout << starX(width);
 
  return 0;
}

