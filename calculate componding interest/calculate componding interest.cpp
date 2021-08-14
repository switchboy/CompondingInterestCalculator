#include <iostream>
#include <string>

class finance {
public:
    finance(
        double monthlyInvestment,
        double amountInSavingsAccount,
        double yearlyInterestSavingsAccount,
        double yearlyAverageYieldInvestment,
        double yearlyInflation,
        double amountInvested,
        double amountOfMortage,
        double interestOnMortage,
        double penaltyFreeMortageReduction,
        double valueOfHouse
    ) {
        this->monthlyInvestment = monthlyInvestment;
        this->amountInSavingsAccount = amountInSavingsAccount;
        this->yearlyInterestSavingsAccount = yearlyInterestSavingsAccount;
        this->yearlyAverageYieldInvestment = yearlyAverageYieldInvestment;
        this->yearlyInflation = yearlyInflation;
        this->amountInvested = amountInvested;
        this->amountOfMortage = amountOfMortage;
        this->interestOnMortage = interestOnMortage;
        this->penaltyFreeMortageReduction = penaltyFreeMortageReduction;
        this->valueOfHouse = valueOfHouse;
    };

 private:
     double monthlyInvestment;
     double amountInSavingsAccount;
     double yearlyInterestSavingsAccount;
     double yearlyAverageYieldInvestment;
     double yearlyInflation;
     double amountInvested;
     double amountOfMortage;
     double interestOnMortage;
     double penaltyFreeMortageReduction;
     double valueOfHouse;
};


bool isValidDouble(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

void askAndGetAnswerFromConsole(std::string question, double& answer) {
    std::string myNumberString;
    bool numberEnterd = false;
    while (!numberEnterd) {
        std::cout << question << std::endl;
        std::getline(std::cin, myNumberString);
        if (isValidDouble(myNumberString)) {
            answer = std::stod(myNumberString);
            std::cout << std::endl;
            numberEnterd = true;
        }
        else {
            std::cout << "Please enter only number and a point: use the folowing format 999.99!" << std::endl << std::endl;
        }
    }
}

void getStartingValuesFromUser(){
    double  amountInSavingsAccount;
    double  yearlyInterestSavingsAccount;
    double  amountInvested;
    double  yearlyAverageYieldInvestment;
    double  valueOfHouse;
    askAndGetAnswerFromConsole("How much money is in your savings account right now:", amountInSavingsAccount);
    askAndGetAnswerFromConsole("What has been the avarage interest on this savings account: (%)", yearlyInterestSavingsAccount);
    askAndGetAnswerFromConsole("How much money is in your investment portofolio right now:", amountInvested);
    askAndGetAnswerFromConsole("What is the expected yield of your portofolio: (%)", yearlyAverageYieldInvestment);
    askAndGetAnswerFromConsole("What is the value of your home:", valueOfHouse);
}

void displayWelcomeText() {
    std::cout << "Finance calculator v 0.1" << std::endl;
    std::cout << "Calculate the effect of compounding interest and inflation on buying power in \"Today's money\" over a given number of \n" <<
        "years. This wil help you eveluate your savings and investment plan. It will note the years from now when you could \n" <<
        "expect to retire with your current lifestyle. This will be three percent annualy of your total capital" << std::endl << std::endl << std::endl;
}

int main()
{
    displayWelcomeText();
    getStartingValuesFromUser();
    system("pause");

}