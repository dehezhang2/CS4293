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

  

### Task 2

* Observation

  * Use `s -aes-128-cbc`

    * command

    ![1579342171019](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342171019.png)

    ![1579342102099](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342102099.png)

    ![1579342144057](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342144057.png)

  * Use `-bf-cbc`

    ![1579342370293](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342370293.png)

    ![1579342277795](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342277795.png)

    ![1579342326581](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342326581.png)

  * Use `-aes-128-cfb`

    ![1579342541148](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342541148.png)

    ![1579342518751](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342518751.png)

    ![1579342495551](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342495551.png)

  * Use different algorithms to encode and decode

    ![1579342655197](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342655197.png)

    ![1579342634791](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342634791.png)

## MD5 Collision Attack



## RSA Public-Key Encryption and Signature



## Pseudo Random Number Generation



