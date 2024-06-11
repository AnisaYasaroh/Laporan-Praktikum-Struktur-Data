#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main(){
  int Anisa_2311102063;
  cout << "Silakan masukkan jumlah simpul : ";
  cin >> Anisa_2311102063;

  vector<string> simpul(Anisa_2311102063);
  vector<vector<int>> busur(Anisa_2311102063, vector<int>(Anisa_2311102063, 0));
  cout << "Silakan masukkan nama simpul " << endl;
    for (int a = 0; a < Anisa_2311102063; a++){
      cout << "Simpul " << (a + 1) << " : ";
      cin >> simpul[a];
    }
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int a = 0; a < Anisa_2311102063; a++){
      for (int b = 0; b < Anisa_2311102063; b++){
        cout << simpul[a] << " --> " << simpul[b] << " = ";
        cin >> busur[a][b];
        }
    }
    cout << endl;
    cout << setw(7) << " ";
    for (int a = 0; a < Anisa_2311102063; a++){
      cout << setw(8) << simpul[a];
    }
    cout << endl;
    for (int a = 0; a < Anisa_2311102063; a++){
      cout << setw(7) << simpul[a];
      for (int b = 0; b < Anisa_2311102063; b++){
        cout << setw(8) << busur[a][b];
        }
        cout << endl;
    }
}