#include "exception.h"

#ifndef ACCOUNT
#define ACCOUNT

class Account {

    private:

        double balance;

    public:

        Account():balance(0)

        {

        }

        Account(double initialDeposit):balance( initialDeposit)

        {

        }

        double getBalance()

        {

            return balance;

        }

        // returns new balance or -1 if error

        double deposit(double amount)

        {

            if (amount > 0)

                balance += amount;

            else

                throw Exception_Negative_Deposit(); // code indicating error

            return balance;

        }

        // returns new balance or -1 if invalid amount

        double withdraw(double amount)

        {

            if(amount < 0)

                throw Exception_Negative_Withdraw();

            else if (amount > balance)

                throw Exception_Overdraw();

            else

                balance -= amount;

            return balance;

        }

};

#endif
