#include<iostream>
using namespace std;

int min(int a, int b) {
   return ((a < b) ? a : b);
}

// print the maximum size square submatrix
// Logic :- Construct an auxilliary matrix 'aux' where each entry
// (i,j) is given by min[aux(i,j-1),aux(i-1,j),aux(i-1,j-1)] + 1 if mat(i,j) is 1.
// Find the max entry, suppose it is k
// then, max square submatrix is of size k and it can be traced
// by moving k cells upwards and leftwards
void printMaxSquareSubMat(bool mat[6][5],int row,int col) {
   int i,j;
   int aux[row][col]; //auxiliary matrix
   int aux_max; // max value in auxilliary matrix
   int x, y; // indices of the max value in auxilliary matrix

   // initialize 1st column of aux
   for (i = 0; i < row; i++)
         aux[i][0] = mat[i][0];
   // initialize 1st row of aux
   for (j = 0; j < col; j++)
         aux[0][j] = mat[0][j];

   // compute other entries of auxilliary matrix
   for (i = 1; i < row; i++) {
       for (j = 1; j < col; j++) {
           if (mat[i][j] == 1)
              aux[i][j] = min(aux[i][j-1], min(aux[i-1][j], aux[i-1][j-1])) + 1;
           else
              aux[i][j] = 0;
         }
   }

   // find the max value and its index in the
   // auxilliary matrix
   aux_max = aux[0][0]; x = 0; y = 0;
   for (i=0;i<row;i++) {
         for (j=0;j<col;j++) {
               if (aux_max < aux[i][j]) {
                  aux_max = aux[i][j];
                  x = i;
                  y = j;
               }
         }
   }

   // print the max size sq. submatrix
   cout<<"\nMaximum size sub-matrix is:- \n";
   for(i=x;i>(x-aux_max);i--) {
         for(j=y;j>(y-aux_max);j--) {
               cout<<mat[i][j]<<" ";
         }
         cout<<endl;
   }
}

// main
int main() {
   bool mat[6][5] = {{0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 0},
                     {0, 1, 1, 1, 1},
                     {0, 1, 1, 1, 0},
                     {1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0}};
   printMaxSquareSubMat(mat,6,5);
   cout<<endl;
   return 0;
}
