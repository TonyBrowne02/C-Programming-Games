/*  Author:Tony Browne
    Date: 02/03/2022
    Description: Lotto game involving a menu along with a variety of options
*/
#include <stdio.h>

#define SIZE 6

void enter_numbers(int*, int*, int*);
void display_numbers(int*);
void sort_numbers(int*);
void play_lotto(int*);
void show_freq(int*, int*);
int end_program(void);

int main()
{
    char menu_choice = '0';
    int numbers[SIZE] = {0,0,0,0,0,0};
    int numbers_chosen = 0;
    int freq_table[42] = {0};

    do
    {
        // menu
        printf("\n1.Enter numbers\n2.Display Picked Numbers\n3.Sort Picked Numbers\n4.Play Lotto\n5.Display Frequency of Picked Numbers\n6.End Program\n");

        //inputting menu choice
        scanf("%1s",&menu_choice);
        while (getchar() != '\n');//Buffer Clear

        switch (menu_choice)
        {
        case '1' :
            enter_numbers(numbers, &numbers_chosen, freq_table);
            break;
        
        case '2' :
            if(numbers_chosen==1)
            {
            display_numbers(numbers);
            break;
            }
            printf("You must choose option 1 first!");
            break;
        
        case '3' :
            if(numbers_chosen==1)
            {
            sort_numbers(numbers);
            break;
            }
            printf("You must choose option 1 first!");
            break;

        case '4' :
            if(numbers_chosen==1)
            {
            play_lotto(numbers);
            break;
            }
            printf("You must choose option 1 first!");
            break;

        case '5' :      
            if(numbers_chosen==1)
            {
            show_freq(numbers, freq_table);
            break;
            }
            printf("You must choose option 1 first!");
            break;

        case '6' :
            menu_choice = end_program();
            break;
        
        default:
            printf("Invalid Option!\n");
            break;
        }//end switch
    }while (menu_choice!=7);
    
    return 0;
}//end main
void enter_numbers(int *numbers, int *numbers_chosen, int* freq_table)
{
    int i,j,temp;

    printf("\nPlease enter 6 numbers between 1 and 42\n");

    for(i=0;i<SIZE;i++)
    {
        scanf("%d",(numbers+i));
        while (getchar() != '\n');//Buffer Clear
        //ensuring entered numbers is between 1 and 42
        if(*(numbers+i)<=42&&*(numbers+i)>=1)
        {   
            //checking for double entries in previously entered numbers 
            for(j=i-1;j>=0;j--)
            {
                if(*(numbers+i)==(*(numbers+j)))
                {
                    printf("\nInvalid option! %d was already selected\n",*(numbers+i));
                    i--;
                }//end if
            }//end for
        }
        else
        {
            printf("\nInvalid option! Enter a number between 1 and 42\n");
            i--;
        }//end if else
    }//end for

    //putting the numbers inputted into the frequency table
    for(i=0;i<6;i++)
    {

        (*(freq_table + (*(numbers+i))))++;
    }
    *numbers_chosen = 1;
}//end enter_numbers
void display_numbers(int *numbers)
{
    int i;
    printf("\nYou chose\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ",*(numbers+i));
    }//end for
}//end display_numbers
void sort_numbers(int *numbers)
{
    int i, j;
    int lindex; //the index of the current lowest element
    int cmin; //current minimum

    //logic for sorting
    for(i=0;i<SIZE-1;i++)
    {
        cmin = *(numbers+i);
        lindex = i;
        for(j=i;j<SIZE;j++)
        {
            if(cmin>*(numbers+j))
            {
                cmin=*(numbers+j);
                lindex=j;
            }//end if
        }//end for

        //swapping the current position in the array with the lowest after that position
        if(i != lindex)
        {
            //Fancy Swap without temp variable
            *(numbers+i) = *(numbers+i) + *(numbers+lindex);
            numbers[lindex] = *(numbers+i) - *(numbers+lindex);
            *(numbers+i)=*(numbers+i) - *(numbers+lindex);
        }//end if
    }//end for

    printf("Numbers sorted\n");
}//end sort_numbers
void play_lotto(int *numbers)
{
    int no_correct = 0;
    int i,j;
    int answers[SIZE] = {1, 3, 5, 7, 9, 11};

    sort_numbers(numbers);
    //checking choices against answer array
    for(i=0;i<SIZE;i++)
    {
        for(j=i;j<SIZE;j++)
        {
            if(*(numbers+i)==*(answers+j))
            {
                no_correct++;
            }//end if
        }//end inner for
    }//end outer for

    printf("\nYou got %d numbers correct!\n",no_correct);

    switch(no_correct)
    {
        case 1||2:
            printf("You didn't win anything, better luck next time!\n");
            break;
        
        case 3:
            printf("You have won a cinema pass\n");
            break;
        
        case 4:
            printf("You have won a weekend away\n");
            break;
        
        case 5:
            printf("You have won a new car\n");
            break;

        case 6:
            printf("You have won the jackpot\n");
    }//end switch
}//end play_lotto
void show_freq(int* numbers, int* freq_table)
{
    int i;
    sort_numbers(numbers);// sort before so it displays in numerical order

    for(i=0;i<SIZE;i++)
    {
        printf("number %d has been entered %d times\n",*(numbers+i), (*(freq_table + (*(numbers+i)))));
    }//end for
}//end show_freq
int end_program(void)
{
    char choice;
    int decision_made = 0;
    while(decision_made!=1)
    {
        printf("Are you sure you want to end the program? Y/N\n");
        scanf("%1s",&choice);
        if(choice=='Y')
        {
            printf("\nEnding Program!\n");
            decision_made = 1;
            return 7;
        }

        if(choice=='N')
        {
            decision_made = 1;
            printf("\nReturning to program!\n");
            return 0;
        }

        if(choice!='N'||choice!='Y')
        {
            printf("%c is an invalid option!\n",choice);
            decision_made = 0;
        }//end else
    }//end while
}//end end_program
