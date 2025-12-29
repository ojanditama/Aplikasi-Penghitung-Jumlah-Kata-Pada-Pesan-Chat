#include <iostream>
#include <string>

using namespace std;

// === CARA 1: PAKAI LOOPING (ITERATIF) ===
int hitungPakaiLooping(string teks) {
    int jumlahKata = 0;
    int totalHuruf = teks.length(); // Hitung ada berapa huruf totalnya
    bool lagiBacaKata = false;      // Penanda: kita lagi baca kata atau spasi?

    // Cek huruf satu per satu dari awal sampai akhir
    for (int i = 0; i < totalHuruf; i++) {
        
        // Kalau hurufnya BUKAN spasi
        if (teks[i] != ' ') {
            // Dan sebelumnya kita tidak sedang baca kata (berarti ini kata baru)
            if (lagiBacaKata == false) {
                jumlahKata = jumlahKata + 1; // Tambah hitungan
                lagiBacaKata = true;         // Tandai kita lagi baca kata
            }
        } 
        // Kalau ketemu spasi
        else {
            lagiBacaKata = false; // Reset penanda
        }
    }
    return jumlahKata;
}

// === CARA 2: PAKAI FUNGSI SENDIRI (REKURSIF) ===
int hitungPakaiRekursif(string teks, int posisi, bool lagiBacaKata) {
    int totalHuruf = teks.length();

    // Syarat Berhenti: Kalau posisi sudah lewat huruf terakhir
    if (posisi == totalHuruf) {
        return 0;
    }

    int tambahan = 0;
    bool statusBerikutnya = lagiBacaKata;

    // Cek huruf di posisi sekarang
    if (teks[posisi] != ' ') {
        if (lagiBacaKata == false) {
            tambahan = 1;           // Nemu kata baru!
            statusBerikutnya = true;
        }
    } else {
        statusBerikutnya = false;   // Nemu spasi
    }

    // Panggil diri sendiri buat cek huruf di depannya (posisi + 1)
    return tambahan + hitungPakaiRekursif(teks, posisi + 1, statusBerikutnya);
}

// === PROGRAM UTAMA ===
int main() {
    string pesan;

    cout << "=== PROGRAM PENGHITUNG KATA ===" << endl;
    cout << "Ketik kalimat kamu di bawah ini:" << endl;
    
    // Perintah untuk input kalimat dengan spasi
    getline(cin, pesan); 

    cout << "\n-----------------------------" << endl;
    
    // Langsung jalankan keduanya
    int hasil1 = hitungPakaiLooping(pesan);
    int hasil2 = hitungPakaiRekursif(pesan, 0, false);

    cout << "Hasil Cara Looping  : " << hasil1 << " kata" << endl;
    cout << "Hasil Cara Rekursif : " << hasil2 << " kata" << endl;
    cout << "-----------------------------" << endl;

    return 0;
}
