#include<iostream>
#include <chrono>
#include <fstream>
/*
Chrono library is used to deal with date and time. This library was designed to deal with the fact that timers and clocks might be different on different systems
and thus to improve over time in terms of precision. The unique thing about chrono is that it provides a precision-neutral concept by separating duration
and point of time ("timepoint") from specific clocks.
*/
using namespace std;

int bol(int*, int const, int const);
void quickSortHelper(int*, int const , int const);


void birlestir(int*, int const, int const, int const);
void mergeSortHelper(int *, int const, int const);

int * mergeSort(int * dizi, int boyut)
{
    mergeSortHelper(dizi, 0, boyut-1);
    return dizi;
}
int * quickSort(int * dizi, int boyut)
{
	quickSortHelper(dizi,0, boyut-1);
	return dizi;
}
bool diziSiraliMi(int* dizi, int boyut)
{
	for(auto i=1;i<boyut;i++)
        if(dizi[i] < dizi[i-1])
            return false;
    return true;
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
void printArray(int* dizi, int boyut)
{
    for (auto i = 0; i < boyut; i++)
        cout << dizi[i] << ", ";
     cout<<endl;
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
/*int main()
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

    cout<<"****************Ouicsort sorttan önce dizi**************"<<endl;
    printArray(dizi, boyut);
    cout<<"************************************"<<endl;

	auto t1 = high_resolution_clock::now();
	sirali_dizi_qui=quickSort(dizi, boyut);
	auto t2 = high_resolution_clock::now();

    cout<<"****************Ouicsort sorttan sonra dizi**************"<<endl;
    printArray(dizi, boyut);
    cout<<"****************Mergesort********************"<<endl;

	auto t3 = high_resolution_clock::now();
	sirali_dizi_mer=mergeSort(dizi, boyut);
	auto t4 = high_resolution_clock::now();
    cout<<"****************Merge sorttan sonra dizi**************"<<endl;
    printArray(dizi, boyut);
    cout<<"*****************************************************"<<endl;


	auto sure_qui = duration_cast<milliseconds>(t2 - t1);
	auto sure_mer = duration_cast<milliseconds>(t4 - t3);

	cout<<"sure_qui: "<<sure_qui.count()<<"\n";
	cout<<"sure_mer: "<<sure_mer.count()<<"\n";

	if(diziSiraliMi(sirali_dizi_mer, boyut) && diziSiraliMi(sirali_dizi_qui, boyut))
	{
		cout<<"Diziler Sirali!\n";
	}
	else
	{
		cout<<"Diziler Sirali Degil!\n";
	}

	enHizliAlg(sure_mer, sure_qui);


}*/
void mergeSortHelper(int* dizi, int const baslangic, int const bitis)
{
    if (baslangic >= bitis)
        return; // Returns recursively

    int mid = baslangic + (bitis - baslangic) / 2;
    mergeSortHelper(dizi, baslangic, mid);
    mergeSortHelper(dizi, mid + 1, bitis);
    birlestir(dizi, baslangic, mid, bitis);
}

void birlestir(int* dizi, int sol, int orta, int sag)
{
    int altDiziuzunluk1 = orta - sol + 1;
    int altDiziuzunluk2 = sag - orta;

    int *solDizi = new int[altDiziuzunluk1];
    int *sagDizi = new int[altDiziuzunluk2];

    // Copy data to temp arrays solDizi[] and sagDizi[]
    for (int i = 0; i < altDiziuzunluk1; i++)
        solDizi[i] = dizi[sol + i];
    for (int j = 0; j < altDiziuzunluk2; j++)
        sagDizi[j] = dizi[orta + 1 + j];

    int altDiziIndex1= 0,  altDiziIndex2= 0;
    int index = sol;

    // Merge the temp arrays back into dizi[sol..sag]
    while (altDiziIndex1 < altDiziuzunluk1 && altDiziIndex2 < altDiziuzunluk2) {
        if (solDizi[altDiziIndex1] <= sagDizi[altDiziIndex2]) {
            dizi[index]
                = solDizi[altDiziIndex1];
            altDiziIndex1++;
        }
        else {
            dizi[index]
                = sagDizi[altDiziIndex2];
            altDiziIndex2++;
        }
        index++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (altDiziIndex1 < altDiziuzunluk1) {
        dizi[index]
            = solDizi[altDiziIndex1];
        altDiziIndex1++;
        index++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (altDiziIndex2 < altDiziuzunluk2) {
        dizi[index]
            = sagDizi[altDiziIndex2];
        altDiziIndex2++;
        index++;
    }
    delete[] solDizi;
    delete[] sagDizi;
}


int bol(int* dizi, int baslangic, int bitis)
{

    int pivot =  (baslangic + bitis) / 2; // orta elamani pivot olarak aldim
    int pivotIndex = (baslangic + bitis) / 2; //
    swap(dizi[pivotIndex], dizi[baslangic]);

    int i = baslangic;
    int j = bitis;

    while (i < pivotIndex && j > pivotIndex) {

        while (dizi[i] <= pivot) {
            i++;
        }

        while (dizi[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(dizi[i++], dizi[j--]);
        }
    }

    return pivotIndex;
}

void quickSortHelper(int* dizi, int baslangic, int bitis)
{

    // base case
    if (baslangic >= bitis)
        return;

    // partitioning the array
    int p = bol(dizi, baslangic, bitis);

    // Sorting the left part
    quickSortHelper(dizi, baslangic, p - 1);

    // Sorting the right part
    quickSortHelper(dizi, p + 1, bitis);
}
