// CPP Program to multiply two matrix using pthreads
#include <bits/stdc++.h>
using namespace std;
 
// maximum size of matrix
#define MAX 2
 
// maximum number of threads
#define MAX_THREAD 4
 
int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

int r1,r2,c1,c2,i,j,k;






void* multi(void* arg)
{
    int i = step_i++; //i denotes row number of resultant matC
   
    for (int j = 0; j < MAX; j++)
      for (int k = 0; k < MAX; k++)
        matC[i][j] += matA[i][k] * matB[k][j];
}
 
// Driver Code
int main()
{


cout << "enter rows and ccoloum for first matrix " << endl;
cin >> r1 >> c1;
cout << "enter rows and ccoloum for second matrix " << endl;
cin >> r2 >> c2;

while (c1!=r2)
{
cout << "Error! column of first matrix not equal to row of second.";

}

    // Generating random values in matA and matB
  //  for (int i = 0; i < MAX; i++) {
  //      for (int j = 0; j < MAX; j++) {
  //          matA[i][j] = rand() % 10;
  //          matB[i][j] = rand() % 10;
  //      }
  //  }
 

    // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> matA[i][j];
        }

    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> matB[i][j];
        }







    // Displaying matA
    cout << endl
         << "Matrix A" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matA[i][j] << " ";
        cout << endl;
    }
 
    // Displaying matB
    cout << endl
         << "Matrix B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matB[i][j] << " ";       
        cout << endl;
    }
 
    // declaring four threads
    pthread_t threads[MAX_THREAD];
 
    // Creating four threads, each evaluating its own part
    for (int i = 0; i < MAX_THREAD; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }
 
    // joining and waiting for all threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);   
 
    // Displaying the result matrix
    cout << endl
         << "Multiplication of A and B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matC[i][j] << " ";       
        cout << endl;
    }
    return 0;
}
