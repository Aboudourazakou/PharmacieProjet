#include "Medicament.h"
#include<fstream>


 istream &operator>>(istream &c,Medicament &m){
 	 ofstream file1("Medicament.txt",ios::app);
 	 file1<<m.code<<"|"<<m.nomc<<"|"<<m.DCI<<"|"<<m.quantite<<"|"<<m.prix_unite<<"|"<<m.dosage<<"|"<<m.date_exp<<"|"<<m.nbrvente<<endl;
 }
 void Medicament::setcode(int b){
 	code=b;
 }
 void Medicament::setdate_xp(string c){
 	date_exp=c;
 }
 void Medicament::setDCI(string c){
 	DCI=c;
 }
 void Medicament::setdosage(float c){
 	dosage=c;
 }
 void Medicament::setnbrvente(int c){
 	nbrvente=c;
 }
 void Medicament::setnomc(string c){
 	nomc=c;
 }
 void Medicament::setprix_unite(float c){
 	prix_unite=c;
 }
 void Medicament::setquantite(int c){
 	quantite=c;
 }
 
