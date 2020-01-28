//Michael Glushchenko and Josh Higashi starC.cpp
//modified 1.27.20
//This program takes an input of width and height
//and prints the letter C with int width stars across
//the first and last row and int height stars in the
//far left column

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

// Write starC per specifictions in the lab writeup

string starC(int width, int height)
{
  string result = "";
  //if width is less than the minimum 2 and height
  //is less than the minimum 3, return empty string
  if (width < 2 || height < 3) {
	  return result;
  }
  // constructs C of width and height dimensions
  for (int i = 0; i < height; i++) {
	  //prints top and bottom row of stars
	  if (i == 0 || i == (height-1)){
	  	for (int k = 0; k < width; k++) {
			result += "*";
		}
		result += "\n"; //creates new line
	  }
	  //prints left column of stars
	  else {
	  	result += "*";
		for (int l = 0; l < width - 1; l++){
			result += " ";
		}
		result += "\n";
	  }
  }

  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starC34Expected =
      "***\n"
      "*  \n"
      "*  \n"
      "***\n";

  assertEquals(starC34Expected, starC(3, 4), "starC(3,4)");

  string starC53Expected =
      "*****\n"
      "*    \n"
      "*****\n";

  assertEquals(starC53Expected, starC(5, 3), "starC(5,3)");

  assertEquals("", starC(2, 1), "starC(2,1)");
  assertEquals("", starC(2, 2), "starC(2,2)");

  string starC23Expected =
      "**\n"
      "* \n"
      "**\n";

  assertEquals(starC23Expected, starC(2, 3), "starC(2,3)");
}

// Test harness
void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
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
  //If insufficient paramaters given, output error message
  if (argc != 3) {
  	cerr << "Usage: " << argv[0] << " width height\n";
	exit(1);
  }
  
  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  //runs tests if width and height are both -1
  if (width == -1 && height == -1) {
  	runTests();
	exit(1);
  }
  //Prints resulting C
  cout << starC(width, height);
  return 0;
}
