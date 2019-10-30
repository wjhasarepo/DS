#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

public:
    String(const char* s);
    String(const String &);
    ~String();
    const String &operator=(const String &);
    const String &operator+=(const String &);
    bool operator!() const;
    bool operator==(const String &) const;
    bool operator<(const String &) const;
    bool operator!=(const String &right) const
    {
		return !(*this == right);
    }
    bool operator>(const String &right) const
    {
		return right < *this;
    }
    bool operator<=(const String &right) const
    {
		return !(right < *this);
    }
    bool operator>=(const String &right) const
    {
		return !(*this < right);
    }
    char &operator[](int);
    const char &operator[](int) const;
    //String &operator()(int, int);
    int getLength() const;

private:
    int length;
    char *ptr;

    void setString(const char *);
};

String::String(const char* s):length(strlen(s))
{
	setString(s);
}

String::String(const String &copy):length(copy.length)
{
	setString(copy.ptr);
}

String::~String()
{
	delete [] ptr;
}

const String &String::operator=(const String &right)
{
	if(&right != this)
	{
		delete [] ptr;
		length = right.length;
		setString(right.ptr);
	}
	else
	{
		std::cout << "Attempted assignment of a String to itself" << std::endl;
	}

	return *this;
}

const String &String::operator+=(const String &right)
{
	char *tempPtr = ptr;
	length += right.length;
	ptr = new char[length + 1];
	assert(ptr != 0);
	strcpy(ptr, tempPtr);
	strcat(ptr, right.ptr);
	delete [] tempPtr;
	return *this;
}

bool String::operator!() const
{
	return length == 0;
}

bool String::operator==(const String &right) const
{
    return strcmp(ptr, right.ptr) == 0;
}

bool String::operator<(const String &right) const
{
    return strcmp(ptr, right.ptr) < 0;
}

char &String::operator[](int subscript)
{
	assert(subscript >= 0 && subscript < length);
	return ptr[subscript];
}

const char &String::operator[](int subscript) const
{
	assert(subscript >= 0 && subscript < length);
	return ptr[subscript];
}
/*
String &String::operator()(int index, int subLength)
{
	assert(index >= 0 && index < length && subLength >= 0);

	String *subPtr = new String;
	assert(subPtr != 0);

	if((subLength == 0) || (index + subLength > length))
		subPtr->length = length - index + 1;
	else
		subPtr->length = subLength + 1;

	delete subPtr->ptr;
	subPtr->ptr = new char[subPtr->length];
	assert(subPtr->ptr != 0);

	strncpy(subPtr->ptr, &ptr[index], subPtr->length);
	subPtr->ptr[subPtr->length] = '\0';

	return *subPtr;
}
*/
int String::getLength() const
{
	return length;
}

void String::setString(const char *str)
{
	ptr = new char[length + 1];
	assert(ptr != 0);
	strcpy(ptr, str);
}

inline std::ostream &operator<<(std::ostream &output, const String &s)
{
	output << s.ptr;
	return output;
}

inline std::istream &operator>>(std::istream &input, String &s)
{
	char temp[100];

	input >> temp;
	s=temp;
	return input;
}

#endif
