#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H
#include "Pharmacien.h"
#include <Windows.h>

class Medicament;
class Administrateur : public Pharmacien
{
	
	
	public:
		
		Administrateur(int,string,string);
		string creerCompte(string id);
		void creerPharmacien();
		string supprimerPharmacien(string);
		string supprimerCompte(string,string);
		bool modifierPharmacien(string);
		void modifierMedicament(string,Medicament &);
		void ajouterMedicament(Medicament &M);
		void supprimerMedicament();
		void ModifierMedicament();
		void supprimerFacture();
		void afficherPharmaciens();
		bool supprimerMedicament(string);
		
		
		

};
#include"Medicament.h"

#endif

