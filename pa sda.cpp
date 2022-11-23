// pa strukdat

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct akun
{
    string username;
    string password;
};

struct data_game
{
    string nama_game;
    string studio_game;
    string genre_game;
    int harga_game;
    int tahun_rilis;
};

struct Node
{
    data_game game;
    struct Node *next;
};
int panjangList;


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
void add_first(Node **head);
void add_last(Node **head);
void add_mid(Node **head);
void tambah();
void header(string text);
void input(string text);
void keluar();
/*-------------------End Of Prototype Menu---------------------*/
struct Node *head = NULL; 
int main()
{
	
    read_file_login();
    int choice;
    do
    {
        system("cls");
        cout << " ====================================" << endl;
        cout << "|         Welcome to Program        |" << endl;
        cout << " ====================================" << endl;
        cout << "\n 1. Login \n 2. Register \n 3. Exit" << endl;
        cout << "--------------------------------------" << endl;
        input("Enter choice");
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Mohon Masukkan Angka" << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                login();
                break;
            case 2:
                Register();
                break;
            case 3:
                keluar();
            default:
                cout << "Pilihan Tidak Ada" << endl;
                getch();
            }
        }
    } while (choice != 3);
}

/*--------------------------------------Fungsi Login-----------------------------------*/
void read_file_login()
{
    int i = 0;

    string username, password;
    file_login.open("login.csv", ios::in);
    if (!file_login.is_open())
    {
        file_login.open("login.csv", ios::out);
        file_login.close();
    }
    else
    {
        while (!file_login.eof())
        {
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

void simpan_akun()
{
    file_login.open("login.csv", ios::out);
    for (int i = 0; i < counter_akun; i++)
    {
        file_login << akun_user[i].username << "," << akun_user[i].password << endl;
    }
    file_login.close();
}

void login()
{
    string username, password;
    int i;
    system("cls");
    header("Menu Login");
    cout << "" << endl;
    input("Masukkan username");
    cin >> username;
    if (username == "admin")
    {
        input("Masukkan password");
        cin >> password;
        if (password == "admin")
        {
            cout << "\nLogin Berhasil" << endl;
            getch();
            menu_admin();
        }
        else
        {
            cout << "Password Salah" << endl;
            getch();
        }
    }
    else
    {
        for (i = 0; i < counter_akun; i++)
        {
            if (username == akun_user[i].username)
            {
                while (password != akun_user[i].password)
                {
                    input("Masukkan password");
                    cin >> password;
                    if (password == akun_user[i].password)
                    {
                        cout << "\nLogin berhasil" << endl;
                        getch();
                        menu_user();
                        break;
                    }
                    else
                    {
                        cout << "\nPassword salah" << endl;
                    }
                }
                break;
            }
        }
        if (i == counter_akun)
        {
            cout << "" << endl;
            cout << "Username tidak ditemukan silahkan daftar terlebih dahulu" << endl;
            getch();
        }
    }
}

void Register()
{
    string username, password;
    system("cls");
    header("Menu Register");
    cout << "" << endl;
    input("Masukkan username");
    cin >> username;
    int i;
    for (i = 0; i < counter_akun; i++)
    {
        if (akun_user[i].username == username)
        {
            cout << "\nUsername telah dipakai silahkan ke menu login / gunakan username lain" << endl;
            getch();
            break;
        }
    }
    if (username == "admin")
    {
        cout << "\nUsername tidak boleh admin" << endl;
    }
    if (i == counter_akun)
    {
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
void add_first(Node **head)
{
    system("cls");
    cout << "============================================================" << endl;
    cout << " ADD FIRST " << endl;
    cout << "============================================================" << endl;
    Node *nodebaru = new Node;
    cout << "Masukkan Nama Game : ";
    fflush(stdin);
    getline(cin, nodebaru->game.nama_game);
    cout << "Masukkan Tahun Rilis : ";
    fflush(stdin);
    cin >> nodebaru->game.tahun_rilis;
    cout << "Masukkan Studio Game : ";
    fflush(stdin);
    cin >> nodebaru->game.studio_game;
    cout << "Masukkan Genre Game : ";
    fflush(stdin);
    cin >> nodebaru->game.genre_game;
    cout << "Masukkan Harga Game : ";
    fflush(stdin);
    cin >> nodebaru->game.harga_game;
    nodebaru->next = *head;
	*head = nodebaru;
}
void add_last(Node **head)
{
    system("cls");
    cout << "============================================================" << endl;
    cout << " ADD LAST " << endl;
    cout << "============================================================" << endl;
    Node *nodebaru = new Node;
    cout << "Masukkan Nama Game : ";
    fflush(stdin);
    getline(cin, nodebaru->game.nama_game);
    cout << "Masukkan Tahun Rilis : ";
    fflush(stdin);
    cin>> nodebaru->game.tahun_rilis;
    cout << "Masukkan Studio Game : ";
    fflush(stdin);
    cin >> nodebaru->game.studio_game;
    cout << "Masukkan Genre Game : ";
    fflush(stdin);
    cin >> nodebaru->game.genre_game;
    cout << "Masukkan Harga Game : ";
    fflush(stdin);
    cin >> nodebaru->game.harga_game;
    	nodebaru->next = NULL;
	
	if(*head == NULL){
		*head = nodebaru;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = nodebaru;
}
void add_mid(Node **head)
{
    system("cls");
    
    cout << "============================================================" << endl;
    cout << " ADD MIDDLE " << endl;
    cout << "============================================================" << endl;
    Node *nodebaru = new Node;
    Node *ptr = *head;
    int len = 0;
    cout << "Masukkan Nama Game : ";
    fflush(stdin);
    getline(cin, nodebaru->game.nama_game);
    cout << "Masukkan Tahun Rilis : ";
    fflush(stdin);
    cin>> nodebaru->game.tahun_rilis;
    cout << "Masukkan Studio Game : ";
    fflush(stdin);
    cin >> nodebaru->game.studio_game;
    cout << "Masukkan Genre Game : ";
    fflush(stdin);
    cin >> nodebaru->game.genre_game;
    cout << "Masukkan Harga Game : ";
    fflush(stdin);
    cin >> nodebaru->game.harga_game;
    if(*head == NULL){
		*head = nodebaru;
	}
	while(ptr != NULL){
		len++;
		ptr = ptr->next;
	}
	int count = ((len % 2)==0)?(len/2):(len+1)/2;
	ptr = *head;
	
	while(count-- > 1){
		ptr = ptr->next;
	}
	nodebaru->next = ptr->next;
	ptr->next = nodebaru;
}
void tambah()
{
    int pil;
    while (pil != 4)
    {
        system("cls");
        cout << "=============================" << endl
             << "       | TAMBAH DATA |      " << endl
             << "=============================" << endl
             << "|1|Tambah Data Pertama |" << endl
             << "|2|Tambah Data Tengah |" << endl
             << "|3|Tambah Data Terakhir |" << endl
             << "|4|Kembali Ke Menu Utama |" << endl
             << "=============================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            add_first(&head);
            cout << "Data Berhasil ditambahkan" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 2:
            add_mid(&head);
            cout << "Data Berhasil ditambahkan" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 3:
            add_last(&head);
            cout << "Data Berhasil ditambahkan" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 4:
            continue;
        default:
            system("cls");
            cout << "Pilihan Tidak Ada !" << endl
                 << "Klik apa saja untuk kembali " << endl;
            getch();
        }
    }
}
int is_empty(Node **head){
	system("cls");
	if(*head == NULL){
		cout<<"======================================================================================================================="<<endl;
		cout<<"| No |          Nama Game          |         Tahun Rilis         |  Studio Game  |    Genre Game      |   Harga Game   |"<<endl;
		cout<<"======================================================================================================================="<<endl;
		cout<<"| "<<setiosflags(ios::left)<<setw(3)<<"-"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(15)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<"Kosong"<<"|"<<endl;
		cout<<"======================================================================================================================="<<endl;
		return 1;
	}
	else return 0;
}
void print_data(Node* head){
	if(head == NULL){
		is_empty(&head);
	}
	else if(head != NULL){
	int i=0;
	system("cls");
	cout<<"======================================================================================================================="<<endl;
	cout<<"| No |          Nama Game          |        Tahun Rilis         |     Studio Game   |    Genre Game    |  Harga Game  |"<<endl;
	cout<<"======================================================================================================================="<<endl;
	while(head != NULL){
		cout<<"| "<<setiosflags(ios::left)<<setw(3)<<i+1<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<< head->game.nama_game <<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<head->game.tahun_rilis<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<head->game.studio_game<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(11)<<head->game.genre_game <<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<head->game.harga_game <<"|"<<endl;
		head = head->next;
		i++;

	}
	cout<<"======================================================================================================================="<<endl;
	cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
	}

}
void update_data(Node** head){
	system("cls");
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
	}
	string nama;
	cout<<"================================================"<<endl
		<<"                  UPDATE DATA                   "<<endl
		<<"================================================"<<endl;
	cout<<"Masukkan Nama yang akan diubah : ";fflush(stdin);
	getline(cin,nama);
	Node *temp = (*head);
	while(temp != NULL){
		if(temp->game.nama_game == nama){
			cout<<"Masukkan Nama Game Baru    : ";fflush(stdin);
			getline(cin,temp->game.nama_game);
			cout<<"Masukkan Tahun Rilis Baru  : ";fflush(stdin);
			cin>>temp->game.tahun_rilis;
			cout<<"Masukkan Studio Game Baru : ";fflush(stdin);
			getline(cin,temp->game.studio_game);
			cout<<"Masukkan Genre Game Baru  : ";fflush(stdin);
			getline(cin,temp->game.genre_game);
			cout<<"Masukkan Harga Game Baru  : ";fflush(stdin);
			cin>>temp->game.harga_game;
			return;	
		}
		temp = temp->next;
	}
	cout<<"Data tidak ada !"<<endl;
}
void delete_first(Node** head){
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return;
	}
	*head = (*head)->next;
}

void delete_last(Node** head){
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return;
	}
	if((*head)->next == NULL){
		*head = NULL;
		return;
	}
	Node* temp = *head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp->next = NULL;
}

struct Node* delete_mid(struct Node* head){
	if(head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return NULL;
	}
	if(head->next == NULL){
		delete head;
		return NULL;
	}
	struct Node* slow_ptr = head;
	struct Node* fast_ptr = head;
	struct Node* prev;
	while(fast_ptr != NULL && fast_ptr->next != NULL){
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	prev->next = slow_ptr->next;
	delete slow_ptr;
	return head;
}
void hapus_data()
{
    int pil;
    while (pil != 4)
    {
        system("cls");
        cout << "=============================" << endl
             << "       | TAMBAH DATA |      " << endl
             << "=============================" << endl
             << "|1|Hapus Data Pertama |" << endl
             << "|2|Hapus Data Tengah |" << endl
             << "|3|Hapus Data Terakhir |" << endl
             << "|4|Kembali Ke Menu Utama |" << endl
             << "=============================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            delete_first(&head);
            cout << "Data Berhasil dihapus" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 2:
            delete_mid(head);
            cout << "Data Berhasil dihapus" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 3:
            delete_last(&head);
            cout << "Data Berhasil dihapus" << endl
                 << "Tekan apa saja untuk kembali ";
            getch();
            break;
        case 4:
            continue;
        default:
            system("cls");
            cout << "Pilihan Tidak Ada !" << endl
                 << "Klik apa saja untuk kembali " << endl;
            getch();
        }
    }
}
/*-----------------------------------------Menu------------------------------------------*/
void menu_admin()
{
    int pilihan;
    do
    {
        system("cls");
        header("ADMIN | GG GAMES ONLINE");
        cout << "[1] Tambah Daftar Game" << endl;
        cout << "[2] Melihat Daftar Game" << endl;
        cout << "[3] Ubah Daftar Game" << endl;
        cout << "[4] Hapus Daftar Game" << endl;
        cout << "[5] Logout " << endl;
        cout << "-------------------------------------------" << endl;
        input("Pilih menu");
        cin >> pilihan;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nMohon masukkan angka" << endl;
        }
        else
        {
            switch (pilihan)
            {
            case 1:
                cout << "fungsi create" << endl;
                tambah();
                break;
            case 2:
                cout << "fungsi read" << endl;
                print_data(head);
                break;
            case 3:
                cout << "fungsi update" << endl;
                update_data(&head);
                break;
            case 4:
                cout << "fungsi hapus" << endl;
                hapus_data();
                break;
            case 5:
                cout << "\nBack to main menu.." << endl;
                getch();
                break;
            default:
                cout << "pilihan tidak ada" << endl;
            }
        }
    } while (pilihan != 5);
}

void menu_user()
{
    int pilihan;
    do
    {
        system("cls");
        header("GG GAMES ONLINE");
        cout << "[1] melihat daftar game" << endl;
        cout << "[2] beli game" << endl;
        cout << "[3] Logout " << endl;
        cout << "-------------------------------------------" << endl;
        input("Pilih menu");
        cin >> pilihan;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nMohon masukkan angka" << endl;
        }
        else
        {
            switch (pilihan)
            {
            case 1:
                cout << "fungsi liat game" << endl;
                print_data(head);
                break;
            case 2:
                cout << "beli game" << endl;
                break;
            case 3:
                cout << "\nBack to main menu.." << endl;
                getch();
                break;
            default:
                cout << "pilihan tidak ada" << endl;
            }
        }
    } while (pilihan != 3);
}

// fungsi pembantu header, input, keluar
void header(string text)
{
    string line = "-------------------------------------------";
    cout << line << endl;
    for (int i = 0; i < (line.length() - text.length()) / 2; i++)
        cout << " ";
    cout << text << endl;
    cout << line << endl;
}

void input(string text)
{
    cout << setw(20) << left << text << ": ";
}

void keluar()
{
    system("cls");
    cout << "\n		 +++++ Terima kasih telah menggunakan program, semoga hari Anda dipenuhi kebahagiaan +++++" << endl;
    getch();
    exit(0);
}
/*---------------------------End Of Fungsi Menu-----------------------*/

