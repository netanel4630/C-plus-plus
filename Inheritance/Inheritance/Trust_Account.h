#pragma once
#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"


class Trust_Account : public Savings_Account {

	friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
	static constexpr const char *def_name = "Unnamed Trust Account";
private:
	static constexpr const double bonus = 50.0;
	static constexpr const double treshold = 5000.0;
	static constexpr const int max_withdraw_per_year = 3;
	static constexpr const float allowed_withdrawals_percentance = 0.2;
	int withdraw_per_year = 0;

public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);
	bool withdraw(double amount);
};



#endif