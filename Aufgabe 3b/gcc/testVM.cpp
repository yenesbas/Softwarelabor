#include <iostream>
#include <string>

using namespace std;

#include "vm.h"
#include "parser.h"
#include "ast.h"

void showVMRes(Optional<int> r) {
  if(r.isNothing())
    cout << "\nVM stack (top): empty";

  cout << "\nVM stack (top):" << r.fromJust() << "\n\n";
  

}
void display(Optional<EXP> e){
    if(e.isNothing()) {
    cout << "nothing \n";
  } else {
    auto eingabe = e.fromJust();
    cout  << "\n" << eingabe->pretty() << "\n";
    cout  << eingabe->cleverPretty() << "\n";
    vector<Code> ergebnis = eingabe->toVm();
    Optional<int> x = VM(ergebnis).run();
    showVMRes(x);
    /*
    vector<string> ergebnis = eingabe->toVm();s
    for (string &instr : ergebnis) {
        cout << instr << "; " << "\n";
    }
    */
  }
}


 
void testVM() {
    
    
     
  {
    vector<Code> vc{
          newPush(1),
      newPush(2),
      newPush(3),
      newMult(),
      newPlus() };

    Optional<int> res = VM(vc).run();

    showVMRes(res);
  }
  
  
    
  {
    vector<Code> vc{
          newPush(2),
      newPush(3),
      newPush(5),
      newPlus(),
      newMult() };

    Optional<int> res = VM(vc).run();

    showVMRes(res);
  }
}

void testParserGood() {
    display(Parser("3 * 2 + 1").parse());
    display(Parser("(5 + 3) * 2").parse());
    display(Parser("(3 + 2) * 5").parse());
}


int main() {

  //testVM();
  testParserGood();
  return 1;
}