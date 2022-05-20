#include<iostream> 
#include"spreads.h"
using namespace std;
/*int main()                 //Simple Intrest
{
	float prin,rate,years;
	cout<<"\nEnter principal: ";
	cin>>prin;
	cout<<"\nEnter rate: ";
	cin>>rate;
	cout<<"\nEnter number of years: ";
	cin>>years;
	cout<<"Simple Interest: "<<simpleInterest(prin,rate,years);
	return 0;
}*/

/*int main()                        //Compound Intrest
{
	float prin,rate,years;
	int num;
	cout<<"\nEnter principal: ";
	cin>>prin;
	cout<<"\nEnter rate: ";
	cin>>rate;
	cout<<"\nEnter number of years: ";
	cin>>years;
	cout<<"\nEnter number of times: ";      //yearly,semi,quarterly,monthly
	cin>>num;
	cout<<"Compound Interest: "<<compoundIntrest(prin,rate,years,num);
	return 0;
}*/

int main()                             //Long Straddle
{
	float exercisePrice,buyPut,buyCall,eStrikePrice;
	cout<<"\nEnter Exercise price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Put option cost: ";
	cin>>buyPut;
	cout<<"\nEnter Call option cost: ";
	cin>>buyCall;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longStraddle(exercisePrice,eStrikePrice,buyCall,buyPut);
	return 0;
}

/*int main()                             //Short Straddle
{
	float exercisePrice,sellPut,sellCall,eStrikePrice;
	cout<<"\nEnter Exercise price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Put option cost: ";
	cin>>sellPut;
	cout<<"\nEnter Call option cost: ";
	cin>>sellCall;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortStraddle(exercisePrice,eStrikePrice,sellCall,sellPut);
	return 0;
}*/

/*int main()                                   //long strangle static array
{
	float eStrikePrice;
	//float arr[3][3] = {{1000,80,25},{1100,55,40}, {1200,35,55}};
	float arr[2][3] = {{105,1.50,2},{95,3,1.30}};
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longStrangle(arr,eStrikePrice,2);
}*/

/*int main()                                   //Short strangle static array
{
	float eStrikePrice;
	float arr[3][3] = {{1000,80,25},{1100,55,40},{1200,35,55}};
	//float arr[2][3] = {{105,1.50,2},{95,3,1.30}};
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortStrangle(arr,eStrikePrice,3);
}*/

/*int main()                             //long Straps
{
	float exercisePrice,eStrikePrice,buyPut,buyCall;
	cout<<"\nEnter Exercise Price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Call option cost: ";
	cin>>buyCall;
	cout<<"\nEnter Put option cost: ";
	cin>>buyPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longStraps(exercisePrice,eStrikePrice,buyCall,buyPut);
	return 0;
}*/
/*int main()                             //Short Straps
{
	float exercisePrice,eStrikePrice,sellPut,sellCall;
	cout<<"\nEnter Exercise Price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Call option cost: ";
	cin>>sellCall;
	cout<<"\nEnter Put option cost: ";
	cin>>sellPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortStraps(exercisePrice,eStrikePrice,sellCall,sellPut);
	return 0;
}*/

/*int main()                             //Long Strips
{
	float exercisePrice,eStrikePrice,buyPut,buyCall;
	cout<<"\nEnter Exercise Price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Call option cost: ";
	cin>>buyCall;
	cout<<"\nEnter Put option cost: ";
	cin>>buyPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longStrips(exercisePrice,eStrikePrice,buyCall,buyPut);
	return 0;
}*/

/*int main()                             //Short Strips
{
	float exercisePrice,eStrikePrice,sellPut,sellCall;
	cout<<"\nEnter Exercise Price: ";
	cin>>exercisePrice;
	cout<<"\nEnter Call option cost: ";
	cin>>sellCall;
	cout<<"\nEnter Put option cost: ";
	cin>>sellPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortStrips(exercisePrice,eStrikePrice,sellCall,sellPut);
	return 0;
}*/

/*int main()                             //Bull Call Spread
{
	float exercisePrice1,exercisePrice2,eStrikePrice,buyCall,sellCall;
	cout<<"\nEnter lower exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy call at lower exercise price: ";
	cin>>buyCall;
	cout<<"\nEnter higher exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell call at higher exercise price: ";
	cin>>sellCall;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	bullCallSpread(exercisePrice1,exercisePrice2,eStrikePrice,buyCall,sellCall);
	return 0;
}*/

/*int main()                             //Bear Put Spread
{
	float exercisePrice1,exercisePrice2,eStrikePrice,buyPut,sellPut;
	cout<<"\nEnter higher exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy put at higher exercise price: ";
	cin>>buyPut;
	cout<<"\nEnter lower exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell put at lower exercise price: ";
	cin>>sellPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	bearPutSpread(exercisePrice1,exercisePrice2,eStrikePrice,buyPut,sellPut);
	return 0;
}*/

/*int main()                             //Bull Put Spread
{
	float exercisePrice1,exercisePrice2,eStrikePrice,buyPut,sellPut;
	cout<<"\nEnter higher exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell put at higher exercise price: ";
	cin>>sellPut;
	cout<<"\nEnter lower exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy put at lower exercise price: ";
	cin>>buyPut;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	bullPutSpread(exercisePrice1,exercisePrice2,eStrikePrice,buyPut,sellPut);
	return 0;
}*/

/*int main()                             //Bear Call Spread
{
	float exercisePrice1,exercisePrice2,eStrikePrice,buyCall,sellCall;
	cout<<"\nEnter higher exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy call at higher exercise price: ";
	cin>>buyCall;
	cout<<"\nEnter lower exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell call at lower exercise price: ";
	cin>>sellCall;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	bearCallSpread(exercisePrice1,exercisePrice2,eStrikePrice,buyCall,sellCall);
	return 0;
}*/

/*int main()                             //Long Call Butterfly
{
	float exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,buyCall1,buyCall2,sellCall;
	cout<<"\nEnter In the money(lowest) exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy call at lowest exercise price: ";
	cin>>buyCall1;
	cout<<"\nEnter At the money(medium) exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell call at medium exercise price: ";
	cin>>sellCall;
	cout<<"\nEnter Out the money(highest) exercise price: ";
	cin>>exercisePrice3;
	cout<<"\nEnter cost to buy call at highest exercise price: ";
	cin>>buyCall2;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longCallButterfly(exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,buyCall1,buyCall2,sellCall);
	return 0;
}*/

/*int main()                             //Short Call Butterfly
{
	float exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,sellCall1,sellCall2,buyCall;
	cout<<"\nEnter In the money(lowest) exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to sell call at lowest exercise price: ";
	cin>>sellCall1;
	cout<<"\nEnter At the money(medium) exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to buy call at medium exercise price: ";
	cin>>buyCall;
	cout<<"\nEnter Out the money(highest) exercise price: ";
	cin>>exercisePrice3;
	cout<<"\nEnter cost to sell call at highest exercise price: ";
	cin>>sellCall2;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortCallButterfly(exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,sellCall1,sellCall2,buyCall);
	return 0;
}*/

/*int main()                             //Long Put Butterfly 
{
	float exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,buyPut1,buyPut2,sellPut;
	cout<<"\nEnter In the money(lowest) exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to buy put at lowest exercise price: ";
	cin>>buyPut1;
	cout<<"\nEnter At the money(medium) exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to sell put at medium exercise price: ";
	cin>>sellPut;
	cout<<"\nEnter Out the money(highest) exercise price: ";
	cin>>exercisePrice3;
	cout<<"\nEnter cost to buy put at highest exercise price: ";
	cin>>buyPut2;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	longPutButterfly(exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,buyPut1,buyPut2,sellPut);
	return 0;
}*/

/*int main()                             //Short Put Butterfly 
{
	float exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,sellPut1,sellPut2,buyPut;
	cout<<"\nEnter Out the money(lowest) exercise price: ";
	cin>>exercisePrice1;
	cout<<"\nEnter cost to sell put at lowest exercise price: ";
	cin>>sellPut1;
	cout<<"\nEnter At the money(medium) exercise price: ";
	cin>>exercisePrice2;
	cout<<"\nEnter cost to buy put at medium exercise price: ";
	cin>>buyPut;
	cout<<"\nEnter In the money(highest) exercise price: ";
	cin>>exercisePrice3;
	cout<<"\nEnter cost to sell put at highest exercise price: ";
	cin>>sellPut2;
	cout<<"\nEnter expected strike price at expiry: ";
	cin>>eStrikePrice;
	shortPutButterfly(exercisePrice1,exercisePrice2,exercisePrice3,eStrikePrice,sellPut1,sellPut2,buyPut);
	return 0;
}*/
