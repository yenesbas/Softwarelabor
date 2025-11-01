#include <stdio.h>
#include <stdlib.h>


enum Bool;
struct OldNew;

int length(char *s);
char* normalisiere(char* s);
void copy(char* s, int n, char* t);
char* copyStr(char* s);
char* putFront(char c, char* s);
char* reverse(char* s);
char* putBack(char c, char* s);
char* rev(char* s);
void replace(char* s, struct OldNew* m, int n);
char* show(enum Bool b);
enum Bool strCmp(char* s1, char* s2);



// Anzahl aller Zeicher (ohne Null-terminator).
int length(char *s) {
  int n = 0;
  while(*s != '\0') {
    n++;
    s++;
  }

  return n;
}


// Normalisiere C String.
// 1. Eliminiere Leerzeichen.
// 2. Alle Grossbuchstaben werden in Kleinbuchstaben umgewandelt.
// 3. Kleinbuchstaben bleiben unveraendert.
// Annahme: C String besteht nur aus Klein-/Grossbuchstaben und Leerzeichen.
char* normalisiere(char* s) { // zuerst zahlen wie viele Zeichen es gibt
  // TODO
    int lange = length(s);
    int zeichenAnzahl = 0; //Zaehlen wie viele Zeichen es ohne Leerzeichen gibt
    for(int h = 0; h < lange; h++) {
    if(s[h] != ' ') {
        zeichenAnzahl++;
        }
    }
    
    char* normale = (char*)malloc(zeichenAnzahl + 1);
    
    int k = 0;
    for(int i = 0; i < lange; i++) {
        if(s[i] != ' ') {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                normale[k] = s[i] + 32; // + 32 andert große Buchstaben zu kleinen (ASCII Tabelle)
            } else {
                normale[k] = s[i];
            }
            k++;
        }
    }
    normale[k] = '\0';
    
    return normale;
}


// Kopiere n Zeichen von s nach t.
// Annahme: n ist > 0
void copy(char* s, int n, char* t) {
  int i = 0;
  while(i < n) {
    t[i] = s[i];
    i++;
  }
}


// Baue neuen String welcher eine Kopie des Eingabestrings ist.
char* copyStr(char* s) { // noch mal fragen
  // TODO
  int a = length(s);
  char* koppiert = (char*)malloc(a + 1);
  
  int i = 0;
  while(i < a) {
    koppiert[i] = s[i];
    i++;
  }
  
  return koppiert;
}

// Baue neuen String welcher mit Zeichen c startet gefolgt von allen Zeichen in s.
char* putFront(char c, char* s) {
  const int n =  length(s);
  char* r = (char*)malloc(sizeof(char) * (n+2));
  copy(s, n+1, r+1);
  r[0] = c;
  return r;
}


// Umkehrung eines Strings.
char* reverse(char* s) {
  const int n = length(s);
  char* t = (char*)malloc(n + 1);
  int i;

  for(i = 0; i < n; i++) {
    t[i] = s[n-1-i];
  }
  t[n] = '\0';

  return t;
}

// Baue neuen String welcher aus allen Zeichen in s besteht gefolgt von Zeichen c.
char* putBack(char c, char* s) { // FREE 
  // TODO
  const int n = length(s);
  char* cAmEnde = (char*)malloc(n + 1);
  char* a = reverse(s);
  char* b = putFront(c, a);
  free(a);
  cAmEnde = reverse(b);
  free(b);
  return cAmEnde;
}

// Baue einen neuen String welcher die Umkehrung des Eingabestrings ist.
// Hinweis: Die Implementierung soll rekursiv sein und die Hilfsroutine putBack verwenden.
char* rev(char* s) { // Wie macht man das rekursiv? (s+1)
  // TODO
    if (*s == '\0') {
        char* reversed = (char*)malloc(sizeof(char));
        *reversed = '\0';
        return reversed;
    }
    char* reversed = rev(s + 1);
    char* rueckgabe = putBack(*s, reversed);
    free(reversed);

  return rueckgabe;
}


struct OldNew {
  char old;
  char new;
};


// Ersetze in einem String jedes Zeichen 'old' mit dem Zeichen 'new'.
// Die Zeichen 'old' und 'new' sind definiert in einem Array vom Typ struct OldNew.
void replace(char* s, struct OldNew* m, int n) {
  // TODO
  int i = 0;
  int a = length(s);
  while(i != a){
      for(int j = 0; j < n; j++) {
            if(s[i] == m[j].old) {
                s[i] = m[j].new;
                break;
            }
        }
      i++;
  }
}

enum Bool {
  True = 1,
  False = 0
};

char* show(enum Bool b) {
  if(b == True) {
    return copyStr("True");
  } else {
    return copyStr("False");
  }
}


// Teste ob zwei Strings identisch sind.
enum Bool strCmp(char* s1, char* s2) {
  // TODO
  int lange1 = length(s1);
  int lange2 = length(s2);
  if(lange2 != lange1){
      return False;
  } else{
      for (int i = 0; i < lange1; i++) {
          if(!s1[i] == s2[i]){
              return False;
            }
        }
    }
      
  
  return True;
}


void userTests() {
  printf("\n\n *** User Tests *** \n\n");

  char s1[] = "Ha Ll o o ";

  printf("\n1. %s", s1);

  printf("\n2. %s", normalisiere(s1));

  char* s2 = (char*)malloc(length("Hello")+1);

  char* s3 = copyStr("Hello");

  printf("\n3. %s", s3);

  char s4[] = "abcd";

  char* s5 = putBack('!',s4);

  printf("\n4. %s", s5);

  char* s6 = rev(s5);

  printf("\n5. %s", s6);

  char s7[] = "Aa dss fBB";

  printf("\n6. %s", s7);

  struct OldNew m[] = { {'B', 'b'}, {'s', '!'}};

  replace(s7, m, 2);

  printf("\n7. %s", s7);

  char s8[] = "HiHi";

  char* s9 = copyStr(s8);

  enum Bool b1 = strCmp(s8,s9);

  char* s10 = show(b1);

  printf("\n8. %s", s10);

  char s11[] = "HiHo";

  enum Bool b2 = strCmp(s9, s11);

  char* s12 = show(b2);

  printf("\n8. %s", s12);

  free(s2);
  free(s3);
  free(s5);
  free(s6);
  free(s9);
  free(s10);
  free(s12);
}

struct TestCase_ {
  char* input;
  char* expected;
};

typedef struct TestCase_ TC;

void runTests(TC* tc, int n, char* sut(char*)) {
  int i;

  for(i=0; i<n; i++) {
    char* result = sut(tc[i].input);
    if(True == strCmp(tc[i].expected, result)) {
      printf("\n Okay Test (%s,%s) => %s", tc[i].input,tc[i].expected, result);
    } else {
      printf("\n Fail Test (%s,%s) => %s", tc[i].input,tc[i].expected, result);
    }
    free(result);
  }

}


void unitTests() {
  printf("\n\n *** Unit Tests *** \n\n");

  TC normTests[] = {
    {"hElLo", "hello"},
    {"hEl Lo", "hello"},
    {"h  El Lo", "hello"},
  };


  runTests(normTests, 3, normalisiere);

}

char* rndString() {
  int i;
  int n = (rand() % 10) + 1;
  char* s = (char*)malloc(n+1);

  for(i=0; i<n; i++) {
    int lowHigh = (rand() % 2) ? 'a' : 'A';
    int c = rand() % 26;
    s[i] = (char)(c + lowHigh);
  }
  s[n] = '\n';

  return s;
}

void invariantenTests() {
  printf("\n\n *** Invarianten Tests *** \n\n");

  int i;
  for(i=0; i<20; i++) {
    char* s = rndString();
    char* r = reverse(s);
    char* n1 = normalisiere(s);
    char* n2 = normalisiere(r);
    char* n3 = reverse(n2);

    if(True == strCmp(n1,n3)) {
      printf("Okay %s", s);
    } else {
      printf("Fail %s", s);
    }

    free(s);
    free(r);
    free(n1);
    free(n2);
    free(n3);
  }



}


int main() {
  userTests();

  unitTests();

  invariantenTests();
}