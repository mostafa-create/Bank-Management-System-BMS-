#pragma once
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
class account : public database {
protected:
	user p;
	transfer m;
public:
	account();
	bool num_validation(string num) {
		for (auto it : num) {
			if (it >= '0' && it <= '9') {
				continue;
			}
			else return false;
		}
		if (num.size() == 11)return true;
		return false;
	}
	bool Login(ll, vector < user >(&));
	void Create_Card();
	void Deposit(ll, vector < user >(&));
	void Withdraw(ll, vector < user >(&));
	void Balance_Enquiry();
	void Money_Transaction(ll, vector < user >(&));
	void Create_Phone_Wallet();
	void Deposit_In_A_Phone_wallet();
	void Withdraw_In_A_Phone_wallet();
	void Show_Transfers_To_Me(ll);
	void Show_Transfers_From_Me(ll);
	void Modify_The_Account(ll, vector < user >(&));
	void Logout();
	bool Delete_Card(ll, vector < user >(&));
	~account();
};
