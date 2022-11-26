#pragma once
class SavingAccount
{
public:
	SavingAccount(float);
	float calculateMonthlyInterest();
	static void modifyInterestRate(float);
	float getBalance();
private:
	float savingBalance;
	static float annualInterestRate;
};