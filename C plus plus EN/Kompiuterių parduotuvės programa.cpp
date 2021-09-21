// Obj Programavimo Egzas.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Dominykas V. PRM

#include <iostream>
using namespace std;
//-----------------------------------
class Procesorius {
private:
	int greitis;
	float kaina;
	string architektura;
	int kiekBranduoliu;
	float kiekSuvartojaEl;
	string Pavadinimas;

public:
	Procesorius() {}
	Procesorius(int grei, float kai, string arch, int kbra, float keikel, string pav) {
		greitis = grei;
		kaina = kai;
		architektura = arch;
		kiekBranduoliu = kbra;
		kiekSuvartojaEl = keikel;
		Pavadinimas = pav;
	}
//Setters
	void SetGreitis(int grei) {
		greitis = grei;
	}
	void SetKaina(float kai) {
		kaina = kai;
	}
	void SetArchitektura(string arch) {
		architektura = arch;
	}
	void SetBranduoliai(int kbra) {
		kiekBranduoliu = kbra;
	}
	void SetElSuvartojimas(float keikel) {
		kiekSuvartojaEl = keikel;
	}
	void SetPavadinimas(string pav) {
		Pavadinimas = pav;
	}
//Getters
	int GetGreitis() {
		return greitis;
	}
	float GetKaina() {
		return kaina;
	}
	string GetArchitektura() {
		return architektura;
	}
	int GetBranduoliai() {
		return kiekBranduoliu;
	}
	float GetElSuvartojimas() {
		return kiekSuvartojaEl;
	}
	string GetPavadinimas() {
		return Pavadinimas;
	}
//Konstruktai

};
//-----------------------------------
class Vaizdo_Plokste {
private:
	string pavadinimas;
	float greitis;
	float kaina;
	string architektura;
	int branduoliuKiekis;
	int hashRate;
	int kiekRam;

public:
	Vaizdo_Plokste() {}
	Vaizdo_Plokste(string pav, float grei, float kain, string arch, int kiekbra, int hashr, int kiekr) {
		pavadinimas = pav;
		greitis = grei;
		kaina = kain;
		architektura = arch;
		branduoliuKiekis = kiekbra;
		hashRate = hashr;
		kiekRam = kiekr;

	}
//Setters
	void SetPavadinimas(string pav) {
		pavadinimas = pav;
	}
	void SetGreitis(float grei) {
		greitis = grei;
	}
	void SetKaina(float kain) {
		kaina = kain;
	}
	void SetArchitektura(string arch) {
		architektura = arch;
	}
	void SetBranduoliuKiekis(int kiekbra) {
		branduoliuKiekis = kiekbra;
	}
	void SetHashRate(int hashr) {
		hashRate = hashr;
	}
	void SetRam(int kiekr) {
		kiekRam = kiekr;
	}
//Getters
	string GetPavadinimas() {
		return pavadinimas;
	}
	float GetGreitis() {
		return greitis;
	}
	float GetKaina() {
		return kaina;
	}
	string GetArchitektura() {
		return architektura;
	}
	int GetBranduoliuKiekis() {
		return branduoliuKiekis;
	}
	int GetHashRate() {
		return hashRate;
	}
	int GetRam() {
		return kiekRam;
	}
//Konstruktai

};
//-----------------------------------
class Kompiuteris: public Vaizdo_Plokste, public Procesorius{
private:
	string pavadinimas;
	int kurisCPU;
	int kurisGPU;
public:

	Kompiuteris() {}
	Kompiuteris(string pav, int kcpu, int kgpu) {
		pavadinimas = pav;
		kurisCPU = kcpu;
		kurisGPU = kgpu;
	}

//Setter
	void SetPavadinimas(string pav) {
		pavadinimas = pav;		
	}
	void SetKurisCPU(int kcpu) {
		kurisCPU = kcpu;
	}
	void SetKurisGPU(int kgpu) {
		kurisGPU = kgpu;
	}
//Getter
	string GetPavadinimas() {
		return pavadinimas;
	}
	int GetKurisCPU() {
		return kurisCPU;
	}
	int GetKurisGPU() {
		return kurisGPU;
	}
	//Konstruktai
	
};
//-----------------------------------
class Parduotuve {
private:
	int kiekPC = 0;
	int kiekGPU = 0;
	int kiekCPU = 0;
public:
	Kompiuteris PC[50];
	Vaizdo_Plokste GPU[50];
	Procesorius CPU[50];
//Setters
	void SetKiekPC(int pc) {
		kiekPC = pc;
	}
	void SetKiekGPU(int gpu) {
		kiekGPU = gpu;
	}
	void SetKiekCPU(int cpu) {
		kiekCPU = cpu;
	}

//Getters
	int GetKiekPC() {
		return kiekPC;
	}
	int GetKiekGPU() {
		return kiekGPU;
	}
	int GetKiekCPU() {
		return kiekCPU;
	}
	
};
//-----------------------------------
void ContentMenu() {
	cout << "|------------------------------|" << endl;
	cout << "|1. Prideti CPU.               |" << endl;
	cout << "|2. Prideti GPU.               |" << endl;
	cout << "|3. Atspausdinti visus CPU.    |" << endl;
	cout << "|4. Atspausdinti visus GPU.    |" << endl;
	cout << "|5. Sukurti kompiuteri.        |" << endl;
	cout << "|6. Atspausdinti kompiuterius. |" << endl;
	cout << "|7. Exit.                      |" << endl;
	cout << "|------------------------------|" << endl;

}
//-----------------------------------
void PridetiCPU(Parduotuve &shop);
void AtspausdintiCPU(Parduotuve shop);
void PridetGPU(Parduotuve& shop);
void AtspausdintiGPU(Parduotuve shop);
void SukurtiKompiuteri(Parduotuve &shop);
void AtspausdintiKompiuterius(Parduotuve shop);
//-----------------------------------
float BendraKaina(float a, float b) {
	return a + b;
}
//-----------------------------------
int main()
{
	Parduotuve shop;
	int Pas;
	do {
		ContentMenu();
		cout << ">";
		cin >> Pas;
		switch (Pas){
		case 1:
			PridetiCPU(shop);
			break;
		case 2:
			PridetGPU(shop);
			break;
		case 3:
			AtspausdintiCPU(shop);
			break;
		case 4:
			AtspausdintiGPU(shop);
			break;
			SukurtiKompiuteri(shop);
		case 5:
			SukurtiKompiuteri(shop);
			break;
		case 6:
			AtspausdintiKompiuterius(shop);
			break;

		default:
			cout << "Tokio pasirinkimo nera." << endl;
			break;
		}

	} while (Pas != 7);
	
}
//-----------------------------------
void PridetiCPU(Parduotuve& shop) {

	int sk;
	string zod;
	float skplus;
	cout << "Iveskite pavadinima: ";
	cin >> zod;
	shop.CPU[shop.GetKiekCPU()].SetPavadinimas(zod);
	cout << "Iveskite greiti: ";
	cin >> sk;
	shop.CPU[shop.GetKiekCPU()].SetGreitis(sk);
	cout << "Iveskite kaina: ";
	cin >> skplus;
	shop.CPU[shop.GetKiekCPU()].SetKaina(skplus);
	cout << "Iveskite architekturos tipa: ";
	cin >> zod;
	shop.CPU[shop.GetKiekCPU()].SetArchitektura(zod);
	cout << "Iveskite branduoliu skaiciu: ";
	cin >> sk;
	shop.CPU[shop.GetKiekCPU()].SetBranduoliai(sk);
	cout << "Iveskite kiek per metus suvartoja elektros: ";
	cin >> skplus;
	shop.CPU[shop.GetKiekCPU()].SetElSuvartojimas(skplus);
	shop.SetKiekCPU(shop.GetKiekCPU() + 1);
	cout << endl;

}
//-----------------------------------
void AtspausdintiCPU(Parduotuve shop) {

	for (int i = 0; i < shop.GetKiekCPU(); i++) {
		cout << i+1 << ". " << shop.CPU[i].GetPavadinimas() << " " << shop.CPU[i].GetGreitis() << " " << shop.CPU[i].GetKaina() << " " << shop.CPU[i].GetArchitektura() << " ";
		cout << shop.CPU[i].GetBranduoliai() << " " << shop.CPU[i].GetElSuvartojimas() << endl;
	}
	cout << endl;

}
//-----------------------------------
void PridetGPU(Parduotuve &shop) {

	int sk;
	string zod;
	float skplus;
	cout << "Iveskite pavadinima: ";
	cin >> zod;
	shop.GPU[shop.GetKiekGPU()].SetPavadinimas(zod);
	cout << "Iveskite greiti: ";
	cin >> skplus;
	shop.GPU[shop.GetKiekGPU()].SetGreitis(skplus);
	cout << "Iveskite kaina: ";
	cin >> skplus;
	shop.GPU[shop.GetKiekGPU()].SetKaina(skplus);
	cout << "Iveskite architekturos tipa: ";
	cin >> zod;
	shop.GPU[shop.GetKiekGPU()].SetArchitektura(zod);
	cout << "Iveskite branduoliu kieki: ";
	cin >> sk;
	shop.GPU[shop.GetKiekGPU()].SetBranduoliuKiekis(sk);
	cout << "Iveskite HashRate: ";
	cin >> sk;
	shop.GPU[shop.GetKiekGPU()].SetHashRate(sk);
	cout << "Iveskite ramu skaiciu: ";
	cin >> sk;
	shop.GPU[shop.GetKiekGPU()].SetRam(sk);
	shop.SetKiekGPU(shop.GetKiekGPU() + 1);
	cout << endl;

}
//-----------------------------------
void AtspausdintiGPU(Parduotuve shop) {

	for (int i = 0; i < shop.GetKiekGPU(); i++) {
		cout << i + 1 << ". " << shop.GPU[i].GetPavadinimas() << " " << shop.GPU[i].GetGreitis() << " " << shop.GPU[i].GetKaina() << " ";
		cout << shop.GPU[i].GetArchitektura() << " " << shop.GPU[i].GetBranduoliuKiekis() << " " << shop.GPU[i].GetHashRate() << " " << shop.GPU[i].GetRam() << endl;
	}
	cout << endl;

}
//-----------------------------------
void SukurtiKompiuteri(Parduotuve &shop) {

	string pav;
	int pasirinkimas;
	cout << "--Visi CPU--" << endl;
	AtspausdintiCPU(shop);
	cout << endl;
	cout << "Pasirinkite CPU: ";
	cin >> pasirinkimas;
	shop.PC[shop.GetKiekPC()].SetKurisCPU(pasirinkimas-1);
	cout << "--Visi GPU--" << endl;
	AtspausdintiGPU(shop);
	cout << endl;
	cout << "Pasirinkite GPU: ";
	cin >> pasirinkimas;
	shop.PC[shop.GetKiekPC()].SetKurisGPU(pasirinkimas-1);
	cout << "Iveskite kompiuterio pavadinima: ";
	cin >> pav;
	shop.PC[shop.GetKiekPC()].SetPavadinimas(pav);
	shop.SetKiekPC(shop.GetKiekPC() + 1);
	cout << endl;

}
//-----------------------------------
void AtspausdintiKompiuterius(Parduotuve shop) {

	for (int i = 0; i < shop.GetKiekPC(); i++) {
		cout << i + 1 << ". " << shop.PC[i].GetPavadinimas() << " - " << shop.CPU[shop.PC[i].GetKurisCPU()].GetPavadinimas() << " " << shop.GPU[shop.PC[i].GetKurisGPU()].GetPavadinimas() << " " << shop.CPU[shop.PC[i].GetKurisCPU()].GetKaina() + shop.GPU[shop.PC[i].GetKurisGPU()].GetKaina() << endl;
	
	}
	
}
//-----------------------------------
