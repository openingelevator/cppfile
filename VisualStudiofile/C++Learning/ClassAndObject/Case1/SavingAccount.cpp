#include"SavingAccount.h"


float SavingAccount::calculateMonthlyInterest()
{
	float mothlyInterst = annualInterestRate / 1.0 / 12 * savingBalance;
	savingBalance += mothlyInterst;
	return mothlyInterst;
}
float SavingAccount::getBalance()
{
	return savingBalance;
}
void SavingAccount::modifyInterestRate(float rate)
{
	annualInterestRate = rate;
}
float SavingAccount::annualInterestRate = 0.03;
SavingAccount::SavingAccount(float account):savingBalance(account)
{

}