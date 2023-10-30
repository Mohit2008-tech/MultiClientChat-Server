#include"multiClientChat.h"

using namespace std;

 int main()
{
	
	
   MultiClientChat mcc("190.10.10.10", 3600);
   if(mcc.init() != 0) return 0;
   
   mcc.run();
   system("pause");
   return 0;

}