#include <iostream>
#include <string>
#include "treeFunctions.cpp"

using namespace std;

int main()
{
    indexNode* root = NULL;
    string data;
    string type;
        
    cout << "Would you like to enter data (Y, N)?: ";
    cin >> data;
    
    //checks that DATA is valid
    while( data != "yes" && data != "y" && data != "Y" && data != "YES" && data != "Yes" && data != "no" && data != "n" && data != "N" && data != "No" && data != "NO" )
    {
        cout << "Invalid input. Enter either yes (Y) or no (N): ";
        cin >> data;
    }
    
    if( data == "yes" || data == "y" || data == "Y" || data == "YES" || data == "Yes" )
    {
        
        cout << "Will the data be numbers (N) or words (W)?: ";
        cin >> type;
        
        //checks that TYPE is valid
        while( type!= "n" && type!= "N" && type!= "numbers" && type!= "Numbers" && type!= "NUMBERS" && type!= "n" && type!= "w" && type!= "W" && type!= "words" && type!= "Words" && type!= "WORDS" )
        {
            cout << "Invalid input. Enter either (N) for numbers or (W) for words: ";
            cin >> type;
        }
        
        //Handles NUMBER type data
        if( type == "N" || type == "n" || type == "numbers" || type == "Numbers" || type == "NUMBERS" )
        {
            string ADD;
            type = "n";
            cout << "\n::Numbers::\n";
            int holder;
            cout << "Enter value: ";
            cin >> holder;
            root = create( holder );
            cout << "Add entry (Y, N)?: ";
            
            //checks that user wants to continue aadding data
            while(  cin >> ADD && ADD != "no" && ADD != "n" && ADD != "N" && ADD != "No" && ADD != "NO" )
            {
                while( ADD != "yes" && ADD != "y" && ADD != "Y" && ADD != "YES" && ADD != "Yes" && ADD != "no" && ADD != "n" && ADD != "N" && ADD != "No" && ADD != "NO" )
                {
                    cout << "Invalid input. Enter either yes (Y) or no (N): ";
                    cin >> ADD;
                }
                
                if( ADD == "yes" || ADD == "y" || ADD == "Y" || ADD == "YES" || ADD == "Yes" )
                {
                    cout << "Enter value: ";
                    cin >> holder;
                    build( root, holder );
                }
                
                cout << "\nAdd entry (Y, N)?: ";
            }

        }
        //handles WORD type data
        else if( type == "w" || type == "W" || type == "words" || type == "Words" || type == "WORDS" )
        {
            string ADD;
            type = "w";
            cout << "\n::Words::\n\n";
            string holder;
            cout << "Enter word: ";
            cin >> holder;
            
            //makes words all lowercase
            for( int x = 0; x < holder.length(); x++ )
            {
                holder[ x ] = tolower( holder[ x ] );
            }
            
            root = create( holder );
            cout << "Add entry (Y, N)?: ";
            
            //checks that user wants to continue adding data
            while(  cin >> ADD && ADD != "no" && ADD != "n" && ADD != "N" && ADD != "No" && ADD != "NO" )
            {
                while( ADD != "yes" && ADD != "y" && ADD != "Y" && ADD != "YES" && ADD != "Yes" && ADD != "no" && ADD != "n" && ADD != "N" && ADD != "No" && ADD != "NO" )
                {
                    cout << "Invalid input. Enter either yes (Y) or no (N): ";
                    cin >> ADD;
                }
                if( ADD == "yes" || ADD == "y" || ADD == "Y" || ADD == "YES" || ADD == "Yes" )
                {
                    cout << "Enter word: ";
                    cin >> holder;
                    build( root, holder );
                }
                cout << "\nAdd word (Y, N)?: ";
            }
        }
        
    }
    
    //handles circumstance of user not wanting to add any data
    else if( data == "n" || data == "N" || data == "no" || data == "No" || data == "NO")
    {
        cout << "Have a nice day.";
        return 0;
    }
    
    //asks user if they want to print
    printer( root, type );
    cout << "Have a nice day.";
    
    return 0;
}
