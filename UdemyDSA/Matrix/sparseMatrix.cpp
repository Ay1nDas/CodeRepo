//     0 1 2 3 4        0 1 2 3 4

// 0   0 0 7 0 0        0 0 2 0 0
// 1   2 0 0 5 0        2 3 3 0 0
// 2   9 0 0 0 0        0 0 9 0 1
// 3   0 0 0 0 4        0 3 0 0 0

// 0 0 9 0 0
// 4 3 3 5 0
// 9 0 9 0 1
// 0 3 0 0 4

#include <bits/stdc++.h>
using namespace std;

int **scanMatrix(int r, int c)
{
  int **matrix = (int **)malloc((r * c + 1) * sizeof(int *));

  int elemCnt = 0;
  cout << "Enter Matrix: " << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      int tmp;
      cin >> tmp;
      if (tmp)
      {
        elemCnt++;
        matrix[elemCnt] = (int *)malloc(3 * sizeof(int));
        matrix[elemCnt][0] = i;
        matrix[elemCnt][1] = j;
        matrix[elemCnt][2] = tmp;
      }
    }
  }

  int **tmpPtr = (int **)realloc(matrix, (elemCnt + 1) * sizeof(int *));
  // cout << tmpPtr << endl;
  // cout << matrix << endl;

  if (tmpPtr)
    matrix = tmpPtr;

  matrix[0] = (int *)malloc(3 * sizeof(int));
  matrix[0][0] = r;
  matrix[0][1] = c;
  matrix[0][2] = elemCnt;

  return matrix;
}

int **scanMatrix()
{
  int r = 0, c = 0;
  cout << "Enter Row    : ";
  cin >> r;
  cout << "Enter Column : ";
  cin >> c;

  return scanMatrix(r, c);
}

void displayMatrix(int **matrix)
{
  int matrix_index = 1;
  for (int i = 0; i < matrix[0][0]; i++)
  {
    for (int j = 0; j < matrix[0][1]; j++)
    {
      if (matrix[matrix_index][0] == i && matrix[matrix_index][1] == j)
      {
        cout << matrix[matrix_index++][2] << " ";
      }
      else
      {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

void displaySparce(int **matrix)
{
  for (int i = 0; i <= matrix[0][2]; i++)
  {
    cout << matrix[i][0] << "  " << matrix[i][1] << "  " << matrix[i][2] << endl;
  }
}

int **addMatrix(int **m1, int **m2)
{
  if (m1[0][0] != m2[0][0] || m1[0][1] != m2[0][1])
    return NULL;

  int **matrix = (int **)malloc((m1[0][2] + m2[0][2] + 1) * sizeof(int *));
  int elemCnt = 0, i = 1, j = 1;

  while (i <= m1[0][2] && j <= m2[0][2])
  {
    if (m1[i][0] < m2[j][0])
    {
      matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

      matrix[elemCnt][0] = m1[i][0];
      matrix[elemCnt][1] = m1[i][1];
      matrix[elemCnt][2] = m1[i][2];
      i++;
    }
    else if (m1[i][0] > m2[j][0])
    {
      matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

      matrix[elemCnt][0] = m2[j][0];
      matrix[elemCnt][1] = m2[j][1];
      matrix[elemCnt][2] = m2[j][2];
      j++;
    }
    else if (m1[i][1] < m2[j][1])
    {
      matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

      matrix[elemCnt][0] = m1[i][0];
      matrix[elemCnt][1] = m1[i][1];
      matrix[elemCnt][2] = m1[i][2];
      i++;
    }
    else if (m1[i][1] > m2[j][1])
    {
      matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

      matrix[elemCnt][1] = m2[j][1];
      matrix[elemCnt][0] = m2[j][0];
      matrix[elemCnt][2] = m2[j][2];
      j++;
    }
    else
    {
      matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

      matrix[elemCnt][0] = m1[i][0];
      matrix[elemCnt][1] = m1[i][1];
      matrix[elemCnt][2] = m1[i][2] + m2[j][2];
      i++;
      j++;
    }
  }

  while (i <= m1[0][2])
  {
    matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

    matrix[elemCnt][0] = m1[i][0];
    matrix[elemCnt][1] = m1[i][1];
    matrix[elemCnt][2] = m1[i][2];
    i++;
  }
  while (j <= m2[0][2])
  {
    matrix[++elemCnt] = (int *)malloc(3 * sizeof(int));

    matrix[elemCnt][0] = m2[j][0];
    matrix[elemCnt][1] = m2[j][1];
    matrix[elemCnt][2] = m2[j][2];
    j++;
  }

  int **tmpPtr = (int **)realloc(matrix, (elemCnt + 1) * sizeof(int *));
  // cout << tmpPtr << endl;
  // cout << matrix << endl;

  if (tmpPtr)
    matrix = tmpPtr;

  matrix[0] = (int *)malloc(3 * sizeof(int));
  matrix[0][0] = m1[0][0];
  matrix[0][1] = m1[0][1];
  matrix[0][2] = elemCnt;

  return matrix;
}

int main()
{
  scanMatrix();

  int **matrix1 = scanMatrix(4, 5);
  int **matrix2 = scanMatrix(4, 5);
  // displayMatrix(matrix1);
  displaySparce(matrix1);
  displaySparce(matrix2);

  displayMatrix(addMatrix(matrix1, matrix2));

  return 0;
}
