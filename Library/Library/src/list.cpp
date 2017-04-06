#include <iostream>
#include "tlist.h"

using namespace std;

int main(int argc, char *argv[])
{
    int i, x;
    TList<int> L;

    for (i = 0; i < 10; ++i)
    {
        x = i*i;
        L.push_front(x); // mit Quadratzahlen füllen
    }

    TList<int>::Iterator ListIter(L);

    cout << "*ListIter = " << *ListIter << endl;
    cout << "ListIter++;" << endl;
    ListIter++;
    cout << "*ListIter = " << *ListIter << endl;

   // 36 löschen, falls vorhanden
   while(ListIter++ != L.end())
      if (*ListIter == 36)
      {
         cout << *ListIter << " wird geloescht\n";
         L.erase(ListIter);
         cout << *ListIter
              << " an aktueller Position\n";
         break;
      }

   int target = 3;
   int count = 0;

   TList<int>::Iterator it = L.begin();
   while (it != L.end()) {
       if (count == target) {
           std::cout << "bam" << *it << std::endl;
       }
       count++;
       it++;
   }

   //for (TList<int>::Iterator iter = L.begin(); iter != L.end(); i++) {
   //    std::cout << *iter << std::endl;
   //}

   //TList<int>::Iterator it = L.begin();
   //while (it != L.end()) {
   //    std::cout << *it << std::endl;
   //    it++;
   //}
   for (TList<int>::Iterator itt = L.begin(); itt != L.end(); ++itt) {
       std::cout << *itt << " ";
   }
   

    return 0;
}
