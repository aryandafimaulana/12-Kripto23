/*
Nama        : Aryan Dafi Maulana
NPM         : 140810210012
Kelas       : B
Tanggal     : 17 September 2023
Deskripsi   : program shift chiper
*/
#include <iostream>
using namespace std;

string encrypt(string plaintext, int key) {
    string ciphertext = "";
    for (char letter : plaintext) {
        if (isalpha(letter)) {
            char base = isupper(letter) ? 'A' : 'a';
            char encryptedLetter = (letter - base + key) % 26 + base;
            ciphertext += encryptedLetter;
        } else {
            ciphertext += letter;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int key) {
    return encrypt(ciphertext, 26 - key); // Menggunakan kunci negatif untuk dekripsi
}

int main() {
    int key;
    string plaintext, ciphertext;

    cout << "Masukkan kunci (bilangan bulat positif): ";
    cin >> key;

    if (key <= 0 || key >= 26) {
        cout << "Kunci tidak valid. Harus menjadi bilangan bulat positif yang kurang dari 26." << endl;
        return 1;
    }

    cin.ignore();
    cout << "Masukkan teks yang akan dienkripsi: ";
    getline(cin, plaintext);

    ciphertext = encrypt(plaintext, key);
    cout << "Teks terenkripsi: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Teks terdekripsi: " << decryptedText << endl;

    return 0;
}
