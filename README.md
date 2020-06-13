## C++ Project's Description
### 1. Vending Machine Change Maker
This program will simulate a simple change maker for a vending machine. It will start with a stock of coins and dollars. It will then repeatedly request the price for an item to be purchased or to quit.
* It only accepts nickels, dimes, quarters, one-dollar and five-dollar bills
* When the user has deposited enough to cover the cost of the item, the program will calculate the coins to be dispensed in change. Alternately, the user can cancel the purchase up until full payment has been deposited, in which case, your program will calculate the coins to be dispensed to refund any partial payment already deposited.
* At program start, assume a stock of 25 nickels, 25 dimes, and 25 quarters. Print the contents of the stock.
* Repeatedly prompt the user for a price in the form xx.xx, where x denotes a digit, or to enter ‘q’ to quit.
* With each purchase, the program will update the stock of coins and dollars. Before quitting, it will output the remaining stock of coins and dollars.
* The specifications are spelled out more thoroughly below. An example interaction appears at the end of this section. All change and refunds must be in coins only, and must use the minimum number of coins possible.
 * Check the price entered is a (non-negative) multiple of .05 (i.e., it is payable in nickels). If not, then print an error message and start over requesting either a new price or to quit (indicated by entering a ‘q’).
 * Print a menu for indicating the coin/bill deposited or to cancel payment.
 * Prompt for a selection from this menu.
 * If the user enters an illegal selection, re-prompt for a correct one.
 * Following each deposit, print the remaining amount owed (indicate the number of dollars and the number of cents).
 * In case exact payment is deposited, print a message such as “No change due.”
 * Just before quitting, print the total amount (the number of dollars and number of cents) left in the stock.
 * Sample run output:
 ![VM1](/images/VM1.png)
 ![VM1](/images/VM2.png)
 ![VM1](/images/VM3.png)
 ![VM1](/images/VM4.png)
