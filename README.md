# Cryptography Concepts CIA
# Gronsfeld Cipher with Hashing (C++)
## Overview

This project implements the **Gronsfeld Cipher** along with a **custom polynomial rolling hash function** to demonstrate secure message transmission using encryption and message authentication of TYPE A

---

## Gronsfeld Cipher (Brief Theory)

The Gronsfeld Cipher is a classical polyalohabetic substitution cipher similar to the Vigenère cipher, but it uses a **numeric key (0–9)** instead of alphabetic keys.

### Working:

* Each character of the plaintext is shifted using a digit from the key
* The key repeats if it is shorter than the message
* Encryption uses addition, while decryption uses subtraction

Example logic:

* Plain test is taken and numeric values for each character is taken
* String of key is taken and converted to numeric values for each character
* Both are added and the mod 26 is applied on the numeirc value of each character
* Cipher text is gotten from the numeric value 

---

## Hash Function (Brief Theory)

A **polynomial rolling hash function** is used to generate a hash value for the message.

Formula:
h = (h * p + c) mod M (used basic DSA polynomial hash )

Where:

* p = 13 (prime base)
* M = 1e9 + 7 (large prime modulus)
* c = ASCII value of each character

This hash is concatenated with the message before encryption to ensure **data integrity** of message as this is TYPE A message authentication

---

## Instructions to Run

```bash
g++ cia_hash.cpp 
./a.exe(in windows)
./a.out(in linux and mac)
```

Steps:

1. Choose option 1 → Enter plaintext and key → get encrypted text
2. Choose option 2 → Enter encrypted text and key → system verifies hash and decrypts

---
## Worked Examples (Using Key = 4)

---

### Example 1

**Plaintext (M):** Anunav22

---

### Step 1: Compute Hash

H(M) = 619289987

---

### Step 2: Concatenate

```
Anunav22 | 619289987
```

---

### Step 3: Encryption (Key = 4)

```
A → E  
n → r  
u → y  
n → r  
a → e  
v → z  
2 → 6  
2 → 6  
| → |  
6 → 0  
1 → 5  
9 → 3  
2 → 6  
8 → 2  
9 → 3  
9 → 3  
8 → 2  
7 → 1  

Encrypted Text: Eryrez66|053623321
```

---

### Example 2

**Plaintext (M):** 13anu15

---

### Step 1: Compute Hash

H(M) = 258480834

---

### Step 2: Concatenate

```
13anu15 | 258480834
```

---

### Step 3: Encryption (Key = 4)

```
1 → 5  
3 → 7  
a → e  
n → r  
u → y  
1 → 5  
5 → 9  
| → |  
2 → 6  
5 → 9  
8 → 2  
4 → 8  
8 → 2  
0 → 4  
8 → 2  
3 → 7  
4 → 8  

Encrypted Text: 57ery59|692824278
```
---

---
## Decryption Procedure (Short)

1. Input ciphertext and key
2. Decrypt using Gronsfeld cipher
3. Split result into message and hash using `|`
4. Recompute hash on the message
5. Compare both hash values
6. If equal → display message, else → show tampering error


## Why This Hash Function?

The polynomial rolling hash was chosen because:

* It is **efficient (O(n))**
* Easy to implement without libraries
* Familar since used in DSA
* Provides **good distribution of values**

---

## Message Authentication Flow(TYPE A)

1. Compute hash of message
2. Concatenate message and hash
3. Encrypt combined data
4. Decrypt at receiver side
5. Recompute hash and compare

This ensures:

* **Confidentiality** (via encryption)
* **Integrity** (via hashing)

---

## Conclusion

This project demonstrates how classical encryption techniques can be combined with hashing to simulate secure communication and detect tampering in transmitted data.
