#include <iostream>

#include <vector>

using namespace std;

struct Produk {
  string nama_produk;
  string varian;
  int harga;
  int takaran;
  int value;
  bool padat;
};

vector<Produk> detergen;
vector<Produk> sabun_mandi;
vector<Produk> sabun_wajah;
vector<Produk> sampo;
vector<Produk> tisu;

string kapital(string input) {
  bool isPreviousCharSpace = true;
  for (int i = 0; i < input.length(); i++) {
    if (isPreviousCharSpace) {
      input[i] = toupper(input[i]);
    }
    isPreviousCharSpace = isspace(input[i]);
  }

  return input;
}

void HitungValue(Produk& produk) {
  produk.value = produk.harga / produk.takaran;
}
void InsertionSort(vector<Produk>& produk) {
  for (int i = 1; i < produk.size(); i++) {
    Produk key = produk[i];
    int j = i - 1;
    while (j >= 0 && produk[j].value > key.value) {
      produk[j + 1] = produk[j];
      j--;
    }
    produk[j + 1] = key;
  }
}
void InsertionSortNama(vector<Produk>& produk) {
  for (int i = 1; i < produk.size(); i++) {
    Produk key = produk[i];
    int j = i - 1;
    while (j >= 0 && produk[j].nama_produk > key.nama_produk) {
      produk[j + 1] = produk[j];
      j--;
    }
    produk[j + 1] = key;
  }
}


bool InterpolationSearch(vector<Produk>& produk, const string& target, bool& ketemu){
  int low = 0;
  int high = produk.size() - 1;
  while(low<=high&&target>= produk[low].nama_produk && target <= produk[high].nama_produk && ketemu == false){
    int pos = low + ((target.compare(produk[low].nama_produk) * (high - low)) / produk[high].nama_produk.compare(produk[low].nama_produk));
    if(produk[pos].nama_produk == target){
      ketemu = true;
    }
    if(produk[pos].nama_produk < target){
      low = pos + 1;
    }else{
      high = pos - 1;
    }
  } return ketemu;
}
void CariProduk(vector<Produk>& produk,string cari){
  string satuan;
  if (produk[0].padat) {
    satuan = "gr";
  } else {
    satuan = "ml";
  }
  bool ketemu = false;
  InterpolationSearch(produk, cari, ketemu);
  if(ketemu){
    while (true){
      system("cls");
      cout << "Merek " << cari << " ditemukan." << endl<<endl;     
      for(int i = 0; i < produk.size(); i++){
        if(produk[i].nama_produk == cari){
          cout << "Nama Produk: " << produk[i].nama_produk<<" "<< produk[i].varian << endl;
          cout << "Harga: " <<"Rp"<< produk[i].harga << endl;
          cout << "Takaran: " << produk[i].takaran<<satuan << endl;
          cout << endl;
        }
      }
      cout << "Kembali ke menu utama? (y/n): ";
      char pilih; cin>>pilih; cin.ignore();
      if(pilih == 'y' || pilih == 'Y'){
        system("cls");
        cout << "Kembali ke menu utama"<<endl;
        break;
      }
    }
  }else{
    system("cls");
    cout << "Produk dengan nama " << cari << " tidak ditemukan." << endl;
  }
}

void masukkandata(vector<Produk>& jenisproduk, string nama_jenisproduk[], float harga_jenisproduk[], float takaran_jenisproduk[], int banyak, string varian_jenisproduk[]){
    for (int i = 0; i < banyak; i++) {
      Produk produk;
      produk.nama_produk = nama_jenisproduk[i];
      produk.harga = harga_jenisproduk[i];
      produk.takaran = takaran_jenisproduk[i];
      produk.varian = varian_jenisproduk[i];
      jenisproduk.push_back(produk);
  }
}

void TampilkanMenu() {
  cout << "=================================" << endl;
  cout << "REKOMENDASI PRODUK RUMAH TANGGA" << endl;
  cout << "=================================" << endl;
  cout << "1. Lihat Rekomendasi Merek" << endl;
  cout << "2. Cari dan Cek Harga Produk" << endl;
  cout << "3. Keluar" << endl;
}

void TampilkanJenisProduk() {
  cout << "Jenis Produk" << endl;
  cout << "============" << endl;
  cout << "1. Detergen" << endl;
  cout << "2. Sabun mandi" << endl;
  cout << "3. Sabun wajah" << endl;
  cout << "4. Sampo" << endl;
  cout << "5. Tisu" << endl;
}

void showproduk(vector<Produk> produk) {
  string satuan;
  if (produk[0].padat==1) {
    satuan = "gr";
  } else {
    satuan = "ml";
  }
  cout << "No | Nama Produk      | Takaran "<<"("<<satuan<<") | Harga      | Harga/"<<satuan << endl;
  cout << "---------------------------------------------------------------------" << endl;
  for (int i = 0; i < 5; i++) {
    cout << i + 1 << " | " << produk[i].nama_produk << " " << produk[i].varian << " | " << produk[i].takaran<<satuan << " | Rp" << produk[i].harga << " | Rp" << produk[i].value << "/"<<satuan << endl;
  }
  while (true){
    cout << "\nLihat Produk Lainnya? (y/n): ";
    char pilih;
    cin >> pilih;
    cin.ignore();
    if (pilih == 'y' || pilih == 'Y') {
      while (true) {
        system("cls");
        cout << "Merek dari yang murah ke mahal (harga/"<<satuan<<")"; cout << endl;
        cout << "No | Nama Produk      | Takaran "<<"("<<satuan<<") | Harga      | Harga/"<<satuan << endl;
        for (int i = 0; i < produk.size(); i++) {
        cout << i + 1 << " | " << produk[i].nama_produk << " " << produk[i].varian << " | " << produk[i].takaran<<satuan << " | Rp" << produk[i].harga << " | Rp" << produk[i].value << "/"<<satuan << endl;
        }
        cout << "\nKembali ke menu utama? (y/n): ";
        cin >> pilih;cin.ignore();
        if (pilih == 'y' || pilih == 'Y') {
          system("cls");
          cout << "Kembali ke menu utama"<<endl;
          break;
        }
      }break;
    } else if (pilih == 'n' || pilih == 'N') {
      system("cls");
      cout << "Kembali ke menu utama"<<endl<<endl;
      break;
    } else {
      system("cls");
      cout << "Pilihan tidak tersedia"<<endl;
    }
  }

}


void Rekomendasi() {
  char pilihan;
  cout << "Pilih jenis produk: ";
  cin >> pilihan; cin.ignore();

  switch (pilihan) {
    case '1':      
      system("cls");
      cout <<endl<< "5 Merek Detergen Terhemat" << endl<<endl;
      for (int i = 0; i < detergen.size(); i++) {
        HitungValue(detergen[i]);
      }
      InsertionSort(detergen);
      showproduk(detergen);
      break;
    case '2':
      system("cls");
      cout <<endl<< "5 Merek Sabun mandi Terhemat" << endl<<endl;
      for (int i = 0; i < sabun_mandi.size(); i++) {
        HitungValue(sabun_mandi[i]);
      }
      InsertionSort(sabun_mandi);
      showproduk(sabun_mandi);
      break;
    case '3':
      system("cls");
      cout <<endl<< "5 Merek Sabun wajah Terhemat" << endl<<endl;
      for (int i = 0; i < sabun_wajah.size(); i++) {
        HitungValue(sabun_wajah[i]);
      }
      InsertionSort(sabun_wajah);
      showproduk(sabun_wajah);
      break;
    case '4':
      system("cls");  
      cout <<endl<< "5 Merek Sampo Terhemat" << endl<<endl;
      for (int i = 0; i < sampo.size(); i++) {
        HitungValue(sampo[i]);
      }
      InsertionSort(sampo);
      showproduk(sampo);
      break;
    case '5':
      system("cls");
      cout <<endl<< "5 Merek Tisu Terhemat" << endl<<endl;
      for (int i = 0; i < tisu.size(); i++) {
        HitungValue(tisu[i]);
      }
      InsertionSort(tisu);
      showproduk(tisu);
      break;
    default:
      system("cls");
      cout << "Pilihan tidak tersedia" << endl<<endl;
  }
}


int main() {
    string nama_detergen[30]= {"Daia", "Daia", "So Klin", "So Klin", "Attack","So Klin","So Klin", "Sosoft","Sosoft", "Sayang", "Sayang", "Daia", "Daia", "Attack", "Attack"};
    string varian_detergen[30] = {"Violet", "Clean", "", "", "", "Bomat Topload", "Bomat Frontload", "Floral", "Nature", "Lavender", "Lavender", "Violet", "Bunga", "Pesona Segar", "Pesona Segar"};
    float harga_detergen[30] = {50600, 50600, 54800, 39100, 43000,39100,54800,15500,15500,16200,36130,34900,50600,26500,19500};
    float takaran_detergen[30] = {2700, 1800, 2700, 1800, 1800,1800,1800,750,750,800,1800,1700,2700,1700,850};
    string nama_sabun_mandi[30]= {"Lifebuoy", "Lifebuoy", "Dove", "Dove", "Lux", "Lux","Lifebuoy","Lifebuoy","Nuvo", "Biore","Biore", "Nuvo","Nuvo"};
    string varian_sabun_mandi[30] = {"Sisho", "Lemon", "Deeply", "Deeply", "Sakura", "Jasmine", "3in1", "Coconut", "Liquis soap", "Foam Pure", "Guard", "Pink Pouch", "Tosca Pouch"};
    float harga_sabun_mandi[30] = {41400, 38100, 41710, 22780, 39800, 39500, 24255, 23900, 35900, 42900, 42470, 13900, 18500 };
    float takaran_sabun_mandi[30] = {825, 825, 825, 400, 825, 825, 450, 400, 825, 800, 800, 250, 450};
    string nama_sabun_wajah[30] = {"Wardah", "Kahf", "Biore", "Vaseline", "Scarlett", "Acnes","Poise", "Ponds", "Pigeon", "Fair & Lovely", "Natur E", "Shinzui", "Garnier", "Emina"};
    string varian_sabun_wajah[30] = {""};
    float harga_sabun_wajah[30] = {41300, 44900, 31800, 43600, 67500,40900, 24000, 36500, 27600, 30200, 41950, 31200, 32800, 21900};
    float takaran_sabun_wajah[30] = {100, 100, 100, 100, 100,100,100,100,100,100,50,80,100,50};
    string nama_sampo[30] = {"Dove", "Serasoft", "Rejoice", "Elseve", "Lifebuoy", "Zinc", "Emeron", "Clear", "Lifebuoy", "Rejoice", "Sunsilk", "Emeron", "Emeron", "Head & Shoulder"};
    string varian_sampo[30] = {"Perawatan Rontok", "Hijab", "Rich Jeju","", "Refresh N Cool", "Hijab", "Hijab", "Coconut", "Refresh N Cool", "Rich Jeju", "", "Hairfall Control", "Hairfall Control", ""};
    float harga_sampo[30] = {45500, 46200, 50900, 79000, 43500,37125,19200,52500,24750,25600,24900,25900,15300,34900};
    float takaran_sampo[30] = {290, 340, 340, 280, 310,340,170,300,155,150,160,340,170,160};
    string nama_tisu[30] = {"Multi", "Nice", "Montiss", "Jolly", "Raisa", "Raisa"};
    string varian_tisu[30] = {"", "", "", "", "", "Kecil"};
    float harga_tisu[30] = {51900, 42900, 40300, 49000, 46500, 26500};
    float takaran_tisu[30] = {1000, 900, 1000, 1000, 1000, 500};
    masukkandata(detergen, nama_detergen, harga_detergen, takaran_detergen, 15, varian_detergen);
    masukkandata(sabun_mandi, nama_sabun_mandi, harga_sabun_mandi, takaran_sabun_mandi, 13, varian_sabun_mandi);
    masukkandata(sabun_wajah, nama_sabun_wajah, harga_sabun_wajah, takaran_sabun_wajah, 14, varian_sabun_wajah);
    masukkandata(sampo, nama_sampo, harga_sampo, takaran_sampo, 14, varian_sampo);
    masukkandata(tisu, nama_tisu, harga_tisu, takaran_tisu, 6, varian_tisu);
    for (int i = 0; i < detergen.size(); i++) {
      detergen[i].padat = false;
    }
    for (int i = 0; i < sabun_mandi.size(); i++) {
      sabun_mandi[i].padat = false;
    }
    for (int i = 0; i < sabun_wajah.size(); i++) {
      sabun_wajah[i].padat = false;
    }
    for (int i = 0; i < sampo.size(); i++) {
      sampo[i].padat = false;
    }
    for (int i = 0; i < tisu.size(); i++) {
      tisu[i].padat = true;
    }

// mulai programnya disini
    system("cls");
    while (true) {
      char pilihan;
      TampilkanMenu();
      cout << "Menu: ";
      cin >> pilihan; cin.ignore();
      system("cls");

      if (pilihan == '1') {  
          TampilkanJenisProduk();
          Rekomendasi();
      } else if (pilihan == '2') {
          string cari;
          TampilkanJenisProduk();
          cout << "Pilih jenis produk yang ingin dicari: "; cin >> pilihan; cin.ignore();system("cls");
          switch(pilihan){
            case '1':
              InsertionSortNama(detergen);
              cout << "Masukkan merek detergen(contoh: So Klin) "<<endl;
              cout <<"Cari: ";getline(cin, cari); cari =kapital(cari);
              CariProduk(detergen, cari);
              break;
            case '2':
              InsertionSortNama(sabun_mandi);
              cout << "Masukkan merek sabun mandi (contoh: Lifebuoy ) "<<endl;
              cout <<"Cari: ";getline(cin, cari);cari = kapital(cari);
              CariProduk(sabun_mandi, cari);
              break;
            case '3':
              InsertionSortNama(sabun_wajah);
              cout << "Masukkan merek sabun wajah (contoh: Wardah) "<<endl;
              cout <<"Cari: ";getline(cin, cari);cari = kapital(cari);
              CariProduk(sabun_wajah, cari);
              break;
            case '4':
              InsertionSortNama(sampo);
              cout << "Masukkan merek sampo (contoh: Emeron) "<<endl;
              cout <<"Cari: ";getline(cin, cari);cari = kapital(cari);
              CariProduk(sampo, cari);
              break;
            case '5':
              InsertionSortNama(tisu);
              cout << "Masukkan merek tisu  (contoh: Raisa) "<<endl;
              cout <<"Cari: ";getline(cin, cari);cari = kapital(cari);
              CariProduk(tisu, cari);
              break;
            default:
              cout << "Pilihan tidak tersedia" << endl;

          }
          

      } else if (pilihan == '3') {
          cout << "Terima kasih telah menggunakan program ini."<<endl;
          return 0;
      } else {
          cout << "Pilihan tidak tersedia" << endl;
      }
    }
    return 0;
}
