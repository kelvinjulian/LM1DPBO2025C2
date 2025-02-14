#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class PetShop {
private:
    struct Product {
        int id;
        string nama;
        string kategori;
        float harga;

        // Constructor untuk inisialisasi Product
        Product(int id, string nama, string kategori, float harga)
            : id(id), nama(nama), kategori(kategori), harga(harga) {}

        // Getter dan Setter
        int getId() const { return id; }
        void setId(int id) { this->id = id; }

        string getNama() const { return nama; }
        void setNama(const string& nama) { this->nama = nama; }

        string getKategori() const { return kategori; }
        void setKategori(const string& kategori) { this->kategori = kategori; }

        float getHarga() const { return harga; }
        void setHarga(float harga) { this->harga = harga; }
    };

    vector<Product> products;

    // Fungsi untuk mengecek apakah ID sudah ada
    bool isDuplicateID(int id) {
        for (const auto& p : products) {
            if (p.getId() == id) {
                return true; 
            }
        }
        return false; 
    }

    // Fungsi untuk mengecek apakah Nama Produk sudah ada
    bool isDuplicateName(const string& name) {
        for (const auto& p : products) {
            if (p.getNama() == name) {
                return true; 
            }
        }
        return false;
    }

public:
    PetShop() {
        // Menambahkan produk awal
        products.push_back(Product(1, "Dog Food", "Makanan", 50000));
        products.push_back(Product(2, "Cat Food", "Makanan", 45000));
        products.push_back(Product(3, "Shampoo Anjing", "Perawatan", 120000));
    }

    void tampilkanProduk() {
        if (products.empty()) {
            cout << "\nDaftar produk kosong." << endl;
            return;
        }

        cout << "\nDaftar Produk PetShop:\n";
        for (const auto& p : products) {
            cout << "ID: " << p.getId() 
                << ", Nama: " << p.getNama() 
                << ", Kategori: " << p.getKategori()
                << ", Harga: " << p.getHarga()
                << endl;
        }
    }

    void tambahProduk() {
        cout << "\nMasukkan ID, Nama Produk, Kategori Produk, dan Harga Produk:\n";

        string input;
        cin.ignore();
        getline(cin, input);

        stringstream ss(input);
        string idStr, nama, kategori, hargaStr;

        if (getline(ss, idStr, ',') &&
            getline(ss >> ws, nama, ',') &&
            getline(ss >> ws, kategori, ',') &&
            getline(ss >> ws, hargaStr)) {

            int id = stoi(idStr);
            float harga = stof(hargaStr);

            // Cek apakah ID atau Nama sudah ada
            if (isDuplicateID(id)) {
                cout << "ERROR: ID sudah ada! Gunakan ID lain.\n";
                return;
            }
            if (isDuplicateName(nama)) {
                cout << "ERROR: Nama produk sudah ada! Gunakan nama lain.\n";
                return;
            }

            products.push_back(Product(id, nama, kategori, harga));
            cout << "Produk berhasil ditambahkan!\n";
        } else {
            cout << "Format input tidak valid. Silakan coba lagi.\n";
        }
    }

    void ubahProduk() {
        int id;
        cout << "\nMasukkan ID produk yang ingin diubah: ";
        cin >> id;
        cin.ignore();

        bool found = false;
        for (auto& p : products) {
            if (p.getId() == id) {
                cout << "Masukkan data baru (ID, Nama Produk, Kategori Produk, Harga Produk):\n";
                string input;
                getline(cin, input);

                stringstream ss(input);
                string idStr, nama, kategori, hargaStr;

                if (getline(ss, idStr, ',') &&
                    getline(ss >> ws, nama, ',') &&
                    getline(ss >> ws, kategori, ',') &&
                    getline(ss >> ws, hargaStr)) {

                    int newId = stoi(idStr);
                    float newHarga = stof(hargaStr);

                    // Pastikan ID baru tidak bentrok dengan produk lain
                    if (newId != id && isDuplicateID(newId)) {
                        cout << "ERROR: ID baru sudah digunakan oleh produk lain!\n";
                        return;
                    }

                    // Pastikan Nama baru tidak bentrok dengan produk lain
                    if (nama != p.getNama() && isDuplicateName(nama)) {
                        cout << "ERROR: Nama produk baru sudah ada! Gunakan nama lain.\n";
                        return;
                    }

                    // Update produk
                    p.setId(newId);
                    p.setNama(nama);
                    p.setKategori(kategori);
                    p.setHarga(newHarga);

                    cout << "Data produk berhasil diubah.\n";
                    found = true;
                } else {
                    cout << "Format input tidak valid.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Produk dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    void hapusProduk() {
        int id;
        cout << "\nMasukkan ID produk yang ingin dihapus: ";
        cin >> id;

        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getId() == id) {
                products.erase(it);
                cout << "Produk berhasil dihapus.\n";
                return;
            }
        }
        cout << "Produk dengan ID " << id << " tidak ditemukan.\n";
    }

    void cariProduk() {
        string nama;
        cout << "\nMasukkan nama produk yang ingin dicari: ";
        cin.ignore();
        getline(cin, nama);

        bool found = false;
        for (const auto& p : products) {
            if (p.getNama() == nama) {
                cout << "Produk ditemukan: ID: " << p.getId() << ", Nama: " << p.getNama()
                     << ", Kategori: " << p.getKategori() << ", Harga: " << p.getHarga()
                     << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Produk dengan nama '" << nama << "' tidak ditemukan.\n";
        }
    }
};
