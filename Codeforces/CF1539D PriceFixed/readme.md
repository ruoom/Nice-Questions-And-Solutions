# [CF1539D](https://codeforces.com/problemset/problem/1539/D)

# tags
`binary search` `greedy` `implementation` `sortings` `two pointers` `*1600`

# description
Lena is the most economical girl in Moscow. So, when her dad asks her to buy some food for a trip to the country, she goes to the best store  — "PriceFixed". Here are some rules of that store:

The store has an infinite number of items of every product.
All products have the same price: 22 rubles per item.
For every product ii there is a discount for experienced buyers: if you buy bibi items of products (of any type, not necessarily type ii), then for all future purchases of the ii-th product there is a 50%50% discount (so you can buy an item of the ii-th product for 11 ruble!).
Lena needs to buy nn products: she must purchase at least aiai items of the ii-th product. Help Lena to calculate the minimum amount of money she needs to spend if she optimally chooses the order of purchasing. Note that if she wants, she can buy more items of some product than needed.

Input
The first line contains a single integer nn (1≤n≤1000001≤n≤100000) — the number of products.

Each of next nn lines contains a product description. Each description consists of two integers aiai and bibi (1≤ai≤10141≤ai≤1014, 1≤bi≤10141≤bi≤1014) — the required number of the ii-th product and how many products you need to buy to get the discount on the ii-th product.

The sum of all aiai does not exceed 10141014.

Output
Output the minimum sum that Lena needs to make all purchases.

## input
```
3
3 4
1 3
1 5
```

## output
```
8
```

## input
```
5
2 7
2 8
1 2
2 4
1 8
```

## output
```
12
```
Note
In the first example, Lena can purchase the products in the following way:

one item of product 33 for 22 rubles,
one item of product 11 for 22 rubles,
one item of product 11 for 22 rubles,
one item of product 22 for 11 ruble (she can use the discount because 33 items are already purchased),
one item of product 11 for 11 ruble (she can use the discount because 44 items are already purchased).
In total, she spends 88 rubles. It can be proved that it is impossible to spend less.

In the second example Lena can purchase the products in the following way:

one item of product 11 for 22 rubles,
two items of product 22 for 22 rubles for each,
one item of product 55 for 22 rubles,
one item of product 33 for 11 ruble,
two items of product 44 for 11 ruble for each,
one item of product 11 for 11 ruble.
In total, she spends 1212 rubles.



