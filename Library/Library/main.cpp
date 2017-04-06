#include <iostream>

using namespace std;

#include "TLibraryPool.h"

int main()
{
   TLibraryPool LP("data.xml");

   cout << LP << endl;

   return 0;
}


/*
    #include <iostream>

    using namespace std;

    #include "TLibraryPool.h"

    int main()
    {
       TLibraryPool LP("data.xml");

       LP.print();
       cout << endl;

       return 0;
    }

*/
