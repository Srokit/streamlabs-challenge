# StreamLabs Challenge Explanation
# Author: Stan Rokita

## Install

$ cmake
$ make

## Run

$ ./buy_from_stream_labs_store

## Quick Explanation

2 customers buy a product at random from the store 100 times each.

Logging information explains if the product was in-stock or not at time of their purchase attempt.

You can see all the receipts from the purchases under ./receipts afterwards.

I chose to not print info about the products after using a get_products_by_family method or get_product method, but using these methods to get info about the product is trivial.

## Quiz Answers

1\. How long did it take you to complete this assignment?
A. 8 Hours (Most of it after a long day of interviewing)


2. What about this assignment did you find unclear?


A. How to represent purchashing. I chose to represent it mostly through stdout logs explaining a transaction as it happend. I also wasn't sure if the fake customers should start with a certain amount of cash themselves. I decided that they had unlimited cash and were only limited by quantity of products.


3\. Do you feel like this assignment has an appropriate level of difficulty?


A. I feel as though the basic premis is simple, but it ends up being more complex once you start dealing with the complexities of C++ implementation and configuring the CMake projects and the git sumbodule setup.


4\. Briefly explain the technical decisions you made in this project, i.e. architecture, code-splitting, librairies, or other decisions and tradeoffs.


A. I chose to separate the library into a subfolder called 'store'. I then divided the buy_from_stream_labs_store executable into sources inside the customer subdir, which contains simple customer objects which just have a name. I then put most of the functionality of spinning up threads that make purchases as 2 customers into main.cpp. I have the customers randomly select a product after fetching the list of all product ids and attempt to purchase it. The purchases are locked only before and after checking the availability of a product and decrementing its number. The printing of receipts can be done in paralell since the data used does not change and we print to different file each time by generating a unqiue number string on the end.