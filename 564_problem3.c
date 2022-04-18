//problem 3 (Prolific potion)
//Name : ANAND SAGAR
//USN : 01fe20bcs327
//Roll : 564
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the structure for my prolific_potion

typedef struct prolific_potion
{
    char ingredient[30];
    int quantity;
    struct prolific_potion *prev;
    struct prolific_potion *next;
} prolific_potion;

//At first we will create a list of required items(global variable),with which are going to compare the items which we will insert
/*
30 cups of fluxweed
20 bundles of knotgrass
42 leeches
50 Lacewing flies
9 Bicorn horn
*/

typedef struct requiredItems
{
    char ingredient[30];
    int quantity;
} REQ_ITEMS;

REQ_ITEMS item_list[5];
int front = 0; //this will be used to delete the required items once we have inserted them in the potion brewer

void create_item_list()
{
    //this will create the required item list in the same order as mentioned in question
    strcpy(item_list[0].ingredient, "cups of fluxweed");
    item_list[0].quantity = 30;
    strcpy(item_list[1].ingredient, "bundles of knotgrass");
    item_list[1].quantity = 20;
    strcpy(item_list[2].ingredient, "leeches");
    item_list[2].quantity = 42;
    strcpy(item_list[3].ingredient, "Lacewing flies");
    item_list[3].quantity = 50;
    strcpy(item_list[4].ingredient, "Bicorn horn");
    item_list[4].quantity = 9;
}

int check_meets_requirement(prolific_potion *potion)
{
    //this function checks if the node to be inserted meets our requirement for the potion or not
    //if the required item has quantity less than the required then the item doesn't meet our requirement
    //and if the item is not found in the required item list then the element will be inserted in the end
    int flag_item_found = 0;
    int flag_item_quantity = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(item_list[i].ingredient, potion->ingredient) == 0)
        {
            flag_item_found = 1;
            if (potion->quantity >= item_list[i].quantity)
            {
                flag_item_quantity = 1;
            }
        }
    }
    if (flag_item_found == 1 && flag_item_quantity == 1)
        return 1;
    else if (flag_item_found == 0)
        return 1;
    else
        return 0;
}

prolific_potion *insert_at_end(prolific_potion *potion)
{
    //this function inserts the node at the end after all requirements are satisfied
    char ingredient[30];
    int quantity;
    printf("\nEnter the ingredient : ");
    fflush(stdin);
    gets(ingredient);
    fflush(stdin);
    printf("\nEnter the quantity of the ingredient : ");
    scanf("%d", &quantity);
    prolific_potion *temp = (prolific_potion *)malloc(sizeof(prolific_potion));
    strcpy(temp->ingredient, ingredient);
    temp->quantity = quantity;
    temp->prev = NULL;
    temp->next = NULL;
    if (potion == NULL)
    {
        if (check_meets_requirement(temp))
        {
            potion = temp;
            return potion;
        }
        else
        return NULL;
    }
    else
    {
        if (check_meets_requirement(temp))
        {
            prolific_potion *curr = potion;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
        }
    }
    return potion;
}

int check_all_items_gathered(prolific_potion *potion)
{
    //this function checks if all the items have been gathered or not
    if (potion == NULL)
        return 0;
    prolific_potion *curr = potion;
    int count = 0;
    while (curr != NULL)
    {
        char ingredient[30];
        int quantity;
        strcpy(ingredient, curr->ingredient);
        quantity = curr->quantity;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(ingredient, item_list[i].ingredient) == 0 && quantity >= item_list[i].quantity)
                count++;
        }
        curr = curr->next;
    }
    if (count >= 5)
        return 1;
    else
        return 0;
}
prolific_potion *brew_the_potion(prolific_potion *potion)
{
    //this function deletes/updated the node depending on the question demand
    //and also prints relevant information after each ITEMS are added in the brew pot
    printf("\n");
    while (front < 5)
    {
        //first we will take out each element from the queue and we will compare with each element of the DLL and do a/c to question
        char ingredient[30];
        strcpy(ingredient, item_list[front].ingredient);
        int quantity = item_list[front].quantity;
        if (strcmp(ingredient, potion->ingredient) == 0) //if the item to be updated/deleted is head node itself
        {
            printf("\nItem added for brewing : %s .", ingredient);
            printf("\nQuantity left : %d .", potion->quantity - quantity);
            if (quantity == potion->quantity && potion->next != NULL)
            {
                //in this case we will delete the node
                printf("(So the node was deleted.)\n");
                prolific_potion *temp = potion;
                potion = potion->next;
                potion->prev = NULL;
                free(temp);
                temp = NULL; //making the dangling pointer point to NULL
            }
            else if (quantity == potion->quantity && potion->next == NULL) //if there is only one node left
            {
                prolific_potion *temp = potion;
                potion = NULL;
                free(temp);
                temp = NULL; //handling the dangling pointer
                printf("(So the node was deleted.)");
            }
            else
            {
                potion->quantity = (potion->quantity) - quantity;
                printf("(So the node was updated.)\n");
            }
        }
        else
        {
            //if the node is not the front node then
            prolific_potion *current = potion;
            prolific_potion *previous = NULL;
            while (current != NULL)
            {
                if (strcmp(ingredient, current->ingredient) == 0)
                {
                    printf("\nItem added for brewing : %s .", ingredient);
                    printf("\nQuantity left : %d .", current->quantity - quantity);
                    if (quantity == current->quantity)
                    {
                        //in this case we will delete the node
                        printf("(So the node was deleted.)\n");
                        prolific_potion *temp = current;
                        if (current->next != NULL) //if the node is not the last node
                        {
                            previous->next = current->next;
                            current->next->prev = previous;
                            free(temp);
                            temp = NULL; //making dangling pointer point to NULL
                        }
                        else
                        {
                            previous->next = NULL;
                            free(current);
                            current = NULL;//fixing the dangling pointer to NULL
                            break; 
                        }
                    }
                    else
                    {
                        current->quantity = (current->quantity) - quantity;
                        printf("(So the node was updated.)\n");
                    }
                }
                previous = current;
                current = current->next;
            }
        }
        front = front + 1;
    }
    return potion;
}
int main()
{
    create_item_list(); //creating the required items list by calling the function
    prolific_potion *potion = NULL;
    while (1)
    {
        //this loops will keep accepting input until all the required items are gathered.
        if (check_all_items_gathered(potion))
            break;
        else
            potion = insert_at_end(potion);
    }
    potion = brew_the_potion(potion);
    printf("\nThe POTION is ready, The dark army can now be defeated again!\n");
}
