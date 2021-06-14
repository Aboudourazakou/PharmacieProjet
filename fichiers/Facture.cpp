#include "Facture.h"
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;


void Facture::GenererFacture(){
	
	ofstream file("facture.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	
	else{
		file<<idFacture<<"|"<<idVendeur<<"|"<<nomVendeur<<"|"<<date<<endl;
		ifstream file2("panier.txt",ios::in);
		ofstream file3("vente.txt",ios::app);
		string line;
		
		while(getline(file2,line)){
			file3<<line<<endl;
		}
		
		file2.close();
		file3.close();
		remove("panier.txt");
		
		
	}
	cout<<"Votre vente a ete sauvegarder avec succes"<<endl<<endl;

};





void Facture::afficherFacture(string id){
	 ifstream file("facture.txt",ios::in);
	 ifstream file2("vente.txt");
	 if(file.bad() || file2.bad())cout<<"Erreur d'ouverture fichier"<<endl;

	 else{
	 		 string line,line2,nom,date;
	 	 while(getline(file,line)){
	 	  if(line!="\0"){
	 	  	
	 	  		char N[200];
	 	 	strcpy(N,line.c_str());
	 	 	char *tempon=strtok(N,"|");
	 	 	if(!strcmp(tempon,id.c_str())){
	 	 		
	 	 		tempon=strtok(NULL,"|");
	 	 		tempon=strtok(NULL,"|");
	 	 	    nom=tempon;
	 	 		tempon=strtok(NULL,"|");
	 	 	    date=tempon;
	 	 	    cout<<endl<<endl<<"Nom de la societe: Pharmacie Nouvelle"<<endl;
	 	 	    cout<<"Vendeur:   "<<nom<<endl;
	 	 	    cout<<"Date de vente:    "<<date<<endl;
	 	 	    cout<<"Identifiant de la facture:   "<<id<<endl;
	 	 	    cout<<"MEDICAMENTS ACHETES ET PRIX   "<<endl;
	 	 	    cout<<"Designation|Quantite|Posologie|Prix unitaire|Prix total|"<<endl<<endl;
	 	 	    float sommeTotal=0;
	 	 	    bool trouve=false;
	 	 	    
	 	 	    while(getline(file2,line2)){
	 	 	    	if(line2!="\0"){ 
					  
	 	 	    	char L[200];
	 	 	    	strcpy(L,line2.c_str());
	 	 	    	char *neutre=strtok(L,"|");
	 	 	    	if(!strcmp(neutre,id.c_str())){
	 	 	    	     trouve=true;
	 	 	    	     tempon=strtok(NULL,"|");
					      string designation=tempon;
					     tempon=strtok(NULL,"|");
					     string quantite=tempon;
					     tempon=strtok(NULL,"|");
					     string prixUnite=tempon;
					     tempon=strtok(NULL,"|");
					     string dosage=tempon;
					     tempon=strtok(NULL,"|");
					     tempon=strtok(NULL,"|");
					     float prixTotal=atof(tempon);
					     sommeTotal+=prixTotal;
					     cout<<designation<<"     "<<quantite<<"    "<<prixUnite<<"  "<<dosage<<"   "<<prixTotal<<endl;
					 }
					   		
	 	 	    		
					}
				  }
				  if(trouve==true)cout<<endl<<"Montant total:     "<<sommeTotal<<endl;
				  
				  file.close();
				  file2.close();
	 	 	    
	 	 		
			  }
		   }
	 	 	
	 	 	
          
		  }
	 	
	   }
}
