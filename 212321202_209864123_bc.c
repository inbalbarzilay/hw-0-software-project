#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convertToBase10(int sourceBase) {
    int number = 0;
    char c;
    int digit;

    c = getchar();
    while ( (c = getchar()) != '\n') {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {

            switch(c) {
                case 'a':
                    digit = 10;
                    break;
                case 'b':
                    digit = 11;
                    break;
                case 'c':
                    digit = 12;
                    break;
                case 'd':
                    digit = 13;
                    break;
                case 'e':
                    digit = 14;
                    break;
                case 'f':
                    digit = 15;
                    break;
                default:
                    digit = c - '0';
                    break;
            }

            if (digit >= sourceBase) {
                printf("Invalid input number!\n");
                exit(1);
            }
            
            number = number * sourceBase;
            number = number + digit;
        }
        else {
            continue;
        }
    }
    return number;
}

void convertFromBase10(int targetBase, int number) {
    int i = -1, temp = number, digit;
    char c;
    
    while (temp != 0) {
        i++;
        temp = floor(temp / targetBase);
    }    

    while(i != -1) {
        digit = number / ((int) pow((double) targetBase, (double) i));
        c = digit + '0';
        
        switch (digit) {
            case 10:
                c = 'a';
                break;
            case 11:
                c = 'b';
                break;
            case 12:
                c = 'c';
                break;
            case 13:
                c = 'd';
                break;
            case 14:
                c = 'e';
                break;
            case 15:
                c = 'f';
                break;
        }
        printf("%c", c);
        number = number - digit * ((int) pow((double) targetBase, (double) i));
        i--;
    }
    printf("\n");
}

int main() {
    int sourceBase, targetBase; 

    printf("Enter the source base: ");
    scanf("%d", &sourceBase);

    if (sourceBase < 2 || sourceBase > 16) {
        printf("Invalid source base!\n");
        exit(1);
    }

    printf("Enter the target base: ");
    scanf("%d", &targetBase);

    if (targetBase < 2 || sourceBase > 16) {
        printf("Invalid target base!\n");
        exit(1);
    }
    
    printf("Enter a number in base %d: ", sourceBase);
    convertFromBase10(targetBase, convertToBase10(sourceBase));

    return 0;
}
