#include <iostream>
#include"Fournisseur.h"
#include"Facture.h"
#include"Medicament.h"
#include"Pharmacien.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
    Pharmacien p;
    p.setIdentifiant(786);
    p.setMDP("62345678");
    p.setNom("OUT");
    p.setPrenom("Yahya");
    p.setrole("Admin");
    cin>>p;
    
	return 0;
}
