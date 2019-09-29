/*
 * main.cpp
 * SumSublist
 * Margaret Peterson
 * CS2C
 * Lab 01 Sum Sublist
 * 9/27/2019
 *
 */

/* ----------- PART A SOURCE ----------- */

#include <iostream>
#include <vector>
using namespace std;

class Sublist{

public:
   Sublist(vector<int> *orig = NULL)
      : sum(0), originalObjects (orig) { }
   Sublist addItem( int indexOfItemToAdd ) const;
   void showSublist() const;
   int getSum() const { return sum; }
   bool setIndices(vector<int>list);
   bool updateSum(int index);

private:
   int sum;
   vector<int> *originalObjects;
   vector<int> indices;

};

bool Sublist::updateSum(int index){

   if(index < 0 || index > originalObjects->size()-1 )
      return false;

   sum += (*originalObjects)[index];
   return true;

}

bool Sublist::setIndices(vector<int>list){

   if(list.size() > originalObjects->size())
      return false;

   indices = list;
   return true;
}

void Sublist::showSublist() const{

   cout<<"Sublist ---------------- "<<endl;
   cout<<"Sum: "<<sum<<endl;

   for(int i = 0; i < indices.size(); i++){
      cout<<"array["<<indices[i]<< "]"<<" = "<<(*originalObjects)[indices[i]]<<endl;
   }

}

Sublist Sublist::addItem(int index) const{

   Sublist newSub = *this; //deep copy

   vector<int> newIndices = indices;
   newIndices.push_back(index);
   newSub.setIndices(newIndices);
   newSub.updateSum(index);

   return newSub;
}

int main()
{
   int TARGET = 207;
   vector<int> dataSet;
   vector<Sublist> choices;
   vector<Sublist>::iterator iter, iterBest;
   int max;

   dataSet.push_back(20); dataSet.push_back(12); dataSet.push_back(22);
   dataSet.push_back(15); dataSet.push_back(25);
   dataSet.push_back(19); dataSet.push_back(29);
   dataSet.push_back(18);
   dataSet.push_back(11); dataSet.push_back(13); dataSet.push_back(17);

   choices.clear();
   cout << "Target time: " << TARGET << endl;

   choices.push_back(Sublist(&dataSet)); //initialize with empty sublist

   //create power set of dataSet, save in choices
   for(int i = 0; i < dataSet.size(); i++){

      long choicesSize = choices.size();

      for(int j = 0; j < choicesSize; j++){

         if (choices[j].getSum() + dataSet[i] < TARGET){
            choices.push_back(choices[j].addItem(i));
         }
         else if (choices[j].getSum() + dataSet[i] == TARGET){
            choices.push_back(choices[j].addItem(i));
            break;
         }
      }
   }

   //find largest sum out of choices
   max = choices[0].getSum();
   iterBest = choices.begin();

   for(iter = choices.begin(); iter != choices.end(); iter++){
      if((*iter).getSum() > max){
         iterBest = iter;
         max = (*iter).getSum();
      }
   }

   iterBest->showSublist();

   return 0;
}

/* ------------ SAMPLE RUNS ------------

 Target time: 1
 Sublist ----------------
 Sum: 0

 Target time: 67
 Sublist ----------------
 Sum: 67
 array[0] = 20
 array[2] = 22
 array[4] = 25

 Target time: 180
 Sublist ----------------
 Sum: 179
 array[0] = 20
 array[1] = 12
 array[3] = 15
 array[4] = 25
 array[5] = 19
 array[6] = 29
 array[7] = 18
 array[8] = 11
 array[9] = 13
 array[10] = 17

 Target time: 200
 Sublist ----------------
 Sum: 190
 array[0] = 20
 array[1] = 12
 array[2] = 22
 array[3] = 15
 array[4] = 25
 array[5] = 19
 array[6] = 29
 array[7] = 18
 array[9] = 13
 array[10] = 17

 Target time: 1000
 Sublist ----------------
 Sum: 201
 array[0] = 20
 array[1] = 12
 array[2] = 22
 array[3] = 15
 array[4] = 25
 array[5] = 19
 array[6] = 29
 array[7] = 18
 array[8] = 11
 array[9] = 13
 array[10] = 17

 Target time: 17
 Sublist ----------------
 Sum: 17
 array[10] = 17

 Target time: 150
 Sublist ----------------
 Sum: 150
 array[0] = 20
 array[1] = 12
 array[2] = 22
 array[4] = 25
 array[6] = 29
 array[7] = 18
 array[8] = 11
 array[9] = 13

 Target time: 207
 Sublist ----------------
 Sum: 201
 array[0] = 20
 array[1] = 12
 array[2] = 22
 array[3] = 15
 array[4] = 25
 array[5] = 19
 array[6] = 29
 array[7] = 18
 array[8] = 11
 array[9] = 13
 array[10] = 17

 ---------- END SAMPLE RUNS ----------- */











