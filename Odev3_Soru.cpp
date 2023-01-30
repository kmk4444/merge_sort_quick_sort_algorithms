#include<iostream>
#include <chrono>
using namespace std;

int * mergeSort(int * dizi, int boyut)
{
	// Buraya kod 
}
int * quickSort(int * dizi, int boyut)
{
	// Buraya kod 
}
bool diziSiraliMi(int * dizi, int boyut)
{
	// Buraya kod 
}
void enHizliAlg(auto sure_mer, auto sure_qui)
{
	if(sure_mer==sure_qui)
		cout<<"Sureler esit!";
	else if(sure_qui<sure_mer)
		cout<<"En hizli Quick Sort!";
	else
		cout<<"En hizli Merge Sort!";
	
}
int main()
{
	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
	
	int boyut;
	cin>>boyut; //BOYUT BİLGİSİ GİRİLİR
	int* dizi = new int[boyut];
	int* sirali_dizi_ins = new int[boyut];
	int* sirali_dizi_mer = new int[boyut];
	int* sirali_dizi_qui = new int[boyut];
	
	for (int i = 0; i < boyut; i++) // input.txt dosyasından alınız.
		cin>>dizi[i];

	auto t1 = high_resolution_clock::now();
	sirali_dizi_qui=quickSort(dizi, boyut);
	auto t2 = high_resolution_clock::now();

	auto t3 = high_resolution_clock::now();
	sirali_dizi_mer=mergeSort(dizi, boyut);
	auto t4 = high_resolution_clock::now();
	
	
	auto sure_qui = duration_cast<milliseconds>(t2 - t1);
	auto sure_mer = duration_cast<milliseconds>(t4 - t3);
	
	if(diziSiraliMi(sirali_dizi_mer, boyut) && diziSiraliMi(sirali_dizi_qui, boyut))
	{
		cout<<"Diziler Sirali!\n";
	}
	else
	{
		cout<<"Diziler Sirali Degil!\n";
	}
	
	enHizliAlg(sure_mer, sure_qui);
	

}