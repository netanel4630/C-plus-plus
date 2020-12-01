#include "Checking_Acount.h"
#include <iostream>

#include <string>
using std::string;

Checking_Acount::Checking_Acount(string name, double balance)
	: Account{ name, balance } {
}

bool Checking_Acount::withdraw(double amount) {
	return Account:: withdraw(amount - def_fee_rate);
}


std::ostream &operator<<(std::ostream &os, const Checking_Acount &account) {
	os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.def_fee_rate << "%]";
	return os;
}