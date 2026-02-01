#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException : public std::exception
{
private:
	const char* _msg;
public:
	MyException(const char* m) : _msg(m) {}

	const char* what() const noexcept 
	{
		return _msg;
	}
};

#endif // MYEXCEPTION_H