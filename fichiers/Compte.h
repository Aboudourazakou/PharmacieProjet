#ifndef COMPTE_H
#define COMPTE_H
#include<iostream>
using namespace std;

class Compte
{
	private:
	int identifiant;
	string password;
	string role;
	public:
		bool createCompte(int id,string password,string role);
	
};

#endif
