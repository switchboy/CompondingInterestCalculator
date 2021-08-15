#include <iostream>
#include <string>
#include <list>

struct month {
    double amountInSavingsAccount;
    double amountInvested;
    double amountOfMortage;
    double availableCash;
};

struct year {
    double amountInSavingsAccount;
    double amountInvested;
    double amountOfMortage;
    double availableCash;
    double valueOfHouse;
};

class finance {
public:
    finance() {
        this->monthlyInvestmentPortofolio = 0;
        this->monthlyInvestmentSavingsAccount = 0;
        this->amountInSavingsAccount = 0;
        this->yearlyInterestSavingsAccount = 0;
        this->yearlyAverageYieldInvestment = 0;
        this->yearlyInflation = 0;
        this->amountInvested = 0;
        this->amountOfMortage = 0;
        this->interestOnMortage = 0;
        this->penaltyFreeMortageReduction = 0;
        this->valueOfHouse = 0;
        this->realEstateYearlyYield = 0;
        this->netYearlyIncome = 0;
        this->availableCash = 0;
        this->yearsLeftOnMorgage = 0;
    };
    void setFinancialPicture(
        double monthlyInvestmentPortofolio,
        double monthlyInvestmentSavingsAccount,
        double amountInSavingsAccount,
        double yearlyInterestSavingsAccount,
        double yearlyAverageYieldInvestment,
        double yearlyInflation,
        double amountInvested,
        double amountOfMortage,
        double interestOnMortage,
        double penaltyFreeMortageReduction,
        double valueOfHouse,
        double realEstateYearlyYield,
        double netYearlyIncome,
        double yearsLeftOnMorgage
    );
    void calculateOneMonthOnCurrentPlan();
    void calculateOneYearOnCurrentPlan();

 private:
     double monthlyInvestmentPortofolio;
     double monthlyInvestmentSavingsAccount;
     double amountInSavingsAccount;
     double yearlyInterestSavingsAccount;
     double yearlyAverageYieldInvestment;
     double yearlyInflation;
     double amountInvested;
     double amountOfMortage;
     double interestOnMortage;
     double penaltyFreeMortageReduction;
     double valueOfHouse;
     double realEstateYearlyYield;
     double netYearlyIncome;
     double availableCash;
     double yearsLeftOnMorgage;
     std::list<month> listOfMonths;
     std::list<year> listOfYears;
};

bool isValidInt(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool isValidDouble(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

void askAndGetAnswerFromConsole(std::string question, int& answer) {
    std::string myNumberString;
    bool numberEnterd = false;
    while (!numberEnterd) {
        std::cout << question << std::endl;
        std::getline(std::cin, myNumberString);
        if (isValidInt(myNumberString)) {
            answer = std::stod(myNumberString);
            std::cout << std::endl;
            numberEnterd = true;
        }
        else {
            std::cout << "Please enter only numbers!" << std::endl << std::endl;
        }
    }
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

void finance::setFinancialPicture(double monthlyInvestmentPortofolio, double monthlyInvestmentSavingsAccount, double amountInSavingsAccount, double yearlyInterestSavingsAccount, double yearlyAverageYieldInvestment, double yearlyInflation, double amountInvested, double amountOfMortage, double interestOnMortage, double penaltyFreeMortageReduction, double valueOfHouse, double realEstateYearlyYield, double netYearlyIncome, double yearsLeftOnMorgage)
{
    this->monthlyInvestmentPortofolio = monthlyInvestmentPortofolio;
    this->monthlyInvestmentSavingsAccount = monthlyInvestmentSavingsAccount;
    this->amountInSavingsAccount = amountInSavingsAccount;
    this->yearlyInterestSavingsAccount = yearlyInterestSavingsAccount;
    this->yearlyAverageYieldInvestment = yearlyAverageYieldInvestment;
    this->yearlyInflation = yearlyInflation;
    this->amountInvested = amountInvested;
    this->amountOfMortage = amountOfMortage;
    this->interestOnMortage = interestOnMortage;
    this->penaltyFreeMortageReduction = penaltyFreeMortageReduction;
    this->valueOfHouse = valueOfHouse;
    this->realEstateYearlyYield = realEstateYearlyYield;
    this->netYearlyIncome = netYearlyIncome;
    this->yearsLeftOnMorgage = yearsLeftOnMorgage;
}

void finance::calculateOneMonthOnCurrentPlan()
{
    double avarageMonthlyIncome = netYearlyIncome / 12;
    double thisMonthsMortageBill = ((this->amountOfMortage + (this->amountOfMortage * (this->interestOnMortage / 100))) / this->yearsLeftOnMorgage) / 12;
    
    this->availableCash = avarageMonthlyIncome - (thisMonthsMortageBill + this->monthlyInvestmentPortofolio + this->monthlyInvestmentSavingsAccount);
    this->amountInSavingsAccount += this->monthlyInvestmentSavingsAccount;
    this->amountInvested += this->monthlyInvestmentPortofolio;
    this->amountOfMortage -= (this->amountOfMortage / this->yearsLeftOnMorgage) / 12;

    this->listOfMonths.push_back({
     amountInSavingsAccount,
     amountInvested,
     amountOfMortage,
     availableCash,
        });

}

void finance::calculateOneYearOnCurrentPlan()
{
    for (int i = 0; i < 12; i++) {
        calculateOneMonthOnCurrentPlan();
    }
    this->amountInSavingsAccount += amountInSavingsAccount * (this->yearlyInterestSavingsAccount / 100);
    this->amountInvested += this->amountInvested * (this->yearlyAverageYieldInvestment / 100);
    this->amountOfMortage -= this->penaltyFreeMortageReduction;
    this->availableCash = 0;
    for (int i = 0; i < 12; i++) {
        month listElement = *std::prev(this->listOfMonths.end(), i);
        this->availableCash += listElement.availableCash;
    }
    this->availableCash = this->availableCash/12;
    this->valueOfHouse += this->valueOfHouse * (this->realEstateYearlyYield / 100);
    this->listOfYears.push_back({
        this->amountInSavingsAccount,
        this->amountInvested,
        this->amountOfMortage,
        this->availableCash,
        this->valueOfHouse
        });
    this->yearsLeftOnMorgage -= 1;
}

void getStartingValuesFromUser(finance& financialSituation){
    double amountInSavingsAccount;
    double yearlyInterestSavingsAccount;
    double amountInvested;
    double yearlyAverageYieldInvestment;
    double valueOfHouse;
    double realEstateYearlyYield;
    double monthlyInvestmentPortofolio;
    double monthlyInvestmentSavingsAccount;
    double amountOfMortage;
    double interestOnMortage;
    double penaltyFreeMortageReduction;
    double yearlyInflation;
    double netYearlyIncome;
    double yearsLeftOnMorgage;
    askAndGetAnswerFromConsole("What is your average expected total yearly net income ", netYearlyIncome);
    askAndGetAnswerFromConsole("How much money is in your savings account right now:", amountInSavingsAccount);
    askAndGetAnswerFromConsole("What has been the avarage interest on this savings account: (%)", yearlyInterestSavingsAccount);
    askAndGetAnswerFromConsole("How much do you save each month", monthlyInvestmentSavingsAccount);
    askAndGetAnswerFromConsole("How much money is in your investment portofolio right now:", amountInvested);
    askAndGetAnswerFromConsole("What is the expected yield of your portofolio: (%)", yearlyAverageYieldInvestment);
    askAndGetAnswerFromConsole("How much are you planning to invest each month?", monthlyInvestmentPortofolio);
    askAndGetAnswerFromConsole("What is the value of your home:", valueOfHouse);
    askAndGetAnswerFromConsole("What is the avarage yearly value increase on realestate in your area?", realEstateYearlyYield);
    askAndGetAnswerFromConsole("What is your current mortage", amountOfMortage);
    askAndGetAnswerFromConsole("What is the interest rate on your mortage", interestOnMortage);
    askAndGetAnswerFromConsole("How many years are left on your mortage", yearsLeftOnMorgage);
    askAndGetAnswerFromConsole("If you have the option to do so penalty free how much do you plan to pay off extra on your mortage each year", penaltyFreeMortageReduction);
    askAndGetAnswerFromConsole("What is the average yearly inflation in your area", yearlyInflation);

    financialSituation.setFinancialPicture(
        monthlyInvestmentPortofolio,
        monthlyInvestmentSavingsAccount,
        amountInSavingsAccount,
        yearlyInterestSavingsAccount,
        yearlyAverageYieldInvestment,
        yearlyInflation,
        amountInvested,
        amountOfMortage,
        interestOnMortage,
        penaltyFreeMortageReduction,
        valueOfHouse,
        realEstateYearlyYield,
        netYearlyIncome,
        yearsLeftOnMorgage
    );
}

void displayWelcomeText() {
    std::cout << "Finance calculator v 0.1" << std::endl;
    std::cout << "Calculate the effect of compounding interest and inflation on buying power in \"Today's money\" over a given number of \n" <<
        "years. This wil help you eveluate your savings and investment plan. It will note the years from now when you could \n" <<
        "expect to retire with your current lifestyle. This will be three percent annualy of your total capital" << std::endl << std::endl << std::endl;
}

void doTheMath(finance& financialSituation) {
    int yearsIntoTheFuture;
    askAndGetAnswerFromConsole("How many years do you want to look into the future?", yearsIntoTheFuture);
    for (int i = 0; i < yearsIntoTheFuture; i++) {
        financialSituation.calculateOneYearOnCurrentPlan();
    }
}

void showYearly() {

}

void showMonthly() {

}

void determenHowToShowResultsAndShowThem() {
    int userChoise = 0;
    while(userChoise != 3){
        askAndGetAnswerFromConsole("Press 1 to show results by year, 2 to show results by month and enter 3 to exit", userChoise);
        switch (userChoise) {
        case 1:
            showYearly();
            break;
        case 2:
            showMonthly();
            break;
        default:
            break;
        }
    }
}

int main()
{
    finance financialSituation;
    displayWelcomeText();
    getStartingValuesFromUser(financialSituation);
    doTheMath(financialSituation);
    determenHowToShowResultsAndShowThem();
    system("pause");
}


