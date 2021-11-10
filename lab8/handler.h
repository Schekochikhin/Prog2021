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
        vector <float> num;

    public:
        Handler() {
            this->handlerName = to_string(tag);
            tag++;
        }
        Handler(string name) {
            this->handlerName = name;
        }

    public:
        void push_back_vector(){
            float tmp = 0.0;
            ifstream in("in.txt");
            string str;

            if (in.is_open()){
                
                for (in >> str; !in.eof(); in >> str){
                    tmp = ::atof(str.c_str());
                    num.push_back(tmp);
                }
            }
            in.close();
        }
};

class ErrorHandler : public Handler {
    public: 
        ErrorHandler() : Handler() {}
        ErrorHandler(string name) : Handler(name) {}
    public:
        void create(){

            float error = static_cast <float> (rand() % (INT_MAX / 4)) / static_cast <float> (rand() % 10);
            srand(time(0));
            push_back_vector();

            int pos = rand() % (num.size() - 0);

            cout << "Error create in " << pos << " position with : " << error << " value" << endl;
            
            ofstream out("out.txt");

            if (out.is_open()){
                
                for (int i = 0; i < num.size(); i ++){
                    if (i == pos){
                        out << error << " ";
                    }else{
                        out << num[i] << " ";                    
                    }
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

            float answer = 0.0;

            push_back_vector();

            for (int i = num.size() - 1; i > num.size() - N - 1; i--)
                answer += num[i];
            answer = answer / N;

            cout << "Avarage value last " << N << " numbers : " << answer << endl; 
        }
};
