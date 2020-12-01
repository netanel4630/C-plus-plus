#include "Trust_Account.h"


Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate} {}



bool Trust_Account::deposit(double amount) {

	if (amount > treshold) {
		return Savings_Account::deposit(amount + bonus);
	}
	
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
	if (withdraw_per_year == max_withdraw_per_year || balance * allowed_withdrawals_percentance >= amount) {
		return false;
	}

	withdraw_per_year++;

	return Savings_Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
	os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
	return os;
}