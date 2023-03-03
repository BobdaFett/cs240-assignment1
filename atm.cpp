#include "atm.h"
using atm::ATM;

ATM::ATM() {
	this->current_account = accountType::CHECKING;
	this->current_transaction = transactionType::DEPOSIT;
	this->current_state = state::START;
}

ATM::ATM(accountType new_type, transactionType new_trans, state new_state) {
	this->current_account = new_type;
	this->current_transaction = new_trans;
	this->current_state = new_state;
}

void ATM::set_state(state new_state) {
	this->current_state = new_state;
}

void ATM::set_accountType(accountType new_type) {
	this->current_account = new_type;
}

void ATM::set_transType(transactionType new_type) {
	this->current_transaction = new_type;
}

void ATM::set_custNum(int new_num) {
	this->customerNumber = new_num;
}

void ATM::set_pin(int new_pin) {
	this->customerPIN = new_pin;
}

void ATM::set_transAmount(double amount) {
	this->transactionAmount = amount;
}