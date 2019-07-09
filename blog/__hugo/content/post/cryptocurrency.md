---
title: "Cryptocurrency"
date: 2019-07-09T18:39:34+10:00

hiddenFromHomePage: false
postMetaInFooter: false

cateogories: ["Extended Security", "Musings"]
flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Cryptocurrency

> Consider buying a product with your debit/credit card...
* The customer would first tap their card on the EFTPOS terminal.  
* Their card information and transaction data would then be transmitted to a _payment gateway_ which would validate and handle the transaction.  
* The money then gets transferred to the seller

With cryptocurrency, the customer and seller have a more direct transaction, 'without' the need for a payment gateway.

## Blockchain and Hashing

Cryptocurrency is based on the model of blockchains - that is blocks of information chained together (_sorta like a linked list!_).  

Each block contains a **collection of transactions**, as well as a SHA-256 hash of the **previous**, **current** and (possibly) **next** block adjacent to the current block.

By nature of design, a lot of bits of work is needed to compute the hashes of these blocks, so it is difficult to falsify.

The longest chain is regarded as the latest and authentic chain.

# Mining 

When a new transaction is made, it is considered **unverified**. This transaction is placed into a pool of other unverified transactions where people (called miners) attempt to (brute-forcing the _nonce_ value) to find a hash value smaller than a target hash value.  

When the hash is solved, the _nonce_ value is broadcasted onto other miners, and the transaction is appended at the end of the chain.

Miners often work together (mining pools) to have a higher chance of solving the problem. (It gets exponentially harder and harder)

# Proof of Stake

Proof of Stake is a type of consensus algorithm where the idea of competing to be the first solver is replaced with income based on the ratio of your assets in the pool

# Why so many different cryptocurrencies?  
It's not just about money!

- Payment & Current
- Privacy
- Computing and Data Management
- Some other stuff

# Privacy

_Who's who? How do you know which transaction belongs to whom?_

* Inferring identity by relations between addresses
* Interactions between nodes and users

Some cryptocurrencies are intended for anonymity, and so they employ various techniques to make tracing and inferring ownership difficult
