/**************************** WORD BUILDING ***************************/

#include<stdio.h>
#include<string.h>
#include<conio.h>

//function declarations

void build();
void show();

// Structure of the word

struct Node
{
   char data[50];
   struct Node *next;
}*front = NULL,*rear = NULL,*temp, *new;

//life for playing
int life = 3;
//quit string
char q[] = "i-quit";

void main()
{
   int ch;

 /*
   puts("       W                 W   OOOO    RRRRRRR    DDDDDD            BBBBB   U       U  IIIIIIIII  L          DDDDDD    EEEEEEE    RRRRRRRR\n");
   puts("        W               W  OO    OO  R      R   D     D           B    B  U       U      I      L          D     D   E          R       R\n");
   puts("         W             W   OO    OO  R      R   D     D           B    B  U       U      I      L          D     D   E          R       R\n");
   puts("          W     W     W    OO    OO  RRRRRRR    D     D  ------   BBBBB   U       U      I      L          D     D   EEEEEEE    RRRRRRRR\n");
   puts("           W   W W   W     OO    OO  R R        D     D           B    B  U       U      I      L          D     D   E          R R  \n");
   puts("            W W   W W      OO    OO  R   R      D     D           B    B  U       U      I      L          D     D   E          R   R\n");
   puts("             W     W         OOOO    R     RR   DDDDDD            BBBBB    UUUUUUU   IIIIIIIII  LLLLLLLL   DDDDDD    EEEEEEE    R     RR\n");
*/

    puts("\n\n\t\t\t\tWORD BUILDER\n\n");


// RULES and BLA BLA BLA

    puts("\nIntro:");
    puts("\nYou have given ~3 lives~");
    puts("\nYou have to Enter a word first");
    puts("\nThen you have to build a word tower using the last letter of the past words");
    puts("\nIf you didn\'t start with the last letter - You lose a life");
    puts("\nIf you use the already entered word - Guess what - You lose a life");
    puts("\nIf you wanna quit Enter \"i-quit\" -\( Enter it without  \" \) \n\n\n");

//Building block

    do{

        build();

    }while(strcmp(new->data,q));

}

//Function for memory allocation

struct Node* create(char val[])
{
    new = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new->data,val);
    new -> next = NULL;
    return new;
}

//Function for checking if the last letter of the last word and the first letter of the current word are equal
//returns 1 if equal
//returns 0 if it sucks


int check(char l[], char c[])
{
    int max;
    char ll;
    max = strlen(l);
    ll = l[max-1];

    if(ll == c[0])
        return 1;
    else
        return 0;
}

//Function for checking if the current word already used to build
//returns 1 if already used and it means you are fucked up
//returns 0 if not used and it means you're good to go


int reoc(char c[])
{
    temp = front;
    do
    {
        if(strcmp(c,temp->data) == 0)
            {
            return 1;
            break;
            }
        else
            temp = temp->next;
    }while(temp != NULL);
    return 0;

}

//function which used to build
//it allows the word to build only if
//1.check() returns 1
//2.reoc()  returns 0
//unless you gonna sucked up real hard


void build()
{
   char val[50];
   int ch = 0;

    printf("Enter the word: ");
    scanf("%s", val);

   if(strcmp(val,q) == 0)
   {
        puts("\n------------------------QUITER---------------------------------");
        exit(1);
   }

   new = create(val);


   if(front == NULL)
      front = rear = new;
   else{
      if(life !=0 )
      {
      if(check(rear->data,new->data) == 1)
      {
         if(reoc(new->data) != 1)
         {
                rear -> next = new;
                rear = new;
                show();
         }
         else
        {
            puts("\nalready typed that word\n");
            puts("\t\tOne life Down");
            life--;
            printf("\nCurrent lives        ::          %d\n", life);
        }
      }
      else
      {
            puts("\nMismatch in last and first letters\n");
            puts("\t\tOne life Down");
            life--;
            printf("\nCurrent lives           ::         %d\n", life);
      }
      }
      else
      {
            puts("\nOut of lives\n");
            puts("----------------------------------you LOSE-----------------------------------------------------------------------\n");
            exit(1);
      }

}
}


//FINALLY the display function
//it displays the tower of words that you're built
//if it doesn't display it means you lose
//And that also means you suck at this game

void show()
{
   if(front == NULL)
      printf("\nnot built yet!!\n");
   else{
        temp = front;
        do{
        printf("\t\t\t%s\n",temp->data);
        temp = temp -> next;
      }while(temp != NULL);
   }
}
