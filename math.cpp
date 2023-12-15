#include <iostream>
#include <math.h>
#ifdef NAN
/* NAN is supported */
#endif
#ifdef INFINITY
/* INFINITY is supported */
#endif

using namespace std;

int main() {
  int n;
  double matrix1[10][10];

  cout << "This program calculates the determinant from the matrix." << endl;
  // Input the size of the matrix
  cout << "Matrix size (one number 2-5):";
  cin >> n;
  if (n < 2 || n > 5) {
    cout << "Invalid matrix size." << endl;
    return 0;
  }

  // Input the elements of the matrix
  cout << "Enter the elements of the matrix:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix1[i][j];
    }
  }

  // Show the matrix
  for (int i = 0; i < n; i++) {
    cout << "|\t";
    for (int j = 0; j < n; j++) {
      cout << matrix1[i][j] << "\t";
    }
    cout << "|" << endl;
  }

  //If there is a row with all zeros, the determinant is zero.
  for (int i = 0; i < n; i++) {
    if (n==2 && matrix1[i][0] == 0 && matrix1[i][1] == 0){
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==3 && matrix1[i][0] == 0 && matrix1[i][1] == 0 && matrix1[i][2] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==4 && matrix1[i][0] == 0 && matrix1[i][1] == 0 && matrix1[i][2] == 0 && matrix1[i][3] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==5 && matrix1[i][0] == 0 && matrix1[i][1] == 0 && matrix1[i][2] == 0 && matrix1[i][3] == 0 && matrix1[i][4] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
  }

  //If there is a column with all zeros, the determinant is zero.
  for (int j = 0; j < n; j++) {
    if (n==2 && matrix1[0][j] == 0 && matrix1[1][j] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==3 && matrix1[0][j] == 0 && matrix1[1][j] == 0 && matrix1[2][j] == 0 ) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==4 && matrix1[0][j] == 0 && matrix1[1][j] == 0 && matrix1[2][j] == 0 && matrix1[3][j] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
    if (n==5 && matrix1[0][j] == 0 && matrix1[1][j] == 0 && matrix1[2][j] == 0 && matrix1[3][j] == 0 && matrix1[4][j] == 0) {
      cout << "The determinant is 0." << endl;
      goto SOLUTION;
    }
  }

  // If the matrix is 2x2, calculate the determinant
  if (n==2){
    double det = matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
    cout << "The determinant is " << det << "." << endl;
    goto SOLUTION;
  }

  // If the matrix is 3x3, calculate the determinant
  if (n==3){
    double det = matrix1[0][0]*matrix1[1][1]*matrix1[2][2] + matrix1[0][1]*matrix1[1][2]*matrix1[2][0] + matrix1[0][2]*matrix1[1][0]*matrix1[2][1] - matrix1[0][2]*matrix1[1][1]*matrix1[2][0] - matrix1[0][0]*matrix1[1][2]*matrix1[2][1] - matrix1[0][1]*matrix1[1][0]*matrix1[2][2];
    cout << "The determinant is " << det << "." << endl;
    goto SOLUTION;
  }

  // If the matrix is 4x4, calculate the determinant
  if (n==4){
    double det, c00,c01,c02, c03;
    c00=matrix1[1][1]*matrix1[2][2]*matrix1[3][3] + matrix1[1][2]*matrix1[2][3]*matrix1[3][1] + matrix1[1][3]*matrix1[2][1]*matrix1[3][2] - matrix1[1][3]*matrix1[2][2]*matrix1[3][1] - matrix1[1][1]*matrix1[2][3]*matrix1[3][2] - matrix1[1][2]*matrix1[2][1]*matrix1[3][3];

    c01=matrix1[1][0]*matrix1[2][2]*matrix1[3][3]+matrix1[2][0]*matrix1[3][2]*matrix1[1][3] + matrix1[3][0]*matrix1[1][2]*matrix1[2][3]-matrix1[3][0]*matrix1[2][2]*matrix1[1][3]-matrix1[2][3]*matrix1[3][2]*matrix1[1][0]-matrix1[2][0]*matrix1[1][2]*matrix1[3][3];

    c02=matrix1[1][0]*matrix1[2][1]*matrix1[3][3]+matrix1[2][0]*matrix1[3][1]*matrix1[1][3] + matrix1[1][1]*matrix1[2][3]*matrix1[3][0]-matrix1[3][0]*matrix1[2][1]*matrix1[1][3]-matrix1[2][3]*matrix1[3][1]*matrix1[1][0]-matrix1[2][0]*matrix1[1][1]*matrix1[3][3];

    c03=matrix1[1][0]*matrix1[2][1]*matrix1[3][2]+matrix1[2][2]*matrix1[3][0]*matrix1[1][1] + matrix1[2][0]*matrix1[3][1]*matrix1[1][2]-matrix1[3][0]*matrix1[2][1]*matrix1[1][2]-matrix1[2][2]*matrix1[3][1]*matrix1[1][0]-matrix1[2][0]*matrix1[1][1]*matrix1[3][2];

    det=matrix1[0][0]*c00-matrix1[0][1]*c01+matrix1[0][2]*c02-matrix1[0][3]*c03;
    cout << "The determinant is " << det << "." << endl;
    goto SOLUTION; 
  }

  // If the matrix is 5x5, calculate the determinant
  if (n==5){

    double det, c00, c01, c02, c03, c04;
    double c10, c11, c12, c13, c14;
    double c20,c21,c22,c23,c24;

          // c11
          // 22 23 24
          // 32 33 34
          // 42 43 44
      c22=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c24=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
          c11=matrix1[2][2]*c22-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c12
          // 21 23 24
          // 31 33 34
          // 41 43 44
      c21=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c24=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
          c12=matrix1[2][1]*c21-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c13
          // 21 22 24
          // 31 32 34
          // 41 42 44
      c21=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c22=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c24=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
          c13=matrix1[2][1]*c21-matrix1[2][2]*c22+matrix1[2][4]*c24;
          // c14
          // 21 22 23
          // 31 32 33
          // 41 42 43
      c21=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
      c22=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
      c23=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
          c14=matrix1[2][1]*c21-matrix1[2][2]*c22+matrix1[2][3]*c23;

  //c11,c12,c13,c14
    //+11 -12 +13 -14
    //21 22 23 24
    //31 32 33 34
    //41 42 43 44
  c00=matrix1[1][1]*c11-matrix1[1][2]*c12+matrix1[1][3]*c13-matrix1[1][4]*c14;

//------------------------------------------------------------------------------
          // c10
          // 22 23 24
          // 32 33 34
          // 42 43 44
      c22=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c24=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
          c10=matrix1[2][2]*c22-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c12
          // 20 23 24
          // 30 33 34
          // 40 43 44
      c20=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
          c12=matrix1[2][0]*c20-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c13
          // 20 22 24
          // 30 32 34
          // 40 42 44
      c20=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c22=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
          c13=matrix1[2][0]*c20-matrix1[2][2]*c22+matrix1[2][4]*c24;
          // c14
          // 20 22 23
          // 30 32 33
          // 40 42 43
      c20=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
      c22=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
      c23=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
          c14=matrix1[2][0]*c20-matrix1[2][2]*c22+matrix1[2][3]*c23;
            
  //c10,c12,c13,c14
    //+10 -12 +13 -14
    //20 22 23 24
    //30 32 33 34
    //40 42 43 44
  c01=matrix1[1][0]*c10-matrix1[1][2]*c12+matrix1[1][3]*c13-matrix1[1][4]*c14;

//------------------------------------------------------------------------------
          // c10
          // 21 23 24
          // 31 33 34
          // 41 43 44
      c21=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c24=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
          c10=matrix1[2][1]*c21-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c11
          // 20 23 24
          // 30 33 34
          // 40 43 44
      c20=matrix1[3][3]*matrix1[4][4]-matrix1[3][4]*matrix1[4][3];
      c23=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
          c11=matrix1[2][0]*c20-matrix1[2][3]*c23+matrix1[2][4]*c24;
          // c13
          // 20 21 24
          // 30 31 34
          // 40 41 44
      c20=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c13=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][4]*c24;
          // c14
          // 20 21 23
          // 30 31 33
          // 40 41 43
      c20=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
      c23=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c14=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][3]*c23;
    
  //c10,c11,c13,c14
    //+10 -11 +13 -14
    //20 21 23 24
    //30 31 33 34
    //40 41 43 44
  c02=matrix1[1][0]*c10-matrix1[1][1]*c11+matrix1[1][3]*c13-matrix1[1][4]*c14;

//------------------------------------------------------------------------------
          // c10
          // 21 22 24
          // 31 32 34
          // 41 42 44
      c21=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c22=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c24=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
          c10=matrix1[2][1]*c21-matrix1[2][2]*c22+matrix1[2][4]*c24;
          // c11
          // 20 22 24
          // 30 32 34
          // 40 42 44
      c20=matrix1[3][2]*matrix1[4][4]-matrix1[3][4]*matrix1[4][2];
      c22=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
          c11=matrix1[2][0]*c20-matrix1[2][2]*c22+matrix1[2][4]*c24;
          // c12
          // 20 21 24
          // 30 31 34
          // 40 41 44
      c20=matrix1[3][1]*matrix1[4][4]-matrix1[3][4]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][4]-matrix1[3][4]*matrix1[4][0];
      c24=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c12=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][4]*c24;
          // c14
          // 20 21 22
          // 30 31 32
          // 40 41 42
      c20=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
      c22=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c14=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][2]*c22;
    
  //c10,c11,c12,c14
    //+10 -11 +12 -14
    //20 21 22 24
    //30 31 32 34
    //40 41 42 44
  c03=matrix1[1][0]*c10-matrix1[1][1]*c11+matrix1[1][2]*c12-matrix1[1][4]*c14;

//------------------------------------------------------------------------------
          // c10
          // 21 22 23
          // 31 32 33
          // 41 42 43
      c21=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
      c22=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
      c23=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
          c10=matrix1[2][1]*c21-matrix1[2][2]*c22+matrix1[2][3]*c23;
          // c11
          // 20 22 23
          // 30 32 33
          // 40 42 43
      c20=matrix1[3][2]*matrix1[4][3]-matrix1[3][3]*matrix1[4][2];
      c22=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
      c23=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
          c11=matrix1[2][0]*c20-matrix1[2][2]*c22+matrix1[2][3]*c23;
          // c12
          // 20 21 23
          // 30 31 33
          // 40 41 43
      c20=matrix1[3][1]*matrix1[4][3]-matrix1[3][3]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][3]-matrix1[3][3]*matrix1[4][0];
      c23=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c12=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][3]*c23;
          // c13
          // 20 21 22
          // 30 31 32
          // 40 41 42
      c20=matrix1[3][1]*matrix1[4][2]-matrix1[3][2]*matrix1[4][1];
      c21=matrix1[3][0]*matrix1[4][2]-matrix1[3][2]*matrix1[4][0];
      c22=matrix1[3][0]*matrix1[4][1]-matrix1[3][1]*matrix1[4][0];
          c13=matrix1[2][0]*c20-matrix1[2][1]*c21+matrix1[2][2]*c22;
            
  //c10,c11,c12,c13
    //+10 -11 +12 -13
    //20 21 22 23
    //30 31 32 33
    //40 41 42 43
  c04=matrix1[1][0]*c10-matrix1[1][1]*c11+matrix1[1][2]*c12-matrix1[1][3]*c13;

//------------------------------------------------------------------------------

    
    det=matrix1[0][0]*c00-matrix1[0][1]*c01+matrix1[0][2]*c02-matrix1[0][3]*c03+matrix1[0][4]*c04;
    cout << "The determinant is " << det << "." << endl;
    goto SOLUTION;
  }





  
SOLUTION:

  cout <<endl<<endl<< "Now we're looking for a solution"<<endl;
  cout << "Enter b " << n << " times: "<<endl;
  //Input b
  for (int i=0; i<n; i++)
    {
      cin >> matrix1[i][n];
    }
  
  // Show the matrix
  for (int i = 0; i < n; i++) {
    cout << "|\t";
    for (int j = 0; j < n+1; j++) {
      cout << matrix1[i][j] << "\t";
    }
    cout << "|" << endl;
  }

  
    double k;
//1 step
    k=matrix1[0][0];
    //Making 00 == 1
    for (int i=0; i<n+1; i++)
      {
        matrix1[0][i]=matrix1[0][i]/k;
      }
//2 step
    k=matrix1[1][0];
    //Making 10 == 0
    for (int i=0; i<n+1; i++)
      {
        matrix1[1][i]=matrix1[1][i]-k*matrix1[0][i];
      }
//3 step
  if (n>2){
    k=matrix1[2][0];
    //Making 20 == 0
    for (int i=0; i<n+1; i++)
      {
        matrix1[2][i]=matrix1[2][i]-k*matrix1[0][i];
      }
  }
//4 step
  if (n>3){
    k=matrix1[3][0];
    //Making 30 == 0
    for (int i=0; i<n+1; i++)
      {
        matrix1[3][i]=matrix1[3][i]-k*matrix1[0][i];
      }
  }
  if (n>4){
//4.5 step
    k=matrix1[4][0];
    //Making 40 == 0
    for (int i=0; i<n+1; i++)
      {
        matrix1[4][i]=matrix1[4][i]-k*matrix1[0][i];
      }
  }
//5 step
    k=matrix1[1][1];
    //making 11 == 1
    for (int i=1; i<n+1; i++)
      {
        matrix1[1][i]=matrix1[1][i]/k;
      }
//6 step
    k=matrix1[0][1];
    //making 01 == 0
    for (int i=1; i<n+1; i++)
      {
        matrix1[0][i]=matrix1[0][i]-k*matrix1[1][i];
      }
//7 step
  if (n>2){
    k=matrix1[2][1];
    //making 21 == 0
    for (int i=1; i<n+1; i++)
      {
        matrix1[2][i]=matrix1[2][i]-k*matrix1[1][i];
      }
  }
//8 step
  if (n>3){
    k=matrix1[3][1];
    //making 31 == 0
    for (int i=1; i<n+1; i++)
      {
        matrix1[3][i]=matrix1[3][i]-k*matrix1[1][i];
      }
  }
  if (n>4){
//8.5 step
    k=matrix1[4][1];
    //making 41 == 0
    for (int i=1; i<n+1; i++)
      {
        matrix1[4][i]=matrix1[4][i]-k*matrix1[1][i];
      }
  }
    if (n==2){goto TESTING;}
//9 step
    k=matrix1[2][2];
    //making 22 == 1
    for (int i=2; i<n+1; i++)
      {
        matrix1[2][i]=matrix1[2][i]/k;
      }
//10 step
    k=matrix1[0][2];
    //making 02 == 0
    for (int i=2; i<n+1; i++)
      {
        matrix1[0][i]=matrix1[0][i]-k*matrix1[2][i];
      }
//11 step
    k=matrix1[1][2];
    //making 12 == 0
    for (int i=2; i<n+1; i++)
      {
        matrix1[1][i]=matrix1[1][i]-k*matrix1[2][i];
      }
//12 step
  if (n>3){
    k=matrix1[3][2];
    //making 32 == 0
    for (int i=2; i<n+1; i++)
      {
        matrix1[3][i]=matrix1[3][i]-k*matrix1[2][i];
      }
  }
  if (n>4){
//12.5 step
    k=matrix1[4][2];
    //making 42 == 0
    for (int i=2; i<n+1; i++)
      {
        matrix1[4][i]=matrix1[4][i]-k*matrix1[2][i];
      }
  }
    if (n==3){goto TESTING;}
//13 step
    k=matrix1[3][3];
    //making 33 == 1
    for (int i=3; i<n+1; i++)
      {
        matrix1[3][i]=matrix1[3][i]/k;
      }
//14 step
    k=matrix1[0][3];
    //making 03 == 0
    for (int i=3; i<n+1; i++)
      {
        matrix1[0][i]=matrix1[0][i]-k*matrix1[3][i];
      }
//15 step
    k=matrix1[1][3];
    //making 13 == 0
    for (int i=3; i<n+1; i++)
      {
        matrix1[1][i]=matrix1[1][i]-k*matrix1[3][i];
      }
//16 step
    k=matrix1[2][3];
    //making 23 == 0
    for (int i=3; i<n+1; i++)
      {
        matrix1[2][i]=matrix1[2][i]-k*matrix1[3][i];
      }
    if (n==4){goto TESTING;}
//17 step
    k=matrix1[4][4];
    //making 44 == 1
    for (int i=4; i<n+1; i++)
      {
        matrix1[4][i]=matrix1[4][i]/k;
      }
//18 step
    k=matrix1[0][4];
    //making 04 == 0
    for (int i=4; i<n+1; i++)
      {
        matrix1[0][i]=matrix1[0][i]-k*matrix1[4][i];
      }
//19 step
    k=matrix1[1][4];
    //making 14 == 0
    for (int i=4; i<n+1; i++)
      {
        matrix1[1][i]=matrix1[1][i]-k*matrix1[4][i];
      }
//20 step
    k=matrix1[2][4];
    //making 24 == 0
    for (int i=4; i<n+1; i++)
      {
        matrix1[2][i]=matrix1[2][i]-k*matrix1[4][i];
      }
//21 step
    k=matrix1[3][4];
    //making 34 == 0
    for (int i=4; i<n+1; i++)
      {
        matrix1[3][i]=matrix1[3][i]-k*matrix1[4][i];
      }
  


    TESTING:
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
          if (isinf(matrix1[i][j])||isnan(matrix1[i][j]))
          {
            cout << "No solution or infinitive solutions" << endl;
            return 0;
          }
      }
    }


  cout<< endl<< "After Gauss elimination method: "<<endl;
  // Show the matrix
  for (int i = 0; i < n; i++) {
    cout << "|\t";
    for (int j = 0; j < n+1; j++) {
      cout << matrix1[i][j] << "\t";
    }
    cout << "|" << endl;
  }

  double t=1;
  for (int i=0; i<n; i++)
    {
      cout << "x" << t+i << " = " << matrix1[i][n] << endl;
    }

  //   matrix1[][]
  
  return 0;
}