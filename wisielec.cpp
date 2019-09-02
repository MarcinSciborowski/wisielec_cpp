#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;
class Hangman
{
    private:
        string name;
        int point = 0;

    public:
        Hangman(string n){set_name(n);};
        Hangman(const Hangman &obj){};
        ~Hangman(){};

        void set_name(string n)
        {
            name = n;
        }

        string get_name()
        {
            return name;
        }

        void set_point(int x)
        {
            point += x;
        }

        int get_point()
        {
            return point;
        }

        int random_number()
        {
            srand(time(NULL));
            int rand_num = (rand()%5637)+7;
            return rand_num;
        }

        double random_double()
        {
            double x=((double)rand()/(double)RAND_MAX);
            return x*100;
        }

        string random_word(int random_num)
        {
            string line,sentence;
            string wor = "";
            int sp=0;
            int counter = 0;

            ifstream myfile ("words.txt");

            if (myfile.is_open())
            {
                while ( getline (myfile,line) )
                {
                    sentence += line;
                }
                myfile.close();
                for (int i=0; i<sentence.length(); i++)
                {
                    if (int(sentence[i]) == 32)
                    {
                        sp++;
                    }
                }

                string *lista = new string[sp];
                for(int i = 0; i<sentence.length(); i++)
                {
                    if (int(sentence[i]) == 32)
                    {
                        lista[counter] = wor;
                        counter++;
                        wor = "";
                    }
                    else
                    {
                        wor += sentence[i];
                    }
                }
                return lista[random_num];
            }
        else cout << "Unable to open file";
        }

        string hide_word(int random_num)
        {
            string str = random_word(random_num);
            string res = "";
            for(int i=0; i<str.length(); i++)
            {
                res += "?";
            }
            return res;
        }

        string all_words()
        {
            string line,sentence;
            string wor = "";
            int sp=0;
            int counter = 0;

            ifstream myfile ("words.txt");

            if (myfile.is_open())
            {
                while ( getline (myfile,line) )
                {
                    sentence += line;
                }
                myfile.close();
            }
            else cout << "Unable to open file";
            return sentence;
        }

        double num_letter()
        {
            double coun = 0.0;
            string sentence = all_words();
            for (int j=0; j<sentence.length(); j++)
            {
                if (int(sentence[j])>=65 && int(sentence[j])<=90)
                {
                    coun++;
                }
            }
            return coun;
        }

        vector<int> count_letter()
        {
            string sentence = all_words();
            //string sentence = "ALA MA KOTA";
            int ascii = 0;
            vector<int> count_list;
            int *lista = new int[26];

            for (int i=0; i<26; i++)
            {
                lista[i] = 0;
            }

            for (int j=0; j<sentence.length(); j++)
            {
                ascii = int(sentence[j]);
                if (ascii>=65 && ascii<=90)
                {
                    lista[ascii-65]+=1;
                }
            }

            for (int k=0; k<26; k++)
            {
                count_list.push_back(lista[k]);
            }
            return count_list;
        }

        vector<double> perc_count_letter(int x, vector<int> ccl, double num_letter)
        {
            //vector<int> copy_count_list = copy_count_letter();
            vector<double> perc_count;
            double count_l = num_letter;
            //cout<<count_l<<endl;
            //cout<<(float(copy_count_list[0])/count_l)<<endl;
            for(int i=0; i<ccl.size(); i++)
            {
                if ( i==0 )
                {
                    perc_count.push_back((double(ccl[i])/count_l)*100);
                }
                else
                {
                    perc_count.push_back((double(ccl[i])/count_l)*100+perc_count[i-1]);
                }
            }
            return perc_count;
        }

        string letters()
        {
            string let = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            return let;
        }

        /*void per_list()
        {
            int *lista = new int[26];
            for(int i=0; i<26; i++)
            {
                lista[i] = count_letter(i);

            }
            for (int k=0; k<26; k++)
            {
                seqs.push_back(lista[k]);
            }
        }*/

        bool cheak_repeat(string used_str,char chara)
        {
            for(int j=0; j<used_str.length(); j++)
                {
                    if(chara == used_str[j])
                    {
                        cout<<"This character was use!"<<endl;
                        return 0;
                    }
                }
            return 1;
        }

        char upper_case(char chara)
        {
            int char_int = 0;
            char res;
            char_int = int(chara);
            char_int = char_int-32;
            res = char(char_int);
            return res;
        }

        bool cheak_symbol(char chara)
        {
            int el = 0;
            el = int(chara);
            if(el>=65 && el<=90 || el>=97 && el<=122)
            {
                return 1;
            }
            else
            {
                cout<<"This symbol is't a letter"<<endl;
                return 0;
            }
        }

        void hang_10()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |    /|\\ "<<endl;
            cout<<"  |    / \\ "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_9()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |    /|\\ "<<endl;
            cout<<"  |    /    "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_8()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |    /|\\ "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_7()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |    /|   "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_6()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_5()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |     O   "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_4()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |     |   "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_3()
        {
            cout<<"   _____    "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_2()
        {
            cout<<"            "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"  |         "<<endl;
            cout<<"------      "<<endl;
        }

        void hang_1()
        {
            cout<<"            "<<endl;
            cout<<"            "<<endl;
            cout<<"            "<<endl;
            cout<<"            "<<endl;
            cout<<"            "<<endl;
            cout<<"            "<<endl;
            cout<<"------      "<<endl;
        }

        void draw_hangman(int chance)
        {
                if (chance == 9)
                {
                    hang_1();
                }
                if (chance == 8)
                {
                    hang_2();
                }
                if (chance == 7)
                {
                    hang_3();
                }
                if (chance == 6)
                {
                    hang_4();
                }
                if (chance == 5)
                {
                    hang_5();
                }
                if (chance == 4)
                {
                    hang_6();
                }
                if (chance == 3)
                {
                    hang_7();
                }
                if (chance == 2)
                {
                    hang_8();
                }
                if (chance == 1)
                {
                    hang_9();
                }
        }

        void play()
        {
            int chance = 10;
            int check = 0;
            int temp = 0;
            int ran_num = random_number();
            char chara;

            string str = random_word(ran_num);
            string h_word = hide_word(ran_num);
            string used_str = "";
        //    cout<<str<<endl;

            cout<<"Your turn - " << get_name()<<"!"<<endl;
            cout<<"This word has "<<str.length()<<" letters."<<endl;
            cout<<"\n";

            while(1)
            {
                cout << "Please write a letter: ";
                cin >> chara;
                if (cheak_symbol(chara)==1)
                {
                    chara = upper_case(chara);
         //         cout << "Bool: "<<cheak_repeat(used_str,chara)<<endl;
         //         cout << used_str <<endl;

                    temp = check;

                    if (cheak_repeat(used_str,chara)==1)
                    {
                        for(int i=0; i<str.length(); i++)
                        {
                            if (chara == str[i])
                            {
                                h_word[i]=chara;
                                check++;
                            }
                        }

                        if (check>temp)
                        {
                            used_str += chara;
                        }

                        if (check==temp)
                        {
                            used_str += chara;
                            chance--;
                        }
                    }

                    if (chance==0)
                    {
                        hang_10();
                        cout<<"You lose! The word was: " << str << endl;
                        set_point(check);
                        break;
                    }

                    if(str.length()==check)
                    {
                        cout<<"Congratulations! You guessed a word!"<<endl;
                        set_point(check*10);
                        break;
                    }
                }
                cout<<"You have "<<chance<<" chance."<<endl;
                draw_hangman(chance);
                cout<<"Used letters: "<<used_str<<endl;
                cout<<h_word<<endl;
                cout<<"\n";
            }
        }

        void play_pc()
        {
            int chance = 10;
            int check = 0;
            int temp = 0;
            int ran_nun = random_number();
            int j = 0;

            string str = random_word(ran_nun);
            string h_word = hide_word(ran_nun);
            string used_str = "";
            char a;
            char chara[27] = "aeoiznsrwctlykdpmujbghfqxv";
        //    cout<<str<<endl;

            cout<<"Your turn - " << get_name()<<"!"<<endl;
            cout<<"This word has "<<str.length()<<" letters."<<endl;
            cout<<"\n";

            while(1)
            {
                cout << "Please write a letter: " << endl;
                Sleep(2000);
                cout<<chara[j]<<endl;
                //cin>>a;

                if (cheak_symbol(chara[j])==1)
                {
                    chara[j] = upper_case(chara[j]);
         //         cout << "Bool: "<<cheak_repeat(used_str,chara)<<endl;
         //         cout << used_str <<endl;

                    temp = check;

                    if (cheak_repeat(used_str,chara[j])==1)
                    {
                        for(int i=0; i<str.length(); i++)
                        {
                            if (chara[j] == str[i])
                            {
                                h_word[i]=chara[j];
                                check++;
                            }
                        }

                        if (check>temp)
                        {
                            used_str += chara[j];
                        }

                        if (check==temp)
                        {
                            used_str += chara[j];
                            chance--;
                        }
                    }

                    if (chance==0)
                    {
                        hang_10();
                        cout<<"You lose! The word was: " << str << endl;
                        set_point(check);
                        break;
                    }

                    if(str.length()==check)
                    {
                        cout<<"Congratulations! You guessed a word!"<<endl;
                        set_point(check*10);
                        break;
                    }
                }
                cout<<"You have "<<chance<<" chance."<<endl;
                draw_hangman(chance);
                cout<<"Used letters: "<<used_str<<endl;
                cout<<h_word<<endl;
                cout<<"\n";
                j++;
            }
        }

        void play_pc_2()
        {
            vector<int> cl = count_letter();

            string let = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            double nl = num_letter();
            //cout<<"poczatkowa liczba liter: "<<nl<<endl;
            int round = 0;
            int chance = 10;
            int check = 0;
            int temp = 0;
            int j = 0;
            int x = 0; //number of remove letter
            int start_l = 0;
            int ran_nun = random_number();
            int flag = 0;
            int index = 0;
            vector<double> pcl = perc_count_letter(x, cl, nl);
            int end_l=pcl[j];
            string a;
            string str = random_word(ran_nun);
            string h_word = hide_word(ran_nun);
            string used_str = "";
        //    cout<<str<<endl;

            cout<<"Your turn - " << get_name()<<"!"<<endl;
            cout<<"This word has "<<str.length()<<" letters."<<endl;
            cout<<"\n";

            while(1)
            {
                /*cout<<"Statystyki liter:"<<endl;
                for (int i=0; i<26 - round; i++)
                {
                    cout<<let[i]<< " - " << pcl[i]<<endl;
                }

                cout<<"Liczba liter:"<<endl;
                for (int i=0; i<26 - round; i++)
                {
                    cout<<let[i]<< " - " << cl[i]<<endl;
                }*/

                cout << "Please write a letter: " << endl;
                Sleep(2000);
                double ran_num_dou = random_double();
                //cout<<"wylosowany procent: "<<endl;
                //cout<<ran_num_dou<<endl;

                while(flag == 0)
                {
                   if (start_l <= ran_num_dou && end_l >= ran_num_dou)
                   {
                       if (start_l==0)
                       {
                           index = 0;
                           flag = 1;
                       }
                       else
                       {
                           index = j-1;
                           //cout<<index<<endl;
                           flag = 1;
                           //cout<<"ta: "<< let[index]<<endl;
                       }
                   }
                   else
                   {
                       start_l = end_l;
                       j++;
                       end_l = pcl[j];
                   }
                }

                if (cheak_symbol(let[index])==1)
                {
                    temp = check;
                    if (cheak_repeat(used_str,let[index])==1)
                    {
                        for(int i=0; i<str.length(); i++)
                        {
                            if (let[index] == str[i])
                            {
                                h_word[i]=let[index];
                                check++;
                            }
                        }

                        if (check>temp)
                        {
                            used_str += let[index];
                        }

                        if (check==temp)
                        {
                            used_str += let[index];
                            chance--;
                        }
                    }

                    cout<<let[index]<<endl;
                    if (chance==0)
                    {
                        hang_10();
                        cout<<"You lose! The word was: " << str << endl;
                        set_point(check);
                        break;
                    }

                    if(str.length()==check)
                    {
                        cout<<"Congratulations! You guessed a word!"<<endl;
                        set_point(check*10);
                        break;
                    }
                }

                cout<<"You have "<<chance<<" chance."<<endl;
                draw_hangman(chance);
                cout<<"Used letters: "<<used_str<<endl;
                cout<<h_word<<endl;
                cout<<"\n";
                x = cl[index];
                //cout<<"x -zrobione"<<endl;
                cl.erase(cl.begin() + index);
                //cout<<"usuniecie zrobione"<<endl;
                let.erase(let.begin()+index);
                //cout<<let.length();
                /*for (int j = 0; j<let.length();j++)
                {
                    cout<<"l: "<<let[j]<<endl;
                }*/
                //cout<<"usuniecie strnga"<<endl;
                pcl.clear();
                //cout<<"rozmiar vec: " << pcl.size()<<endl;
                //cout<<"wyczyszczenie wektora"<<endl;
                nl = nl-x;
                //cout<<"Wysapienia: "<< x<<endl;
                //cout<<"liczba liter "<<nl<<endl;
                pcl = perc_count_letter(x,cl,nl);
                //cout<<"nowy wektor"<<endl;
                j=0;
                start_l = 0;
                end_l = pcl[j];
                flag = 0;
                round--;
                //cin>>a;
            }
        }
};

int main()
{
	int mode = 0;
	cout<<"Welcome in the Hangman game"<<endl;
	cout<<"Choose game mode: "<<endl;
	cout<<"1 - One player"<<endl;
	cout<<"2 - PC vs. player"<<endl;
	cout<<"3 - player1 vs. player2"<<endl;
	cout<<"4 - PC_1 vs. PC_2"<<endl;
	cin>>mode;

	if (mode == 1)
    {
        string name;
        cout<<"What's your name?"<<endl;
        cin>>name;
        Hangman h1(name);
        h1.play();
    }

    if (mode == 2)
    {
        int x = 0;
        string name;
        cout<<"What's your name?"<<endl;
        cin>>name;
        Hangman h1(name);
        Hangman h2("PC");
        cout<<"Set the number of games: ";
        cin>>x;
        for (int i=0; i<x; i++)
        {
            h1.play();
            cout<<"\n";
            h2.play_pc();
        }
        cout<<"\n";
        cout<<"Result: "<<h1.get_point()<<":"<<h2.get_point()<<endl;
        if (h1.get_point()>h2.get_point())
        {
            cout<<h1.get_name()<<" - You are the winner!" << endl;
        }
        if (h1.get_point()==h2.get_point())
        {
            cout<<"Draw"<<endl;
        }
        if (h1.get_point()<h2.get_point())
        {
            cout<<h2.get_name()<<" - You are the winner!" << endl;
        }
    }

	if (mode == 3)
	{
	    int x = 0;
	    string name1,name2;
	    cout<<"Player 1 - What's your name?"<<endl;
	    cin>>name1;
	    cout<<"Player 2 - What's your name?"<<endl;
	    cin>>name2;
        Hangman h1(name1);
        Hangman h2(name2);
        cout<<"Set the number of games: ";
        cin>>x;
        for (int i=0; i<x; i++)
        {
            h1.play();
            cout<<"\n";
            h2.play();
        }
        cout<<"\n";
        cout<<"Result: "<<h1.get_point()<<":"<<h2.get_point()<<endl;
        if (h1.get_point()>h2.get_point())
        {
            cout<<h1.get_name()<<" - You are the winner!" << endl;
        }
        if (h1.get_point()==h2.get_point())
        {
            cout<<"Draw"<<endl;
        }
        if (h1.get_point()<h2.get_point())
        {
            cout<<h2.get_name()<<" - You are the winner!" << endl;
        }
	}

	if (mode == 4)
    {
        int x = 0;
        Hangman h1("PC1");
        Hangman h2("PC2");
        cout<<"Set the number of games: ";
        cin>>x;
        for (int i=0; i<x; i++)
        {
            h1.play_pc();
            cout<<"\n";
            h2.play_pc_2();
        }
        cout<<"\n";
        cout<<"Result: "<<h1.get_point()<<":"<<h2.get_point()<<endl;
        if (h1.get_point()>h2.get_point())
        {
            cout<<h1.get_name()<<" - You are the winner!" << endl;
        }
        if (h1.get_point()==h2.get_point())
        {
            cout<<"Draw"<<endl;
        }
        if (h1.get_point()<h2.get_point())
        {
            cout<<h2.get_name()<<" - You are the winner!" << endl;
        }
    }
	return 0;
}
