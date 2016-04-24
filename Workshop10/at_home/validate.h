<<<<<<< HEAD
// OOP244 Workshop 10: Function Templates
// File: Validate.h
// Version: 1.0
// Date: 2016/04/4
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict{
	template <typename T1>
	bool validate(T1 min, T1 max, T1* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (testValue[i] >= min && max >= testValue[i]);
			if (result[i]){
				count++;
			}
		}
		return count == x;
	}
	template <>
	bool validate<char>(char min, char max, char* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (toupper(testValue[i]) >= min && max >= toupper(testValue[i]));
			if (result[i]){
				count++;
			}
		}
		return count == x;
	}
	template <> 
	bool validate<Car>(Car min, Car max, Car* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (testValue[i] >= min) && (testValue[i] <= max) && strlen((const char*)testValue[i]) == 6;
			if (result[i]){
				count++;
			}
		}
		return count == x;
		return true;
	}
}
#endif
=======
// OOP244 Workshop 10: Function Templates
// File: Validate.h
// Version: 1.0
// Date: 2016/04/4
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict{
	template <typename T1>
	bool validate(T1 min, T1 max, T1* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (testValue[i] >= min && max >= testValue[i]);
			if (result[i]){
				count++;
			}
		}
		return count == x;
	}
	template <>
	bool validate<char>(char min, char max, char* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (toupper(testValue[i]) >= min && max >= toupper(testValue[i]));
			if (result[i]){
				count++;
			}
		}
		return count == x;
	}
	template <> 
	bool validate<Car>(Car min, Car max, Car* testValue, int x, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < x; i++){
			result[i] = (testValue[i] >= min) && (testValue[i] <= max) && strlen((const char*)testValue[i]) == 6;
			if (result[i]){
				count++;
			}
		}
		return count == x;
		return true;
	}
}
#endif
>>>>>>> 462f745acb960edd2a588aeb146f428a36c4dc0d
