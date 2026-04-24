#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string myName;
    int agents;
    string others;

    // 1. Input data
    // Masukkan nama Anda
    getline(cin, myName);
    // Masukkan jumlah agen
    cin >> agents;
    cin.ignore(); // Membersihkan buffer
    // Masukkan nama 4 orang lainnya
    getline(cin, others);

    // 2. Gabungkan semua nama ke dalam satu vector
    vector<string> allNames;
    allNames.push_back(myName);

    stringstream ss(others);
    string tempName;
    while (ss >> tempName) {
        allNames.push_back(tempName);
    }

    // 3. Urutkan nama berdasarkan alfabet
    sort(allNames.begin(), allNames.end());

    // 4. Cari posisi nama Anda (index dimulai dari 1)
    int myPosition = 0;
    for (int i = 0; i < allNames.size(); i++) {
        if (allNames[i] == myName) {
            myPosition = i + 1;
            break;
        }
    }

    // 5. Hitung waktu total
    // Logika: (posisi / jumlah agen) dibulatkan ke atas, dikali 20 menit
    int timeTaken = ((myPosition + agents - 1) / agents) * 20;

    // 6. Output hasil
    cout << timeTaken << endl;

    return 0;
}
