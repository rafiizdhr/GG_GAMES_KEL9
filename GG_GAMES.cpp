//pa strukdat

#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<sstream>
#include<conio.h>
#include <iomanip>

using namespace std;

struct akun{
	string username;
	string password;
};

struct data_game{
	string nama_game;
	string studio_game;
	string genre_game;
	int harga_game;
	int tahun_rilis;
};

struct Node{
	data_game game;
	struct Node* next;
};

/*------------------Variabel GLobal Untuk Login----------------*/
fstream file_login;
int counter_akun = 0;
akun akun_user[50];
/*----------------------End Variabel Global-----------------*/

/*--------------------------Menu login--------------------------*/
void read_file_login();
void simpan_akun();
void login();
void Register();
/*--------------------------End Menu login----------------------------*/

/*-------------------Variabel Global Menu-------------------*/

/*----------------------End Variabel Global Menu----------------------*/


/*-------------------Prototype Menu---------------------*/
void menu_admin();
void menu_user();

void header(string text);
void input(string text);
void keluar();
/*-------------------End Of Prototype Menu---------------------*/


int main(){
	read_file_login();
	int choice;
	do{
		system("cls");
		cout<<" ===================================="<<endl;
        cout<<"|         Welcome to Program        |"<<endl;
        cout<<" ===================================="<<endl;
        cout<<"\n 1. Login \n 2. Register \n 3. Exit"<<endl;
        cout<<"--------------------------------------"<<endl;
        input("Enter choice");
        cin>>choice;
        if(cin.fail()){
        	cin.clear();
        	cin.ignore();
        	cout<<"Mohon Masukkan Angka"<<endl;
		}
		else{
			switch(choice){
				case 1:
					login();
					break;
				case 2: 
					Register();
					break;
				case 3:
					keluar();	
				default:
				cout<<"Pilihan Tidak Ada"<<endl;
				getch();		
			}
		}
	}while(choice != 3);


}

/*--------------------------------------Fungsi Login-----------------------------------*/
void read_file_login(){
	int i = 0;
	
	string username, password;
	file_login.open("login.csv", ios::in);
	if(!file_login.is_open()){
		file_login.open("login.csv",ios::out);
		file_login.close();
	}
	else{
		while(!file_login.eof()){
			counter_akun = i;
			getline(file_login, username, ',');
			getline(file_login, password, '\n');
			
			stringstream userstring(username);
			stringstream passwordstring(password);
			userstring >> akun_user[i].username;
			userstring >> akun_user[i].password;
			i++;
			}
		file_login.close();
	}
}

void simpan_akun(){
	file_login.open("login.csv",ios::out);
	for (int i = 0; i < counter_akun; i++){
		file_login << akun_user[i].username << "," << akun_user[i].password << endl;
	}
	file_login.close();
}

void login(){
	string username, password;
	int i;
	system("cls");
	header("Menu Login");
	cout << "" << endl;
	input("Masukkan username");
	cin >> username;
	if(username == "admin"){
		input("Masukkan password");
		cin >> password;
		if(password == "admin"){
			cout << "\nLogin Berhasil" << endl;
			getch();
			menu_admin();
		}else{
			cout << "Password Salah" << endl;
			getch();
		}
	}else{
		for(i = 0; i < counter_akun; i++){
			if(username == akun_user[i].username){
				while(password != akun_user[i].password){
					input("Masukkan password");
					cin >> password;
					if(password == akun_user[i].password){
						cout << "\nLogin berhasil" << endl;
						getch();
						menu_user();
						break;
					}else{
						cout << "\nPassword salah" << endl;
					}
				}
				break;
			}
		}
		if(i == counter_akun){
			cout << "" << endl;
			cout << "Username tidak ditemukan silahkan daftar terlebih dahulu" << endl;
			getch();
		}
	}
}

void Register(){
	string username, password;
	system("cls");
	header("Menu Register");
	cout << "" << endl;
	input("Masukkan username");
	cin >> username;
	int i;
	for(i=0; i < counter_akun; i++){
		if(akun_user[i].username == username){
			cout << "\nUsername telah dipakai silahkan ke menu login / gunakan username lain" << endl;
			getch();
			break;
		}
	}
	if(username == "admin"){
		cout << "\nUsername tidak boleh admin" << endl;
	}
	if(i == counter_akun){
		input("Masukkan password");
		cin >> password;
		akun_user[counter_akun].username = username;
		akun_user[counter_akun].password = password;
		counter_akun++;
		simpan_akun();
		cout << "\n Registrasi berhasil" << endl;
		getch();
	}
}
/*------------------------------------End Fungsi Login-----------------------------------*/


/*-----------------------------------------Menu------------------------------------------*/
void menu_admin(){
	int pilihan;
	do{
		system("cls");
		header("ADMIN | GG GAMES ONLINE");
		cout << "[1] tambah daftar game" << endl;
		cout << "[2] melihat daftar game" << endl;
		cout << "[3] ubah daftar game" << endl;
		cout << "[4] hapus daftar game" << endl;
		cout << "[5] Logout " << endl;
		cout << "-------------------------------------------" << endl;
		input("Pilih menu");
		cin >> pilihan;
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "\nMohon masukkan angka" << endl;
		}else{
			switch (pilihan){
				case 1:
					cout << "fungsi create" << endl; 
					break;
				case 2:
					cout << "fungsi read" << endl;
					break;
				case 3:
					cout << "fungsi update" << endl;
					break;
				case 4:		
					cout << "fungsi hapus" << endl;
					break;
				case 5: 
		        	cout << "\nBack to main menu.." << endl;
					getch();
					break;
				default:
					cout << "pilihan tidak ada" << endl;
			}
		}
	}while(pilihan != 5);
}

void menu_user(){
	int pilihan;
	do{
		system("cls");
		header("GG GAMES ONLINE");
		cout << "[1] melihat daftar game" << endl;
		cout << "[2] beli game" << endl;
		cout << "[3] Logout " << endl;
		cout << "-------------------------------------------" << endl;
		input("Pilih menu");
		cin >> pilihan;
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "\nMohon masukkan angka" << endl;
		}else{
			switch(pilihan){
				case 1:
					cout << "fungsi liat game" << endl;
					break;
				case 2: 
					cout << "beli game" << endl;	
					break;
				case 3:
					cout << "\nBack to main menu.." << endl;
					getch();
					break;
				default:
					cout << "pilihan tidak ada"	<< endl;	
			}
		}
	}while(pilihan != 3);
}

//fungsi pembantu header, input, keluar
void header(string text){
    string line = "-------------------------------------------";
	cout << line << endl;
	for (int i = 0; i < (line.length() - text.length()) / 2; i++)
		cout << " ";
	cout << text << endl;
	cout << line << endl;	
}

void input (string text){
	cout << setw(20) << left << text << ": ";
} 

void keluar(){
	system("cls");
	cout << "\n		 +++++ Terima kasih telah menggunakan program, semoga hari Anda dipenuhi kebahagiaan +++++" << endl;
	getch();
	exit(0);
}
/*---------------------------End Of Fungsi Menu-----------------------*/


