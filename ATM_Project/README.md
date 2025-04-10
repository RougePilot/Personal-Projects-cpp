# ATM Project
- Uses object-oriented programming
- Has Checking Account and Savings Account
  - Savings Account will add or subtract up to 50% of the value each time the ATM is logged into

## Usage
- After compiling both ``` ATMProject.cpp ``` and ``` Bank.cpp ```, and running. follow the prompts
  - Inputs requiring words/letter are case sensitive; inouts must be all capitalized
  - Refer to below key for ``` accounts.txt ``` for ID, PIN, and Account Numbers
  - After each transaction, user will be asked if he wants to make another transaction, selecting N (No) will end the program
  - New accounts may be created with [OPEN] and existing accounts may be closed with [CLOSE]

- 'accounts.txt' contains user data:
  - Contains user data in format: ```ID PIN CheckingAccNum CheckingAccBal SavingsAccNum SavingsAccBal```
  - **DO NOT** add more lines to the file unless you change anywhere in the code that uses '100' as an iterator amount!
  - Program can support up to 100 accounts
  - Closed accounts are not written back into the file
 
