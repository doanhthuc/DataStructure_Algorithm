#include <iostream>

using namespace std;
void thapHaNoi(int n, char A, char B, char C){
    if (n == 1) cout << A << " --> " << C << "\n";
    else {
        thapHaNoi(n-1, A, C, B);
        thapHaNoi(1, A, B, C);
        thapHaNoi(n-1, B, A, C);
    }
}

int main(){
    int n;
    cout << "Nhap so tang thap: ";
    cin >> n;
    thapHaNoi(3, 'A', 'B', 'C');
    return 0;
}
