#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}


void Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}
