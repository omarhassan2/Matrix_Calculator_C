#include "Matrix.h"
void Operation_Table(void);


int main()
{
    unsigned char sign_operation=0;
    unsigned short flag=0;  // flag = 2 to end program and flag = 1 to chose another operation

    printf("\t\t\t\t\t ::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t ::  Welcome To Matrix Calculator  ::\n");
    printf("\t\t\t\t\t ::::::::::::::::::::::::::::::::::::\n\n");
    printf("\t   ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t   ::   In this program you can do Addition , Subtraction, Multiplication, on at most '3' matrices   :: \n\t   ::\t        And you can do division '2' matrices , Transpose, Inverse, Determinant.\t             ::\n");
    printf("\t   ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    Operation_Table();
    printf("Select an operation by it's sign\n");
    printf("---------------------------------\n");


    while(1)
    {
        printf("Enter the sign operation:\n");
        fflush(stdin); // Thanks Eng. Mahmoud
        scanf("%c", &sign_operation);
        Select_Operation(sign_operation);
        printf("\n\nDo you want to chose another operation or end program: \n1)Select another operation\n2)End program\n");
        scanf("%hu", &flag);
        system("cls");
        Operation_Table();
        if(flag == 2)
        {
            system("cls");
            printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("\t\t\t\t::            The Program Ended             ::\n");
            printf("\t\t\t\t::    Thank You Dr.Ahmed and Eng.Mahmoud    ::\n");
            printf("\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::\n");
            break;
        }
        else {/* Do Nothing */}

    }



}

void Operation_Table(void)
{
    printf("\t\t\t\t\t    :::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t    :: The Signs Operations is ::\n");
    printf("\t\t\t\t\t    :::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t    ::        Addition [+]     ::\n");
    printf("\t\t\t\t\t    ::       Subtraction [-]   ::\n");
    printf("\t\t\t\t\t    ::     Multiplication [*]  ::\n");
    printf("\t\t\t\t\t    ::        Division [/]     ::\n");
    printf("\t\t\t\t\t    ::        Transpose [T]    ::\n");
    printf("\t\t\t\t\t    ::        Inverse [I]      ::\n");
    printf("\t\t\t\t\t    ::      Determinant [D]    ::\n");
    printf("\t\t\t\t\t    :::::::::::::::::::::::::::::\n\n");
}

