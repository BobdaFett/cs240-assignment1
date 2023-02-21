#pragma once


/// <summary>
/// To be controlled by the atmForm.
/// </summary>
ref class atm {
public:
	enum class accountType {CHECKING, SAVINGS};
	enum class transactionType {DEPOSIT, WITHDRAWAL};
	enum class state {START, PIN, ACCOUNT, TRANSACTION};
private:
	double transactionAmount;  // Is a money amount, cannot be an integer type.
	int customerPIN;
	int customerNumber;
};