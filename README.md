# Gronsfeld Cipher with Hashing (C++)

## Overview

This project implements the Gronsfeld Cipher along with a polynomial rolling hash function to demonstrate secure message transmission using encryption and message authentication.

---

## Gronsfeld Cipher (Brief Theory)

The Gronsfeld Cipher is a classical polyalphabetic substitution cipher similar to the Vigenère cipher, but it uses a numeric key (0–9).

Each character of the plaintext is shifted using the corresponding digit of the key. If the key is shorter than the text, it is repeated.

* Alphabets use modulo 26 shifting
* Digits use modulo 10 shifting

Encryption applies addition, while decryption applies subtraction.

---

## Hash Function (Brief Theory)

A polynomial rolling hash function is used:

h = (h * p + c) mod M

Where:

* p = 13
* M = 1e9 + 7
* c = ASCII value of character

The hash is computed on the plaintext and concatenated with the message before encryption to ensure integrity.

---

## Instructions to Run

```bash
g++ cia_hash.cpp
./a.exe
```

Steps:

1. Select option 1 for encryption
2. Enter plaintext and numeric key
3. Select option 2 for decryption
4. Enter ciphertext and key to verify integrity

---

## Worked Examples

### Example 1

Plaintext (M): Anunav22
Key: 4

Step 1: Compute Hash
H(M) = 656419309

Step 2: Concatenate
Anunav22 | 656419309

Step 3: Encryption

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
5 → 9
6 → 0
4 → 8
1 → 5
9 → 3
3 → 7
0 → 4
9 → 3

Encrypted Text: Eryrez66|090853743

---

### Example 2

Plaintext (M): 13anu15
Key: 4

Step 1: Compute Hash
H(M) = 258482134

Step 2: Concatenate
13anu15 | 258482134

Step 3: Encryption

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
2 → 6
1 → 5
3 → 7
4 → 8

Encrypted Text: 57ery59|692826578

---

## Decryption Procedure (Short)

1. Input ciphertext and key
2. Decrypt using Gronsfeld cipher
3. Split into message and hash using '|'
4. Recompute hash on message
5. Compare both hashes
6. If equal, display message; otherwise show tampering error

---

## Why This Hash Function

The polynomial rolling hash is chosen because:

* It is efficient (O(n))
* Easy to implement without libraries
* Provides good distribution of values
* Suitable for demonstrating hashing concepts

---

## Message Authentication Flow

M → H(M) → M || H(M) → Encrypt → Decrypt → Split → Verify

---

## Conclusion

This project demonstrates how classical encryption combined with hashing ensures both confidentiality and integrity of transmitted data.
