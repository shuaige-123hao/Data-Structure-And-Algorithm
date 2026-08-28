#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
	size_t length;
	char* str;
public:
	String();
	String(const char* h);
	~String();
	size_t getsize()const;
	char operator[](size_t index)const;
	String& operator=(const String& m);
	bool operator!=(const String& m);
	bool operator==(const String& m);
	String copy()const;
	String operator+(const String& m);
	friend ostream& operator<<(ostream& out, const String& m);
	String(const String& m) {
		this->length = m.length;
		str = new char[length + 1];
		strcpy(str, m.str);
	}
};

String::String() {
	length = 0;
	str = new char[1];
	str[0] = '\0';
}
String::String(const char* h) {
	length = strlen(h);
	str = new char[length + 1];
	strcpy(str, h);
}
String::~String() {
	delete[]str;
	length = 0;
}
size_t String::getsize()const {
	return length;
}
char String::operator[](size_t index)const {
	return str[index];
}
String& String::operator=(const String& m) {
	if (this != &m) {
		delete[]str;
		length = m.length;
		str = new char[m.getsize() + 1];
		strcpy(str, m.str);
	}
	return *this;
}
bool String::operator!=(const String& m) {
	return strcmp(str,m.str);
}
bool String::operator==(const String& m) {
	return strcmp(str, m.str)==0;
}
String String::copy()const {
	String s(*this);
	return s;
}
String  String::operator+(const String& m) {
	String result;
	result.length = m.length + this->length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, m.str);
	return result;
}
ostream& operator<<(ostream& out, const String& m) {
	out << m.str;
	return out;
}

int main() {
	String s("12345d");
	cout << s << endl;
	cout << s + "445" << endl;
	cout << s[5] << endl;
	cout << (s=="12345d") << endl;
	cout << (s!="12345d") << endl;
	s = s + "asd";
	String a, b, c;
	a = b = c = s;
	cout << s<<endl;
	cout << a << b << c << s << endl;
	String x = s.copy();
	cout << x << endl;





	return 0;
}