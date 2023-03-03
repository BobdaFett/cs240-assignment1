#include "atmForm.h"
#include "errorWindow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CS240Assignment1;

[STAThread]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew atmForm());
	return 0;
}

void atmForm::numButtonClick(System::Object^ o, System::EventArgs^ e) {
	String^ button_name = ((Button^)o)->Name;
	String^ button_text = ((Button^)o)->Text;

	// Being able to create a switch statement would be awesome here...
	if (button_name == "buttonClear") {
		textBox1->Clear();
		return;
	} if (button_name == "buttonA") {
		buttonA_Event();
		return;
	} if (button_name == "buttonB") {
		buttonB_Event();
		return;
	} if (button_name == "buttonC") {
		buttonC_Event();
		return;
	}
	// Will only execute should this if the button is a number button. These stay constant throughout every state.
	textBox1->AppendText(button_text);
}

void atmForm::buttonA_Event() {
	switch (current_atm.get_state()) {
	case state::START: {
		// Should store customer number into the ATM
		// Changes current_state to PIN
		int cust_num{};  // equivalent to an Int32, not an Int16.
		Int32::TryParse(textBox1->Text, cust_num);  // put into if statement later.
		if (Int32::TryParse(textBox1->Text, cust_num)) {
			current_atm.set_custNum(cust_num);
			current_atm.set_state(state::PIN);
		}
		else {
			// modal window with error message.
			// Clear textBox1 and then do nothing. Should this be in the window function?
			error_window("Please enter a valid number.");
		}
		break;
	}
	case state::PIN: {
		// Stores and sets customerPIN.
		// Changes current_state to ACCOUNT
		int pin{};
		Int32::TryParse(textBox1->Text, pin);  // put into if statement later.
		if (Int32::TryParse(textBox1->Text, pin)) {
			current_atm.set_pin(pin);
			current_atm.set_state(state::ACCOUNT);
		}
		else {
			// Modal window with error message.
			// Clear textBox1.
			error_window("Please enter a valid number.");
		}
		break;
	}
	case state::ACCOUNT: {
		// Sets current_account to CHECKING
		// Changes current_state to TRANSACTION
		current_atm.set_accountType(accountType::CHECKING);
		current_atm.set_state(state::TRANSACTION);
		break;
	}
	case state::TRANSACTION: {
		// Sets current_transaction to WITHDRAWAL - perhaps check if balance will become negative, and block if so. (NEXT ASSIGNMENT)
		// Set transactionAmount to user entered number (parsed from string, handle errors accordingly.)
		// Changes current_state to ACCOUNT
		double trans_amount{};
		Double::TryParse(textBox1->Text, trans_amount);  // put into if statement later. not sure why it's not working?
		if (Double::TryParse(textBox1->Text, trans_amount)) {
			current_atm.set_transType(transactionType::WITHDRAWAL);
			current_atm.set_transAmount(trans_amount);
		}
		else {
			// Modal window with error message.
			// Clear textBox1
			error_window("Please enter a valid dollar amount.");
		}
		break;
	}
	}
	change_formState();
}

void atmForm::buttonB_Event() {
	switch (current_atm.get_state()) {
	case state::ACCOUNT: {
		// Sets current_account to SAVINGS
		// Changes current_state to TRANSACTION
		current_atm.set_accountType(accountType::SAVINGS);
		current_atm.set_state(state::TRANSACTION);
		break;
	}
	case state::TRANSACTION: {
		// Sets current_transaction to DEPOSIT
		// Set transactionAmount to user entered number (parsed from string, handle errors accordingly.)
		// Changes current_state to ACCOUNT
		double user_amount = 0.0;
		Double::TryParse(textBox1->Text, user_amount);
		if (Double::TryParse(textBox1->Text, user_amount)) {
			current_atm.set_transType(transactionType::DEPOSIT);
			current_atm.set_transAmount(user_amount);
		}
		else {
			// Modal window with error message.
			error_window("Please enter a valid dollar amount.");
		}
		break;
	}
	}
	change_formState();
}

void atmForm::buttonC_Event() {
	switch (current_atm.get_state()) {
	case state::START: {
		// Exits application
		Application::Exit();
		break;
	}
	case state::ACCOUNT: {
		// Sets current_state to START
		current_atm.set_state(state::START);
		break;
	}
	case state::TRANSACTION: {
		// Sets current_state to ACCOUNT
		current_atm.set_state(state::ACCOUNT);
		break;
	}
	}
	change_formState();
}

void atmForm::change_formState() {
	switch (current_atm.get_state()) {
	case state::START: {
		// buttonA = "OK"
		// buttonB = null
		// buttonC = "Exit"
		// textBox2 = "Enter cust num and press OK"
		buttonA->Text = "OK";
		buttonB->Visible = false;
		buttonC->Text = "Exit";
		textBox2->Text = "Enter customer number and press OK.";
		break;
	}
	case state::PIN: {
		// buttonA = "OK"
		// buttonB = null
		// buttonC = null
		// textBox2 = "Enter PIN and press OK"
		buttonA->Text = "OK";
		buttonB->Visible = false;
		buttonC->Visible = false;
		textBox2->Text = "Enter PIN and press OK.";
		break;
	}
	case state::ACCOUNT: {
		// buttonA = "Checking"
		// buttonB = "Savings"
		// buttonC = "Cancel"
		// textBox2 = "Select Account"
		buttonA->Text = "Checking";
		buttonB->Visible = true;
		buttonB->Text = "Savings";
		buttonC->Visible = true;
		buttonC->Text = "Cancel";
		textBox2->Text = "Select account type.";
		break;
	}
	case state::TRANSACTION: {
		// buttonA = "Withdraw"
		// buttonB = "Deposit"
		// buttonC = "Cancel"
		// textBox2 = "Balance... Enter amount and select transaction"
		buttonA->Text = "Withdraw";
		buttonB->Visible = true;
		buttonB->Text = "Deposit";
		buttonC->Visible = true;
		buttonC->Text = "Cancel";
		textBox2->Text = "Balance: $0.0\nEnter amount and select transaction type.";
		break;
	}
	}
	textBox1->Clear();
}

void atmForm::error_window(System::String^ error_text) {
	errorWindow^ e = gcnew errorWindow();
	e->getLabel()->Text = error_text;
	e->ShowDialog();
	textBox1->Clear();
}