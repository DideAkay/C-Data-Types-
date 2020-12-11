#include "bst.h"


//allocates memory for the new node
BSTnode_t* createNode(int _code)
{
	BSTnode_t *temp = (BSTnode_t*)malloc(sizeof(BSTnode_t ));
	temp->code = _code;
	temp->left =NULL;
    temp->right = NULL;
    temp->parent = NULL;
    for (int i = 0; i < 20; i++)
            {
                temp->numbers[i] = 0;
            }
            
	return temp;
}

BSTnode_t* insertNode(int _code, BSTnode_t* _root){

    if (_root == NULL)
    {
        //bir leaf'e denk geldik, yeni node olusturup bu leaf'e eklenmesi icin adresini dondurur
        _root = createNode(_code); 
         return _root;  
    }
    
    int curCode = _root->code ;

    //parent adresi ekliyorum cünkü deleteNode'da leaf node lari silemedim
    if (_code < curCode ){
         BSTnode_t* left_child= insertNode(_code, _root->left); 
         _root->left = left_child;
         left_child->parent=_root;

    }

    else if (_code > curCode){
        BSTnode_t* right_child= insertNode(_code, _root->right);  
        _root->right =  right_child;
        right_child->parent=_root;
    } 
 
    return _root;
}

BSTnode_t* findMin(BSTnode_t* _node){
    if (_node->left == NULL)
    {
        //aradigimizi bulduk
         return _node;  
    }

    return findMin(_node->left);  
}

BSTnode_t* findMax(BSTnode_t* _node){
    if (_node->right == NULL)
    {
        //aradigimizi bulduk
         return _node;  
    }

    return findMax(_node->right);
}

BSTnode_t* findNode(int _code, BSTnode_t* _root){ 
    if (_root == NULL )
    {
       // printf("node not found\n"); 
        return NULL;
    }
    
    if (_root->code == _code)
    {
       // printf("node found: %d\n",_root->code ); 
        return _root;
    }

    if (_code > _root->code)
    {
        return findNode(_code,_root->right ); 
    }

    else if (_code < _root->code)
    {
        return findNode(_code,_root->left ); 
    }

}

BSTnode_t* deleteNode(int _code,BSTnode_t* _root){
    
    if (_root == NULL)
    {
        printf( "error tree empty \n");
        return NULL;
    }

    BSTnode_t* temp=  (findNode(_code,_root )); 

    if (temp)
    {
        if (temp->left==NULL && temp->right==NULL)
        {
        

            //we have to delete the pointer to the child             
            if (temp->parent->left && temp->parent->left->code == _code)
            {
                temp->parent->left=NULL;
            }
            if (temp->parent->right && temp->parent->right->code == _code)
            {
                temp->parent->right=NULL;
            }
            // printf( "deleted parents child ptr\n"); 
            temp=NULL;
            
            free(temp);
            return NULL;
            
        }
        
        else if (temp->left==NULL)
        {

            //replaces the smallest node of the right tree
            BSTnode_t* new_temp = findMin(temp->right);

            temp->code = new_temp->code; 
            for (int i = 0; i < 20; i++)
            {
                temp->numbers[i] = new_temp->numbers[i];
            }


            deleteNode(new_temp->code,temp->right);//prevents duplicate nodes          
            

            return temp; 
            
        }

        else if (temp->right==NULL)
        {
            //sag cocuk bos
            //promotes the left child of root eder
            BSTnode_t* new_temp = (temp->left);

            temp->code = new_temp->code; 
            temp->left = new_temp->left;
            temp->right = new_temp->right;
            for (int i = 0; i < 20; i++)
            {
                temp->numbers[i] = new_temp->numbers[i];
            }
            
            return temp; 
            
        }

        else
        {
            //If it has to child nodes 
            
            BSTnode_t* new_temp = findMin(temp->right);
             temp->code = new_temp->code; 
             for (int i = 0; i < 20; i++)
            {
                temp->numbers[i] = new_temp->numbers[i];
            }
            
            deleteNode(new_temp->code,temp->right);//prevents duplicate nodes  

  
             return temp; 

           
        }
        
    }

}

void inorder(BSTnode_t *root)
{
    if(root!=NULL)
    {
        inorder(root->left); 
        printf(" %d ", root->code); 
        inorder(root->right);
       
    }
}

void postorder(BSTnode_t *root)
{
    if(root!=NULL)
    {
        //once en asagiya leaf'e iner sonra yukari cikarak basar
        postorder(root->left); 
        
        postorder(root->right);
        printf(" %d ", root->code); 
       
    }
}

void preorder(BSTnode_t *root)
{
    if(root!=NULL)
    {
        printf(" %d ", root->code); //once parent sonra sol ve sag cocuklar
        preorder(root->left);         
        preorder(root->right);              
    }
}

int findDepth(BSTnode_t * node)  
{ 
   if (node==NULL)  
        return 0; 
   else 
   {
      //recursively calls itself untill node==null 
      
       int depth_left = findDepth(node->left); 
       int depth_right = findDepth(node->right); 
  
       // Returns the bigger value
       if (depth_left > depth_right)  
            return(depth_left+1); 
       else 
            return(depth_right+1); 
   } 
}

void printLevel(BSTnode_t* root, int level_counter )
{
    if (root == NULL)
        return;
    
    // when we have moved down to the level that will be printed :
    if (level_counter == 1)
        printf("%d ", root->code);

    // countdown recursively
    else if (level_counter > 1)
    {
        printLevel(root->left, level_counter-1);
        printLevel(root->right, level_counter-1);
    }
}

void levelOrder(BSTnode_t* root)
{
    if (root!=NULL )
    {   // prints the levels one by one

        for (int i=1; i<=findDepth(root); i++){ 
            printLevel(root, i);
        } 
    }
    
}
