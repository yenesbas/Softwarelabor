#include <iostream>
#include <string>

using namespace std;


#include "parser.h"
#include "ast.h"



void display(Optional<EXP> e) {
  if(e.isNothing()) {
    cout << "nothing \n";
  } else {
    auto exp = e.fromJust();
    cout  << "\n" << exp->pretty() << "\n";
    cout  << exp->cleverPretty() << "\n\n";  // eine Zeile leer inzwischen
    
    // 3b: Hinzufügen der Instruktionen-Ausgabe
    vector<string> instructions = exp->toVm();
    cout << "Instructions:\n";
    
    /*
    for (int i = instructions.size() - 1; i >= 0; i--) {
    if (instructions[i][0] == 'P')
        cout << instructions[i] << "\n";
    } 
    */
    
    for (string &instr : instructions) {
        cout << instr << "; ";// << "\n";
    }
    cout << "\n";
    
    /*
    for (string &instr : instructions) {
        if(instr[0] == 'P')
            cout << instr << "\n";
    }
    for (string &instr : instructions) {
        if(instr[0] != 'P')
            cout << instr << "\n";
    }
    */
  }
  
  return;
}


void testParserGood() {
    
    display(Parser("3 * 2 + 1").parse());    
    
    display(Parser("(5 + 3) * 2").parse());
}

void testParser() {

    testParserGood();
}


int main() {

    testParser();

  return 1;
}