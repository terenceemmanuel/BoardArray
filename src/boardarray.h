#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            for (int i = 0; i < index; i++){
                Entry existing= array[i];
                bool compare(existing.compare(entry));
                
                    if(existing.compare(entry)== true){
                        for (int j = 0; j < index; j++){
                            array[i+1]= array[i];
                        }
                    }
            
               
            }
            return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};