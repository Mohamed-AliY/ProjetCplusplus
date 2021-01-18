#pragma once

#include <iostream>
#include <string>

class Parametres{
public:
	Parametres();
	void consulteParam();
	void afficherTous();
	void Changer(int num);
	//getters
	int getAvecResume(){return avecResume;};
	int getNivDifficulte(){return nivDifficulte;};
	int getAffichageSymboles(){return affichageSymboles;};
	int getAffichageIndex(){return affichageIndex;};
	int getSansEgalite(){return sansEgalite;};
	int getCritereEgalite(){return critereEgalite;};
	//setters
	void setAffichageSymboles(int affichageSymb)
	{affichageSymboles=affichageSymb;};
	void setAffichageIndex(int affichageInd)
	{affichageIndex=affichageInd;};
	void setCritereEgalite(int critereEgal)
	{critereEgalite=critereEgal;};
	void setNivDifficulte(int nivDiff)
	{nivDifficulte=nivDiff;};
	void setSansEgalite(int sansEga)
	{sansEgalite=sansEga;};
	void setAvecResume(int avecResum)
	{avecResume=avecResum;};

private:
	int affichageSymboles;
	int affichageIndex;
	int critereEgalite;
	int nivDifficulte;
	int sansEgalite;
	int avecResume;
};