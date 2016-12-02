// **************************************** //
// Autor kreativnog rjesenja: ANTONIO ÆOSIÆ //
// **************************************** //

#include<iostream>
#include<windows.h>
typedef int elementtype;
#include "header_1.h"
using namespace std;

int covjek[3][3]={32,79,32,     //Umjesto znakova sam u polje stavljao ascii vrijednost
				  47,124,92,    //jer mi prilikom unosenja znaka '\' javi grešku i traži
				  47,32,92};    //još i unos 0 da bit to bio znak za terminiranje niza '\0'
				  
int ljut_covjek[3][3]={92,79,47,
				  	   32,124,32, 
				       47,32,92};
					        
void draw_covjek(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << char(covjek[i][j]);	
		cout << endl;
	}
}

void draw_ljut_covjek(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << char(ljut_covjek[i][j]);	
		cout << endl;
	}
}

void odbrojavanje(int poc, int kraj){
	for(double i = poc; i<kraj; i++){
		cout<<".";
	    //Beep(250,940);            //Ovdje je moguce promijeniti frekvenciju Beepa(frekvencija, duljina trajanja u ms)
	    Sleep(1000);
    }
}

int broj_procesa, trajanje_obrade, pomocni_za_odbrojavanje;
int main(){
    queue red;
    Init(red);
    cout<<"Unesite broj zahtjeva koje zelite obraditi: ";
    cin>>broj_procesa;
    cout<<"Unesite vrijeme obrade jednog zahtjeva: ";
    cin>>trajanje_obrade;
    cout << "Za svaku obradu unesite vrijeme pocetka u odnosu\nna prethodnu obradu(u sekundama): " << endl;
    cout << "------------------------------------------------" << endl;
    Enqueue(red,0);
    cout << "1. Obrada pocinje u " << Front(red) << " sec." << endl;
    for(int i=1;i<broj_procesa;i++){
        int unos;
        cout << i+1 << ". Obrada pocinje za ";
        cin>>unos;
        Enqueue(red,unos);
    }
    cout << endl << endl;
    float ukupno_kasnjenje=0;
    int hazard_procesa;
    int dolazak_tekuci=0, pocetak_tekuci=0, kraj_prethodni=trajanje_obrade, pocetak_procesa;
    for(int i=0;i<broj_procesa;i++){
    	system("CLS");
        pocetak_procesa=Front(red);
        cout << i+1 << ". Zahtjev " << endl 
                    << "************" << endl;
        Dequeue(red);
        dolazak_tekuci+=pocetak_procesa;
        if(dolazak_tekuci==0){
        	cout << "Nema kasnjenje obrade zahtjeva. Obrada pokrenuta na vrijeme." << endl;
        	cout << endl;
        	draw_covjek();
        	cout << "Obrada zahtjeva";
        	odbrojavanje(0,trajanje_obrade);
        	pocetak_tekuci=0;
        	kraj_prethodni=pocetak_tekuci+trajanje_obrade+1;
        	cout << endl << endl;
        	continue;
		}
        if(dolazak_tekuci>kraj_prethodni){
        	pocetak_tekuci=dolazak_tekuci;
	        kraj_prethodni=pocetak_tekuci+trajanje_obrade+1;
	        cout << "Nema kasnjenje obrade zahtjeva. Obrada pokrenuta na vrijeme." << endl;
	        cout << endl;
	        draw_covjek();
	        cout << "Obrada zahtjeva";
	        odbrojavanje(pocetak_tekuci,kraj_prethodni-1);
	        cout << endl << endl;
	        continue;
		}
		if(dolazak_tekuci<kraj_prethodni){
			//cout << endl;
			pocetak_tekuci=dolazak_tekuci;
			pomocni_za_odbrojavanje=kraj_prethodni;
        	hazard_procesa=kraj_prethodni-pocetak_tekuci;
	        kraj_prethodni=kraj_prethodni+trajanje_obrade+1;
	        cout << "Klijent je ljut jer pocetak obrade zahtjeva kasni za " << hazard_procesa << " sec." << endl;
	        draw_ljut_covjek();
			cout << "Obrada zahtjeva";
	        odbrojavanje(pomocni_za_odbrojavanje, kraj_prethodni-1);
	        cout << endl << endl;
		}
        ukupno_kasnjenje+=hazard_procesa;
    }
    cout << endl;
    cout << "Svi zahtjevi su obradjeni!" << endl;
    cout << "--------------------------" << endl;
    cout << "Ukupno kasnjenje: " << ukupno_kasnjenje << " sec." << endl;
    cout << "=============================" << endl;
    cout << "Prosjecno vrijeme cekanja u redu je: " << ukupno_kasnjenje/broj_procesa <<" sec." << endl;
    cout << endl;
    system("pause");
    return 0;
}
