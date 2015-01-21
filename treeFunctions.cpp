#include <iostream>
#include <string>
#include "trees.h"

using namespace std;

void build( indexNode* local, int VALUE )//Builds for int data
{
    //cout << "local: " << local -> value << "\n";//gives present location in tree
    while( local != NULL )
    {
        //INSERTS LEFT leaves
        if( VALUE < local -> value )
        {
            if( local -> left == NULL )
            {
                //cout << "inserting left ";//test line: tells what the builder is doing
                insert( local-> left, create( VALUE ) );
                //cout << local -> left -> value;//tells what is stored in the LEFT leaf
                return;
            }
            //calls BUILD again
            else if( local -> left != NULL )
            {
                //cout << "building left\n";//test line: tells what the builder is doing
                build( local-> left, VALUE );
                return;
            }
        }
        //INSERTS RIGHT leaves
        else if( VALUE > local -> value )
        {
            if( local -> right == NULL )
            {
                //cout << "\ninserting right ";//test line: tells what the builder is doing
                insert( local-> right, create( VALUE ) );
                //cout << local -> right -> value;//tells what is stored in the RIGHT leaf
                return;
            }
            //calls BUILD again
            else if( local -> right != NULL )
            {
                //cout << "building right\n";//test line: tells what the builder is doing
                build( local-> right, VALUE );
                return;
            }
        }
        //handles duplicate values
        else if( VALUE == local -> value )
        {
            local -> count+=1;
            return;
        }
    }
    
}

void build( indexNode* local, string WORD )//Builds for string data
{
    //cout << "local: " << local -> word << "\n";//test line. Gives present location in tree
    
    //makes words all lowercase
    for( int x = 0; x < WORD.length(); x++ )
    {
        WORD[ x ] = tolower(WORD[ x ]);
    }

    
    while( local != NULL )
    {
        //INSERTS LEFT leaves
        if( WORD < local -> word )
        {
            if( local -> left == NULL )
            {
                //cout << "inserting left ";//test line: tells what the builder is doing
                insert( local-> left, create( WORD ) );
                //cout << local -> left -> word;//tells what is stored in the LEFT leaf
                return;
            }
            //calls BUILD again
            else if( local -> left != NULL )
            {
                //cout << "building left\n";//test line: tells what the builder is doing
                build( local-> left, WORD );
                return;
            }
        }
        
        else if( WORD > local -> word )
        {
            //INSERTS RIGHT leaves
            if( local -> right == NULL )
            {
                //cout << "\ninserting right ";//test line: tells what the builder is doing
                insert( local-> right, create( WORD ) );
                //cout << local -> right -> word;//tells what is stored in the RIGHT leaf
                return;
            }
            //calls BUILD again
            else if( local -> right != NULL )
            {
                //cout << "building right\n";//test line: tells what the builder is doing
                build( local-> right, WORD );
                return;
            }
        }
        else if( WORD == local -> word )
        {
            local -> count+=1;
            return;
        }
    }
}
void printer( indexNode* root, string type )//asks user if they want to view data and then displays it in the chosen order
{
    string view;
    cout << "Would you like to view the data (Y, N)?: ";
    cin >> view;
    while( view == "yes" || view == "y" || view == "Y" || view == "YES" || view == "Yes" )
    {
        string query;
        string order;
        cout << "\nWhat order would you like the data displayed? \nIn, Pre, Post, or Level (enter one): ";
        cin >> order;
        
        //handles the different possible inputs for display type
        if( order == "in" || order == "In" || order == "IN" )
        {
            printInOrder(root, type);
            
        }
        else if( order == "pre" || order == "Pre" || order == "PRE" )
        {
            printPreOrder(root, type);
        }
        else if( order == "post" || order == "Post" || order == "POST" )
        {
            printPostOrder(root, type);
        }
        else if( order == "level" || order == "Level" || order == "LEVEL" )
        {
            printLevelOrder(root, type);
        }
        else if(  order != "in" && order != "In" && order != "IN" && order != "pre" && order != "Pre" && order != "PRE"  &&  order != "post" && order != "Post" && order != "POST"  &&  order != "level" && order != "Level" && order != "LEVEL" )
        {
            cout << order <<" is not a valid entry\n";
        }
        
        
        cout << "\nDisplay in another order (Y, N)?: ";
        cin >> query;
        if( query != "y" && query != "Y" && query != "yes" && query != "Yes" && query != "YES" )
        {
            view = "no";
        }
    }
}




