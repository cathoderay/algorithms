#include<vector>


typedef vector<double> row;
typedef vector<row> matrix;


void printm(matrix m) {
    int s = m.size();
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
