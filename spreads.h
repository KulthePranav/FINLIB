#include<iostream> 
#include<iomanip> 
#include<math.h>  
using namespace std;

template <typename T> 
T simpleInterest(T p,T r,T t){
	T simpint;
	simpint=(p*r*t)/100;
	return simpint;
}

template <typename T> 
T compoundIntrest(T p,T r,T t,int n){
	T times=n*t;
	T value;
	value=pow(1+(r/(100*n)),times);
	T Amount=p*value;
	T compInt=Amount - p;
	return compInt;
}

template <typename T> 
T longStraddle(T exercisePrice,T eStrikePrice,T buyCall,T buyPut){
	T c;
	T strategyCost=buyCall+buyPut;
	T a=exercisePrice - strategyCost;
	T b=exercisePrice + strategyCost;
	if(exercisePrice>eStrikePrice)
	{
		c=(exercisePrice-eStrikePrice)-strategyCost;
	}
	else
	{
		c=(eStrikePrice-exercisePrice)-strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
			cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial outflow: "<<strategyCost<<endl;
	cout<<"Maximum loss: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T> 
T shortStraddle(T exercisePrice,T eStrikePrice,T sellCall,T sellPut){
	T c;
	T strategyCost=sellCall+sellPut;
	T a=exercisePrice - strategyCost;
	T b=exercisePrice + strategyCost;
	if(exercisePrice>eStrikePrice)
	{
		c=(eStrikePrice-exercisePrice)+strategyCost;
	}
	else
	{
		c=(exercisePrice-eStrikePrice)+strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
		cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial inflow: "<<strategyCost<<endl;
	cout<<"Maximum profit: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T> 
T longStrangle(T data[][3],T eStrikePrice,int n){
	int i,pos1,pos2;
	T c;
	T minBuyCallcost=data[0][1];
	for(i=0;i<n;i++)
	{
		if(data[i][1]<=minBuyCallcost)
		{
			minBuyCallcost=data[i][1];
			pos1=i;
		}
	}
	T minBuyPutcost=data[0][2];
	for(i=0;i<n;i++)
	{
		if(data[i][2]<=minBuyPutcost)
		{
			minBuyPutcost=data[i][2];
			pos2=i;
		}
	}
	T strategyCost=minBuyCallcost+minBuyPutcost;
	T exercisePrice1= data[pos1][0];
	T exercisePrice2= data[pos2][0];
	if(exercisePrice1>exercisePrice2)
	{
		T a=exercisePrice2 - strategyCost;
		T b=exercisePrice1 + strategyCost;
		if(eStrikePrice>exercisePrice1)
		{
			c=(eStrikePrice-exercisePrice1)-strategyCost;
		}
		else if(eStrikePrice<exercisePrice2)
		{
			c=(exercisePrice2-eStrikePrice)-strategyCost;
		}
		else
		{
			c=-strategyCost;
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}

template <typename T> 
T shortStrangle(T data[][3],T eStrikePrice,int n){
	int i,pos1,pos2;
	T c;
	T minSellCallcost=data[0][1];
	for(i=0;i<n;i++)
	{
		if(data[i][1]<=minSellCallcost)
		{
			minSellCallcost=data[i][1];
			pos1=i;
		}
	}
	T minSellPutcost=data[0][2];
	for(i=0;i<n;i++)
	{
		if(data[i][2]<=minSellPutcost)
		{
			minSellPutcost=data[i][2];
			pos2=i;
		}
	}
	T strategyCost=minSellCallcost+minSellPutcost;
	T exercisePrice1= data[pos1][0];
	T exercisePrice2= data[pos2][0];
	if(exercisePrice1>exercisePrice2)
	{
		T a=exercisePrice2 - strategyCost;
		T b=exercisePrice1 + strategyCost;
		if(eStrikePrice>exercisePrice1)
		{
			c=(exercisePrice1-eStrikePrice)+strategyCost;
		}
		else if(eStrikePrice<exercisePrice2)
		{
			c=(eStrikePrice-exercisePrice2)+strategyCost;
		}
		else
		{
			c=strategyCost;
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}
		cout<<"Initial inflow: "<<strategyCost<<endl;
		cout<<"Maximum profit: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}

template <typename T> 
T longStraps(T exercisePrice,T eStrikePrice,T buyCall,T buyPut){
	T c;
	T strategyCost=(2*buyCall)+buyPut;
	T a=exercisePrice - strategyCost;
	T b=exercisePrice + (strategyCost/2);
	if(eStrikePrice>exercisePrice)
	{
		c=(2*(eStrikePrice-exercisePrice))-strategyCost;
	}
	else
	{
		c=(exercisePrice-eStrikePrice)-strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
		cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial outflow: "<<strategyCost<<endl;
	cout<<"Maximum loss: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T> 
T shortStraps(T exercisePrice,T eStrikePrice,T sellCall,T sellPut){
	T c;
	T strategyCost=(2*sellCall)+sellPut;
	T a=exercisePrice - strategyCost;
	T b=exercisePrice + (strategyCost/2);
	if(eStrikePrice>exercisePrice)
	{
		c=(2*(exercisePrice-eStrikePrice))+strategyCost;
	}
	else
	{
		c=(eStrikePrice-exercisePrice)+strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
		cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial inflow: "<<strategyCost<<endl;
	cout<<"Maximum profit: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T> 
T longStrips(T exercisePrice,T eStrikePrice,T buyCall,T buyPut){
	T c;
	T strategyCost=buyCall+(2*buyPut);
	T a=exercisePrice - (strategyCost/2);
	T b=exercisePrice + strategyCost;
	if(eStrikePrice>exercisePrice)
	{
		c=(eStrikePrice-exercisePrice)-strategyCost;
	}
	else
	{
		c=(2*(exercisePrice-eStrikePrice))-strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
		cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial outflow: "<<strategyCost<<endl;
	cout<<"Maximum loss: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T> 
T shortStrips(T exercisePrice,T eStrikePrice,T sellCall,T sellPut){
	T c;
	T strategyCost=sellCall+(2*sellPut);
	T a=exercisePrice - (strategyCost/2);
	T b=exercisePrice + strategyCost;
	if(eStrikePrice>exercisePrice)
	{
		c=(exercisePrice-eStrikePrice)+strategyCost;
	}
	else
	{
		c=(2*(eStrikePrice-exercisePrice))+strategyCost;
	}
	if(eStrikePrice==a || eStrikePrice==b)
	{
		cout<<"Profit: 0 and Loss: 0"<<endl;
	}
	else if(c<0)
	{
		cout<<"Loss: "<<-c<<endl;
	}
	else
	{
		cout<<"Profit: "<<c<<endl;
	}
	cout<<"Initial inflow: "<<strategyCost<<endl;
	cout<<"Maximum profit: "<<strategyCost<<endl;
	cout<<"Break even point is: "<<a<<" and "<<b;
}

template <typename T>
T bullCallSpread(T exercisePrice1,T exercisePrice2,T eStrikePrice,T buyCall,T sellCall){  //ep1<ep2 therefore  buyCall>sellCall
	T c;
	if(exercisePrice1<exercisePrice2 && buyCall>sellCall )
	{
		T strategyCost= buyCall-sellCall;
		T maxProfit=(exercisePrice2-exercisePrice1)-strategyCost;
		T a=exercisePrice1+strategyCost;
		if(eStrikePrice<=exercisePrice1)
		{
			c=-strategyCost;
		}
		else if(eStrikePrice>exercisePrice1 && eStrikePrice<=exercisePrice2)
		{
			c=(eStrikePrice-exercisePrice1)-strategyCost;
		}
		else
		{
			c=(eStrikePrice-exercisePrice1)+(exercisePrice2-eStrikePrice)-strategyCost;
		}
		if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<strategyCost<<endl;
		cout<<"Maximum Profit: "<<maxProfit<<endl;
		cout<<"Break even point is: "<<a<<endl;
	}	
}

template <typename T>
T bearPutSpread(T exercisePrice1,T exercisePrice2,T eStrikePrice,T buyPut,T sellPut){  //ep1>ep2 therefore  buyPut>sellPut

	T c;
	if(exercisePrice1>exercisePrice2 && buyPut>sellPut )
	{
		T strategyCost= buyPut-sellPut;
		T maxProfit=(exercisePrice1-exercisePrice2)-strategyCost;
		T a=exercisePrice1-strategyCost;
		if(eStrikePrice<exercisePrice2)
		{
			c=(exercisePrice1-eStrikePrice)+(eStrikePrice-exercisePrice2)-strategyCost;
		}
		else if(eStrikePrice>=exercisePrice2 && eStrikePrice<exercisePrice1)
		{
			c=(exercisePrice1-eStrikePrice)-strategyCost;
		}
		else
		{
			c=-strategyCost;
		}
		if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}	
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<strategyCost<<endl;
		cout<<"Maximum Profit: "<<maxProfit<<endl;
		cout<<"Break even point is: "<<a<<endl;
	}	
}

template <typename T>
T bullPutSpread(T exercisePrice1,T exercisePrice2,T eStrikePrice,T buyPut,T sellPut){  //ep1<ep2 therefore  buyPut<sellPut

	T c;
	if(exercisePrice1<exercisePrice2 && buyPut<sellPut )
	{
		T strategyCost= sellPut-buyPut;
		T maxLoss=(exercisePrice2-exercisePrice1)-strategyCost;
		T a=exercisePrice2-strategyCost;
		if(eStrikePrice<exercisePrice1)
		{
			c=(exercisePrice1-eStrikePrice)+(eStrikePrice-exercisePrice2)+strategyCost;
		}
		else if(eStrikePrice>=exercisePrice1 && eStrikePrice<exercisePrice2)
		{
			c=(eStrikePrice-exercisePrice2)+strategyCost;
		}
		else
		{
			c=strategyCost;
		}
		if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}
		cout<<"Initial inflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<maxLoss<<endl;
		cout<<"Maximum Profit: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<endl;
	}	
}

template <typename T>
T bearCallSpread(T exercisePrice1,T exercisePrice2,T eStrikePrice,T buyCall,T sellCall){  //ep1>ep2 therefore  buyCall<sellCall

	T c;
	if(exercisePrice1>exercisePrice2 && buyCall<sellCall )
	{
		T strategyCost= sellCall- buyCall;
		T maxLoss=(exercisePrice1-exercisePrice2)-strategyCost;
		T a=exercisePrice2+strategyCost;
		if(eStrikePrice<=exercisePrice2)
		{
			c=strategyCost;
		}
		else if(eStrikePrice>exercisePrice2 && eStrikePrice<=exercisePrice1)
		{
			c=(exercisePrice2-eStrikePrice)+strategyCost;
		}
		else
		{
			c=(exercisePrice1-eStrikePrice)+(exercisePrice2-eStrikePrice)+strategyCost;
		}
		if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}	
		cout<<"Initial inflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<maxLoss<<endl;
		cout<<"Maximum Profit: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<endl;
	}	
}

template <typename T>
T longCallButterfly(T exercisePrice1,T exercisePrice2,T exercisePrice3,T eStrikePrice,T buyCall1,T buyCall2,T sellCall){
//buyCall1 at ep1 and buyCall2 at ep3
//ep1<ep2<ep3
	T c;
	if(exercisePrice3>exercisePrice2 && exercisePrice2> exercisePrice1 && buyCall1>sellCall && sellCall>buyCall2 && (2*(sellCall)-(buyCall1+buyCall2))<0 && (exercisePrice1+exercisePrice3)==2*(exercisePrice2))
	{
		T strategyCost=(buyCall1+buyCall2)-(2*(sellCall));
		T maxProfit=(exercisePrice2-exercisePrice1)-strategyCost;
		T a=exercisePrice1+strategyCost;
		T b=exercisePrice3-strategyCost;
		if(eStrikePrice<=exercisePrice1)
		{
			c=-strategyCost;
		}
		else if(eStrikePrice>exercisePrice1 && eStrikePrice<=exercisePrice2)
		{
			c=(eStrikePrice-exercisePrice1)-strategyCost;
		}
		else if(eStrikePrice>exercisePrice2 && eStrikePrice<=exercisePrice3)
		{
			c=(2*(exercisePrice2-eStrikePrice)+(eStrikePrice-exercisePrice1)-strategyCost);
		}
		else
		{
			c=(2*(exercisePrice2-eStrikePrice)+(eStrikePrice-exercisePrice3)+(eStrikePrice-exercisePrice1)-strategyCost);
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<c<<endl;
		}	
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<strategyCost<<endl;
		cout<<"Maximum Profit: "<<maxProfit<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b<<endl;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}

template <typename T>
T shortCallButterfly(T exercisePrice1,T exercisePrice2,T exercisePrice3,T eStrikePrice,T sellCall1,T sellCall2,T buyCall){
//sellCall1 at ep1 and sellCall2 at ep3
//ep1<ep2<ep3	
	T c;
	if(exercisePrice3>exercisePrice2 && exercisePrice2> exercisePrice1 && sellCall1>buyCall && buyCall>sellCall2 && ((sellCall1+sellCall2)-2*(buyCall))>0 && (exercisePrice1+exercisePrice3)==2*(exercisePrice2))
	{
		T strategyCost=(sellCall1+sellCall2)-(2*(buyCall));
		T maxLoss=(exercisePrice2-exercisePrice1)-strategyCost;
		T a=exercisePrice1+strategyCost;
		T b=exercisePrice3-strategyCost;
		if(eStrikePrice<=exercisePrice1)
		{
			c=strategyCost;
		}
		else if(eStrikePrice>exercisePrice1 && eStrikePrice<=exercisePrice2)
		{
			c=strategyCost+(exercisePrice1-eStrikePrice);	
		}
		else if(eStrikePrice>exercisePrice2 && eStrikePrice<=exercisePrice3)
		{
			c=(2*(eStrikePrice-exercisePrice2)+(exercisePrice1-eStrikePrice)+strategyCost);
		}
		else
		{
			c=(2*(eStrikePrice-exercisePrice2)+(exercisePrice3-eStrikePrice)+(exercisePrice1-eStrikePrice)+strategyCost);
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<fixed<<setprecision(2)<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<fixed<<setprecision(2)<<c<<endl;
		}	
		cout<<"Initial inflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<maxLoss<<endl;
		cout<<"Maximum Profit: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b<<endl;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}

template <typename T>
T longPutButterfly(T exercisePrice1,T exercisePrice2,T exercisePrice3,T eStrikePrice,T buyPut1,T buyPut2,T sellPut){
//buyPut1 at ep1 and buyPut2 at ep3
//ep1<ep2<ep3	
	T c;
	if(exercisePrice3>exercisePrice2 && exercisePrice2>exercisePrice1 && buyPut1<sellPut && sellPut<buyPut2 && (2*(sellPut)-(buyPut1+buyPut2))<0 && (exercisePrice1+exercisePrice3)==2*(exercisePrice2))
	{
		T strategyCost=(buyPut1+buyPut2)-(2*(sellPut));
		T maxProfit=(exercisePrice3-exercisePrice2)-strategyCost;
		T a=exercisePrice1+strategyCost;
		T b=exercisePrice3-strategyCost;
		if(eStrikePrice<exercisePrice1)
		{
			c=(2*(eStrikePrice-exercisePrice2)+(exercisePrice3-eStrikePrice)+(exercisePrice1-eStrikePrice)-strategyCost);
		}
		else if(eStrikePrice>=exercisePrice1 && eStrikePrice<exercisePrice2)
		{
			c=(2*(eStrikePrice-exercisePrice2)+(exercisePrice3-eStrikePrice)-strategyCost);	
		}
		else if(eStrikePrice>=exercisePrice2 && eStrikePrice<exercisePrice3)
		{
			c=(exercisePrice3-eStrikePrice)-strategyCost;
		}
		else
		{
			c=-strategyCost;
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<fixed<<setprecision(2)<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<fixed<<setprecision(2)<<c<<endl;
		}	
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<strategyCost<<endl;
		cout<<"Maximum Profit: "<<maxProfit<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b<<endl;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}

template <typename T>
T shortPutButterfly(T exercisePrice1,T exercisePrice2,T exercisePrice3,T eStrikePrice,T sellPut1,T sellPut2,T buyPut){
//sellPut1 at ep1 and sellPut2 at ep3
//ep1<ep2<ep3	
	T c;
	if(exercisePrice3>exercisePrice2 && exercisePrice2>exercisePrice1 && sellPut1<buyPut && buyPut<sellPut2 && ((sellPut1+sellPut2)-2*(buyPut))>0 && (exercisePrice1+exercisePrice3)==2*(exercisePrice2))
	{
		T strategyCost=(sellPut1+sellPut2)-(2*(buyPut));
		T maxLoss=(exercisePrice2-exercisePrice1)-strategyCost;
		T a=exercisePrice1+strategyCost;
		T b=exercisePrice3-strategyCost;
		if(eStrikePrice<exercisePrice1)
		{
			c=(2*(exercisePrice2-eStrikePrice)+(eStrikePrice-exercisePrice3)+(eStrikePrice-exercisePrice1)+strategyCost);
		}
		else if(eStrikePrice>=exercisePrice1 && eStrikePrice<exercisePrice2)
		{
			c=(2*(exercisePrice2-eStrikePrice)+(eStrikePrice-exercisePrice3)+strategyCost);
		}
		else if(eStrikePrice>=exercisePrice2 && eStrikePrice<exercisePrice3)
		{
			c=(eStrikePrice-exercisePrice3)+strategyCost;
		}
		else
		{
			c=strategyCost;
		}
		if(eStrikePrice==a || eStrikePrice==b)
		{
			cout<<"Profit: 0 and Loss: 0"<<endl;
		}
		else if(c<0)
		{
			cout<<"Loss: "<<fixed<<setprecision(2)<<-c<<endl;
		}
		else
		{
			cout<<"Profit: "<<fixed<<setprecision(2)<<c<<endl;
		}	
		cout<<"Initial outflow: "<<strategyCost<<endl;
		cout<<"Maximum loss: "<<maxLoss<<endl;
		cout<<"Maximum Profit: "<<strategyCost<<endl;
		cout<<"Break even point is: "<<a<<" and "<<b<<endl;
	}
	else
	{
		cout<<"Strategy error"<<endl;
	}
}


