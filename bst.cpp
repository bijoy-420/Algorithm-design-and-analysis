#include<bits/stdc++.h>
using namespace std;
class bst
{
    public:
        int data;
        bst*left;
        bst*right;
        bst(int val)
        {
            data=val;
            left=NULL;
            right=NULL;

        }
};
bst*insert(bst*root,int val)
{
    if(root==NULL)
    {
        return new bst(val);
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else
        root->right=insert(root->right,val);

    return root;
}
void inorder(bst*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//search in bst
void search(bst*root,int key)
{
    if(root==NULL)
    {

        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    if(root->data>key)
    {
        return search(root->left,key)
    }
    else
        return search(root->right,key);

    
}

int main()
{
    bst *root=NULL;
    root=insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,4);
    insert(root,2);
    insert(root,7);
    inorder(root);
    cout<<endl;
    if(search(root,10)==NULL)
    {
        cout<<"key doesn't exists";
    }
    else
        cout<<"key is exists";
    cout<<endl;
}