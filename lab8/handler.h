#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#define N 6
using namespace std;

int tag = 0;

class Handler {
    public:
        string name;
        string handlerName;

    public:
        Handler() {
            this->handlerName = to_string(tag);
            tag++;
        }
        Handler(string name) {
            this->handlerName = name;
        }
};

class ErrorHandler : public Handler {
    public: 
        ErrorHandler() : Handler() {}
        ErrorHandler(string name) : Handler(name) {}
    public:
        void create(){
            ifstream in("in.txt");
            srand(time(0));
            float error = static_cast <float> (rand() % (INT_MAX / 4)) / static_cast <float> (rand() % 10);
            float tmp = 0.0;
            string str;
            vector <float> num;

            if (in.is_open()){
                
                for (in >> str; !in.eof(); in >> str){
                    tmp = ::atof(str.c_str());
                    num.push_back(tmp);
                }
            }
            in.close();
            int pos = rand() % (num.size() - 0);
            cout << "Error create in " << pos << " position with : " << error << " value" << endl;
            ofstream out("out.txt");

            if (out.is_open()){
                
                for (int i = 0; i < num.size() + 1; i ++){
                    if (i == pos){
                        out << error << " ";
                    }else{
                        out << num[i] << " ";                    }
                }
            }else{
                cout << "Error with open file OUT" << endl;
            }
            out.close();
        }   
};

class AverageHandler : public Handler {
    public: 
        AverageHandler() : Handler() {}
        AverageHandler(string name) : Handler(name) {}
    public:
        void create(){
            ifstream in("in.txt");
            float tmp = 0.0;
            int i = 0;
            float answer = 0.0;
            string str;
            vector <float> num;
            
            if (in.is_open()){

                for (in >> str; !in.eof(); in >> str){
                    tmp = ::atof(str.c_str());
                    num.push_back(tmp);
                }

                in >> str;
                tmp = ::atof(str.c_str());
                num.push_back(tmp);

                for (int j = num.size() - 1; j > num.size() - N - 1; j--)
                    answer += num[j];
                answer = answer / N;
            }else{
                cout << "Error with open file IN" << endl;
            }
            in.close();

            cout << "Avarage value last " << N << " numbers : " << answer << endl; 
        }
};
