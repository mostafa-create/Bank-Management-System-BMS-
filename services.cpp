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
account::account() {
	cout << "\n\n                                          -> Bank Management System <-" << endl << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
void account::Create_Card() {
	cout << "chose one option :" << endl << endl;
	cout << "\t1: Bank Masr Card" << endl;
	cout << "\t2: National Bank Of Egypt Card" << endl;
	cout << "\t3: CIB Bank Card" << endl;
	cout << "\t4: Agricultural Bank Of Egypt Card" << endl;
	cout << "\t5: Arab African Internation Bank Card" << endl;
	cout << "\t6: Faisal Islamic Bank Of Egypt Card" << endl;
	cout << "Enter number between 1 - 6 or -1 to exit:";
	ll n; cin >> n;
	if (n > 6 || n < 1)return;
	else {
		if (n == 1)download_users_bank(n, bankmasr);
		if (n == 2)download_users_bank(n, nationalbank);
		if (n == 3)download_users_bank(n, cibbank);
		if (n == 4)download_users_bank(n, agribank);
		if (n == 5)download_users_bank(n, arabafricanbank);
		if (n == 6)download_users_bank(n, faisalbank);
		user test;
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, test.Name);
		char pass[100];
		cout << "Enter your password or -1 to exit: ";
		char ch;
		for (int i = 0;;)
		{
			ch = _getch();
			if (ch == 32)continue;
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
			{
				pass[i] = ch;
				i++;
				cout << "*";
			}
			else if (ch == '\b' && i >= 1)
			{
				cout << "\b \b";
				--i;
			}
			else if (ch == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		if (pass[0] == '-')return;
		test.Password = pass;
		test.Balance = 0;
		if (n == 1) {
			if (bankmasr.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = bankmasr.size() + 1;
			bankmasr.push_back(test);
			fstream upload;
			upload.open("BM.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		if (n == 2) {
			if (nationalbank.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = nationalbank.size() + 1;
			nationalbank.push_back(test);
			fstream upload;
			upload.open("NB.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		if (n == 3) {
			if (cibbank.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = cibbank.size() + 1;
			cibbank.push_back(test);
			fstream upload;
			upload.open("CIB.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		if (n == 4) {
			if (agribank.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = agribank.size() + 1;
			agribank.push_back(test);
			fstream upload;
			upload.open("AB.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		if (n == 5) {
			if (arabafricanbank.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = arabafricanbank.size() + 1;
			arabafricanbank.push_back(test);
			fstream upload;
			upload.open("AAB.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		if (n == 6) {
			if (faisalbank.size() == 0) {
				test.Accnum = 1;
			}
			else test.Accnum = faisalbank.size() + 1;
			faisalbank.push_back(test);
			fstream upload;
			upload.open("FIB.txt", ios::out | ios::app);
			upload << test.Name << endl << test.Accnum << endl << test.Password << endl << test.Balance << endl;
			upload.close();
		}
		cout << "\nYour account number is " << test.Accnum << " remember it and keep it safe." << endl;
		cout << "Card is created successfully...please login with your card." << endl;

	}
}
bool account::Login(ll num, vector < user >& v) {
	download_users_bank(num, v);
	ll accnum;
	user per;
	bool accisfound = false;
	while (accisfound == false) {
		cout << "Enter your account number or -1 to exit: "; cin >> accnum;
		if (accnum == -1)return false;
		for (auto it : v) {
			if (it.Accnum == accnum) {
				per.Name = it.Name;
				per.Password = it.Password;
				per.Accnum = it.Accnum;
				per.Balance = it.Balance;
				accisfound = true;
			}
		}
		if (accisfound == false) {
			cout << "account number that you entered doesn't exsit...try again." << endl;
		}
	}
	char pass[100];
	do {
		cout << "Enter the password or -1 to exit: ";
		char ch;
		for (int i = 0;;)
		{
			ch = _getch();
			if (ch == 32)continue;
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
			{
				pass[i] = ch;
				i++;
				cout << "*";
			}
			else if (ch == '\b' && i >= 1)
			{
				cout << "\b \b";
				--i;
			}
			else if (ch == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		if (pass[0] == '-')return false;
		if (per.Password == pass) {
			cout << "\n\n\tWelcome, " << per.Name << endl;
			p = per;
			return true;
		}
		else {
			cout << "\nWrong password...Try again " << endl;
		}
	} while (true);
	return true;
}
void account::Deposit(ll num, vector < user >& v) {
	download_users_bank(num, v);
	cout << "Enter the amount or -1 to exit: ";
	ll depo; cin >> depo;
	if (depo == -1) return;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Accnum == p.Accnum) {
			v[i].Balance += depo;
			p.Balance += depo;
			break;
		}
	}
	upload_users_bank(num, v);
	cout << "Deposit has been done." << endl;
}
void account::Withdraw(ll num, vector < user >& v) {
	download_users_bank(num, v);
	cout << "Enter the amount or -1 to exit: ";
	ll wi; cin >> wi;
	if (wi == -1) return;
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].Accnum == p.Accnum) {
				if (v[i].Balance < wi) {
					cout << "Your balance is not enough." << endl;
					return;
				}
				v[i].Balance -= wi;
				p.Balance -= wi;
				break;
			}
		}
		upload_users_bank(num, v);
	}
	cout << "Withdraw has been done." << endl;
}
void account::Balance_Enquiry() {
	cout << "Your balance is : " << p.Balance << endl;
}
void account::Money_Transaction(ll num, vector < user >& v) {
	download_users_bank(num, v);
	cout << "Enter the account number you want transfer money to or -1 to exit:";
	ll accnu; cin >> accnu;
	if (accnu == -1)return;
	if (accnu == p.Accnum) {
		cout << "You can't transfer money to yourself." << endl;
		return;
	}
	bool isfound = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Accnum == accnu) {
			isfound = true;
			break;
		}
	}
	if (!isfound) {
		cout << "This account number does not exsit." << endl;
		return;
	}
	cout << "Enter the amount or -1 to exit:";
	ll n; cin >> n;
	if (n == -1)return;
	if (n > p.Balance) {
		cout << "Your balance is not enough." << endl;
		return;
	}
	cout << "Press y/Y to confirme or n/N to exit :";
	char c; cin >> c;
	if (c == 'y' || c == 'Y') {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].Accnum == accnu) {
				v[i].Balance += n;
			}
			if (v[i].Accnum == p.Accnum) {
				v[i].Balance -= n;
			}
		}
	}
	else return;
	transfer ob;
	ob.Banktype = num;
	ob.Fromacc = p.Accnum;
	ob.Toacc = accnu;
	ob.Amount = n;
	Tran.push_back(ob);
	upload(ob.Banktype, ob.Fromacc, ob.Toacc, ob.Amount);
	upload_users_bank(num, v);
	cout << "Transaction has been done." << endl;
}
void account::Create_Phone_Wallet() {
	download_all_wallets();
	cout << "Enter the your wallet's number: ";
	phone_wallet test;
	cin >> test.number;
	for (auto it : Wallets) {
		if (it.number == test.number) {
			cout << "This phone has already a phone wallet." << endl;
			return;
		}
	}
	if (num_validation(test.number)) {
		char pass[100];
		while (true) {
			cout << "Enter password more than 5 digits/numbers or -1 to exit: ";
			char ch;
			int i;
			for (i = 0;;)
			{
				ch = _getch();
				if (ch == 32)continue;
				if (ch == '\b')continue;
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
				{
					pass[i] = ch;
					i++;
					cout << "*";
				}
				else if (ch == '\b' && i >= 1)
				{
					cout << "\b \b";
					--i;
				}
				else if (ch == '\r')
				{
					pass[i] = '\0';
					break;
				}
			}
			if (pass[0] == '-') {
				return;
			}
			if (i < 6) {
				cout << "\nInvlaid...Please enter more than 5 digits" << endl;
			}
			else break;
		}
		test.password = pass;
		test.Balance = 0;
		Wallets.push_back(test);
		upload(test.number, test.password, test.Balance);
		cout << "\nPhone wallet has been created." << endl;
	}
	else {
		cout << "This number is not valid." << endl;
	}

}
void account::Deposit_In_A_Phone_wallet() {
	download_all_wallets();
	cout << "Enter the wallet's number:";
	string num; cin >> num;
	bool isfound = false;
	for (int i = 0; i < Wallets.size(); i++) {
		if (Wallets[i].number == num) {
			isfound = true;
			char pass[100];
			while (true) {
				cout << "Enter The password or -1 to exit: ";
				char ch;
				int j;
				for (j = 0;;)
				{
					ch = _getch();
					if (ch == 32)continue;
					if (ch == '\b')continue;
					if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
					{
						pass[j] = ch;
						j++;
						cout << "*";
					}
					else if (ch == '\b' && j >= 1)
					{
						cout << "\b \b";
						--j;
					}
					else if (ch == '\r')
					{
						pass[j] = '\0';
						break;
					}
				}
				if (pass[0] == '-') {
					return;
				}
				if (pass != Wallets[i].password) {
					cout << "\nInvlaid...Please enter again" << endl;
				}
				else break;
			}
			cout << "\nEnter the amount: ";
			ll amount; cin >> amount;
			cout << "Press y/Y to confirme or n/N to exit :";
			char c; cin >> c;
			if (c == 'y' || c == 'Y') {
				Wallets[i].Balance += amount;
				upload_all_wallets();
			}
			else {
				return;
			}
			break;
		}
	}
	if (!isfound) {
		cout << "This number does not have a wallet." << endl;
	}

}
void account::Withdraw_In_A_Phone_wallet() {
	download_all_wallets();
	cout << "Enter the wallet's number:";
	string num; cin >> num;
	bool isfound = false;
	for (int i = 0; i < Wallets.size(); i++) {
		if (Wallets[i].number == num) {
			isfound = true;
			char pass[100];
			while (true) {
				cout << "Enter The password or -1 to exit: ";
				char ch;
				int j;
				for (j = 0;;)
				{
					ch = _getch();
					if (ch == 32)continue;
					if (ch == '\b')continue;
					if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
					{
						pass[j] = ch;
						j++;
						cout << "*";
					}
					else if (ch == '\b' && j >= 1)
					{
						cout << "\b \b";
						--j;
					}
					else if (ch == '\r')
					{
						pass[j] = '\0';
						break;
					}
				}
				if (pass[0] == '-') {
					return;
				}
				if (pass != Wallets[i].password) {
					cout << "\nInvlaid...Please enter again" << endl;
				}
				else break;
			}
			cout << "\nEnter the amount: ";
			ll amount; cin >> amount;
			cout << "Press y/Y to confirme or n/N to exit :";
			char c; cin >> c;
			if (c == 'y' || c == 'Y') {
				if (Wallets[i].Balance < amount) {
					cout << "The wallet's balance is not enough." << endl;
					return;
				}
				Wallets[i].Balance -= amount;
				upload_all_wallets();
			}
			else {
				return;
			}
			break;
		}
	}
	if (!isfound) {
		cout << "This number does not have a wallet." << endl;
	}
}
void account::Modify_The_Account(ll num, vector < user >& v) {
	cout << "Chose one option: " << endl;
	cout << "\n\t1. Change your name." << endl;
	cout << "\t2. Change your password." << endl << endl;
	ll num1;
	do {
		cout << "Enter option's number or -1 to exit: ";
		cin >> num1;
		if (num1 == -1)return;
		if (num1 != 1 && num1 != 2) {
			cout << "\nInvalid input...try again.";
		}
	} while (num1 != 1 && num1 != 2);
	if (num1 == 1) {
		string name;
		cout << "Enter the new name: ";
		cin.ignore();
		getline(cin, name);
		for (int i = 0; i < v.size(); i++) {
			if (v[i].Accnum == p.Accnum) {
				v[i].Name = name; break;
			}
		}
		upload_users_bank(num, v);
	}
	else {
		char pass[100];
		cout << "Enter the new password or -1 to exit: ";
		char ch;
		int j;
		for (j = 0;;)
		{
			ch = _getch();
			if (ch == 32)continue;
			if (ch == '\b')continue;
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
			{
				pass[j] = ch;
				j++;
				cout << "*";
			}
			else if (ch == '\b' && j >= 1)
			{
				cout << "\b \b";
				--j;
			}
			else if (ch == '\r')
			{
				pass[j] = '\0';
				break;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].Accnum == p.Accnum) {
				v[i].Password = pass;
				break;
			}
		}
		upload_users_bank(num, v);
		cout << endl;
	}

}
void account::Show_Transfers_To_Me(ll banktype) {
	download_all_transfers();
	bool isfound = false;
	for (int i = 0; i < Tran.size(); i++) {
		if (Tran[i].Banktype == banktype) {
			if (Tran[i].Toacc == p.Accnum) {
				isfound = true;
				cout << "\nMoney transaction from card number( " << Tran[i].Fromacc << " ) to your card, the amount is: "
					<< Tran[i].Amount << endl << endl;
			}
		}
	}
	if (!isfound) {
		cout << "\nThere isn't any money transactions to your card." << endl;
	}


}
void account::Show_Transfers_From_Me(ll banktype) {
	download_all_transfers();
	bool isfound = false;
	for (int i = 0; i < Tran.size(); i++) {
		if (Tran[i].Banktype == banktype) {
			if (Tran[i].Fromacc == p.Accnum) {
				isfound = true;
				cout << "\nMoney transaction from your card to card number ( " << Tran[i].Toacc << " ) the amount is: "
					<< Tran[i].Amount << endl << endl;
			}
		}
	}
	if (!isfound) {
		cout << "\nThere isn't any money transactions from your card." << endl;
	}
}
void account::Logout() {
	return;
}
bool account::Delete_Card(ll num, vector < user >& v) {
	vector < user > temp;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Accnum != p.Accnum) {
			temp.push_back(v[i]);
		}
	}
	cout << "Press y/Y to confirme deleting your card or n/N to exit: ";
	char ch; cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		upload_users_bank(num, temp);
		cout << "Card has beed deleted" << endl;
		return true;
	}
	return false;

}
account::~account()
{
	cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                                Hope you enjoyed" << endl << endl;
}
