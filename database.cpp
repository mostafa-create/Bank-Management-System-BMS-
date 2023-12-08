#include "database.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#define ll long long    
using namespace std;
database::database() {
	fstream Usersfile("Users.txt");
	fstream Transfers("Transfers.txt");
	fstream wallets("Phone.txt");
	fstream Bankmasr("BM.txt");
	fstream Nationalbank("NB.txt");
	fstream cib("CIB.txt");
	fstream Agribank("AB.txt");
	fstream fasialbank("FIB.txt");
	fstream Arabafricanbank("AAB.txt");
}
void database::download_users_bank(ll num, vector < user >& v) {
	v.clear();
	string line;
	ll cnt = 0;
	ifstream outFile;
	outFile.open(Banks[num - 1]);
	user test;
	while (getline(outFile, line))
	{
		if (cnt % 4 == 0) {
			test.Name = (line);
			cnt++;
		}
		else if (cnt % 4 == 2) {
			test.Password = (line);
			cnt++;
		}
		else if (cnt % 4 == 1) {
			test.Accnum = stoi(line);
			cnt++;
		}
		else if (cnt % 4 == 3) {
			test.Balance = stoi(line);
			v.push_back(test);
			cnt++;
		}
	}
	outFile.close();
}
void database::upload_users_bank(ll num, vector < user >& v) {
	fstream uploadUser;
	uploadUser.open(Banks[num - 1], ios::out | ios::trunc);
	for (auto it : v) {
		uploadUser << it.Name << endl << it.Accnum << endl << it.Password << endl << it.Balance << endl;
	}
	uploadUser.close();
}
void database::download_all_transfers() {
	Tran.clear();
	string line;
	ll cnt = 0;
	ifstream outFile;
	outFile.open("Transfers.txt");
	transfer test;
	while (getline(outFile, line))
	{
		if (cnt % 4 == 0) {
			test.Banktype = stoi(line);
			cnt++;
		}
		else if (cnt % 4 == 1) {
			test.Fromacc = stoi(line);
			cnt++;
		}
		else if (cnt % 4 == 2) {
			test.Toacc = stoi(line);
			cnt++;
		}
		else if (cnt % 4 == 3) {
			test.Amount = stoi(line);
			Tran.push_back(test);
			cnt++;
		}
	}
	outFile.close();
}
void database::upload_all_transfers() {
	fstream uploadtran;
	uploadtran.open("Transfers.txt", ios::out | ios::trunc);
	for (auto it : Tran) {
		uploadtran << it.Banktype << endl << it.Fromacc << endl << it.Toacc << endl << it.Amount << endl;
	}
	uploadtran.close();
}
void database::upload_transfer(ll num, ll fromacc, ll toacc, ll amount) {
	fstream uploadtran;
	uploadtran.open("Transfers.txt", ios::out | ios::app);
	uploadtran << num << endl << fromacc << endl << toacc << endl << amount << endl;
	uploadtran.close();
}
void database::upload_wallet(string num, string pass, ll balance) {
	fstream uploadwallet;
	uploadwallet.open("Phone.txt", ios::out | ios::app);
	uploadwallet << num << endl << pass << endl << balance << endl;
	uploadwallet.close();
}
void database::upload_all_wallets() {
	fstream uploadwallets;
	uploadwallets.open("Phone.txt", ios::out | ios::trunc);
	for (auto it : Wallets) {
		uploadwallets << it.number << endl << it.password << endl << it.Balance << endl;
	}
	uploadwallets.close();
}
void database::download_all_wallets() {
	Wallets.clear();
	string line;
	ll cnt = 0;
	ifstream outFile;
	outFile.open("Phone.txt");
	phone_wallet test;
	while (getline(outFile, line))
	{
		if (cnt % 3 == 0) {
			test.number = (line);
			cnt++;
		}
		else if (cnt % 3 == 1) {
			test.password = (line);
			cnt++;
		}
		else if (cnt % 3 == 2) {
			test.Balance = stoi(line);
			Wallets.push_back(test);
			cnt++;
		}
	}
	outFile.close();
}
bool database::num_validation(string num) {
	for (auto it : num) {
		if (it >= '0' && it <= '9') {
			continue;
		}
		else return false;
	}
	if (num.size() == 11)return true;
	return false;
}