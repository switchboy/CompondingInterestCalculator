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


bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main()
{
    std::string myNumberString;
    std::cout << "Finance calculator v 0.1" << std::endl;
    std::cout << "Calculate the effect of compounding interest and inflation on buying power in \"Today's money\" over a given number of \n" <<
                 "years. This wil help you eveluate your savings and investment plan. It will note the years from now when you could expect \n"<<
                 "to retire with your current lifestyle. This will be three percent annualy of your total capital" << std::endl;
    

    std::cout << "How much money is in your savings account right now:" <<std::endl;
    std::getline(std::cin, myNumberString);
    int  amountInSavingsAccount  = std::stoi(myNumberString);

    std::cout << "What has been the avarage interest on this savings account: (%)" << std::endl;
    std::getline(std::cin, myNumberString);
    int  yearlyInterestSavingsAccount = std::stoi(myNumberString);

    std::cout << "How much money is in your investment portofolio right now:" << std::endl;
    std::getline(std::cin, myNumberString);
    int  amountInvested = std::stoi(myNumberString);

    std::cout << "What is the expected yield of your portofolio: (%)" << std::endl;
    std::getline(std::cin, myNumberString);
    int  yearlyAverageYieldInvestment = std::stoi(myNumberString);

    std::cout << "What is the value of your home:" << std::endl;
    std::getline(std::cin, myNumberString);
    int  valueOfHouse = std::stoi(myNumberString);
    
}