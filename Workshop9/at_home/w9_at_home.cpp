#include <istream>
#include <fstream>
#include "Transcript.h"
using namespace std;
using namespace sict;

int main(){
  Transcript T("John Doe", "042942088");
  T += Subject("Introduction to Object Oriented Programming", "OOP244", 40, 60);
  T += Subject("College English", "EAC150", 75, 100);
  T += Subject("iSERIES Business Computing", "IBC233", 80, 100);
  T += Subject("Internet I - Internet Fundamentals", "INT222", 30, 40);
  T += Subject("Introduction to Database Design and SQL", "DBS201",60, 100);
  
  cout << "******Display Test********" << endl << endl;
  cout << T << endl;
  Transcript Y(T), S;
  cout << "******Copy Operator Test********" << endl << endl;
  S = Y;
  cout << Y << endl;
  cout << "******Assignment Operator Test********" << endl << endl;
  cout << S << endl;
  cout << "******Read & Saving to File Test********" << endl << endl;
  char save;
  char filename[50];
  Transcript R;
  cin >> R;
  cout << R << endl;
  cout << "Save to file? (Y/N): ";
  cin >> save;

  if (toupper(save) == 'Y'){
	  cout << "Enter the filename: ";
	  cin >> filename;
	  fstream transcript(filename, ios::out);
	  R.display(transcript);
	  transcript.close();
  }

  return 0;
}