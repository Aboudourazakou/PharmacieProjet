#include "Medicament.h"
#include<fstream>
using namespace std;



Medicament::Medicament(int c,string n,string dc,int q,float p,string d,string da,int nb){
	
	
	  code=c;
	  nomc=n;
	  DCI=d;
	  quantite=q;
	  prix_unite=p;
	  dosage=d;
	  date_exp=d;
	  nbrvente=nb;
	
}



istream &operator>>(istream &c,Medicament &m){
	ofstream file("medicament.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	else{
		file<<m.code<<"|"<<m.nomc<<"|"<<m.DCI<<"|"<<m.quantite<<"|"<<m.prix_unite<<"|"<<m.dosage<<"|"<<m.date_exp<<"|"<<m.nbrvente<<endl;
	    cout<<"Medicament ajoute avec Success"<<endl;
	}
}



	
  void Medicament::setcode(int c)
  { 
   
  code=c;
  };
 void Medicament::setdate_xp(string c)
 { 
 date_exp=c;
 };
 void Medicament::setDCI(string c)
 {
 DCI=c;
 };
 void Medicament::setdosage(string c)
 {
 dosage=c;
 };
 void Medicament::setnbrvente(int c)
 {
 nbrvente=c;
 };
 
 void Medicament::setnomc(string c)
 {
         nomc=c;
 };
 
 void Medicament::setprix_unite(float c)
 {
 prix_unite=c;
 };
 void Medicament::setquantite(int c)
 {
 quantite=c;
 };
 
 
 void Medicament::afficher(){
 	cout<<"le code est :"<<code<<endl;
	cout<<"le nom du medicament:"<<nomc<<endl;
	cout<<"le nom international du medicament:"<<DCI<<endl;
	cout<<"le prix de l'unite:"<<prix_unite<<endl;
	cout<<"la quantite du medicament:"<<quantite<<endl;
	cout<<"la dose est :"<<dosage<<endl;
	cout<<"la date d'experation:"<<date_exp<<endl;
	cout<<"le nombre de vente est :"<<nbrvente<<endl;
	
 }
 
 int Medicament::getquantite(){
 	return quantite;
 }
 
 

