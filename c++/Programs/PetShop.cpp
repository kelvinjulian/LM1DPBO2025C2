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
        // string foto;
    };

    vector<Product> products;

    // Fungsi untuk mengecek apakah ID sudah ada
    bool isDuplicateID(int id) {
        for (const auto& p : products) {
            if (p.id == id) {
                return true; 
            }
        }
        return false; 
    }

    // Fungsi untuk mengecek apakah Nama Produk sudah ada
    bool isDuplicateName(const string& name) {
        for (const auto& p : products) {
            if (p.nama == name) {
                return true; 
            }
        }
        return false;
    }

public:
    void tampilkanProduk() {
        if (products.empty()) {
            cout << "\nDaftar produk kosong." << endl;
            return;
        }

        cout << "\nDaftar Produk PetShop:\n";
        for (const auto& p : products) {
            cout << "ID: " << p.id 
                << ", Nama: " << p.nama 
                << ", Kategori: " << p.kategori
                << ", Harga: " << p.harga
                // << ", Foto: " << p.foto 
                << endl;
        }
    }

    void tambahProduk() {
        cout << "\nMasukkan ID, Nama Produk, Kategori Produk, dan Harga Produk:\n";

        string input;
        cin.ignore();
        getline(cin, input);

        stringstream ss(input);
        string idStr, nama, kategori, hargaStr, foto;

        if (getline(ss, idStr, ',') &&
            getline(ss >> ws, nama, ',') &&
            getline(ss >> ws, kategori, ',') &&
            getline(ss >> ws, hargaStr, ',') 
            // && getline(ss >> ws, foto)
            ) {

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

            products.push_back({id, nama, kategori, harga, 
            // foto
            });
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
            if (p.id == id) {
                cout << "Masukkan data baru (ID, Nama Produk, Kategori Produk, Harga Produk):\n";
                string input;
                getline(cin, input);

                stringstream ss(input);
                string idStr, nama, kategori, hargaStr;

                if (getline(ss, idStr, ',') &&
                    getline(ss >> ws, nama, ',') &&
                    getline(ss >> ws, kategori, ',') &&
                    getline(ss >> ws, hargaStr, ',') 
                    // && getline(ss >> ws, foto)
                    ) {

                    int newId = stoi(idStr);
                    float newHarga = stof(hargaStr);

                    // Pastikan ID baru tidak bentrok dengan produk lain
                    if (newId != id && isDuplicateID(newId)) {
                        cout << "ERROR: ID baru sudah digunakan oleh produk lain!\n";
                        return;
                    }

                    // Pastikan Nama baru tidak bentrok dengan produk lain
                    if (nama != p.nama && isDuplicateName(nama)) {
                        cout << "ERROR: Nama produk baru sudah ada! Gunakan nama lain.\n";
                        return;
                    }

                    // Update produk
                    p.id = newId;
                    p.nama = nama;
                    p.kategori = kategori;
                    p.harga = newHarga;
                    // p.foto = foto;

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
            if (it->id == id) {
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
            if (p.nama == nama) {
                cout << "Produk ditemukan: ID: " << p.id << ", Nama: " << p.nama
                     << ", Kategori: " << p.kategori << ", Harga: " << p.harga
                    //  << ", Foto: " << p.foto 
                     << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Produk dengan nama '" << nama << "' tidak ditemukan.\n";
        }
    }
};
