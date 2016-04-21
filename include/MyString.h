#ifndef CPP_STRING_H
#define CPP_STRING_H
#include <stdexcept>
#include <cstring>

class String {
private:
    int l;
    char * string;
public:
    static char position;
    String(){
		l=0;
		string=new char[1];
		string[0]='\0';
	};
    String(const char *s){
		l = std::strlen(s);
		string = new char[l + 1];
		std::strcpy(string, s);
	};
    String(const char *str, unsigned count){
	 string = new char[count + 1];
    l = count;
    for (int i = 0; i <= l; i++)
        string[i] = str[i];
    };
    String(char ch, unsigned count){
		l = count;
		string = new char[l + 1];
      for (int i = 0; i <= l; i++)
        string[i] = ch;
		string[l] = '\0';
	};
    String(const String &other){
		string = new char[other.l + 1];
		l = other.l;
		std::strcpy(string,other.string);
	};
    String(String &&other)
	 {
	 string = other.string;
    l = other.l;
    other.string = '\0';
    other.l = 0;
	 };
    ~String(){
        delete[] string;
    };
    String & operator=(const String &other){
	 delete[] string;
		 string=new char[other.l + 1];
		 l=other.l;
		std::strcpy(string,other.string);
	 };
    String & operator=(String &&other){
	   l = other.l;
		string = other.string;
		other.l = 0;
		other.string = nullptr;
	 };
    String & operator+=(const String &suffix){  
	 char *concat = new char[l + suffix.l + 1];
    for (int i = 0; i < l; ++i)
        concat[i] = string[i];
    for (int j = l; j < l + suffix.l; ++j)
        concat[j] = suffix.string[j - l];
    concat[l + suffix.l] = '\0';
    delete[] string;
    string = concat;
    l += suffix.l;
    return *this;
	 };
    String & operator+=(const char *suffix){
	  int suffixl = 0;
    const char *temp = suffix;
    while (*(temp++) != '\0') 
        suffixl++;
		  char *concat = new char[l + suffixl + 1];
    for (int i = 0; i < l; ++i)
        concat[i] = string[i];
    for (int j = l; j < l + suffixl; ++j)
        concat[j] = suffix[j - l];
    concat[l + suffixl] = '\0';
    delete[] string;
    string = concat;
    l += suffixl;
    return *this;
	 };
    String & operator+=(char suffix){
	 char *concat = new char[l + 2];
    for (int i = 0; i < l; ++i)
        concat[i] = string[i];
    concat[l] = suffix;
    concat[l + 1] = '\0';
    delete[] string;
    string = concat;
    l++;
    return *this;
	 };
    void swap(String &other){
	 char *tmp;
    int tmpl;
    tmp = string;
    tmpl = l;
    string = other.string;
    l = other.l;
    other.string = tmp;
    other.l = tmpl;
	 };
    char & operator[](int pos){   
	 return string[pos];
	 };
    const char operator[](int pos) const{
	     return string[pos];
	};
    char & at(int pos){    
	 if (pos >= l) 
        throw std::out_of_range("");
    return string[pos];
	};
    const char at(int pos) const{
	  if (pos >= l) 
        throw std::out_of_range("");
    return string[pos];
	 };
    const char * data() const{
	 return string;
	 };
    int size() const{
	 return l;
	 };
friend bool operator==(const String &lhs, const String &rhs){
    if (lhs.l == rhs.l){
        for (int i = 0; i < lhs.l; ++i)
            if (lhs.string[i] != rhs.string[i])
                return false;
        return true;
		  }
    return false;
	}
friend bool operator<(const String &lhs, const String &rhs){
    int size;
    size = lhs.l <= rhs.l ? lhs.l : rhs.l;
    for (int i = 0; i < size; ++i)
      if (lhs.string[i] < rhs.string[i])
         return true;
		else if (lhs.string[i] > rhs.string[i])
         return false;
    if (rhs.l > lhs.l)
        return true;
    return false;
	}
};
String operator+(const String &lhs, const String &rhs){
	return String(lhs) += rhs;
};
String operator+(const String &lhs, const char *rhs){
    return String(lhs) += rhs;
}
String operator+(const char *lhs, const String &rhs){
    return String(rhs) += lhs;
}
bool operator!=(const String &lhs, const String &rhs){
    return !(lhs == rhs);
}
bool operator<=(const String &lhs, const String &rhs){
    return (lhs == rhs) || (lhs < rhs);
}
bool operator>(const String &lhs, const String &rhs){
    return !(lhs <= rhs);
}
bool operator>=(const String &lhs, const String &rhs){
    return !(lhs < rhs);
}
#endif




