#include "services.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#define ll long long    
using namespace std;
#define endl "\n"
void start() {
	account per;
	cout << "Main Menu:" << endl;
	cout << "chose one option :" << endl << endl;
	cout << " \t1: Bank Masr Card" << endl;
	cout << " \t2: National Bank Of Egypt Card" << endl;
	cout << " \t3: CIB Bank Card" << endl;
	cout << " \t4: Agricultural Bank Of Egypt Card" << endl;
	cout << " \t5: Arab African Internation Bank Card" << endl;
	cout << " \t6: Faisal Islamic Bank Of Egypt Card" << endl;
	cout << " \t7: Create Card" << endl;
	cout << " \t8: Create A Phone Wallet" << endl;
	cout << " \t9: Deposit In A Phone wallet" << endl;
	cout << "\t10: Withdraw In A Phone wallet" << endl << endl;
	int num;
	do {
		cout << "Enter number in range 1 - 10 or -1 to exit: ";
		cin >> num;
		if (num == -1) {
			return;
		}
		if (num > 10 || num < 1) {
			cout << "Invalid number...Try again." << endl;
			continue;
		}
		else {
			vector < user > v;
			ll m = 0;
			bool isloggedin = 0;
			if (num == 1) {
				if (per.Login(num, bankmasr)) {
					isloggedin = true;
					v = bankmasr;
					m = num;
				}
			}
			else if (num == 2) {
				if (per.Login(num, nationalbank)) {
					isloggedin = true;
					v = nationalbank;
					m = num;
				}
			}
			else if (num == 3) {
				if (per.Login(num, cibbank)) {
					isloggedin = true;
					v = cibbank;
					m = num;
				}
			}
			else if (num == 4) {
				if (per.Login(num, agribank)) {
					isloggedin = true;
					v = agribank;
					m = num;
				}
			}
			else if (num == 5) {
				if (per.Login(num, arabafricanbank)) {
					isloggedin = true;
					v = arabafricanbank;
					m = num;
				}
			}
			else if (num == 6) {
				if (per.Login(num, faisalbank)) {
					isloggedin = true;
					v = faisalbank;
					m = num;
				}
			}
			else if (num == 7) {
				per.Create_Card();
			}
			else if (num == 8) {
				per.Create_Phone_Wallet();
			}
			else if (num == 9) {
				per.Deposit_In_A_Phone_wallet();
			}
			else if (num == 10) {
				per.Withdraw_In_A_Phone_wallet();
			}
			if (isloggedin) {
				cout << endl;
				cout << " Services: " << endl;
				cout << "  \t1: Deposit" << endl;
				cout << "  \t2: Withdraw" << endl;
				cout << "  \t3: Balance Enquiry" << endl;
				cout << "  \t4: Send Money To Another Account" << endl;
				cout << "  \t5: Modify The Account" << endl;
				cout << "  \t6: Show Transfers To Me" << endl;
				cout << "  \t7: Show Transfers from Me" << endl;
				cout << "  \t8: Logout" << endl;
				cout << "  \t9: Delete My Card" << endl;
				int num2;
				do {
					cout << "Enter number in range 1 - 9 or -1 to exit: ";
					cin >> num2;
					if (num2 == -1) {
						return;
					}
					if (num2 > 9 || num2 < 1) {
						cout << "Invalid number...Try again." << endl;
					}
					else {
						if (num2 == 1) per.Deposit(num, v);
						else if (num2 == 2) per.Withdraw(num, v);
						else if (num2 == 3) per.Balance_Enquiry();
						else if (num2 == 4) per.Money_Transaction(num, v);
						else if (num2 == 5) per.Modify_The_Account(num, v);
						else if (num2 == 6) per.Show_Transfers_To_Me(num);
						else if (num2 == 7) per.Show_Transfers_From_Me(num);
						else if (num2 == 8) per.Logout();
						else if (num2 == 9) {
							if (num == 1) {
								if (per.Delete_Card(num, bankmasr)) {
									return;
								}
							}
							if (num == 2) {
								if (per.Delete_Card(num, nationalbank)) {
									return;
								}
							}
							if (num == 3) {
								if (per.Delete_Card(num, cibbank)) {
									return;
								}
							}
							if (num == 4) {
								if (per.Delete_Card(num, agribank)) {
									return;
								}
							}
							if (num == 5) {
								if (per.Delete_Card(num, arabafricanbank)) {
									return;
								}
							}
							if (num == 6) {
								if (per.Delete_Card(num, faisalbank)) {
									return;
								}
							}
						}
					}
				} while (num2 != 8);
			}
		}
	} while (num > 10 || num < 1);
}
int main()
{
	start();
	return 0;
}