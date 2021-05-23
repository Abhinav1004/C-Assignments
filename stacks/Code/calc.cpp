// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o calc calc.cpp; ./calc < calc_test1.in

#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply 
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero {};
class badInput {};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/*******************************************************
 * INSTRUCTOR NOTE: Implement the functions below.     *
 * You may throw exception classes emptyList, divZero, *
 * or badInput from these functions as needed.         *
 ******************************************************/

// EFFECTS: performs + operation
void DoAdd(Dlist<double> &stack) {
  // Implement this function.
  if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    
    double b = stack.RemoveFront();
    double result = a + b;
    stack.InsertFront(result);
    return;
}

// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack) {
  // Implement this function.
  if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    double b = stack.RemoveFront();
    double result = b - a;
    stack.InsertFront(result);
    return;
}

// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack) {
  // Implement this function.
  if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    double b = stack.RemoveFront();
    double result = a * b;
    stack.InsertFront(result);
    return;
}

// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack) {
  // Implement this function.
  if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    double b = stack.RemoveFront();
    if(b==0){
    	divZero d;
    	throw d;
	}
    double result = a / b;
    stack.InsertFront(result);
    return;
}

// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack) {
  // Implement this function.
   if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    double result = a * -1;
    stack.InsertFront(result);
    return;
}

// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack) {
  // Implement this function.
   if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }

    double a = stack.RemoveFront();
    stack.InsertFront(a);
    stack.InsertFront(a);	
    return;
}

// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack) {
  // Implement this function.
   if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
    double a = stack.RemoveFront();
    if (stack.IsEmpty()) {
        stack.InsertFront(a);
        throw emptyList();
        return;
    }
    double b = stack.RemoveFront();
    stack.InsertFront(a);
    stack.InsertFront(b);
    return;
}

// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack) {
  // Implement this function.
   if (stack.IsEmpty()) {
        throw emptyList();
        return;
    }
	double a = stack.RemoveFront(); 
    std::cout << a <<"\n";
    stack.InsertFront(a);
    return;
}

// EFFECTS: performs c operation
void DoClear(Dlist<double> &stack) {
  // Implement this function.
  
  while(!stack.IsEmpty()){
	stack.RemoveFront();
  }
}

// EFFECTS: performs a operation
void DoPrintAll(Dlist<double> &stack) {
  // Implement this function.
  Dlist<double> temp;
  temp = stack;
  while(!temp.IsEmpty()){
	std::cout<<temp.RemoveFront()<<" ";
  }
  std::cout<<"\n";
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

bool DoOne(Dlist<double> &stack) {
  std::string s;
  double d;

  std::cin >> s;
  switch (s[0]) {
  case '+':
    DoAdd(stack);
    break;
  case '-':
  	if(s[1]=='1'||s[1]=='2'||s[1]=='3'||s[1]=='4'||s[1]=='5'||s[1]=='6'||s[1]=='7'||s[1]=='8'||s[1]=='9'){
  		throw badInput();	
	}
    DoSub(stack);
    break;
  case '*':
    DoMult(stack);
    break;
  case '/':
    DoDiv(stack);
    break;
  case 'n':
    DoNeg(stack);
    break;
  case 'd':
	  DoDup(stack);
	  break;
  case 'r':
	  DoRev(stack);
	  break;
  case 'p':
	  DoPrint(stack);
	  break;
  case 'c':
	  DoClear(stack);
	  break;
  case 'a':
	  DoPrintAll(stack);
	  break;
  case 'q':
	  return true;
	  break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
	  d = std::atof(s.c_str());
      stack.InsertFront(d);
	  break;
  default:
	  badInput e;
	  throw e;
	  break;
  }
  return false;
}

int main() {
  Dlist<double> stack;

  bool done = false;
  while (!done) {
    try {
      done = DoOne(stack);
    } catch (emptyList e) {
      std::cout << "Not enough operands\n";
    } catch (divZero e) {
      std::cout << "Divide by zero\n";
    } catch (badInput e) {
      std::cout << "Bad input\n";
    }
  }
}
