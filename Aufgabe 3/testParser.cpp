
#include <iostream>
#include <string>

using namespace std;


#include "parser.h"
#include "ast.h"



void display(Optional<EXP> e) {
  if(e.isNothing()) {
    cout << "nothing \n";
  } else {
    cout << (e.fromJust())->pretty() << "\n";
  }
  return;
}

void display1(Optional<EXP> e) {
    if(e.isNothing()) {
        cout << "nothing \n";
    }
    else {
        cout << (e.fromJust())->cleverPretty() << "\n";
    }
    return;
}

void testParserGood() {


  display(Parser("1").parse());

  display(Parser("1 + 0 ").parse());

  display(Parser("1 + (0) ").parse());

  display(Parser("1 + 2 * 0 ").parse());

  display(Parser("1 * 2 + 0 ").parse());


  display(Parser("(1* ( 1 + 2) * 0 )").parse());

  display(Parser("(1 + 2) * 0 + 2").parse());
  
  
  
  display1(Parser("1").parse());

  display1(Parser("1 + 0 ").parse());

  display1(Parser("1 + (0) ").parse());

  display1(Parser("1 + 2 * 0 ").parse());

  display1(Parser("1 * 2 + 0 ").parse());


  display1(Parser("(1* ( 1 + 2) * 0 )").parse());

  display1(Parser("(1 + 2) * 0 + 2").parse());
  
}

void testParser() {

  testParserGood();
}


int main() {

    testParser();

  return 1;
}