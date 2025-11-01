#ifndef __DYNARR__
#define __DYNARR__

#include <iostream>
using namespace std;

template<typename T>
void copy_(T* s, int n, T* t) {
  int i = 0;
  while(i < n) {
    t[i] = s[i];
    i++;
  }
}


template<typename T>
class DynArr {
  int len;
  T* p;

public:

  DynArr() {
    this->len = 0;
    this->p = nullptr;
  }
  DynArr(T x, int size) {
    this->len = size;
    this->p = new T[size];

    for(int i=0; i<size; i++) {
      this->p[i] = x;
    }
  }
  DynArr(const DynArr<T>& src) {// copy konstruktor
   // TODO
   len = src.len;
	p = new T[len]; // neue Speicher wird allokiert
	copy_ (src.p, len, p);
  }
   DynArr<T>& operator=(const DynArr<T>& src) {// copy zuweisungsoperator
   // TODO
   if (this != &src) // vermedeitet selbst zuweisung
	  {
		delete[]p;
		len = src.len;
		p = new T[len];
		copy_ (src.p, len, p);
	  }
	return *this;
  }
  DynArr(DynArr<T>&& src) {// move konstruktor
   // TODO
    this->p = src.p;
    src.p = nullptr;
    this->len = src.len;
    src.len = 0;
  }
  DynArr<T>& operator=(DynArr<T>&& src) {
   // TODO
   if (this != &src)
	  {
		delete[]this->p;
		this->p = src.p;
		src.p = nullptr;
        this->len = src.len;
        src.len = 0;
		/* Muss man length auch machen?
        this->len = src.len;
        src.len = 0;
        */
	  }
	return *this;
  }


  ~DynArr() { delete[] p; }

  T& operator[](int index) {
    return p[index];
  }


  int size() const {
      return this->len;
  }

  string show() {
    string s;
    for(int i=0; i<this->len; i++) {
      s = s + to_string(p[i]);
    }
    return s;
  }


  void add(T x) {
    // TODO
    int newLen = len + 1;
	T *newP = new T[newLen];
	
	for (int i = 0; i < len; i++)
	  {
		newP[i] = p[i];
	  }
	//oder einfach: copy_ (p, len, new_p);
	
	newP[len] = x;
	delete[]p;
	p = newP;
	len = newLen;
  }

  void reverse() {
  // TODO
  for (int i = 0; i < len / 2; i++)
	  {
		T reversed = p[i];
		p[i] = p[len - 1 - i];
		p[len - 1 - i] = reversed;
	  }
  }

  void append(const DynArr<T>& src) {
  // TODO
  int newLen = len + src.len;
	T *newP = new T[newLen];
	
	for (int i = 0; i < len; i++)
	  {
		newP[i] = p[i];
	  }
	//oder einfach: copy_ (p, len, new_p);
	
	for (int i = 0; i < src.len; i++)
	  {
		newP[len+i] = src.p[i];
	  }
	//copy_ (src.p, src.len, new_p + len);
	
	delete[]p;
	p = newP;
	len = newLen;
  }

};


#endif






#include <iostream>
using namespace std;



void example1() {

  DynArr<int> d;

  d.add(1);

  cout << "\n1. " << d[0];

  d.add(2);

  cout << "\n2. " << d[0] << d[1];

  cout << "\n3. " << d.show();

  d.reverse();

  cout << "\n4. " << d.show();

  d.append(d);

  cout << "\n5. " << d.show();

  DynArr<int> d2;

  d2 = d;

  cout << "\n6. " << d2.show();

  d.reverse();

  d2.append(d);

  cout << "\n7. " << d2.show();

}


template<typename T>
void someFunc(int i, DynArr<T> d) {
  d.reverse();

  cout << "\n" << i << ". " << d.show();
}


void example2() {

  DynArr<bool> d = DynArr<bool>();

  d.add(true);

  cout << "\n1. " << d[0];

  d.add(false);

  cout << "\n2. " << d[0] << d[1];

  cout << "\n3. " << d.show();

  someFunc<bool>(3,d);

  cout << "\n4. " << d.show();

  someFunc<bool>(5,DynArr<bool>(true, 2));

  DynArr<bool> d2;

  d2 = move(d);

  d2.add(false);

  cout << "\n6. " << d2.show();



}


int main() {

  cout << "\n\n *** example1 *** \n";
  example1();

  cout << "\n\n *** example2 *** \n";
  example2();


}