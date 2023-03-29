# ATM Project
- Uses object-oriented programming
- Has Checking Account and Savings Account
  - Savings Account will add or subtract up to 50% of the value each time the ATM is logged into

- Closed accounts preserve the Account Number but replace all user data with '-1'

- 'accounts.txt' contains user data:
  - Contains user data in format: ID PIN CheckingAccNum CheckingAccBal SavingsAccNum SavingsAccBal
  - **DO NOT** add more lines to the file unless you change anywhere in the code that uses '100' as an iterator amount!
  - Program can support up to 100 accounts

## Dev Note:
- Constructor and Desructor functions print a lot of times due to the nature of the assignment. Future versions may fix the problem, no solution as of now. (2023.3.2)
