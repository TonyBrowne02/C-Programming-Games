/* Author: Tony Browne
   Date:10/11/21 18:18 -> 22:21
   Description: A program to simulate a many based maths quiz game, incorporating various features such as displaying the correct answer,
   only allowing acces to certain parts of the game after necessary components are done i.e input the no. of questions before
   starting a quiz etc. 

*/
#include <stdio.h>
int main()
{
    char selection = ' ';
    int num_questions = 0;
    int question_no = 0;
    int answer = 0;
    int user_answer = 0;
    int q_num1 = 0;
    int q_num2 = 0;
    int no_correct = 0;
    int no_wrong = 0;
    int quiz_ran = 0;
    int qs_chosen = 0;
    int q_checker = 0;
    int OffSwitch = 0;

    while(OffSwitch!=1) //Close when selection = 4, graceful shut down
    {
        //Displaying the menu
        printf("\nPlease choose an available option below\n");
        printf("1. Enter the number of questions to be asked for this round of the quiz\n   (maximum of 5 questions allowed)\n");
        printf("2. Start and play quiz\n");
        printf("3. Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round\n");
        printf("4. Exit Program\n");

        
        scanf(" %c",&selection); //input of the selection from the menu [Breaks and goes on a loop forever if a non numeral is entered]
        printf("\nYOU SELECTED %c\n",selection);
        while (getchar() != '\n');
        switch(selection)
        {
            case '1' :  //if selection 1 is chosen, ask to input the no. of questions    
                q_checker = 0; //resetting the check that a valid no. of questions has been chosen, used if the user wants to change the no. of questions before the quiz
                while (q_checker!=1) // checking that a valid no. of questions has been chosen
                {
                    num_questions = 0;
                    printf("\n\nEnter the number of questions you would like to be asked for this round of the quiz\n\n");
                    scanf(" %d",&num_questions); //input the no of questions [Breaks and goes on a loop forever if a non numeral is entered]
                    

                    if ((num_questions<=5)&&(num_questions>0))//no. of questions must be between 1 and 5
                    {
                        q_checker = 1; //setting check that a VALID no. ofquestions has been chosen
                        qs_chosen = 1; //setting check that the no. of questions has been chosen before starting a quiz
                    } //end if
                    else // if not between 1 and 5, enter in a valid no of questions [BREAKS FOR NON NUMERALS]
                    {
                        printf("\n\nThat is not a valid no. of questions\nplease select a no. of questions between 1 and 5!\n\n");
                       while (getchar() != '\n');
                    } //end else

                } //end while
                break;

            case '2' : //start quiz
                if(qs_chosen==1) //checking that the number of questions has been inputted before starting quiz
                {
                    quiz_ran = 1; //setting the check that a quiz has been run before option 3 can be chosen
                    no_wrong = 0; //resetting the no. of wrong questions from possible previous rounds
                    no_correct = 0; //restting the no of correct questions from possible previous rounds
                    question_no = 0; //resetting the no. of answered questions

                    for(question_no=1;question_no<=num_questions;question_no++)
                    {
                        q_num1 = rand() %21; // Sets q_num1 as a random number between 1 and 20, doesn't include 21
                        q_num2 = rand() %31; // Sets q_num2 as a random number between 1 and 30, doesn't include 31
                        answer = q_num1 + q_num2; //sets the answer

                        printf("Question %d of %d:\n",question_no, num_questions); //prints the question no.
                        printf(" %d + %d = ?\n",q_num1, q_num2); //prints the question
                        scanf(" %d",&user_answer); //gets users answer

                        if(user_answer==answer) //correct answer case
                        {
                            printf("\nCorrect!\nYou entered: %d\nThe correct answer: %d\n",user_answer,answer);
                            no_correct++;
                        } //end if
                        else //wrong answer case
                        {
                            printf("\nIncorrect!\nYou entered: %d\nThe correct answer: %d\n",user_answer,answer);
                            no_wrong++;
                        } //end else
                        while (getchar() != '\n');
                    } //end for

                } //end if
                else //telling the user to do option 1 from the menu before starting the game
                {
                    printf("\n\nYou must first select the no. of questions you would like to answer by selecting option 1!\n\n");
                } //end else
                break;

            case '3' : //Displaying the results from the quiz
                if(quiz_ran==0) //Checking a quiz has been run
                {
                    printf("\n\nYou must start a quiz first!\n\n");

                } //end inner if    
                else if(quiz_ran==1) //If a quiz has been run then displaying the results
                {
                    printf("\n\nCorrect answers :%d\nIncorrect answers :%d\n\n",no_correct,no_wrong);
                } //end else if
                break;

            case '4' : //shut down case
                OffSwitch = 1;
                printf("Program ended");
                break;

            default: // Anything that is not a valid option
                printf("\n\n'%c' is not a valid selection\nPlease choose an option from the menu!\n\n",selection);
                break;

        }//end switch
    }// end while
    return 0;
} //end main