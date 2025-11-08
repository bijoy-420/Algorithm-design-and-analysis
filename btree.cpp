#include<bits/stdc++.h>
using namespace std;
class bitree
{
    public:
        int data;
        bitree*left;
        bitree*right;
        bitree(int val)
        {
            data=val;
            left=NULL;

            right=NULL;
        }
};
    //preorder
        void preorder(bitree* root)
        {
            if(root==NULL)
            {
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);

        }  
        //post order traversal'
        void postorder(bitree* root)
        {
            if(root==NULL)
            {
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        } 

        //inorder traverasal
        void inorder(bitree*root)
        {
            if(root==NULL)
            {
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }


int main()
    {
        bitree *root;
        root=new bitree(1);
        root->left=new bitree(2);
        root->right=new bitree(3);
        root->left->left=new bitree(4);
        root->left->right=new bitree(5);
        root->right->left=new bitree(6);
        root->right->right=new bitree(7);
        preorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;


    }
