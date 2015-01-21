#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <list>


using namespace std;

struct indexNode//prototype for nodes
{
    string word;
    int value;
    int count;
    
    indexNode *left;
    indexNode *right;
};

indexNode* create( int w )//create nodes with data
{
    indexNode* newNode;
    
    newNode = new indexNode;
    
    newNode -> value = w;
    
    newNode -> count = 1;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
};

indexNode* create( string w )//create nodes with strings
{
    indexNode* newNode;
    
    newNode = new indexNode;
    
    newNode -> word = w;
    
    newNode -> count = 1;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
};

void insert( indexNode *&old, indexNode *newer )//inserts nodes into tree
{
    old = newer;
};

void printInOrder( indexNode* top, string type )//prints In Order
{
    if ( type == "n" )
    {
        if ( top )
        {
            printInOrder( top -> left, type );
            
            cout << top -> value << " ";
            
            printInOrder( top -> right, type );
        }
    }
    else if ( type == "w" )
    {
        if ( top )
        {
            printInOrder( top -> left, type );
            
            cout << top -> word << " ";
            
            printInOrder( top -> right, type );
        }
    }
};

void printPostOrder( indexNode* top, string type )//prints Post Order
{
    if ( type == "n" )
    {
        if ( top )
        {
            printPostOrder( top -> left, type );
            
            printPostOrder( top -> right, type );
            
            cout << top -> value << " ";
        }
    }
    else if ( type == "w" )
    {
        if ( top )
        {
            printPostOrder( top -> left, type );
            
            printPostOrder( top -> right, type );
            
            cout << top -> word << " ";
        }
    }

}

void printPreOrder( indexNode* top, string type )//prints Pre Order
{
    if ( type == "n" )
    {
        if ( top )
        {
            cout << top -> value << " ";
            
            printPreOrder( top -> left, type );
            
            printPreOrder( top -> right, type );
        }
    }
    else if ( type == "w" )
    {
        if ( top )
        {
            cout << top -> word << " ";
            
            printPreOrder( top -> left, type );
            
            printPreOrder( top -> right, type );
        }
    }
}

void printLevelOrder( indexNode* top, string type )//prints Level Order
{
    if( type == "n" )
    {
        queue<indexNode*> hold;
        if ( top )
        {
            hold.push( top );
        }
        while ( !hold.empty() )
        {
            indexNode* temp = hold.front();
            hold.pop();
            
            cout << temp -> value << " ";
            
            if ( temp -> left )
            {
                hold.push( temp -> left );
            }
            if ( temp -> right )
            {
                hold.push( temp -> right );
            }
        }
    }
    else if( type == "w" )
    {
        queue<indexNode*> hold;
        if ( top )
        {
            hold.push( top );
        }
        while ( !hold.empty() )
        {
            indexNode* temp = hold.front();
            hold.pop();
            
            cout << temp -> word << " ";
            
            if ( temp -> left )
            {
                hold.push( temp -> left );
            }
            if ( temp -> right )
            {
                hold.push( temp -> right );
            }
        }
    }

}










