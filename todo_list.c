    #include <stdio.h>
    #include <malloc.h>
    #include <string.h>

    //Structure Declaration

    struct node

    {

        char data[50];

        struct node *link;

    }*New, *Prev, *Temp, *Head = NULL;

    //Function Declarations

    struct node* memalloc();

    void insert();

    void delete();

    void display();

    //MAIN

    void main()

     {

        int ch;

        puts("\t\tTo-Do list\n");
        while(1)
        {

            printf("\n1.add a task\n2.checkmark a task\n3.Print all tasks\n 0 - EXIT");
            printf("\nEnter your choice");

            scanf("%d", &ch);



            switch (ch)

            {

            case 0:

                puts("Exiting");

                exit(1);

                break;

            case 1:

                insert();

                display();

                break;


            case 2:

                display();

                delete();

                break;

            case 3:

                puts("\t\tPrinting tasks\n");

                display();

                break;

            default:

                puts("\n...Invalid Choice...\n");

                break;

            }

        }

     }

    //Function for Memory Allocation

    struct node* memalloc()

    {
             New = (struct node *)malloc(sizeof(struct node));

            puts("\nEnter the task without spaces use \"_ or -\" in between words");

            scanf("%s",New->data);

            New->link = NULL;

    }

    //Function for Insert

    void insert()

    {

        New = memalloc();

        if (Head == NULL)

        {
            Head = New;
        }

        else

        {
                New->link = Head;
                Head = New;
        }

        printf("\nElement inserted");

    }



    //Function for Delete

    void delete()

    {

        int pos, count = 0, i;

        if (Head == NULL)

        {

            printf("List is empty");

        }

        else

        {

            printf("\nEnter the task position");

            scanf(" %d", &pos);

            Temp = Head;

            if (pos == 1)

            {

                if(Head == NULL)

                    puts("\nList is Empty");

                else

                {

                    Temp = Head;
                    Head = Head->link;
                    free(Temp);

                }

            }

            else

            {

                do
                {

                    Temp = Temp->link;

                    count++;

                }while (Temp != NULL);


                if (pos > 0 && pos <= count)

                {

                    Temp = Head;

                    for (i = 1;i < pos;i++)

                    {

                        Prev = Temp;

                        Temp = Temp->link;

                    }

                    Prev->link = Temp->link;

                }

                else

                {

                    printf("Position is out of range");

                }

            free(Temp);

            printf("\ntask is checked");

            }

        }

    }



    void display()

    {
        int i=0;

        if (Head == NULL)

        {

            printf("\nEMPTY LIST:");

        }

        else

        {
            Temp = Head;

            puts("\n");

            do

            {
                i++;
                printf("%d.%s\n", i, Temp->data);
                Temp = Temp->link;

            }while(Temp != NULL);


        }

    }

