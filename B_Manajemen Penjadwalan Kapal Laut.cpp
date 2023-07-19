//Bismillah //Kelompok manajemen penjadwalan kapal laut //UAP PEMROGRAMAN TERSTRUKTUR
//KELAS B
//Fitra Dwi Nugraha 2257051007
//Kerina Bakarudin 2217051027
//Ngasiroh Nurjayatri 2257051032

#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

//class jadwal kapal laut
class JadwalKapal{
public:
    list<string> model; //List untuk nyimpan daftar jenis kapal 
    string* drmg; //array and pointer untuk menyimpan dermaga 
    string* namak; //array and pointer untuk menyimpan nama kapal
    string* jamk; //array and pointer untuk menyimpan waktu keberangkatan kapal
    int capacity; // kapasitas maksimal di dermaga
    int size; //jumlah kapal di dermaga
    string kapal, jenis, dermaga,nama,jam; //variabel umum,untuk menyimpan data kapal
	
	void setcolor (unsigned short color){
  	HANDLE hCon= GetStdHandle (STD_OUTPUT_HANDLE);
  	SetConsoleTextAttribute (hCon, color);
	}

	COORD coord = {X:0, Y:0};
	void gotoxy(int x, int y){
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

    //fungsi menampilkan header
	void header(){	
		setcolor(9);
	  	gotoxy(8,13);cout<<" 	    _   __  ___     ___	   ___	  ____	  ___ ";
	  	gotoxy(8,14);cout<<" 	   / /_/ / / _ |   / _ \\  / _ )  / __ \\  / _ \\ ";
	  	gotoxy(8,15);cout<<" 	  / _   / / __ |  / , _/ / _ \\	/ /_/ /	/ , _/    ";
	  	gotoxy(8,16);cout<<"     	 /_/ /_/ /_/ |_| /_/|_| /___ /	\\____/ /_/|_/   ";
		
	}
	
	JadwalKapal(int maxCapacity){
        capacity = maxCapacity;
        size = 0;
        drmg = new string[capacity];
        namak = new string[capacity];
        jamk = new string[capacity];
    }

    //fungsi menampilkan daftar kapal
    void daftar(){
    	setcolor(7);
    	gotoxy(8,13); cout << "==========================" << endl;
    	gotoxy(8,14); cout << "   TAMBAH JADWAL KAPAL" << endl;
    	gotoxy(8,15); cout << "==========================" << endl;
        gotoxy(8,17); cout << "1. Kapal Ferry" << endl;
        gotoxy(8,18); cout << "2. Kapal Kargo" << endl;
        gotoxy(8,19); cout << "3. Kapal Pesiar" << endl;
        gotoxy(8,20); cout << "4. Kapal Tanker" << endl;
    }

    //fungsi tampilan menu utama
    void menu(){
    	setcolor(6);
        cout << "\n\t\t1. Tambah Antrian Kapal"
             << "\n\t\t2. Berangkatkan Kapal"
             << "\n\t\t3. Lihat Jumlah Antrian"
             << "\n\t\t4. Cek kapal di dermaga"
             << "\n\t\t5. Keluar Sistem"
             << "\n\n\t\t>> Pilih : ";
    }

    // fungsi Tambah kapal dengan queue
    void enqueue(){
        do{
            ulang:
            system("cls");

            daftar();
            gotoxy(8,21); cout << "Masukkan jenis kapal: ";
            getline(cin, kapal);

            if (kapal.empty()){
                cout << endl << "Harus isi jenis kapal!";
                getch();
                goto ulang;
            } 
			
			else if (kapal == "1"){
                jenis = "Jenis Kapal Ferry";
            } 
			
			else if (kapal == "2"){
                jenis = "Jenis Kapal Kargo";
            } 
			
			else if (kapal == "3"){
                jenis = "Jenis Kapal Pesiar";
            } 
			
			else if (kapal == "4"){
                jenis = "Jenis Kapal Tanker";
            } 
			
			else{
                cout << "Jenis kapal tidak tersedia";
                getch();
                goto ulang;
            }
            do{
                system("cls");
                daftar();

                gotoxy(8,21); cout<<"Masukkan jam keberangkatan : ";
                getline(cin,jam);

                if (jam.empty()){
                    cout<<endl<<"Jam keberangkatan harus diisi!";
                    getch();
                }
             }
             while (jam.empty());

             do{
                system("cls");
                daftar();

                gotoxy(8,21); cout<<"Masukkan nama kapal : ";
                getline(cin,nama);

                if (nama.empty()){
                    cout<<endl<<"Nama kapal harus diisi!";
                    getch();
                }
             }
             while (nama.empty());


            do{
                system("cls");
                daftar();

                gotoxy(8,21); cout << "Masukkan Dermaga untuk kapal (input nomor dermaga): ";
                getline(cin, dermaga);

                if (dermaga.empty()){
                    cout << endl << "Dermaga Kapal Harus Diisi!";
                    getch();
                }
            } 
			while (dermaga.empty());
        } 
		while (jenis.empty());

        if (size < capacity){
            model.push_back(jenis);
            drmg[size] = dermaga;
            namak[size] = nama;
            jamk[size] = jam;
            size++;
        } 
		else{
            cout << "Dermaga Kapal Penuh" << endl;
        }
    }

    // fungsi memberangkatkan kapal
    void dequeue(){
        if (model.empty()){
            system("cls");
            cout << "\t\t Dermaga Kapal Kosong"<<endl<<"\t\t Tekan enter untuk kembali!";
        } 
		else {
            system("cls");

            cout << "=================================" << endl;
            cout << "\tKAPAL TELAH BERANGKAT!" << endl;
            cout << "=================================" << endl;
            cout << " JENIS KAPAL : " << model.front() << endl;
            cout << " NAMA KAPAL  : " << namak[0] << endl;
            cout << " DARI DERMAGA : " << drmg[0] << endl;
            cout << " JAM KEBERANGKATAN : " << jamk[0] << endl;
            cout << " =================================" << endl;

            model.pop_front();
            for (int i = 0; i < size - 1; i++) {
                drmg[i] = drmg[i + 1];
                namak[i] = namak[i + 1];
                jamk[i] = jamk[i + 1];
            }
            size--;
        }
    }
    //fungsi melihat jumlah antrian jadwal kapal
    void jumlah(){
    	if (dermaga.empty()){
    		cout << "\n\t\tDermaga Kapal Kosong!" << endl;
		}
		else{
			cout << "\n\t\tJumlah antrian kapal Yang ada di dermaga: " << model.size() << endl;
		}
		
	}

    //Divide and Conquer untuk mencari kapal berdasarkan dermaga
    bool carikapal(const string& dermaga, int start, int end){
        if (start > end)
            return false;

        int mid = (start + end) / 2;
        if (drmg[mid] == dermaga){
        	return true;
		}   
        else if (drmg[mid] > dermaga){
        	return carikapal(dermaga, start, mid - 1);
		}
        else{
        	 return carikapal(dermaga, mid + 1, end);
		}
           
    }

    //fungsi untuk menampilkan jadwal kapal
    void view(list<string> jenisview, string dermagaview){
        if (dermaga.empty()){
        	setcolor(9);
            gotoxy(30,18); cout << "Sydney, Australia " << endl;
            cout << "\t\t==============================================" << endl;
            setcolor(4);
            cout << "\n\t\tDermaga Kosong!\n";
        } 
		
		else{
           	setcolor(9);
            gotoxy(30,18); cout << "Sydney, Australia " << endl;
            cout << "\t\t==============================================\n\n";
			setcolor(15);
			list<string> j = jenisview;
            string k = dermagaview;

            list<string>::iterator iter = model.begin();
            for (int i = 0; i < size; i++) {
                cout <<"\t\t" << *iter << endl << "\t\tDermaga : " << drmg[i] << endl << "\t\tNama kapal : "<< namak [i] << endl << "\t\tJam Berangkat : " << jamk [i]<<endl<<"\t\t=============\n";
                ++iter;
            }
            cout << '\n';
        }
    }
};

//program main nya
int main(){
    JadwalKapal jk(100);
    int pilihan;
    string drmg;

    do{
        jk.header();

        jk.view(jk.model, drmg);

        jk.menu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan){
            case 1:
                jk.enqueue();
                break;
                
            case 2:
                jk.dequeue();
                system("pause");
                break;
                
            case 3:
                jk.jumlah();
                system("pause");
                break;
                
            case 4:
                system("cls");
                cout << "Masukkan dermaga untuk mencari kapal : ";
                getline(cin, drmg);
                if (jk.carikapal(drmg, 0, jk.size - 1)){
                    cout << "Kapal di Dermaga " << drmg << " ditemukan" << endl;
                } 
				else{
                    cout << "Tidak ada kapal di dermaga " << drmg << endl;
                }
                system("pause");
                break;
                
            case 5:
            	system("cls");
                cout << "~~~TERIMA KASIH~~~" << endl;
                system("pause");
                break;
                
            default:
                cout << "\n\t\t*pilihan tidak ada" << endl;
                cout << "\t\tMasukan Pilihan Sesuai Dengan Daftar" << endl;
                system("pause");
                break;
        }

        system("cls");

    }while (pilihan != 5);

    return 0;
}
