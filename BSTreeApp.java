/*
  author:Devendra Patra
  resources used:1.www.geeksforgeeks.org
                 2.Tushar Roy(His youTube channel link:https://www.youtube.com/channel/UCZLJf_R2sWyUtXSKiKlyvAw)
                 
  functions used for BST:
            1.insert the node
            2.inorder  traversal
            3.preorder traversal
            4.postorder traversal
            5.size of bst
            6.inorder predecessor
            7.search in a binary search tree
            8.Height of a BST
  
*/

import java.util.Scanner;
import java.lang.Math;

class Node{
    int data;
    Node left,right;
    
    public Node(int x)
    {
        this.data = x;
        left=right=null;
    }
}

class BST
{
    Node root;
    public BST()
    {
        root = null;
    }
    
    Node insert(Node t,int y)
    {
        if(t==null)
        {
            t= new Node(y);
            return t;
        }   
        else
        {
            if(y>t.data)
                t.right = insert(t.right,y);
            else
                t.left = insert(t.left,y);
//debugging: 
// System.out.println("==================");
// System.out.println("this is :"+t.data);
// System.out.println("==================");
            return t;
        }
    }
    
    void inorder(Node t){   //here 't' is the root node.
          if(t!=null)
          {
              inorder(t.left);
              System.out.println(t.data);
              inorder(t.right);
          }
    }
    
    void preorder(Node t,int count){
        if(t!=null){
            System.out.println(t.data);
            preorder(t.left,count);
            preorder(t.right,count);
        }
    }
    
    void postorder(Node t,int count){
        if(t!=null){
            postorder(t.left,count);
            postorder(t.right,count);
            System.out.println(t.data);
        }
    }
    
    int size(Node node)
    {
        if(node == null)
            return 0;
        else
            return (size(node.left) + 1 + size(node.right));
    }
    
    //inorder predecessor
    void predecessor(int nodeData)
    {
        Node p = new Node (nodeData);
        if(p.left != null)
        {
            Node temp = p.left;
            
            while(temp.right !=null)
            {
                temp = temp.right;
            }
            System.out.println(temp.data);
        }
    }
    
    Node search(Node root,int key)
    {
        if(root == null)
            return null;
        if(root.data == key)
            return root;
        else if(root.data<key)
            return search(root.right,key);
        else
            return search(root.left,key);
    }
    
    int height(Node root)
    {
        if(root == null)
            return 0;
        else
        {
            return 1+ Math.max(height(root.left),height(root.right));
        }
    }

}


public class BSTreeApp {
    public static void main(String argsp[]){
        BST bst = new BST();
        Scanner sc= new Scanner(System.in);
        Node t = null;
        int choice,value,count=0;
       
        do
        {   
          System.out.println("=======================================");
            System.out.println("1.insert the node");
            System.out.println("2.inorder  traversal");
            System.out.println("3.preorder traversal");
            System.out.println("4.postorder traversal");
            System.out.println("5.size of bst");
            System.out.println("6.inorder predecessor");
            System.out.println("7.search in a binary search tree");
            System.out.println("8.Height of a BST");
            System.out.println("9.exit");
          System.out.println("=======================================");
            
            
            System.out.println("Enter your choice:\t");
             choice = sc.nextInt();
             
             switch(choice){
                 case 1:System.out.println("Enter the value:");
                        value = sc.nextInt();
                        t=bst.insert(t, value);
                        count++;
                        break;
                 case 2:{
                         bst.inorder(t);
                         break;
                        }
                 
                 case 3:{
                           bst.preorder(t, count);
                           break;
                        }
                 case 4:{
                            bst.postorder(t,count);
                            break;
                        }
                 
                 case 5:{
                            System.out.println(bst.size(t));
                            break;
                               
                        }
                 
                 case 6:{
                            System.out.println("Enter the number to be proceed for:");
                            int val = sc.nextInt();
                            bst.predecessor(val);
                            break;
                        }
                 
                 case 7:{
                            int key = sc.nextInt();
                            Node result = bst.search(t, key);
                            if(result!=null)                               
                                System.out.println(result.data);                          
                            else
                                System.out.println("Node not found!");
                            break;                       
                        }
                 
                 case 8:{
                            System.out.println("The height of Binary Tree is:"+bst.height(t));
                            break;
                        }
                 default:System.out.println("enter the correct option excluding '9'");
             }
        }
        while(choice!=9);
        
        sc.close();
                
    }
}
