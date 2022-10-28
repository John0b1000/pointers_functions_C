// file: functions_and_pointers/example.cc
//
// This program demonstrates various ways to pass arguments into a function.

// include files
//
#include "example.h"

// main program
//
int main(int argc, char** argv) {

  // using values
  //
  fprintf(stdout, "values ---->\n");

  // call by value: x does not change in the main program
  // From Kernighan and Ritchie (1988), 
  // "Since C passes arguments to functions by value, there is no direct way for 
  // the called function to alter a variable in the calling function ... 
  // The way to obtain the desired is for the calling program to pass pointers to the
  // values to be changed."
  //
  float x00_before = 27.0;
  float x00_after = x00_before;
  myfunct_00(x00_after);
  fprintf(stdout, "Calling by value ...");
  fprintf(stdout, "x = %f (before) %f (after)\n", x00_before, x00_after);
    
  // call by pointer: x changes value
  // 
  //
  float x01_before = 27.0;
  float x01_after = x01_before;
  myfunct_01(&x01_after); // here the & operator creates a pointer to x01_after
  fprintf(stdout, "x = %f (before) %f (after)\n", x01_before, x01_after);
    
  // call by reference: x changes value
  // note: looks like call by value, but because of the way the function
  // is declared, a reference to x is passed.
  //
  float x02_before = 27.0;
  float x02_after = x02_before;
  myfunct_02(x02_after);
  fprintf(stdout, "x = %f (before) %f (after)\n", x02_before, x02_after);
    
  // using pointers
  //
  fprintf(stdout, "pointers ---->\n");

  // memory allocation: call by value
  // note: this doesn't work because the space allocated in the function
  // is lost because the argument's value is not changed in the main program.
  //
  /*
  float x03 = -99.99;
  float* x03_before = &x03;
  float* x03_after;
  myfunct_03(x03_after);
  fprintf(stdout, "x = (loc: %u) %f (before) | (loc: %u) %f (after)\n",
	  x03_before, x03_before[0], x03_after, x03_after[0]);
    */

  // memory allocation: call by pointer
  //
  float x04 = -99.99;
  float* x04_before = &x04;
  float* x04_after;
  myfunct_04(&x04_after);
  fprintf(stdout, "x = (loc: %u) %f (before) | (loc: %u) %f (after)\n",
	  x04_before, x04_before[0], x04_after, x04_after[0]);

  // memory allocation: call by reference
  //
  float x05 = -99.99;
  float* x05_before = &x05;
  float* x05_after;
  myfunct_05(x05_after);
  fprintf(stdout, "x = (loc: %u) %f (before) | (loc: %u) %f (after)\n",
	  x05_before, x05_before[0], x05_after, x05_after[0]);

  // exit gracefully
  //
  return 0;
}

// --- functions are here ---//

void myfunct_00(float x) {
  x = (float)-1.0;
}

void myfunct_01(float* x) {
  *x = (float)-1.0; // the * operator dereferences the pointer x
}

void myfunct_02(float& x) {
  x = (float)-1.0;
}

void myfunct_03(float* x) {
  x = new float[10];
  x[0] = 27.0;
}

void myfunct_04(float** x) {
  *x = new float[10];
  *x[0] = 27.0;
}

void myfunct_05(float*& x) {
  x = new float[10];
  x[0] = 27.0;
}
