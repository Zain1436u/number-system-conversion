#include<stdio.h>  // for: input & output
#include<stdlib.h> // for: exit(0) function
#include<conio.h>  // for: getch() function
#include<ctype.h>  // for: isdigit() function
#include<math.h>   // for: pow(2,0) function
#include<string.h> // for: strlen() function

// Define Constant KeyWords: for tracking user key press event (used in: HexaDecimal input validation)
#define ENTER 13
#define TAB 9
#define BKSP 8

void welcomeScreen(void);    // Introduction Page & choice screen
void exitScreen(void);       // program end screen with credits
void screenCleaner(void);    // clears the output screen and input buffers
void userInput(int);         // takes the user input and validates for further opertaions
int digitChecker(int, int);  // validates each digit of input number
void conversion_Title(void); // title for all conversion outputs
void tryAgain(int);          // try Again window

// Binary Conversion functions
void binary_decimal(long int);
void binary_octal(long int);
void binary_hexadecimal(long int);

// Decimal Conversion functions
void decimal_binary(long int);
void decimal_octal(long int);
void decimal_hexadecimal(long int);

// Octal Conversion functions
void octal_binary(long int);
void octal_decimal(long int);
void octal_hexadecimal(long int);

// Hexadecimal Convesion functions
void hexadecimal_binary(char []);
void hexadecimal_octal(char []);
void hexadecimal_decimal(char []);
// C-Program main function
void main()
{
    welcomeScreen();
}

// Intro screen
void welcomeScreen()
{
    int choice;

label1:
    screenCleaner();
    printf("-------------------------------------------\n");
    printf(">>> Welcome to Number System Converter <<< \n");
    printf("-------------------------------------------\n\n");

    printf(">> Select Conversion Type: \n");
    printf("> 1. Binary Conversion \n");
    printf("> 2. Decimal Conversion \n");
    printf("> 3. Octal Conversion \n");
    printf("> 4. Hexadecimal Conversion \n");
    printf("> 5. word ASCII Conversion \n");
    printf("> 6. Exit the Program \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d", &choice);

    // passes the user input for conversion
    switch(choice)
    {
    case 1:
        userInput(1);
        break;
    case 2:
        userInput(2);
        break;
    case 3:
        userInput(3);
        break;
    case 4:
        userInput(4);
        break;
    case 5:
        userInput(5);
        break;
    case 6:
        exitScreen();
        break;
    default:
        printf("\nError: the number must be between 1 to 5.\n");
        printf("Press any key to continue... \n");
        getch();
        goto label1;
    }
}

// program exit screen (credit page)
void exitScreen()
{
    screenCleaner();
     printf("-------------------------------------------\n");
    printf(" >>> original Creator: Ganesh Mourya (@Alkaison) <<< \n");
    printf("-------------------------------------------\n\n");

    printf("> project done by:\n> mohammed nurulazim. ID:C243133 \n");
    printf("> estiak hossain. ID:C243131 \n");
    printf("> syed muntasir mahmud. ID:C243136 \n\n");
    exit(0);  // exit() function to close the program safely
}

void screenCleaner()
{
    system("cls");  // clears the output screen
    fflush(stdin);  // clears the input buffer
}

void userInput(int choice)
{
    screenCleaner();

    if(choice == 1) // Binary input validation code
    {
        char n_input[10];
        int n;

        printf("Enter how many numbers to convert: ");
        scanf("%s", n_input);

        // Check if n_input contains only digits
        for (int i = 0; n_input[i] != '\0'; i++)
        {
            if (!isdigit(n_input[i]))
            {
                printf("Invalid input! Only numbers are allowed.\n");
                getch();
                userInput(choice);
            }
        }
        n = atoi(n_input);
        long int bi[n];
        int flag = 0;

        for(int i=0; i<n; i++)
        {
            printf("Enter the binary: ");
            scanf("%ld", &bi[i]);
        }
        for(int i=0; i<n; i++)
        {
            flag = digitChecker(bi[i], choice);
            if(flag == 1)
            {
                conversion_Title();
                printf("\nError: Binary can only have the digits 0, 1. \n");
            }
            else
            {
                conversion_Title();
                printf("binary number: %ld",bi[i]);
                binary_decimal(bi[i]);
                binary_octal(bi[i]);
                binary_hexadecimal(bi[i]);
            }
        }
        tryAgain(choice);



    }
    else if(choice == 2)  // Decimal input validation code
    {
         char n_input[10];
        int n;

        printf("Enter how many numbers to convert: ");
        scanf("%s", n_input);

        // Check if n_input contains only digits
        for (int i = 0; n_input[i] != '\0'; i++)
        {
            if (!isdigit(n_input[i]))
            {
                printf("Invalid input! Only numbers are allowed.\n");
                getch();
                userInput(choice);
            }
        }
        n = atoi(n_input);
        long int deci[n];
        int flag = 0;
        for(int i=0; i<n; i++)
        {
            printf("Enter the decimal: ");
            scanf("%ld", &deci[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(deci[i] > 0)
                flag = digitChecker(deci[i], choice);
            else
                flag = 1;

            if(flag == 1)
            {
                conversion_Title();
                printf("\nError: Decimal number can't be negative. \n");
            }
            else
            {
                conversion_Title();
                printf("decimal number: %ld",deci[i]);
                decimal_binary(deci[i]);
                decimal_octal(deci[i]);
                decimal_hexadecimal(deci[i]);

            }
        }
        tryAgain(choice);

    }
    else if(choice == 3)  // Octal input validation code
    {
         char n_input[10];
        int n;

        printf("Enter how many numbers to convert: ");
        scanf("%s", n_input);

        // Check if n_input contains only digits
        for (int i = 0; n_input[i] != '\0'; i++)
        {
            if (!isdigit(n_input[i]))
            {
                printf("Invalid input! Only numbers are allowed.\n");
                getch();
                userInput(choice);
            }
        }
        n = atoi(n_input);
        long int octal[n];
        int flag = 0;
        for(int i=0; i<n; i++)
        {
            printf("Enter the octal: ");
            scanf("%ld", &octal[i]);
        }
        for(int i=0; i<n; i++)
        {
            flag = digitChecker(octal[i], choice);

            if(flag == 1)
            {
                conversion_Title();
                printf("\nError: Octal digits can only be between 0 to 7. \n");
            }
            else
            {
                conversion_Title();
                printf("octal number: %ld",octal[i]);
                octal_binary(octal[i]);
                octal_decimal(octal[i]);
                octal_hexadecimal(octal[i]);

            }
        }
        tryAgain(choice);
    }


    else if(choice == 4)  // HexaDecimal input validation code
    {
        char hexa[50];
        char ch;
        int i, j=0, k=0, flag;
        while (1)
        {
            i = 0;
            flag = 0;

            printf("\nEnter the hexadecimal (or type 'exit' to quit): ");

            while(1)
            {
                ch = getch();
                if(ch == ENTER || ch == TAB)
                {
                    hexa[i] = '\0';
                    break;
                }
                else if(ch == BKSP)
                {
                    if(i > 0)
                    {
                        i--;
                        printf("\b \b"); // for backspace
                    }
                }
                else
                {
                    hexa[i++] = ch;
                    printf("%c", ch);
                }
            }
            if (strcmp(hexa, "exit") == 0)
            {
                welcomeScreen();
            }

            for(j=0; j<i; j++)
            {
                if((hexa[j] >= 'A' && hexa[j] <= 'F') || (hexa[j] >= 'a' && hexa[j] <= 'f') || isdigit(hexa[j]))
                    k++;
                else
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1)
            {
                printf("\n\nError: Hexadecimal digits can only be between 0 to 9 & A to F. \n");
                continue;
            }
            else
            {
                printf("\n");
                conversion_Title();
                hexadecimal_binary(hexa);
                hexadecimal_octal(hexa);
                hexadecimal_decimal(hexa);

            }
        }
    }
    else if(choice == 5)
    {
        char word[100];

    printf("Enter a word to convert into ASCII values: ");
    scanf("%s", word);

    // Validate that the input is a word (only alphabetic characters)
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            printf("Invalid input! Only alphabetic characters are allowed.\n");
            tryAgain(choice);
        }
    }

    printf("\nASCII values of the word '%s':\n", word);
    for (int i = 0; word[i] != '\0'; i++) {
        conversion_Title();
                 printf("%c: %d", word[i], word[i]);
                decimal_binary(word[i]);
                decimal_octal(word[i]);
                decimal_hexadecimal(word[i]);



    }
    tryAgain(choice);
    }
    else  // Very rare case message
        printf("\n>> Unexpected Error occured. Report to program Administrator << \n");
}

// validation function for each single digit of a number according to conversion condition
int digitChecker(int num, int choice)
{
    long int rem, temp=0, flag=0;
    temp = num;

    while(temp != 0)
    {
        rem = temp % 10;

        if((rem == 0 || rem == 1) && choice == 1) // binary, choice = 1
            temp = temp / 10;
        else if(rem >= 0 && rem <= 9 && choice == 2) // decimal, choice = 2
            temp = temp / 10;
        else if(rem >= 0 && rem <=7 && choice == 3) // octal, choice = 3
            temp = temp / 10;
        else
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// title for all conversion outputs
void conversion_Title()
{
    printf("\n---------------------------\n");
    printf(">>> Conversion Results <<< \n");
    printf("---------------------------\n");
}

// try Again window
void tryAgain(int choice)
{
    char ch;

    printf("\n\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch (ch)
    {
    case 'Y':
    case 'y':
        userInput(choice);
        break;
    case 'N':
    case 'n':
        welcomeScreen();
        break;
    default:
        printf("\nError: invalid input. \n");
        printf("Press any key to continue... \n");
        getch();
        welcomeScreen();
    }
}

// Binary Conversion functions
void binary_decimal(long int bi)
{
    int rem,sum=0,i=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }

    printf("\nDecimal Number: %d",sum);
}

void binary_octal(long int bi)
{
    int i=0,rem,sum=0,remain[100],len=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%8;
        sum=sum/8;
        i++;
        len++;
    }

    printf("\nOctal Number: ");
    for(i=len-1; i>=0; i--)
    {
        printf("%d",remain[i]);
    }
}

void binary_hexadecimal(long int bi)
{
    int rem,i=0,sum=0,remain[100],len=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%16;
        sum=sum/16;
        i++;
        len++;
    }

    printf("\nHexa-Decimal Number: ");
    for(i=len-1; i>=0; i--)
    {
        switch(remain[i])
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",remain[i]);
        }
    }
    printf("\n");
}

// Decimal Conversion functions
void decimal_binary(long int deci)
{
    int rem[50],i,len=0;

    do
    {
        rem[i]=deci%2;
        deci=deci/2;
        i++;
        len++;
    }
    while(deci !=0);

    printf("\nBinary Number: ");
    for(i=len-1; i>=0; i--)
    {
        printf("%d",rem[i]);
    }
}

void decimal_octal(long int deci)
{
    int rem[50],i,len=0;

    do
    {
        rem[i]=deci%8;
        deci=deci/8;
        i++;
        len++;
    }
    while(deci!=0);

    printf("\nOctal Number: ");
    for(i=len-1; i>=0; i--)
    {
        printf("%d",rem[i]);
    }
}

void decimal_hexadecimal(long int deci)
{
    int rem[50],i,len=0;

    do
    {
        rem[i]=deci%16;
        deci=deci/16;
        i++;
        len++;
    }
    while(deci!=0);

    printf("\nHexa-Decimal Number: ");
    for(i=len-1; i>=0; i--)
    {
        switch(rem[i])
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",rem[i]);
        }
    }
    printf("\n");
}

// Octal Conversion functions
void octal_binary(long int oct)
{
    int rem[50],len=0,decimal=0,i=0,num,ans;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    do
    {
        rem[i]=decimal%2;
        decimal=decimal/2;
        i++;
        len++;
    }
    while(decimal!=0);

    printf("\nBinary Number: ");
    for(i=len-1; i>=0; i--)
    {
        printf("%d",rem[i]);
    }
}

void octal_decimal(long int oct)
{
    int decimal=0,i=0,num,ans;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }
    printf("\nDecimal Number: %d",decimal);
}

void octal_hexadecimal(long int oct)
{
    int rem[50],len=0,decimal=0,i=0,num,ans=0;
    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    while(decimal!=0)
    {
        rem[i]=decimal%16;
        decimal=decimal/16;
        i++;
        len++;
    }

    printf("\nHexa-Decimal Number: ");

    for(i=len-1; i>=0; i--)
    {
        switch(rem[i])
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",rem[i]);
        }
    }
    printf("\n");
}

// Hexadecimal Convesion functions
void hexadecimal_binary(char hexa[])
{
    int i=0;

    printf("\nBinary Number: ");

    for(i=0; i<strlen(hexa); i++)
    {
        switch (hexa[i])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        default:
            printf("\n Invalid hexa digit %c ", hexa[i]);
        }
    }
}

void hexadecimal_octal(char hexa[])
{
    int i,len,num=0,power=0,decimal=0,rem[100];

    for(i=strlen(hexa)-1; i>=0; i--)
    {
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal+num*pow(16,power);
        power++;
    }

    i=0,len=0;
    while(decimal!=0)
    {
        rem[i]=decimal%8;
        decimal=decimal/8;
        i++;
        len++;
    }

    printf("\nOctal Number: ");
    for(i=len-1; i>=0; i--)
    {
        printf("%d",rem[i]);
    }
}

void hexadecimal_decimal(char hexa[])
{
    int i,num=0,power=0,decimal=0;

    for(i=strlen(hexa)-1; i>=0; i--)
    {
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal+num*pow(16,power);
        power++;
    }
    printf("\nDecimal Number: %d\n",decimal);
}
