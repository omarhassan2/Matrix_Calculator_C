#include "Matrix.h"

void multiplication(void)
{
    system("cls");
    unsigned short i, j, k;
    unsigned short a_rows, a_columns, b_rows, b_columns, c_rows, c_columns;
    unsigned short sum = 0, num_of_matrix=0;
    int a[Max][Max], b[Max][Max], c[Max][Max],product_1[Max][Max], product_2[Max][Max];
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t::                             Multiplication [A * B] or [A * B * C]                             ::\n");
    printf("\t::   Make sure when you enter the number of rows and columns you follow the Multiplication rule  ::\n");
    printf("\t::     Multiplication rule is number of columns of 'A' must be equal to number of rows of 'B'    ::\n");
    printf("\t::     And the number of columns of 1st product from [A * B] is equal to number of rows of 'C'   ::\n");
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Enter the number of matrices [2] or [3]:\n"); // [2] --> A*B , [3] --> A*B*C
    scanf("%hu", &num_of_matrix);
    while(num_of_matrix != 3 && num_of_matrix != 2)
    {
        printf("Wrong input !!!!\n");
        printf("Enter the number of matrices [2] or [3]:\n");
        scanf("%hu", &num_of_matrix);
    }
    printf("Enter the number of rows and columns as[n x n] of the  matrix 'A' :\n");
    scanf("%hux%hu", &a_rows, &a_columns);

    /* Input the  matrix */
    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    /* Display the matrix */
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            printf("\t\t%d", a[i][j]);
        }
        printf("\n");
    }


    printf("\nEnter the number of rows and columns as[n x n] of the  matrix 'B' :\n");
    scanf("%hux%hu", &b_rows, &b_columns);

    if(b_rows != a_columns) /* Check the multiplication rule */
    {
        printf("\t ::::::::::::::::::::::::::::\n");
        printf("\t :: Mathematical Error !!! :: \n");
        printf("\t ::::::::::::::::::::::::::::\n");
    }
    else
    {
        /* Input the matrix */
        printf("Please enter the elements of the  matrix 'B' :\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        /* Display the matrix */
        printf("\nThe matrix 'B' is :\n\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                printf("\t\t%d", b[i][j]);
            }
            printf("\n");
        }

        /* calculate [A * B] */
        for(i=0; i< a_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                for(k=0; k<a_rows; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                product_1 [i][j] = sum; /* Product_1 = [A * B] */
                sum=0;
            }
        }

        if(num_of_matrix == 3) // if [ A * B * C ]
        {
            printf("Enter the number of rows and columns as[n x n] of the  matrix 'C' :\n");
            scanf("%hux%hu", &c_rows, &c_columns);

            if(c_rows != b_columns) /* Check the multiplication rule */
            {
                printf("\t ::::::::::::::::::::::::::::\n");
                printf("\t :: Mathematical Error !!! ::\n");
                printf("\t ::::::::::::::::::::::::::::\n");
            }
            else
            {
                /* Input the matrix */
                printf("Please enter the elements of matrix 'c' :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        scanf("%d", &c[i][j]);
                    }
                }
                /* Display the matrix */
                printf("\nThe matrix 'c' is :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        printf("\t\t%d", c[i][j]);
                    }
                    printf("\n");
                }
                /* Calculate [Product_1 * C] */
                for(i=0; i<a_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        for(k=0; k<a_rows; k++)
                        {
                            sum += product_1[i][k] * c[k][j];
                        }
                        product_2[i][j] = sum; /* Product_2 = [Product_1 * C] */
                        sum=0;
                    }
                }
                /* Product_2 = [A * B * C] --> Display it when number of matrix is [3] */
                printf("\nThe product of Multiplication is :\n\n");
                for(i=0; i<a_rows; i++) /* (a)rows = (Product_2)rows */
                {
                    for(j=0; j<c_columns; j++) /* (c)columns = (Product_2)columns */
                    {
                        printf("\t\t%d", product_2[i][j]);
                    }
                    printf("\n");
                }

            }
        }
        else
        {
            /* Product_1 = [A * B] --> Display it when number of matrix is [2] */
            printf("\nThe product of Multiplication is :\n\n");
            for(i=0; i<a_rows; i++) /* (a)rows = (Product_1)rows */
            {
                for(j=0; j<b_columns; j++) /* (b)columns = (Product_1)columns */
                {
                    printf("\t\t%d", product_1[i][j]);
                }
                printf("\n");
            }


        }
    }

}
void Addition(void)
{
    system("cls");
    int sum=0;
    unsigned short a_rows, a_columns, b_rows, b_columns, c_rows, c_columns;
    unsigned short i, j, num_matrix;
    int a[Max][Max], b[Max][Max], c[Max][Max], product1[Max][Max], product2[Max][Max];


    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t::                                Addition [A + B] or [A + B + C]                                ::\n");
    printf("\t::      Make sure when you enter the number of rows and columns you follow the Addition rule     ::\n");
    printf("\t::                 Addition  rule is the matrices must be of the same dimension                  ::\n");
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("Enter the number of matrices [2] or [3]:\n");
    scanf("%hu", &num_matrix);
    while(num_matrix != 3 && num_matrix != 2)
    {
        printf("Wrong input !!!!\n");
        printf("Enter the number of matrices [2] or [3]:\n");
        scanf("%hu", &num_matrix);
    }

    printf("Enter the number of rows and columns as[n x n] of the  matrix 'A' :\n");
    scanf("%hux%hu", &a_rows, &a_columns);

    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            printf("\t\t%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the number of rows and columns as[n x n] of the  matrix 'B' :\n");
    scanf("%hux%hu", &b_rows, &b_columns);

    if((a_rows != b_rows) || (a_columns != b_columns))
    {
        printf("\n");
        printf("\t ::::::::::::::::::::::::::::\n");
        printf("\t :: Mathematical Error !!! ::\n");
        printf("\t ::::::::::::::::::::::::::::\n");
    }
    else
    {
        printf("Please enter the elements of the  matrix 'B' :\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        printf("\nThe matrix 'B' is :\n\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                printf("\t\t%d", b[i][j]);
            }
            printf("\n");
        }

        for(i=0; i<a_rows; i++)
        {
            for(j=0; j<a_columns; j++)
            {
                sum = a[i][j] + b[i][j];

                product1[i][j] = sum;

                sum =0;
            }
        }

        if(num_matrix == 3)
        {
            printf("Enter the number of rows and columns as[n x n] of the  matrix 'C' :\n");
            scanf("%hux%hu", &c_rows, &c_columns);

            if( (a_rows != c_rows) || (a_columns != c_columns))
            {
                printf("\n");
                printf("\t ::::::::::::::::::::::::::::\n");
                printf("\t :: Mathematical Error !!! ::\n");
                printf("\t ::::::::::::::::::::::::::::\n");
            }
            else
            {
                printf("Please enter the elements of matrix 'c' :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        scanf("%d", &c[i][j]);
                    }
                }
                printf("\nThe matrix 'c' is :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        printf("\t\t%d", c[i][j]);
                    }
                    printf("\n");
                }

                for(i=0; i<a_rows; i++)
                {
                    for(j=0; j<a_columns; j++)
                    {
                        sum = product1[i][j] + c[i][j];

                        product2[i][j] = sum;

                        sum =0;
                    }

                }


                printf("\nThe result of the Addition is :\n\n");
                for(i=0; i<a_rows; i++)
                {
                    for(j=0; j<a_columns; j++)
                    {
                        printf("\t\t%d ", product2[i][j]);
                    }
                    printf("\n");
                }

            }
        }
        else
        {
            printf("\nThe result of the Addition is :\n\n");
            for(i=0; i<a_rows; i++)
            {
                for(j=0; j<a_columns; j++)
                {
                    printf("\t\t%d", product1[i][j]);
                }
                printf("\n");
            }
        }



    }
}
void Subtraction(void)
{
    system("cls");
    int sum=0;
    unsigned short a_rows, a_columns, b_rows, b_columns, c_rows, c_columns;
    unsigned short i, j, num_matrix;
    int a[Max][Max], b[Max][Max], c[Max][Max], product1[Max][Max], product2[Max][Max];


    printf("\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t::                                Subtraction [A - B] or [A - B - C]                                ::\n");
    printf("\t::      Make sure when you enter the number of rows and columns you follow the Subtraction rule     ::\n");
    printf("\t::                   Subtraction  rule is the matrices must be at same dimension                    ::\n");
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("Enter the number of matrices [2] or [3]:\n");
    scanf("%hu", &num_matrix);
    while(num_matrix != 3 && num_matrix != 2)
    {
        printf("Wrong input !!!!\n");
        printf("Enter the number of matrices [2] or [3]:\n");
        scanf("%hu", &num_matrix);
    }

    printf("Enter the number of rows and columns as[n x n] of the  matrix 'A' :\n");
    scanf("%hux%hu", &a_rows, &a_columns);

    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            printf("\t\t%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the number of rows and columns as[n x n] of the  matrix 'B' :\n");
    scanf("%hux%hu", &b_rows, &b_columns);

    if((a_rows != b_rows) || (a_columns != b_columns))
    {
        printf("\n");
        printf("\t ::::::::::::::::::::::::::::\n");
        printf("\t :: Mathematical Error !!! ::\n");
        printf("\t ::::::::::::::::::::::::::::\n");
    }
    else
    {
        printf("Please enter the elements of the  matrix 'B' :\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        printf("\nThe matrix 'B' is :\n\n");
        for(i=0; i<b_rows; i++)
        {
            for(j=0; j<b_columns; j++)
            {
                printf("\t\t%d", b[i][j]);
            }
            printf("\n");
        }

        for(i=0; i<a_rows; i++)
        {
            for(j=0; j<a_columns; j++)
            {
                sum = a[i][j] - b[i][j];

                product1[i][j] = sum;

                sum =0;
            }
        }

        if(num_matrix == 3)
        {
            printf("Enter the number of rows and columns as[n x n] of the  matrix 'C' :\n");
            scanf("%hux%hu", &c_rows, &c_columns);

            if( (a_rows != c_rows) || (a_columns != c_columns))
            {
                printf("\n");
                printf("\t ::::::::::::::::::::::::::::\n");
                printf("\t :: Mathematical Error !!! ::\n");
                printf("\t ::::::::::::::::::::::::::::\n");
            }
            else
            {
                printf("Please enter the elements of matrix 'c' :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        scanf("%d", &c[i][j]);
                    }
                }
                printf("\nThe matrix 'c' is :\n");
                for(i=0; i<c_rows; i++)
                {
                    for(j=0; j<c_columns; j++)
                    {
                        printf("\t\t%d", c[i][j]);
                    }
                    printf("\n");
                }

                for(i=0; i<a_rows; i++)
                {
                    for(j=0; j<a_columns; j++)
                    {
                        sum = product1[i][j] - c[i][j];

                        product2[i][j] = sum;

                        sum =0;
                    }

                }


                printf("\nThe result of the Subtraction is :\n\n");
                for(i=0; i<a_rows; i++)
                {
                    for(j=0; j<a_columns; j++)
                    {
                        printf("\t\t%d ", product2[i][j]);
                    }
                    printf("\n");
                }

            }
        }
        else
        {
            printf("\nThe result of the Subtraction is :\n\n");
            for(i=0; i<a_rows; i++)
            {
                for(j=0; j<a_columns; j++)
                {
                    printf("\t\t%d", product1[i][j]);
                }
                printf("\n");
            }
        }



    }
}
void Division(void)
{
    int i, j, k, order;
    float sum=0.0;
    float A[Max][Max], B[Max][Max], product[Max][Max];

    system("cls");
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t::                           Division [A / B] = [A * B^-1(Inverse))]                             ::\n");
    printf("\t::   Make sure That when you enter the number of rows and columns you follow the Division rule   ::\n");
    printf("\t::     Division rule is number of columns of 'A' must be equal to number of rows of 'B^-1'       ::\n");
    printf("\t::           That means the order of Matrix[A] must be equal to order of Matrix[B]               ::\n");
    printf("\t::               That means  Matrix[A] and Matrix[B] Must be [Square Matrices]                   ::\n");
    printf("\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Enter the order of these square matrices at most 100:\n");
    scanf("%d", &order);
    printf("\nEnter the element of matrix 'A':\n");
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }
    printf("\nMatrix 'A' is :\n");
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            printf("\t\t%.2f", A[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the element of matrix 'B':\n");
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            scanf("%f", &B[i][j]);
        }
    }
    printf("\nMatrix 'B' is :\n");
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            printf("\t\t%.2f", B[i][j]);
        }
        printf("\n");
    }

    Inverse_use(B, order);
    if((Determinant_use(B, order)) != 0)
    {
        for(i=0; i<order; i++)
        {
            for(j=0; j<order; j++)
            {
                for(k=0; k<order; k++)
                {
                    sum += A[i][k] * B[k][j];
                }
                product[i][j] = sum;
                sum=0;
            }
        }



        printf("\nThe result of [A/B] is :\n");
        for(i=0; i<order; i++)
        {
            for(j=0; j<order; j++)
            {
                printf("\t\t%.2f", product[i][j]);
            }
            printf("\n");
        }
    }


}
void Transpose(void)
{
    system("cls");
    unsigned short i, j, a_rows, a_columns;
    int a[Max][Max], a_transpose[Max][Max];

    printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t::             Transpose [A(T)]             ::\n");
    printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("Enter the number of rows and columns as [n x n] of the  matrix 'A' :\n");
    scanf("%hux%hu", &a_rows, &a_columns);

    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            printf("\t\t%d", a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<a_rows; i++)
    {
        for(j=0; j<a_columns; j++)
        {
            a_transpose[j][i] = a[i][j];
        }
    }
    printf("\nThe result of Transpose is:\n\n");
    for(i=0; i<a_columns; i++)
    {
        for(j=0; j<a_rows; j++)
        {
            printf("\t\t%d", a_transpose[i][j]);
        }
        printf("\n");
    }
}
int Determinant_use(int A[Max][Max], int n)
{
    int Minor[Max][Max];
    int i,j,k,c1=0,c2=0;
    int determinant=0;
    int O=1;

    if(n == 2) // n is order of matrix
    {
        determinant = 0;
        determinant = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        return determinant;
    }
    else
    {
        for(i = 0 ; i < n ; i++)
        {
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++)
            {
                for(k = 0 ; k < n ; k++)
                {
                    if(j != 0 && k != i)
                    {
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinant = determinant + O*(A[0][i]*Determinant_use(Minor,n-1));
            O=-1*O;
        }
    }
    return determinant;;

}
void Determinant(void)
{
    system("cls");
    int i, j;
    int mat_order=0; // value of  order of the square matrix
    int a[Max][Max];
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                    Determinant[A(D)]                   ::\n");
    printf("\t\t\t:: This Program Calculate determinant of [Square Matrix]  ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Please enter the order of [Square Matrix] at most 100:\n");
    scanf("%d", &mat_order);

    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<mat_order; i++)
    {
        for(j=0; j<mat_order; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<mat_order; i++)
    {
        for(j=0; j<mat_order; j++)
        {
            printf("\t\t%d", a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\t\tThe determinant of matrix = %d \n\n", Determinant_use(a, mat_order));
}
void Inverse_use(float a[Max][Max], int order)
{
    float ratio;
    int i,j,k, c=0;
    /* Augmenting Identity Matrix of Order n */
    for(i=0; i<order; i++)
    {
        for(j=0; j<order; j++)
        {
            if(i==j)
            {
                a[i][j+order] = 1;
            }
            else
            {
                a[i][j+order] = 0;
            }
        }
    }
    /* Applying Gauss Jordan Elimination */
    for(i=0; i<order; i++)
    {
        if(a[i][i] == 0.0)
        {
            printf("\n");
            printf("\t ::::::::::::::::::::::::::::\n");
            printf("\t :: Mathematical Error !!! ::\n");
            printf("\t ::::::::::::::::::::::::::::\n");
            return 0;
        }
        for(j=0; j<order; j++)
        {
            if(i!=j)
            {
                ratio = a[j][i]/a[i][i];
                for(k=0; k<2*order; k++)
                {
                    a[j][k] = a[j][k] - ratio*a[i][k];
                }
            }
        }
    }
    /* Row Operation to Make Principal Diagonal to 1 */
    for(i=0; i<order; i++)
    {
        for(j=order; j<2*order; j++)
        {
            a[i][j] = a[i][j]/a[i][i];
        }
    }
    /* Inverse Matrix */
    for(i=0; i<order; i++)
    {
        c=0;
        for(j=order; j<2*order; j++)
        {
            a[i][c] = a[i][j];
            c++;
        }
    }
}
void Inverse(void)
{
    int mat_order, i, j;
    float a[Max][Max];

    system("cls");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t::                     Inverse[A(I)]                    ::\n");
    printf("\t\t\t::  This Program Calculate inverse of [Square Matrix]   ::\n");
    printf("\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("Please enter the order of [Square Matrix] at most 100:\n");
    scanf("%d", &mat_order);

    printf("Please enter the elements of the  matrix 'A' :\n");
    for(i=0; i<mat_order; i++)
    {
        for(j=0; j<mat_order; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nThe Matrix 'A' is :\n\n");

    for(i=0; i<mat_order; i++)
    {
        for(j=0; j<mat_order; j++)
        {
            printf("\t\t%.2f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    Inverse_use(a, mat_order);
    Determinant_use(a, mat_order);
    if(Determinant_use(a, mat_order) != 0)
    {
        printf("\nThe inverse of matrix is :\n\n");
        for(i=0; i<mat_order; i++)
        {
            for(j=0; j<mat_order; j++)
            {
                printf("\t\t%.2f", a[i][j]);
            }
            printf("\n");
        }
    }
}
void Select_Operation(char sign_operation)
{
    switch (sign_operation)
    {
    case '+':
        Addition();
        break;
    case '-':
        Subtraction();
        break;
    case '*':
        multiplication();
        break;
    case '/':
        Division();
        break;
    case 'T':
        Transpose();
        break;
    case 't':
        Transpose();
        break;
    case 'I':
        Inverse();
        break;
    case 'i':
        Inverse();
        break;
    case 'D':
        Determinant();
        break;
    case 'd':
        Determinant();
        break;
    default:
        printf("Wrong input!!!!");

    }
}
