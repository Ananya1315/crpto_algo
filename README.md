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
## Worked Examples (Correct Flow)

---

### Example 1

**Plaintext (M):** Anunav22
**Key:** 314

---

### Step 1: Compute Hash on Plaintext

Using polynomial rolling hash (p = 13):

| Step | Char | ASCII | Calculation       | Hash      |
| ---- | ---- | ----- | ----------------- | --------- |
| 1    | A    | 65    | 0×13 + 65         | 65        |
| 2    | n    | 110   | 65×13 + 110       | 955       |
| 3    | u    | 117   | 955×13 + 117      | 12432     |
| 4    | n    | 110   | 12432×13 + 110    | 161726    |
| 5    | a    | 97    | 161726×13 + 97    | 2102535   |
| 6    | v    | 118   | 2102535×13 + 118  | 27333073  |
| 7    | 2    | 50    | 27333073×13 + 50  | 355329999 |
| 8    | 2    | 50    | 355329999×13 + 50 | 619289987 |

**H(M) = 619289987**

---

### Step 2: Concatenate

M || H(M)
Anunav22|619289987

---

### Step 3: Encryption (Gronsfeld Cipher)

| Character | A | n | u | n | a | v | 2 | 2 | | | 6 | 1 | 9 | 2 | 8 | 9 | 9 | 8 | 7 |
|----------|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
| Key      | 3 | 1 | 4 | 3 | 1 | 4 | 3 | 1 | - | - | 3 | 1 | 4 | 3 | 1 | 4 | 3 | 1 | 4 |
| Result   | D | o | y | q | b | z | 5 | 3 | | | 9 | 2 | 3 | 5 | 9 | 3 | 2 | 9 | 1 |

**Encrypted Text:** `Doyqbz53|923593291`

---

### Example 2

**Plaintext (M):** 13anu15
**Key:** 23

---

### Step 1: Compute Hash on Plaintext

| Step | Char | ASCII | Calculation      | Hash      |
| ---- | ---- | ----- | ---------------- | --------- |
| 1    | 1    | 49    | 0×13 + 49        | 49        |
| 2    | 3    | 51    | 49×13 + 51       | 688       |
| 3    | a    | 97    | 688×13 + 97      | 9041      |
| 4    | n    | 110   | 9041×13 + 110    | 117643    |
| 5    | u    | 117   | 117643×13 + 117  | 1529476   |
| 6    | 1    | 49    | 1529476×13 + 49  | 19883137  |
| 7    | 5    | 53    | 19883137×13 + 53 | 258480834 |

**H(M) = 258480834**

---

### Step 2: Concatenate

```
M || H(M)
Anunav22 | 619289987
```

---

### Step 3: Encryption (Gronsfeld Cipher)

| Character | A | n | u | n | a | v | 2 | 2 | | | 6 | 1 | 9 | 2 | 8 | 9 | 9 | 8 | 7 |
| --------- | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| Key       | 3 | 1 | 4 | 3 | 1 | 4 | 3 | 1 | - | 3 | 1 | 4 | 3 | 1 | 4 | 3 | 1 | 4 |
| Result    | D | o | y | q | b | z | 5 | 3 | | | 9 | 2 | 3 | 5 | 9 | 3 | 2 | 9 | 1 |

**Encrypted Text:** `Doyqbz53|923593291`


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
