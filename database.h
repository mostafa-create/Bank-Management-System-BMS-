#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#define ll long long    
using namespace std;
struct user {
	string Name, Password;
	ll Accnum, Balance;
};
struct transfer {

	ll Banktype, Fromacc, Toacc, Amount;
};
struct phone_wallet {
	string number, password;
	ll Balance;
};
vector < transfer > Tran;
vector < phone_wallet > Wallets;
vector < user > bankmasr;
vector < user > nationalbank;
vector < user > agribank;
vector < user > arabafricanbank;
vector < user > cibbank;
vector < user > faisalbank;
vector < string > Banks = { "BM.txt","NB.txt","CIB.txt","AB.txt","AAB.txt","FIB.txt" };
user p;
transfer m;
class database {
public:
	database();
	void upload_users_bank(ll, vector < user >(&));
	void download_users_bank(ll, vector < user >(&));
	void download_all_transfers();
	void upload_all_transfers();
	void upload_transfer(ll, ll, ll, ll);
	void upload_wallet(string, string, ll);
	void upload_all_wallets();
	void download_all_wallets();
	bool num_validation(string);
};