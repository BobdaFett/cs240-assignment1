#pragma once

/// <summary>
/// To be controlled by the atmForm.
/// </summary>
namespace atm {
	enum class accountType { CHECKING, SAVINGS };
	enum class transactionType { DEPOSIT, WITHDRAWAL };
	enum class state { START, PIN, ACCOUNT, TRANSACTION };

	ref class ATM {
	public:
		ATM();
		ATM(accountType type, transactionType trans_type, state current_state);
		void set_state(state new_state);
		void set_accountType(accountType new_type);
		void set_transType(transactionType new_type);
		void set_custNum(int new_num);
		void set_pin(int new_pin);
		void set_transAmount(double amount);
		state get_state() { return current_state; };
		accountType get_accountType() { return current_account; };
		transactionType get_transType() { return current_transaction; };

	private:
		double transactionAmount;  // Is a money amount, cannot be an integer type.
		int customerPIN;
		int customerNumber;
		accountType current_account;
		transactionType current_transaction;  // may not be needed, or should be used as a type somewhere else.
		state current_state;
	};
}