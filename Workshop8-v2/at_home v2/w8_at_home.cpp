#include <iostream>
#include "String.h"

using namespace std;
using namespace sict;

ostream& operator~(String& S){  // prints a strings and its properties
	return cout << "->" << S << "<- len: " << S.length() << ", mem: " << S.memSize() << endl;
}

int main(){
  int i;
  char str[500] = "One";
  String S1;
  String S2("Two", 10);
  String S3("Three", 4);
  String S31(S3);
  String tmp;
  ~S1;           //1
  ~S2;           //2
  ~S3;           //3
  ~S31;          //4
  S31 = "Thirty One";
  ~S31;          //5
  cout << (const char*)S31 << endl;   //6
  S1 += str;
  ~S1;           //7
  S1 += " ";
  ~S1;            //8         
  S1 += S2;
  ~S1;            //9 
  tmp = S1++;
  ~tmp;          //10
  tmp = S1 + S3;
  ~tmp;          //11
  ++tmp;
  ~tmp;           //12
  cout << '>';
  for (i = 0; i < (int)tmp; i++){
    cout << tmp[i];
  }
  cout << '<' <<  endl;
  tmp[0] = tmp[4] = tmp[8] = 'X';
  ~tmp;            //13
  return 0;
}