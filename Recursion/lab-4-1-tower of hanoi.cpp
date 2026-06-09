#include <iostream>
using namespace std;

void toh(int disk, char src, char aux, char dest) {
    if (disk == 1) {
        cout << "Move disk " << disk << " from " << src << " to " << dest << endl;
        return;
    }

    toh(disk - 1, src, dest, aux);
    cout << "Move disk " << disk << " from " << src << " to " << dest << endl;
    toh(disk - 1, aux, src, dest);
}

int main() {
    char src = 'A', dest = 'C', aux = 'B';
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    toh(n, src, aux, dest);

    return 0;
}