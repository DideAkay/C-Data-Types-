#include "bst.h"
#include<stdlib.h> 
#include<stdio.h>
#include <string.h>

void main(void){
    printf("test0\n");

    //initialize our trees
    BSTnode_t* root = NULL; //pointers are useful to know whether the tree is empty or not
    BSTnode_t* root2 = NULL;
    BSTnode_t* root3 = NULL;


    printf( "\n-------------------------ORDERING TESTS---------------------------\n");
    root2 = insertNode(50,root2); 
    insertNode(40,root2);
    insertNode(35,root2);
    insertNode(45,root2);
    insertNode(55,root2);

    printf("inorder:\n"); 
    inorder(root2);
    printf("\n"); 
    printf("preorder:\n"); 
    preorder(root2); 
    printf("\n"); 
    printf("postorder:\n"); 
    postorder(root2);
    printf("\n"); 
    printf("levelOrder:\n"); 
    levelOrder(root2);
    printf("\n"); 

    root = insertNode(54,root); 
    printf("added: %d\n",root->code); 
    insertNode(86,root); 
    printf("added: %d\n",root->right->code); 
    (insertNode(20,root)); 
    printf("added: %d\n",root->left->code); 
    insertNode(15,root);
    insertNode(14,root);
    insertNode(17,root);
    insertNode(16,root);
    insertNode(18,root);
    
    insertNode(23,root); 
    insertNode(26,root); 
    insertNode(24,root); 
    insertNode(29,root); 
    insertNode(27,root);


    printf( "\n-------------------------MAX/MIN/PARENT TESTS---------------------------\n");
    printf( "\n");
    inorder( root); 
    printf( "\n");
    printf("parent of %d: %d\n",23, findNode(23,root)->parent->code); //checked 
    
    printf("min:\n");
    printf("%d\n", (findMin(root))->code); //checked
    printf("max:\n");
    printf("%d\n", (findMax(root))->code); //checked 

    printf( "\n");
    inorder( root); 
    printf( "\n");
    


     printf( "\n-------------------------DELETE TESTS---------------------------\n");

     if (findNode(23,root))
    {
        
        deleteNode(23, root);  
        printf("deleting: %d\n",23);    
    } 

    findNode(23,root); //
    printf( "\n");
    inorder( root); 
    printf( "\n");

    if (findNode(86,root))
    {
        deleteNode(86, root);   
        printf("deleting: %d\n",86);   
    }

    findNode(86,root); //
    printf( "\n");
    inorder( root); 
    printf( "\n");

     
    if (findNode(29,root))
    {
        deleteNode(29, root);   
        printf("deleting: %d\n",29);   
    } 
    

    printf( "\n");
    inorder( root); 
    printf( "\n");

     if (findNode(20,root))
    {
        deleteNode(20, root);   
        printf("deleting: %d\n",20);   
    } 

    findNode(20,root); //
    printf( "\n");
    inorder( root); 
    printf( "\n");


   root3 = insertNode(50,root3); 

    printf( "\n-------------------------SWITCH CASE MENU ---------------------------\n");

    int j =1; 
    while (j)
    {

        printf("Press:\n0 for Exit \n1 for Find all the numbers in chosen country \n2 for Add a number \n" );
        scanf( "%d", &j);

        switch (j)
        {
        case 0:
        {
            printf( "bye...\n",j);
            break;
        }
        case 2:
        {
            int code;
            int number;
            printf("please enter country code\n" );
            scanf("%d", &code);

            printf("please enter number\n" );
            scanf("%d", &number);

            BSTnode_t* temp1 = findNode(code,root3); 

            if (!temp1){ 
                //if no node exists with that code, creates a new node
                
               insertNode(code ,root3);             

            }

            BSTnode_t* temp = findNode(code,root3); 

            if (temp)  
            {
                for (int i = 0; i < 20; i++)
                {
                    printf("for\n");
                    
                    if((temp->numbers[i]==0)){
                        //adds the phone number to the node with a relevant country code
                        temp->numbers[i]=number;
                        printf("inserted\n"); //CHECKED
                        break;
                       

                    }
                    
                }
            }
            
            printf( "%d\n",j);
            break;
        }
        case 1:
        {
            int code;
            printf("please enter country code\n" );
            scanf("%d", &code);
             BSTnode_t* temp = findNode(code,root3); 

            if (temp)  
            {
                printf("numbers in country %d:\n", code );
                for (int i = 0; i < 20; i++)
                {
                   // printf("for\n");
                    
                    if((temp->numbers[i]!=0)){
                        printf( "%lld\n",temp->numbers[i]);
                        
                    }
                    
                }
            }
            
            break;
        }

        default:
            break;
        }    
    }
    
}