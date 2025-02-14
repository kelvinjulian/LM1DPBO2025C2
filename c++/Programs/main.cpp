#include <iostream>
#include "PetShop.cpp"  // Menggunakan file PetShop.cpp yang di-include di sini

int main() {
    PetShop petshop;
    int pilihan;

    do {
        cout << "\n===== Menu PetShop =====\n";
        cout << "1. Tampilkan Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                petshop.tampilkanProduk();
                break;
            case 2:
                petshop.tambahProduk();
                break;
            case 3:
                petshop.ubahProduk();
                break;
            case 4:
                petshop.hapusProduk();
                break;
            case 5:
                petshop.cariProduk();
                break;
            case 6:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Opsi tidak valid! Silakan pilih kembali.\n";
        }
    } while (pilihan != 6);

    return 0;
}
