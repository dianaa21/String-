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
	}
    String(const char *s){
		l = std::strlen(s);
		string = new char[l + 1];
		std::strcpy(string, s);
		string[l]='\0';
	}
    String(const char *str, unsigned count){
	 string = new char[count + 1];
    l = count;
    for (int i = 0; i < l; i++)
        string[i] = str[i];
		string[l] = '\0';
    }
    String(char ch, unsigned count){
		l=count;
		string = new char[l + 1];
      for (int i = 0; i < l; i++)
        string[i]=ch;
		string[l]='\0';
	}
    String(const String &other){
		string = new char[other.l + 1];
		l=other.l;
		std::strcpy(string,other.string);
		string[l]='\0';
	}
    String(String &&other){
	 string = other.string;
    l = other.l;
    other.string = nullptr;
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
		string[l] = '\0';
		return *this;
	 }
    String & operator=(String &&other){
	   l = other.l;
		string = other.string;
		other.l = 0;
		other.string = nullptr;
		return *this;
	 }
    String & operator+=(const String &suffix){ 
char *t;	 
	 char *c = t= new char[l + suffix.l + 1];
    for (int i = 0; i < l; ++i)
        c[i] = string[i];
    for (int j = l; j < l + suffix.l; ++j)
        c[j] = suffix.string[j - l];
    c[l + suffix.l] = '\0';
    delete[] string;
    string = t;
    l += suffix.l;
    return *this;
	 }
    String & operator+=(const char *suffix){
	  char *t;
	  char *c = t = new char[l + std::strlen(suffix) + 1];
    for (int i = 0; i < l; ++i)
        c[i] = string[i];
    for (int j = l; j < l + std::strlen(suffix); ++j)
        c[j] = suffix[j - l];
    c[l + std::strlen(suffix)] = '\0';
    delete[] string;
    string = t;
    l += std::strlen(suffix);
    return *this;
	 }
    String & operator+=(char suffix){
	 char *t;
	 char *c =t = new char[l + 2];
    for (int i = 0; i < l; ++i)
        c[i] = string[i];
    c[l] = suffix;
    c[l + 1] = '\0';
    delete[] string;
    string = t;
    l++;
    return *this;
	 }
    void swap(String &other){
	 char *tmp;
    int tmpl;
    tmp = string;
    tmpl = l;
    string = other.string;
    l = other.l;
    other.string = tmp;
    other.l = tmpl;
	 }
    char & operator[](int pos){   
	 return string[pos];
	 }
    const char operator[](int pos) const{
	     return string[pos];
	}
    char & at(int pos){    
	 if (pos >= l) 
        throw std::out_of_range("");
    return string[pos];
	}
    const char at(int pos) const{
	  if (pos >= l) 
        throw std::out_of_range("");
    return string[pos];
	 }
    const char * data() const{
	 return string;
	 }
    int size() const{
	 return l;
	 }
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




