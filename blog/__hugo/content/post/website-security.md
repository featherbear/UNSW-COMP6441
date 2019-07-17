---
title: "Website Security"
date: 2019-07-09T18:09:21+10:00

cateogories: ["Extended Security", "Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Web Security

## Web Fundamentals

When you visit a website, your internet browser sends a HTTP([S](https://featherbear.github.io/UNSW-COMP6441/blog/post/lightning-talk-http-https-security/)) GET request to the web server, which returns the content of the website (HTML + CSS + JS).

Dynamic servers (ie not just static webpages) often have some sort of database backend where data is stored, and are often accessed through the backened with SQL.

To logon to a website, session cookies (special browser cookies) are used as claims of authentication.

## Attacks

### Goals

* Inject content
* Steal cookies
* Modify DOM
* ???
* $$$

### Methods

#### Cross-Site Scripting

Cross Site Scripting (XSS) is an attack where we can inject specially crafted input to circument the (flawed) logic of the server code.  
This is because there is server code does not escape the input.

There are two categories of XSS attacks.

**Reflected XSS** - Where the input is immediately reflected  
**Stored XSS** - Code is stored (ie forum post, message) and is executed by users who load that code

**Why do XSS attacks happen?**  
Bad sanitisation of user data.  
By _sanitising_ the user data (ie stripping script tags, escaping HTML tags), XSS attacks can be prevented.

**Play Around**  

* http://xss-game.appspot.com
* http://govagriculture.web.ctfcompetition.com


#### SQL Injection

SQL is a database language to access and store information to a database server.  
While SQL itself is relatively safe, if it is mishandled it can lead to security vulnerabilities.

Consider the SQL query:
```sql
SELECT * FROM users WHERE username = 'john' AND password = 'citizen'
```
This SQL query fetches the row corresponding to a user who has the username `john` and the password `citizen`.

One common server language for backends is PHP, which is often paired with a MySQL server.  

For example, to execute the above query:
```php
mysqli_query("SELECT * FROM users WHERE username = 'john' AND password = 'citizen'");
```

Cool!

So what happens if we want to pass in variables for the username and password, so we can write our login form?

```php
mysqli_query("SELECT * FROM users WHERE username = '" . $username . "' AND password = '" . $password . "'");
```

So let's set `$username = 'jane'` and `$password = 'smith'`

When we execute the query now, we'll be querying the following:
```php
// mysqli_query("SELECT * FROM users WHERE username = '" . "jane" . "' AND password = '" . "smith" . "'");
mysqli_query("SELECT * FROM users WHERE username = 'jane' AND password = 'smith'");
```

If there is a record in the `users` table with a username of `jane` and password of `smith`, we'll get a result!

_Now to SQL injections..._  
SQL injection attacks the weakness of backend systems where the data and control mechanisms are mixed together.

What if we set `$username = 'admin'` and `$password = "' OR '1'='1"`

```php
// mysqli_query("SELECT * FROM users WHERE username = '" . "admin" . "' AND password = '" . "' OR '1'='1" . "'");
mysqli_query("SELECT * FROM users WHERE username = 'admin' AND password = '' OR '1'='1'");
```
That is, select the `admin` account if the password is `(blank)`, or if `'1' = '1'`...  
`'1' = '1'` is always true, meaning that the right hand condition will be true.  

In other words, we've just gotten access to the `admin` account without knowing the password!

**Preventing**  

To prevent these attacks, we should also sanitise the input.  
With PHP, we would use something like `mysqli_real_escape_string(...)`

#### Cross Site Request Forgery

Abit like a stored XSS attack, a malicious website may embed a crafted link to a target website.
