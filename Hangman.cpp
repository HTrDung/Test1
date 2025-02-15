#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<vector>
#include<fstream>

using namespace std;


vector<string> CreateWordList(string Dictionary);
void draw_hangman();
bool check_repeat(char c);
string generate_word();
void next_prompt();


vector<string> WordList = CreateWordList("WordList.txt");
int WordCount = WordList.size();
string answer, current;
char wrong[5]={0,0,0,0,0};
int n_wrong =0;


int main()
{
    srand(time(0));
    //Generate a random word
    answer = generate_word();
    int len = answer.size();

    //create a string with _ _ _ _ _
    current = answer;
    for (int i=0; i<len;i++)
        {current[i] ='_';}
    //Game
    char letter;
    while(true)
    {
        draw_hangman();
        //Check if over
        if(current.compare(answer) == 0)
        {
            cout << "You won \n" << "Answer: " << answer;
            break;
        }
        else if (n_wrong ==5)
        {
            cout << "You failed \n" <<"Answer: " << answer;
            break;
        }
        bool check = false;

        next_prompt();
        cin >> letter;

        for (int i=0; i<len; i++)
        {
            if(letter == answer[i])
            {
                current[i] = letter;
                check = true;
            }
        }

        if (check == false)
        {
            if(!check_repeat(letter))
            {
                wrong[n_wrong] = letter;
                n_wrong ++;
            }
        }
        cout << "\n";
    }
}
void draw_hangman()
{
    string hangman[] =
    {

        "_____  \n"
        "|      \n"
        "|      \n"
        "|       \n"
        "|       \n",

        "_____  \n"
        "|   |  \n"
        "|      \n"
        "|       \n"
        "|       \n",

        "_____  \n"
        "|   | \n"
        "|   O \n"
        "|      \n"
        "|      \n",
        "_____  \n"
        "|   | \n"
        "|   O \n"
        "|   | \n"
        "|      \n",

        "_____  \n"
        "|   | \n"
        "|   O \n"
        "|  /|\\ \n"
        "|       \n",

        "_____  \n"
        "|   | \n"
        "|   O \n"
        "|  /|\\ \n"
        "|  / \\ \n"
    };

    cout << hangman[n_wrong] << endl;
    return;
}

bool check_repeat(char c)
{
    for (int i=0; i< n_wrong;i++)
    {
        if (c == wrong[i])
            return true;
    }
    return false;
}

string generate_word()
{
    int n_list = rand()%WordCount;
    return WordList[n_list];
}

void next_prompt()
{
    cout << "Current word: " << current <<"    " 
    //Wrong letters
            << "Wrong letters: ";
        for (int i=0;i<n_wrong; i++)
            cout << wrong[i]<<" ";
    //Prepare for input
        cout << "\nYour guess: ";
}

vector<string> CreateWordList(string Dictionary)
{
    ifstream words_file(Dictionary);
    vector<string> ListOfWords;
    string input_string;
    while(words_file >> input_string)
    {
        ListOfWords.push_back(input_string);
    }
    words_file.close();
    return ListOfWords;
}
