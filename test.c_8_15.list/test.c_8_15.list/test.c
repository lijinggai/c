#include "list.h"
void Test()
{
	SLnode* plist = Init();//≥ı ºªØ
	SLnodePushback(plist, 1);//Œ≤≤Â
	SLnodePushback(plist, 2);//Œ≤≤Â
	SLnodePushback(plist, 3);//Œ≤≤Â
	SLnodePushback(plist,4);//Œ≤≤Â
	SLnodePopback(plist);//Œ≤…æ
	SLnodePushFront(plist,5);//Õ∑≤Â
	SLnodePopFront(plist);//Õ∑…æ
	print(plist);//¥Ú”°
	SLnodeDestroy(&plist);// Õ∑≈
}
int main()
{
	Test();
	return 0;
}