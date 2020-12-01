#pragma once
#ifndef _CHECKING_ACCOUNT_H_
#define _CHEKING_ACCOUNT_H_
#include "Account.h"

class Checking_Acount : public Account {

	friend std::ostream &operator<<(std::ostream &os, const Checking_Acount &account);
private:
	static constexpr const char *def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr const double def_fee_rate = 1.5;
protected:
	double int_rate;
public:
	Checking_Acount(std::string name = def_name, double balance = def_balance);
	bool withdraw(double amount);
};

#endif