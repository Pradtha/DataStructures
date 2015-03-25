#include<iostream>
#include<conio.h>

using namespace std;

class treenode
{  public:
      int d;
      treenode *lt, *rt;
      treenode()
      {  d=0;
         lt = rt = NULL;
      }
};

class treehead
{  public:
      int count;
      treenode *root;
      treehead()
      {  count = 0;
         root = NULL;
      }
}th;

void memchk(treenode *node)
{  if(!node)
   {  cout<<"\n Memory not available!!";
      getch();
   }
}

void preorder(treenode *root)
{  if(root)
   {  cout<<root->d<<" ";
      preorder(root->lt);
      preorder(root->rt);
   }
}

void inorder(treenode *root)
{  if(root)
   {  inorder(root->lt);
      cout<<root->d<<" ";
      inorder(root->rt);
   }
}

void postorder(treenode *root)
{  if(root)
   {  inorder(root->lt);
      inorder(root->rt);
      cout<<root->d<<" ";
   }
}

bool searchBST(treenode *root, int item)
{  if(root == NULL)
      return false;
   if(item < root->d)
      return searchBST(root->lt,item);
   else if(item > root->d)
      return searchBST(root->rt,item);
   else
      return true;
}

treenode* largestBST(treenode* root)
{  return (root->rt==NULL)?root:largestBST(root->rt);
}

treenode* insertBST(treenode *&root, treenode *&node)
{  if(!root)
   { treenode *temp = node;
     return temp;
   }
   if(node->d <= root->d)
      root->lt = insertBST(root->lt,node);
   else
      root->rt = insertBST(root->rt,node);
   return root;
}

void addBST(int16_t item)
{  treenode *node = new treenode();
   memchk(node);

   node->d = item;

   if(th.count == 0)
      th.root = node;
   else
      insertBST(th.root,node);

   ++th.count;
   cout<<"\n Node inserted!";
}


treenode* deleteBST(treenode* root, int item)
{  if(item < root->d)
      root->lt = deleteBST(root->lt, item);
   else if(item > root->d)
      root->rt = deleteBST(root->rt, item);
   else
   {  treenode* deletenode = root;

      if(deletenode->lt == NULL)
      {  treenode* temp = deletenode->rt;
         cout<<"\n"<<deletenode->d;
         delete deletenode;
         return temp;
      }

      else if(deletenode->rt == NULL)
      {  treenode* temp = deletenode->lt;
         cout<<"\n"<<deletenode->d;
         delete deletenode;
         return temp;
      }

      else
      {  treenode* largestnode = deletenode->lt;
         while(largestnode->rt)
            largestnode = largestnode->rt;

         int temp;
         temp = deletenode->d;
         deletenode->d = largestnode->d;
         largestnode->d = temp;

         root->lt = deleteBST (root->lt,t
                               -emp);
      }
   }
   return root;
}

void removeBST(int16_t item)
{  if(searchBST(th.root,item))
   {  th.root = deleteBST(th.root,item);
      --th.count;

      cout<<"\n Item Deleted!";

      if(th.count==0)
         cout<<"\n No more deletion possible";
   }
   else
      cout<<"\n Item not found!";
}

int height(treenode *root)
{
    int l,r;
    if(root == NULL)
        return 0;
    l = height(root->lt);
    r = height(root->rt);

    return ((l>r)?l+1:r+1);
}

int diameterBST(treenode *root)
{
    return (height(root->lt) + height(root->rt) + 1);
}

int numberofleaves(treenode *root)
{   if(root->lt==NULL && root->rt==NULL)
        return 1;
    else if(root->rt == NULL && root->lt != NULL)
        return numberofleaves(root->lt);
    else if(root->lt == NULL && root->rt != NULL)
        return numberofleaves(root->rt);
    else
        return numberofleaves(root->lt) +numberofleaves(root->rt);
}

int main()
{  int c = 8;
   while(c)
   {  system("cls");
      cout<<"\n \t\t\t BST operations"
            "\n 1.Insert"
			"\n 2.Delete"
			"\n 3.Traverse"
			"\n 4.Search"
			"\n 5.Largest"
			"\n 6.Diameter"
			"\n 7.Height"
			"\n 8.Number of Leaves"
			"\n 0.Exit.";
      cout<<"\n Enter your choice: ";
      cin>>c;

      switch(c)
	  {  case 1:
            int16_t item;
            cout<<"\n Enter the item to be added: ";
            cin>>item;
            addBST(item);
            getch();
         break;

         case 2:
            cout<<"\n Enter the key to be deleted: ";
            cin>>item;
		    removeBST(item);
		    getch();
         break;

         case 3:
         {   cout<<"\n 1. Inorder"
                   "\n 2. Preorder"
                   "\n 3. Postorder";
             cout<<"\n Enter your choice: ";
             cin>>c;

             switch(c)
             {  case 1:
                   inorder(th.root);
                   getch();
                break;

                case 2:
                   preorder(th.root);
                   getch();
                break;

                case 3:
                   postorder(th.root);
                   getch();
                break;

                default:
                   cout<<"\n invalid choice!!!";
                   c = 8;
             }
         }
         break;

         case 4:
         {
             cout<<"\n Enter the item to be searched: ";
             int16_t item;
             cin>>item;
             if(searchBST(th.root,item))
                 cout<<"\n item Found!!";
             else
                 cout<<"\n Item not found!!";
             getch();
         }
         break;

         case 5:
         {
             treenode *temp = largestBST(th.root);
             cout<<"\n The largets node: "<<temp->d;
             getch();
         }
         break;

         case 6:
            cout<<"\n The diameter of the BST is: "<<diameterBST(th.root);
            getch();
         break;

         case 7:
            cout<<"\n The height of the BST is: "<<height(th.root);
            getch();
         break;

         case 8:
            cout<<"\n The number of leaves in the BST is: "<<numberofleaves(th.root);
            getch();
         break;

         case 0:
         {  while(th.root)
                removeBST(th.root->d);
            cout<<"\n Program terminating!";
            getch();
            exit(0);
         }

         default:
         {  cout<<"\n Invalid choice!";
            getch();
         }
      }
   }
   return 0;
}

