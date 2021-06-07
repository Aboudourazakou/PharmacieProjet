#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <iostream>

using namespace std;
class Medicament
{
	private:
		int code;
		string nomc;
		string DCI;
		int quantite;
		float prix_unite;
		string dosage;
		string date_exp;
		int nbrvente;
		public:
		void	modifier();
		void	afficher();
		bool etat_medicament();
	      void getcode(int);
		void getnomc(string);
		void getDCI(string);
		void getquantite(int);
		void getprix_unite(float);
		void getdosage(float);
		void getdate_exp(string); 
		void getnbrvente(int);
		void setcode(int);
		void setnomc(string);
		void setDCI(string);
		void setquantite(int);
		void setprix_unite(float);
		void setdosage(float);
		void setdate_xp(string); 
		void setnbrvente(int);
		friend istream &operator>>(istream &,Medicament &);
		
};

#endif
