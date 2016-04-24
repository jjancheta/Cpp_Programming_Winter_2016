#include "Displayable.h"
#ifndef SICT_STUDENT_H_
#define SICT_STUDENT_H_
namespace sict{

  class Student :public Displayable{
    int _stno;
    char _name[41];
    void set(int stno, const char* name);
  public:
    Student(int stno, const char* name = "no name");
<<<<<<< HEAD
    Student(const Student& S) = delete;
=======
    Student(const Student& S);
>>>>>>> 462f745acb960edd2a588aeb146f428a36c4dc0d
    Student& operator=(const Student& S) = delete;
    std::ostream& display(std::ostream& os)const;
    bool operator<=(const Student& S)const;
    bool operator>=(const Student& S)const;
    operator const char*()const;
  };
}
<<<<<<< HEAD
#endif 
=======
#endif 
>>>>>>> 462f745acb960edd2a588aeb146f428a36c4dc0d
