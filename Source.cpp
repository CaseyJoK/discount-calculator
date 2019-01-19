//Casey-Jo Kenny, Computer Science for Games, Group 2, Question 1, 2 and 3

#include <iostream>
#include <iomanip>
using namespace std;

double fullPriceGoods, discountedGoods, finalDeliveryCharge, totalCost;
const double fixedDeliveryCharge = 6.50, euroConversionRate = 1.1, dollarConversionRate = 1.22, discount20 = 0.8, discount30 = 0.7, discount50 = 0.5;


int main()
{
	const char poundSign(156); // Sets the variable poundSign to the character of £

	void calculateTotalDiscountedGoods();
	void checkValidVoucherCode();
	void produceOrderCostInOtherCurrency();

	cout << "Please enter the total cost: " << poundSign;
	cin >> fullPriceGoods;

	if (fullPriceGoods <= 0)
	{
		cout << "ERROR: The order value should be a positive number!";
		cout << "\n\n";
		system("pause");
		exit(0);

	}
	else
	{
		checkValidVoucherCode();
	}


	calculateTotalDiscountedGoods();

	cout << fixed << setprecision(2) << "\nOrder value without discount:\t " << poundSign << fullPriceGoods; //fixed and set precision allows for there to always be two decimal places
	cout << fixed << setprecision(2) << "\nOrder value with discount:\t " << poundSign << discountedGoods;
	cout << "\nDelivery Charge:\t\t " << poundSign << finalDeliveryCharge;
	cout << fixed << setprecision(2) << "\nTo pay:\t\t\t\t " << poundSign << totalCost;

	produceOrderCostInOtherCurrency();

	cout << "\n\n";
	system("pause");
	return 0;
}

void calculateTotalDiscountedGoods()
{
	if (fullPriceGoods <= 30) //Sets the discount price depending on how much the bill is
	{
		discountedGoods = fullPriceGoods * discount20;
	}
	if ((fullPriceGoods > 30) && (fullPriceGoods <= 60))
	{
		discountedGoods = fullPriceGoods * discount30;
	}
	if (fullPriceGoods > 60)
	{
		discountedGoods = fullPriceGoods * discount50;
	}

	totalCost = discountedGoods + finalDeliveryCharge;
}

void checkValidVoucherCode()
{
	int voucherCode, validCode;


	cout << "Enter voucher: #";
	cin >> voucherCode;

	const int Digit1 = (voucherCode / 1000); //Isolates the digits so I can add them together
	const int Digit2 = (voucherCode % 1000) / 100;
	const int Digit3 = (voucherCode / 10) % 10;
	const int Digit4 = (voucherCode % 10);

	if ((Digit1 + Digit2 + Digit3 + Digit4) == 12 && (voucherCode >= 1000) && (voucherCode <= 9999)) //Checks to see if it is a 4 digit number and all the digits add up to 12
	{
		cout << "Valid voucher - free delivery.";
		validCode = true; //Sets the ValidCode to true which is then used to decide the price of delivery
	}
	else
	{
		cout << "Invalid voucher";
		validCode = false;
	}
	if (validCode)
	{
		finalDeliveryCharge = 0;
	}
	else
	{
		finalDeliveryCharge = fixedDeliveryCharge;
	}
	

}
void produceOrderCostInOtherCurrency()
{
	char currencySymbol;
	const char dollarSign(36);  // Sets the variable dollarSign to the character of $

	cout << "\n\nCurrency ('E' for Euros, '$' for Dollars or '#' for N/A: ";
	cin >> currencySymbol;

	switch (currencySymbol) //By using the switch it means that we can have a default answer for all entries and then have a select few cases that have different answers
	{
	case 'E' :
		cout << fixed << setprecision(2) << "\nCost in Euros: " << totalCost * euroConversionRate << " Euros";
		break;
	case '$':
		cout << fixed << setprecision(2) << "\nCost in US Dollars: " << dollarSign << totalCost * dollarConversionRate;
		break;
	case '#':
		cout << "\n\n";
		system("pause");
		break;
	default:
		cout << "\nERROR: Currency unknown!"; //This is the default answer so anything entered that isnt chosen as a case will respond with this
	}
}
