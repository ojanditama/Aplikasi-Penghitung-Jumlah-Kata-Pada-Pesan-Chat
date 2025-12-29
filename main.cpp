#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ================= ITERATIF =================
// Pakai const string& biar hemat memori (tidak copy string)
int countWordsIterative(const string& text) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ' && !inWord) {
            count++;
            inWord = true;
        } 
        else if (text[i] == ' ') {
            inWord = false;
        }
    }
    return count;
}

// ================= REKURSIF =================
// WAJIB pakai const string&. Kalau tidak, memori akan meledak di input panjang.
int countWordsRecursive(const string& text, int index, bool inWord) {
    // Base Case: Jika index sudah di ujung string
    if (index == text.length())
        return 0;

    // Recursive Step
    if (text[index] != ' ' && !inWord) {
        // Ketemu kata baru, tambah 1, lanjut rekursif dengan status inWord=true
        return 1 + countWordsRecursive(text, index + 1, true);
    }
    else if (text[index] == ' ') {
        // Ketemu spasi, lanjut rekursif dengan status inWord=false
        return countWordsRecursive(text, index + 1, false);
    }
    else {
        // Masih di dalam kata yang sama, lanjut rekursif status tetap true
        return countWordsRecursive(text, index + 1, true);
    }
}

// ================= MAIN =================
int main() {
    string message;
    int choice;
    long long result = 0; // Ubah ke long long jaga-jaga hasil besar (opsional)

    cout << "=== PROGRAM PENGHITUNG KATA + TIMER ===" << endl;
    cout << "Pilih metode algoritma:" << endl;
    cout << "1. Iteratif (Looping)" << endl;
    cout << "2. Rekursif (Divide & Conquer)" << endl;
    cout << "Masukan pilihan (1/2): ";
    cin >> choice;

    cin.ignore(); // Membersihkan buffer enter

    cout << "\nMasukkan pesan chat: ";
    getline(cin, message);

    // --- MULAI TIMER ---
    auto start = high_resolution_clock::now(); 

    // Eksekusi Fungsi
    if (choice == 1) {
        cout << "\n[Mode: ITERATIF] Sedang menghitung..." << endl;
        result = countWordsIterative(message);
    } 
    else if (choice == 2) {
        cout << "\n[Mode: REKURSIF] Sedang menghitung..." << endl;
        // Penanganan stack overflow sederhana (opsional tapi bagus buat laporan)
        if (message.length() > 5000) {
            cout << "WARNING: Input terlalu panjang untuk Rekursif, risiko Stack Overflow!" << endl;
        }
        result = countWordsRecursive(message, 0, false);
    } 
    else {
        cout << "\nPilihan tidak valid!" << endl;
        return 1;
    }

    // --- STOP TIMER ---
    auto stop = high_resolution_clock::now();

    // Hitung durasi (selisih stop - start) dalam satuan mikrodethik
    auto duration = duration_cast<microseconds>(stop - start);

    // Tampilkan Hasil
    cout << "-----------------------------" << endl;
    cout << "Panjang Teks          : " << message.length() << " karakter" << endl;
    cout << "Jumlah kata ditemukan : " << result << endl;
    cout << "Waktu Eksekusi        : " << duration.count() << " mikrodethik" << endl;
    cout << "-----------------------------" << endl;

    return 0;
}
