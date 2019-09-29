//
//  main.cpp
//  SumSublist
//
//  Created by Margaret Peterson on 9/26/19.
//  Copyright © 2019 Margaret Peterson. All rights reserved.
//

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

//prob did this wrong but errkay
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
   int TARGET = 180;
   vector<int> dataSet;
   vector<Sublist> choices; //COL?
   vector<Sublist>::iterator iter, iterBest, iterEnd;
   int k, j, numSets, max, masterSum;
   bool foundPerfect;

   dataSet.push_back(20); dataSet.push_back(12); dataSet.push_back(22);
   dataSet.push_back(15); dataSet.push_back(25);
   dataSet.push_back(19); dataSet.push_back(29);
   dataSet.push_back(18);
   dataSet.push_back(11); dataSet.push_back(13); dataSet.push_back(17);

   choices.clear();
   cout << "Target time: " << TARGET << endl;

   // code provided by student
   choices.push_back(Sublist(&dataSet)); //initialize with empty sublist

   for(int i = 0; i < dataSet.size(); i++){
       //how do i find elements of col?
      int choicesSize = choices.size();

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

   //find largest sum
   max = choices[0].getSum();
   for(iter = choices.begin(); iter != choices.end(); iter++){
      if((*iter).getSum() > max){
         iterBest = iter;
         max = (*iter).getSum();
      }
   }


   iterBest->showSublist();

   return 0;
}
