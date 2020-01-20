# Report of CS4293 Assignment 1

## Secret-Key Encryption

### Task 1:  Frequency Analysis Against Monoalphabetic Substitution Cipher

* Answer: The key of encryption is `vgapnbrtmosicuxejhqyzflkdw` corresponds to `abcdefghijklmnopqrstuvwxyz`

* Explanation: I used the [online decrypting resource](<http://www.richkni.co.uk/php/crypta/freq.php>) to analyze the character frequency and compared it with the frequency [bigram](<https://en.wikipedia.org/wiki/Bigram>) and [trigram](<https://en.wikipedia.org/wiki/Trigram>). I also used the [word finder](<https://word.tips/>). By **selecting all the words with length two and three** and comparing the result, we can find that the most possible mapping is (`plain<=> cypher`): 

* Code (Select words with specific length): 

  ```python
  import operator
  with open('ciphertext.txt', 'r') as file:
  	words = file.read().split()
      dic = {}
      for word in words:
          if len(word) == 3:
              if not word in dic :
                  dic[word] = 1
              else:
                  dic[word] += 1
       sorted_dic = sorted(dic.items(), key=lambda kv:kv[1])
       print(sorted_dic)
  ```

* Observation:

  * Steps to find the key

  ```
  (1) the <=> ytn: 
  {e <=> n, h <=> t, t <=> y}
  (2) three <=> ythnn (guess): 
  {e <=> n, h <=> t, r <=> h, t <=> y}
  (3) that <=> ytvy :  
  {a <=> v, e <=> n, h <=> t, r <=> h, t <=> y}
  (4) to <=> yx :
  {a <=> v, e <=> n, h <=> t, o <=> x, r <=> h, t <=> y}
  (5) of <=> xb :
  {a <=> v, e <=> n, f <=> b, h <=> t, o <=> x, r <=> h, t <=> y}
  (6) it <=> my
  {a <=> v, e <=> n, f <=> b, h <=> t, i <=> m, o <=> x, r <=> h, t <=> y}
  (7) in <=> mu, on <=> xu, no <=> ux
  {a <=> v, e <=> n, f <=> b, h <=> t, i <=> m, n <=> u, o <=> x, r <=> h, t <=> y}
  (8) all <=> vii, which <=> ltmat, until a winner <=> zuymi v lmuunh
  {a <=> v, c <=> a, e <=> n, f <=> b, h <=> t, i <=> m, l <=> i, n <=> u, o <=> x, r <=> h, t <=> y, u <=> z, w <=> l}
  (9) is <=> mq
  {a <=> v, c <=> a, e <=> n, f <=> b, h <=> t, i <=> m, l <=> i, n <=> u, o <=> x, r <=> h, s <=> q, t <=> y, u <=> z, w <=> l}
  (10) about <=> vgxzy, seems <=> qnncq, right <=> hmrty
  {abcefghilmnorstuw <=> vganbrtmicuxhqyzl}
  (11) awards <=> vlvhpq, just <=> ozqy, like <=> imsn, trip <=> yhme, quit <=> jzmy, harvey <=> tvhfnd, extra <=> nkyhv, they <=> ytnd
  {abcdefghijklmnopqrstuvwxyz <=> vgapnbrtmosicuxejhqyzflkdw}
  ```

  * Words with length 2 and 3

  ![1579335280495](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579335280495.png)

  ![1579338582398](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579338582398.png)

  * Frequency

    * one character

      ![1579329814006](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579329814006.png)

    * two character

      ![1579329506891](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579329506891.png)

    * three character

      ![1579328805721](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579328805721.png)

-----------------------------

### Task 2: Encryption using Different Ciphers and Modes

* Observation

  * Use `s -aes-128-cbc`

    * command

    ![1579342171019](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342171019.png)

    * encrypted binary file

    ![1579342102099](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342102099.png)

    * decrypted file

    ![1579342144057](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342144057.png)

  * Use `-bf-cbc`

    * command line

    ![1579342370293](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342370293.png)

    * encrypted binary file

    ![1579342277795](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342277795.png)

    * decrypted file

    ![1579342326581](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342326581.png)

  * Use `-aes-128-cfb`

    * command

    ![1579342541148](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342541148.png)

    * encrypted binary file

    ![1579342518751](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342518751.png)

    * decrypted file

    ![1579342495551](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342495551.png)

  * Use different algorithms to encode and decode

    * command line

    ![1579342655197](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342655197.png)

    * decrypted file by using different algorithm => does not work (use wrong key to decrypt also doesn’t work)

    ![1579342634791](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342634791.png)

--------------------------------

### Task 3: Encryption Mode - ECB vs. CBC

* Observation

  * Command line

    ![1579410582687](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579410582687.png)

  * Comparison between three pictures

    ![1579410767273](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579410767273.png)

* Explanation: ECB is basically raw cipher , while CBC is step-by-step cipher which takes the output of the previous cipher and performs XOR with a block of plaintext. The first output is produced by first plaintext block and initialization vector. Therefore, ECB will preserve some features of the original image, while CBC will not. 

------------------------------------

### Task 4: Padding

* Observation

  * ECB: Has padding

    ![1579412656739](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412656739.png)

  * CBC: Has padding

    ![1579412044015](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412044015.png)

  * CFB: No padding

    ![1579412947219](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412947219.png)

  * OFB: No padding

    ![1579413112390](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579413112390.png)

* Explanation: 

  * The block ciphers require specific block size. 

  * Once the plaintext is not dividable to equal-sized blocks, there will be exactly one smaller block, which will be the last block in the encryption pipeline. 

  * For modes CFB and OFB, the last block of plaintext will not be used by the block cipher (as shown below).

    ![Screen Shot 2020-01-19 at 3.47.57 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 3.47.57 PM.png)

    ![Screen Shot 2020-01-19 at 3.48.03 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 3.48.03 PM.png)

------------------

### Task 5: Error Propagation – Corrupted Cipher Text

* Create: Use `generator.py`: 

  ```python
  with open("1000bytes.txt", "w") as file:
      for i in range(0, 1000):
          file.write(str(i%10))
  ```

  ![Screen Shot 2020-01-20 at 9.38.37 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-20 at 9.38.37 PM.png)

* Encrypt (Use ECB as an example)

  ![Screen Shot 2020-01-20 at 9.43.01 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-20 at 9.43.01 PM.png)

* 

---------------

## MD5 Collision Attack



## RSA Public-Key Encryption and Signature



## Pseudo Random Number Generation

### Task 18: Generate Encryption Key in a Wrong Way

* Observation

  * With `srand`: Seems right.

    ![Screen Shot 2020-01-19 at 4.01.19 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 4.01.19 PM.png)

  * Without `srand`: All the “random” numbers are the same.

    ![Screen Shot 2020-01-19 at 4.03.03 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 4.03.03 PM.png)

* Explanation: 

  * `srand` will pass a seed to the `c++` random number generator. And the `rand` function will generate a pseudo random number based on the given seed. 
  * `time` function is used to use the current time as the seed, since the number genrating function is highly non-linear, the result will be partialy “random”. 

---------

### Task 19: Guessing the Key

* Command line: 

  ![Screen Shot 2020-01-19 at 6.20.14 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 6.20.14 PM.png)

* 

---------