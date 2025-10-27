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
                int pos = index;
               
                    bool shouldInsert = false;
                    int insertPos = index;

                    for (int i = 0; i < index; i++) {
                        if (entry->score > array[i].score) {
                            insertPos = i;
                            shouldInsert = true;
                            break;
                        }
                    }

                    if (index < SIZE) {
                        if (!shouldInsert) {
                            insertPos = index; 
                        }

                        for (int i = index; i > insertPos; i--) {
                            array[i] = array[i - 1];
                        }

                        array[insertPos] = *entry;
                        index++;
                        return;
                    }
                    
                    if (entry->score > array[SIZE - 1].score) {
                        for (int i = SIZE - 1; i > insertPos; i--) {
                            array[i] = array[i - 1];
                        }
                        array[insertPos] = *entry;
                    } else {
                        cout << entry->name << "'s score is too low to be added!" << endl;
                    }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};