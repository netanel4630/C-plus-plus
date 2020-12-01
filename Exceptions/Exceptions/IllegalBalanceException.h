#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

using std::exception;

class IllegalBalanceException : public exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default;

	virtual const char* what() const noexcept {
		return "Illegal balance exception";
	}
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
